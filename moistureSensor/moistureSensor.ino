#include <Wire.h>
#include <LiquidCrystal_I2C.h>  // Including the LiquidCrystal_I2C library

LiquidCrystal_I2C lcd(0x27, 16, 2);  // Initializing the LCD screen with I2C address, 16 columns, and 2 rows

int Moisture_signal = A0;  // Define the Analog pin# on the Arduino for the soil moisture sensor signal
int relay = 2;
float Moisture;
unsigned long previousMoistureCheckMillis = 0;  // Variable to store the last time moisture was checked
const long interval = 1800000;     // Interval to check moisture (in milliseconds) - 1 hour

void setup() {
  lcd.init();       // Initializing the LCD screen
  lcd.backlight();  // Turning on the LCD backlight

  lcd.setCursor(0, 0);  // Setting the cursor position to column 0, row 0
  lcd.print("SurinLearningLab.com"); // Changed the text
  lcd.setCursor(0, 1);  // Setting the cursor position to column 0, row 1
  lcd.print(":)");  // Displaying the symbol ":)"

  delay(5000);  // Waiting for 5 seconds

  lcd.clear();  // Clearing the LCD screen

  pinMode(relay, OUTPUT); // Added pinMode for relay
}

void loop() {
  unsigned long currentMillis = millis();  // Get the current time

  // Calculate time remaining until next moisture check
  unsigned long timeSinceLastMoistureCheck = currentMillis - previousMoistureCheckMillis;
  long timeRemaining = interval - timeSinceLastMoistureCheck;

  // If countdown timer reaches 0 or it's time to check moisture
  if (timeRemaining <= 0) {
    previousMoistureCheckMillis = currentMillis;  // Save the current time as last moisture check time
    Moisture = analogRead(Moisture_signal);
    Serial.print("Soil Moisture Level: ");
    Serial.println(Moisture);

    lcd.clear();  // Clear the LCD screen

    lcd.setCursor(0, 0);         // Setting the cursor position to column 0, row 0
    lcd.print("Moisture % ");        // Displaying the text "Moisture :"
    lcd.print(Moisture / 10);            // Displaying the read value
    lcd.setCursor(0, 1);         // Setting the cursor position to column 0, row 1
    lcd.print("EVACUATE: ");        // Displaying the text "Time left: "
    lcd.print("   "); // Clear previous countdown display
    lcd.setCursor(11, 1); // Move cursor to display time left
    lcd.print("0min"); // Default display 0s

    if (Moisture < 1000 && Moisture > 410) {
      digitalWrite(relay, HIGH);
      delay(300000);  // Delay for 2 minutes
      digitalWrite(relay, LOW);
    }
  } else {
    // Display the countdown timer
    lcd.setCursor(11, 1); // Move cursor to display time left
    // lcd.print("Time: ");
    lcd.print(timeRemaining / 1000 / 60); // Displaying remaining time in seconds
    lcd.print("min");               // Displaying the unit for seconds
  }
}



