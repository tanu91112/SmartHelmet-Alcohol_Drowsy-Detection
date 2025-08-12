#include <Wire.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>

Adafruit_MPU6050 mpu;

#define ALCOHOL_SENSOR A0
#define RED_LED 3
#define YELLOW_LED 4
#define BUZZER 5

// Thresholds
const int alcoholThreshold = 400; // Adjust based on sensor calibration
const float drowsinessTiltThreshold = 30.0; // Tilt in degrees
const unsigned long drowsinessTimeThreshold = 3000; // 3 seconds

unsigned long tiltStartTime = 0;
bool isTilted = false;

void setup() {
  pinMode(ALCOHOL_SENSOR, INPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
  pinMode(BUZZER, OUTPUT);

  Serial.begin(115200);

  if (!mpu.begin()) {
    Serial.println("Could not find a valid MPU6050 sensor, check wiring!");
    while (1);
  }
  
  mpu.setAccelerometerRange(MPU6050_RANGE_4_G);
  mpu.setGyroRange(MPU6050_RANGE_500_DEG);
  mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);

  Serial.println("Smart Helmet System Initialized");
}

void loop() {
  // Alcohol detection
  int alcoholValue = analogRead(ALCOHOL_SENSOR);
  Serial.print("Alcohol Level: ");
  Serial.print(alcoholValue);
  
  if (alcoholValue > alcoholThreshold) {
    Serial.println(" - Alcohol Detected!");
    digitalWrite(RED_LED, HIGH);
    digitalWrite(BUZZER, HIGH); // Turn on buzzer
  } else {
    Serial.println(" - No Alcohol Detected");
    digitalWrite(RED_LED, LOW);
    digitalWrite(BUZZER, LOW); // Turn off buzzer
  }

  // Drowsiness detection
  sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp);

  // Accelerometer data
  Serial.print("Acceleration - X: ");
  Serial.print(a.acceleration.x);
  Serial.print(" m/s^2, Y: ");
  Serial.print(a.acceleration.y);
  Serial.print(" m/s^2, Z: ");
  Serial.print(a.acceleration.z);
  Serial.println(" m/s^2");

  // Gyroscope data
  Serial.print("Gyroscope - X: ");
  Serial.print(g.gyro.x);
  Serial.print(" rad/s, Y: ");
  Serial.print(g.gyro.y);
  Serial.print(" rad/s, Z: ");
  Serial.print(g.gyro.z);
  Serial.println(" rad/s");

  // Temperature data
  Serial.print("Temperature: ");
  Serial.print(temp.temperature);
  Serial.println(" °C");

  // Calculate tilt angle for drowsiness detection
  float tiltAngle = atan2(a.acceleration.y, a.acceleration.z) * 180 / PI;
  tiltAngle = abs(tiltAngle); // Consider absolute tilt
  Serial.print("Tilt Angle: ");
  Serial.println(tiltAngle);

  if (tiltAngle > drowsinessTiltThreshold) {
    if (!isTilted) {
      tiltStartTime = millis();
      isTilted = true;
    } else if (millis() - tiltStartTime > drowsinessTimeThreshold) {
      Serial.println("Drowsiness Detected!");
      digitalWrite(YELLOW_LED, HIGH);
      digitalWrite(BUZZER, HIGH); // Turn on buzzer
    }
  } else {
    isTilted = false;
    digitalWrite(YELLOW_LED, LOW);
    digitalWrite(BUZZER, LOW); // Turn off buzzer
  }

  // Delay for readability in Serial Monitor
  delay(500);
}
