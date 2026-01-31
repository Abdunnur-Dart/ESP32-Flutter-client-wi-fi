# ESP32-Flutter-client-wi-fi
A universal cross-platform system to control ESP32-C3 and other microcontrollers via Flutter mobile app, featuring real-time HTTP communication, PWM dimming, and sensor monitoring.

# 🚀 SmartNode Flutter Commander

Welcome to **SmartNode Commander**! This is a powerful, open-source ecosystem designed to bridge the gap between mobile devices and microcontrollers like the ESP32-C3. 

Whether you are building a smart home system or a remote-controlled robot, this project provides a solid foundation for Wi-Fi-based hardware control.

---

## 🛠 Features

- **📱 Unified Mobile App:** Control your hardware from Android or iOS using a beautiful Flutter UI.
- **⚡ Low-Latency Communication:** Uses optimized HTTP REST API for instant responses.
- **🎛 Multi-Functional Control:**
  - Digital Toggle (ON/OFF)
  - PWM/Analog Control (Brightness/Speed sliders)
  - Real-time Sensor Feedback (Voltage, Light, Temperature)
- **🐍 Python Integration:** Includes a CLI script for automated testing and PC-to-board control.
- **🌍 Platform Agnostic:** Compatible with ESP32, ESP32-C3, ESP8266, and Arduino (with Wi-Fi).

---

## 📂 Project Structure

- `/firmware` — C++ code for Arduino IDE / PlatformIO.
- `/app` — Flutter project for mobile devices.
- `/scripts` — Python automation and testing tools.

---

## 🚀 Getting Started

### 1. Flash the Board
1. Open `/firmware/main_esp32.ino` in Arduino IDE.
2. Enter your Wi-Fi SSID and Password.
3. Upload to your **ESP32-C3 Super Mini**.
4. Open Serial Monitor (115200) to get the board's **IP Address**.

### 2. Launch the App
1. Navigate to `/app`.
2. Run `flutter run` on your connected device.
3. Enter the IP Address from the previous step.

### 3. Python CLI (Optional)
1. Run `pip install requests`.
2. Run `python scripts/control_esp.py` to control your board from the terminal.

---

## 👨‍💻 Author
Developed by an aspiring 11-year-old developer passionate about IoT and Cross-platform apps. 

**Give this project a ⭐ if you find it useful!**
