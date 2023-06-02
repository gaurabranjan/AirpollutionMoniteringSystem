# AirpollutionMoniteringSystem

To implement an air pollution monitoring system using NodeMCU and Blynk server, you'll need to follow these steps:

1.Install the necessary libraries:
	•	Install the Blynk library by going to Sketch -> Include Library -> Manage Libraries in the Arduino IDE and searching for "Blynk" to install it.
	•	Install the Adafruit CCS811 library by going to Sketch -> Include Library -> Manage Libraries in the Arduino IDE and searching for "Adafruit CCS811" to install it.

2.Set up Blynk:
	•	Create a new Blynk project on the Blynk app (available for iOS and Android) and obtain an authentication token.
	•	Add two widgets to the Blynk app: a Value Display widget for displaying the air quality index (AQI) and a Gauge widget for displaying the equivalent CO2 level.

3.Connect the hardware:
	•	Connect the CCS811 sensor to the NodeMCU board. The connections should be as follows:
		o	CCS811 VIN pin to NodeMCU 3.3V pin
		o	CCS811 GND pin to NodeMCU GND pin
		o	CCS811 SDA pin to NodeMCU D2 pin
		o	CCS811 SCL pin to NodeMCU D1 pin

4.Use the following code as an example to implement the air pollution monitoring system using NodeMCU and Blynk server:
