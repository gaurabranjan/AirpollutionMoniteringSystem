#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_CCS811.h>
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// WiFi credentials
char auth[] = "YOUR_AUTH_TOKEN";
char ssid[] = "YOUR_WIFI_SSID";
char pass[] = "YOUR_WIFI_PASSWORD";

// Create an instance of the CCS811 sensor
Adafruit_CCS811 ccs;

// Blynk virtual pin numbers
#define AQI_VIRTUAL_PIN V1
#define CO2_VIRTUAL_PIN V2

void setup()
{
  // Start the serial communication
  Serial.begin(9600);

  // Connect to the Wi-Fi network
  Blynk.begin(auth, ssid, pass);

  // Initialize the CCS811 sensor
  if (!ccs.begin())
  {
    Serial.println("Failed to start CCS811 sensor! Check your wiring.");
    while (1)
      ;
  }

  // Wait for the sensor to be ready
  while (!ccs.available())
    ;

  // Enable the CCS811 sensor
  ccs.setDriveMode(CCS811_DRIVE_MODE_1SEC);
}

void loop()
{
  Blynk.run();

  // Read the air quality data from the sensor
  if (ccs.available())
  {
    if (!ccs.readData())
    {
      // Read the equivalent CO2 level from the sensor
      float co2 = ccs.geteCO2();
      
      // Read the air quality index (AQI) from the sensor
      float aqi = ccs.getTVOC();

      // Send the data to Blynk app
      Blynk.virtualWrite(AQI_VIRTUAL_PIN, aqi);
      Blynk.virtualWrite(CO2_VIRTUAL_PIN, co2);

      // Print the data to the serial monitor
      Serial.print("eCO2: ");
      Serial.print(co2);
      Serial.print(" ppm\t");
      Serial.print("TVOC: ");
      Serial.print(aqi);
      Serial.println(" ppb");
    }
    else
    {
      Serial.println("Failed to read data from CCS811 sensor!");
    }
  }

  // Wait for 1 second before the next reading
  delay(1000);
}