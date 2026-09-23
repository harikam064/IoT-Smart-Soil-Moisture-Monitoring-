Smart Soil Moisture Monitoring

1. Project Title
Smart Soil Moisture Monitoring — An IoT-based Soil Moisture Monitoring System

2. Problem Statement
Manual monitoring of soil moisture in agriculture/gardening is time-consuming and often inaccurate, leading to overwatering or underwatering of plants. This project addresses the need for a real-time, remote way to track soil moisture conditions.

3. Objectives
To measure soil moisture levels in real time using a soil moisture sensor.
To send the collected sensor data to the ThingSpeak cloud platform via Wi-Fi.
To visualize the moisture data through a graph for easy monitoring.
To detect dry soil conditions using a 30% moisture threshold.
To turn ON the LED when soil moisture falls below 30%, indicating that watering is required.
To continuously monitor and update the soil moisture readings at regular intervals.

4. Components and Software Used
Hardware:
ESP32 Development Board
Soil Moisture Sensor
LED – for indicating dry soil conditions
Resistor – connected in series with the LED
Jumper Wires – for connecting the sensor and LED to the ESP32
Note: No breadboard or separate power source is used in the Wokwi circuit; the components are connected directly to the ESP32 in the simulation.

Software:
Wokwi Simulator
Arduino IDE / Wokwi Code Editor
ThingSpeak Cloud Platform
MicroPython  programming language used for the ESP32
ThingSpeak Cloud Platform  for receiving and visualizing soil moisture data
GitHub for storing and submitting the project files

5. Circuit Diagram
The circuit consists of an ESP32 development board, soil moisture sensor, LED, resistor, and connecting wires. The analog output (AO) of the soil moisture sensor is connected to GPIO 34 of the ESP32. The sensor is connected to VCC and GND for power. The LED is connected to GPIO 2 through a resistor and is used as an indicator for dry soil conditions. When the soil moisture level falls below 30%, the LED turns ON.

Connections:
Soil Moisture Sensor AO (Analog Output) → ESP32 GPIO 34
Soil Moisture Sensor VCC → ESP32 VCC
Soil Moisture Sensor GND → ESP32 GND
LED → ESP32 GPIO 2
Resistor → Connected in series with the LED

6. Working Principle
The soil moisture sensor detects the moisture level and provides an analog reading to the ESP32 through GPIO 34. The ESP32 reads this analog value using its ADC and converts it into a soil moisture percentage between 0% and 100%.

The ESP32 then checks the moisture level against the 30% threshold:
Below 30% → LED ON → Soil is dry
30% or above → LED OFF → Soil moisture is normal

The ESP32 connects to Wi-Fi and sends the calculated moisture percentage to ThingSpeak Field 1 at regular 20-second intervals. ThingSpeak stores the readings and displays them as a graph, allowing the moisture level to be monitored over time.

7. Applications
Smart Agriculture and Precision Irrigation – Helps monitor soil moisture and identify when watering may be required.
Home Gardening – Can be used to monitor moisture levels of plants and avoid unnecessary watering.
Greenhouse Monitoring – Provides continuous soil moisture information for plants grown in controlled environments.
Plant Monitoring and IoT Education – Can be used as a simple demonstration of sensor-based IoT monitoring and cloud data visualization.

8. Limitations
The system depends on stable Wi-Fi connectivity for transmitting data to ThingSpeak.
Sensor accuracy can be affected by soil type, moisture distribution, and calibration.
The 30% moisture threshold is fixed and may not be suitable for every type of plant or soil.
The current implementation provides an LED indication only; it does not automatically operate a water pump.
The current project monitors one soil moisture sensor/one zone.

9. Future Scope
Automatic Irrigation: Integrate a relay and water pump to automatically water the plant when moisture falls below the threshold.
Mobile Notifications: Add mobile or notification alerts when the soil becomes critically dry.
Multiple Sensors: Support multiple soil moisture sensors for monitoring different plants or zones.
Adaptive Thresholds: Allow the moisture threshold to be adjusted according to the plant and soil type.
Advanced Data Analysis: Analyze historical ThingSpeak data to identify moisture patterns and improve irrigation decisions.

10. Wokwi Project Link
(https://wokwi.com/projects/475854001710081025)

11. ThingSpeak Channel Link
https://thingspeak.mathworks.com/channels/3499012/sharing
