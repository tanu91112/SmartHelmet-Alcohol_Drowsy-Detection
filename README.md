# 🛡️ Smart Helmet – Alcohol & Drowsiness Detection System

[![Arduino](https://img.shields.io/badge/Platform-Arduino-blue?logo=arduino)]()
[![License](https://img.shields.io/badge/License-MIT-green)]()
[![Sensors](https://img.shields.io/badge/Sensors-MQ__Alcohol%20%7C%20MPU6050-orange)]()

## 📌 Overview
The **Smart Helmet Safety System** is designed to improve rider safety by detecting **alcohol consumption** and **drowsiness** in real time.  
It uses an **MQ-series alcohol sensor** and an **MPU6050 accelerometer + gyroscope** to monitor the rider’s condition.  
If unsafe riding behavior is detected, the system triggers both **visual** and **audible** alerts, helping prevent accidents.

---

## ✨ Features
- **🍺 Alcohol Detection:** Monitors breath alcohol levels; triggers **Red LED** & buzzer if unsafe.
- **😴 Drowsiness Detection:** Tracks helmet tilt angle using MPU6050; prolonged unsafe tilt triggers **Yellow LED** & buzzer.
- **📟 Real-time Monitoring:** Alcohol, tilt, accelerometer, gyroscope, and temperature data via Serial Monitor.
- **⚠️ Dual Alerts:** Visual (LED indicators) and audible (buzzer) for quick rider awareness.

---

## 🛠 Hardware Components
- Arduino Uno / Nano or compatible board  
- MQ-series Alcohol/Gas Sensor  
- MPU6050 Accelerometer + Gyroscope  
- Red & Yellow LEDs + 220Ω resistors  
- Buzzer  
- Jumper wires, breadboard or helmet mounting setup  

---


## 📊 Wiring Diagram

![Wiring Diagram](https://github.com/user-attachments/assets/720255e3-f65e-4eed-8284-20b53ca54f22)

**Connections:**
- **MQ Sensor OUT → A0**  
- **MPU6050 SDA → A4**, SCL → A5  
- **Red LED → D3**, **Yellow LED → D4**  
- **Buzzer → D5**  
- Common GND for all components  


---

## ⚙️ How It Works
1. **Alcohol Monitoring:** Continuously measures breath alcohol concentration. Above threshold → Red LED + buzzer alert.
2. **Tilt/Drowsiness Monitoring:** Calculates helmet tilt angle. If tilt exceeds safe range for >3s → Yellow LED + buzzer alert.
3. **Alerts:** Rider receives immediate visual & audible warnings.

---

## 🚀 Applications
- Motorcycle rider safety enhancement  
- Long-distance travel fatigue prevention  
- Accident prevention systems  

---


## 📷 Demo

![Project Demo](https://github.com/user-attachments/assets/3fb94381-c669-4aef-94a0-de3f0bfe84f8)
