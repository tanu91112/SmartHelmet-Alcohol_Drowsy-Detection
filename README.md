# 🛡️ Smart Helmet – Alcohol & Drowsiness Detection System
[![Arduino](https://img.shields.io/badge/Platform-Arduino-blue?logo=arduino)]()
[![License](https://img.shields.io/badge/License-MIT-green)]()
[![Sensors](https://img.shields.io/badge/Sensors-MQ__Alcohol%20%7C%20MPU6050-orange)]()

## 📌 Overview
The **Smart Helmet Safety System** is an IoT-based project aimed at enhancing two-wheeler rider safety.  
It integrates an **MQ-series alcohol sensor** and an **MPU6050 accelerometer + gyroscope** to detect alcohol consumption and early signs of rider drowsiness.  
By delivering **real-time alerts via LEDs and buzzer**, the system helps reduce accident risks caused by unsafe riding behavior.

---
## ✨ Key Features
- **🍺 Alcohol Detection:** Measures rider’s breath alcohol content; triggers **Red LED** & buzzer alert if above threshold.  
- **😴 Drowsiness Detection:** Utilizes helmet tilt monitoring through MPU6050; sustained unsafe tilt triggers **Yellow LED** & buzzer.  
- **📟 Real-Time Data:** Displays alcohol level, tilt angle, acceleration, gyroscope, and temperature data via Serial Monitor for debugging and analysis.  
- **⚠️ Multi-Mode Alerts:** Combination of **visual indicators** (LEDs) and **audible buzzer** ensures immediate rider awareness.  

---
## 🛠 Hardware Components
- **Microcontroller:** Arduino Uno / Nano (or compatible)  
- **Sensors:** MQ-series Alcohol/Gas Sensor, MPU6050 (Accelerometer + Gyroscope)  
- **Indicators:** Red & Yellow LEDs with resistors  
- **Alert System:** Buzzer  
- **Accessories:** Jumper wires, breadboard, and helmet integration setup  

---
## 📊 Wiring Diagram
![Wiring Diagram](https://github.com/user-attachments/assets/720255e3-f65e-4eed-8284-20b53ca54f22)

**Connections:**  
- MQ Sensor → **A0**  
- MPU6050 → **SDA → A4**, **SCL → A5**  
- Red LED → **D3**  
- Yellow LED → **D4**  
- Buzzer → **D5**  
- Shared **GND** for all components  

---
## ⚙️ System Workflow
1. **Alcohol Detection:** Continuously reads MQ sensor values → Above threshold triggers safety alerts.  
2. **Drowsiness Monitoring:** Evaluates tilt angles using MPU6050 → Unsafe tilt >3 seconds activates alerts.  
3. **Alert Mechanism:** LEDs + buzzer provide **instant, dual-mode safety feedback** to the rider.  

---
## 🚀 Applications
- Rider safety enhancement in motorcycles and scooters  
- Fatigue detection during long-distance rides  
- Integration for **advanced accident prevention systems**  

---
## 📷 Demo
![Project Demo](https://github.com/user-attachments/assets/3fb94381-c669-4aef-94a0-de3f0bfe84f8)
