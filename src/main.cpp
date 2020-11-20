#include "Arduino.h"
// #include "esp_camera.h"
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>

// -----------------I2C-----------------
#define I2C_SDA 14 // SDA Connected to GPIO 14
#define I2C_SCL 15 // SCL Connected to GPIO 15
TwoWire I2CSensors = TwoWire(0);

// BME 280 (Using I2C)
Adafruit_BME280 bme;

// Sensor Variable (BME280)
float temperature, humidity;

void setup()
{
  Serial.begin(115200);

  I2CSensors.begin(I2C_SDA, I2C_SCL, 100000);

  // BME 280 (0x77 or 0x76 will be the address)
  if (!bme.begin(0x76, &I2CSensors))
  {
    Serial.println("Couldn't Find BME280 Sensor");
    while (1)
      ;
  }
  else
  {
    Serial.println("BME280 Sensor Found");
  }
}

void loop()
{
  // -------------Temperature (C)------------------

  temperature = bme.readTemperature();
  Serial.print("Temperature = ");
  Serial.print(temperature);
  Serial.print(" *C - ");

  // ----------------------------------------------

  // ---------------Humidity (%)-------------------

  humidity = bme.readHumidity();
  Serial.print("Humidity = ");
  Serial.print(humidity);
  Serial.println(" %");

  // ----------------------------------------------

  delay(1000);
}