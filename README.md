Define SDA and SCL Pins, Pin Number 14 and 15 are selected respectively.

## I2C Bus

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

## Expected Error (With Adafruit Library)

An expected error while using Adafruit Libraries is that "sensor_t" variable will be conflicting with the ESP32Cam Board since it is used in both Adafruit Library and ESP32Cam Board Library.

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

This happens when you include "esp_camera.h". Inorder to fix this, rename all the "sensor_t" instances to another name, for example "sensor_t1". I used Sublime Text for renaming all this at once. Also I have attached the modified libraries. Rename yourself if you want to use the latest version of the library when it releases.