#include <Wire.h>
#include <LiquidCrystal_I2C.h>  // Including the LiquidCrystal_I2C library

LiquidCrystal_I2C lcd(0x27, 16, 2);  // Initializing the LCD screen with I2C address, 16 columns, and 2 rows

int Moisture_signal = A0;  // Define the Analog pin# on the Arduino for the soil moisture sensor signal
int relay = 6;
int Moisture;
unsigned long previousMillis = 0;  // Variable to store the last time moisture was checked
const long interval = 3600000;     // Interval to check moisture (in milliseconds) - 1 hour

void setup() {
  lcd.init();       // Initializing the LCD screen
  lcd.backlight();  // Turning on the LCD backlight

  lcd.setCursor(0, 0);  // Setting the cursor position to column 0, row 0
  lcd.print("SurinLearningLab.com"); // Changed the text
  lcd.setCursor(0, 1);  // Setting the cursor position to column 0, row 1
  lcd.print(":)");  // Displaying the symbol ":)"

  delay(5000);  // Waiting for 2 seconds

  lcd.clear();  // Clearing the LCD screen

  pinMode(relay, OUTPUT); // Added pinMode for relay
}

void loop() {
  unsigned long currentMillis = millis();  // Get the current time

  if (currentMillis - previousMillis >= interval) {
    // It's time to check the moisture
    previousMillis = currentMillis;  // Save the last time moisture was checked

    Moisture = analogRead(Moisture_signal);
    Serial.print("Soil Moisture Level: ");
    Serial.println(Moisture);

    lcd.setCursor(0, 0);         // Setting the cursor position to column 0, row 0
    lcd.print("Moisture :");        // Displaying the text "Moisture :"
    lcd.print(Moisture);            // Displaying the read value
    lcd.print("    ");           // Displaying empty spaces to clear previous characters

    if (Moisture < 1000 && Moisture > 500) {
      digitalWrite(relay, HIGH);
      delay(120000);  // Delay for 2 minute
      digitalWrite(relay, LOW);
    }
  }
}
