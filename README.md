RFID Smart Attendance System
A compact, hardware-based attendance tracking system built using an Arduino Uno and MFRC522 RFID technology. This project was developed as part of my studies in Computer Engineering to practice hardware-software integration and real-time data processing.

🛠 Tech Stack & Hardware
Microcontroller: Arduino Uno

RFID Module: MFRC522 (SPI Interface)

Display: 16x2 LCD with I2C Module

Feedback: Piezo Buzzer & Dual LEDs (Red/Green)

Language: C++ (Arduino IDE)

📋 Features
Authentication: Validates unique RFID card UIDs against a stored authorized list.

Real-time Feedback: Uses an LCD to display "Welcome" or "Access Denied" messages upon scanning.

Audio-Visual Alerts: Integrated buzzer and LED indicators provide immediate feedback for successful or failed attempts.

🚀 How to Run
Wiring: Ensure the MFRC522 is connected via SPI (SDA: 10, SCK: 13, MOSI: 11, MISO: 12, RST: 9) and the I2C LCD is connected to the A4/A5 pins.

Library Installation: Install the following libraries via the Arduino Library Manager:

MFRC522 by GithubCommunity

LiquidCrystal_I2C by Frank de Brabander

Configuration:

Run the DumpInfo example to identify your tag's unique UID.

Update the authorizedUID array in the main sketch with your specific UID.

Upload: Compile and upload the sketch to your Arduino Uno.

📝 Troubleshooting
LCD blank? Adjust the blue potentiometer on the back of the I2C module to increase contrast.

Firmware error? Ensure all SPI wires are firmly connected; common ground is essential for all components.
