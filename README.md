Automated Soil Moisture Monitoring System
Welcome to the Automated Soil Moisture Monitoring System project! This system uses an Arduino, a soil moisture sensor, and an LCD display to monitor the moisture level of the soil and automatically water your plants when necessary. It's an excellent project for anyone interested in gardening, home automation, or just getting started with Arduino programming.

Features
Real-time Soil Moisture Monitoring: Continuously checks the soil moisture level and displays it on an LCD.
Automatic Watering: Activates a relay to turn on a watering system when the soil moisture drops below a predefined threshold.
Interval Based Checking: Soil moisture level is checked and updated every 30 minutes to ensure timely watering.
Easy-to-Read Display: Uses an I2C LCD display to show moisture levels and other relevant information.
Prerequisites
Before you start, ensure you have the following components:

Arduino Uno (or compatible board)
Soil Moisture Sensor
LiquidCrystal_I2C LCD Display
Relay Module
Jumper Wires
USB Cable for programming
Arduino IDE installed on your computer
Hardware Setup
Sensor Connections:

Connect the Soil Moisture Sensor signal pin to Analog Pin A0 on the Arduino.
Connect power (VCC) and ground (GND) pins to the Arduino.
LCD Display Setup:

Connect the I2C LCD display using the SDA and SCL lines to the corresponding I2C pins on your Arduino.
Relay Module Integration:

Connect the relay signal pin to Digital Pin 2 on the Arduino.
Ensure the relay's power requirements are compatible with your Arduino's output.
Software Setup
Library Installation:

Open Arduino IDE and install the LiquidCrystal_I2C library through the Library Manager.
Programming the Arduino:

Clone this repository or copy the provided code into your Arduino IDE.
Adjust any pin assignments or settings as necessary based on your specific hardware setup.
Upload the sketch to your Arduino board.
Usage
Once the system is powered up and the program is running:

The LCD will display the current soil moisture level.
When the moisture level is below the set threshold, the relay will activate, and the system will begin watering the plant.
Moisture readings and the watering cycle can be monitored directly from the LCD.
Customizing
Threshold Adjustment: Modify the moisture threshold in the code to match the specific watering needs of your plant or garden.
Update Intervals: Change the interval timing for more frequent or less frequent readings based on your needs.
Contributing
Contributions to this project are welcome! Feel free to fork this repository and submit pull requests. You can also open issues for bugs or feature requests.

License
This project is released under the MIT License - see the LICENSE file for details.
