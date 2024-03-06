#include <Adafruit_MPU6050.h>

Adafruit_MPU6050 mpu;
int medicion = 0;
int tiempo_espera = 0;

void setup() {
  Serial.begin(9600);
  mpu.begin();
  mpu.setAccelerometerRange(MPU6050_RANGE_2_G);
}

void loop() {
  if (tiempo_espera <= 3) {
    Serial.println(String(tiempo_espera));
    tiempo_espera++;
    delay(1000);
  } else {
    medicion++;

    sensors_event_t a, g, temp;
    mpu.getEvent(&a, &g, &temp);

    if (medicion == 1) {
      Serial.println("Medicion,Aceleracion_X,Aceleracion_Y,Aceleracion_Z");
    }

    // Serial.println(String(medicion) + "," + String(a.acceleration.x / 9.80665) + "," + String(a.acceleration.y / 9.80665) + "," + String(a.acceleration.z / 9.80665));

    Serial.println(String(medicion) + "," + String(a.acceleration.x) + "," + String(a.acceleration.y) + "," + String(a.acceleration.z));

    delay(100);
  }
}
