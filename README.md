# ESP32Cam with I2C Sensor Example

Read detailed blog at [how-to-use-i2c-sensor-bme280-with-esp32cam](https://3iinc.xyz/blog/how-to-use-i2c-sensor-bme280-with-esp32cam/).

## I2C Bus

Define SDA and SCL Pins, Pin Number 14 and 15 are selected respectively.
```cpp
#define I2C_SDA 14
#define I2C_SCL 15
```

Create a Two Wire Instance.
```cpp
TwoWire I2CSensors = TwoWire(0);
```

In setup(), intialize the Two Wire Instance by passing in the SDA & SCL Pins and the clock frequency.
```cpp
I2CSensors.begin(I2C_SDA, I2C_SCL, 100000);
```

![Interfacing](https://github.com/abish7643/ESP32Cam-I2CSensors/blob/master/ESP32Cam%20-%20BME280.jpg "BME280 Connected to I2C Bus")

## Expected Error (With Adafruit Library)

An expected error while using Adafruit Libraries is that "sensor_t" will be conflicting with the ESP32Cam Board since it is declared both in Adafruit Library and ESP32Cam Board Library. This happens only when you include "esp_camera.h", that is if you use camera.

```bash
In file included from src/main.cpp:4:0:
lib/Adafruit_Unified_Sensor/Adafruit_Sensor.h:155:3: error: conflicting declaration 'typedef struct sensor_t sensor_t'
 } sensor_t;
   ^
In file included from /home/abish/.platformio/packages/framework-arduinoespressif32/tools/sdk/include/esp32-camera/esp_camera.h:70:0,
                 from src/main.cpp:2:
/home/abish/.platformio/packages/framework-arduinoespressif32/tools/sdk/include/esp32-camera/sensor.h:133:3: note: previous declaration as 'typedef struct _sensor sensor_t'
 } sensor_t;
   ^
*** [.pio/build/esp32cam/src/main.cpp.o] Error 1
```

![Error](https://github.com/abish7643/ESP32Cam-I2CSensors/blob/master/Error-AdafruitLibrary-ESP32Cam.png "Conflicting Declaration")

Inorder to fix this, rename all the "sensor_t" instances to another name, for example "sensor_t1". I used Sublime Text for renaming all this at once. Also I have attached the modified libraries. Rename yourself if you want to use the latest version of the library when it releases.