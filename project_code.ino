import network
import time
import urequests
from machine import Pin, ADC

# -------------------------------
# Soil Moisture Sensor
# SIG -> GPIO 34
# -------------------------------
sensor = ADC(Pin(34))

# Set ADC range
sensor.atten(ADC.ATTN_11DB)
sensor.width(ADC.WIDTH_12BIT)

# -------------------------------
# LED
# LED -> GPIO 2
# -------------------------------
led = Pin(2, Pin.OUT)

# -------------------------------
# Wokwi Wi-Fi
# -------------------------------
SSID = "Wokwi-GUEST"
PASSWORD = ""

# -------------------------------
# ThingSpeak
# -------------------------------
API_KEY = "X2WMG93X8V90P394"
URL = "http://api.thingspeak.com/update"

# -------------------------------
# Connect to Wi-Fi
# -------------------------------
wifi = network.WLAN(network.STA_IF)
wifi.active(True)
wifi.connect(SSID, PASSWORD)

print("Connecting to Wi-Fi...")

while not wifi.isconnected():
    time.sleep(1)

print("Wi-Fi connected!")
print(wifi.ifconfig())

# -------------------------------
# Monitor Soil Moisture
# -------------------------------
while True:
    try:
        # Read soil moisture
        value = sensor.read()

        # Convert ADC value to percentage
        moisture = int((4095 - value) * 100 / 4095)

        # Keep percentage between 0 and 100
        moisture = max(0, min(100, moisture))

        print("Soil Moisture:", moisture, "%")

        # -------------------------------
        # LED indication
        # -------------------------------
        if moisture < 30:
            led.on()
            print("Soil is DRY - Water needed!")
        else:
            led.off()
            print("Soil moisture is NORMAL")

        # -------------------------------
        # Send data to ThingSpeak
        # -------------------------------
        response = urequests.get(
            URL + "?api_key=" + API_KEY +
            "&field1=" + str(moisture)
        )

        print("ThingSpeak response:", response.text)
        response.close()

    except Exception as e:
        print("Error:", e)

    # ThingSpeak update interval
    time.sleep(20)
