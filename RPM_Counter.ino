#include <Wire.h>
#include <LiquidCrystal_I2C.h>

volatile int rotationCount = 0;
unsigned long startTime = 0;
bool rpmPrinted = false;
unsigned long lastPulseTime = 0;

LiquidCrystal_I2C lcd(0x27, 16, 2);  

void setup() {
  Serial.begin(9600);
  pinMode(2, INPUT);
  attachInterrupt(digitalPinToInterrupt(2), countRotation, FALLING);

  lcd.init();        // Initialize LCD
  lcd.backlight();   // Turn on backlight

  // Display greeting message
  lcd.setCursor(0, 0);
  lcd.print("Welcome to");
  lcd.setCursor(0, 1);
  lcd.print("RPM Counter!");
  delay(3000);

  // Start counting display
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Counting...");

  startTime = millis();
}

void loop() {
  static unsigned long lastPrint = 0;

  if (millis() - lastPrint >= 1000 && !rpmPrinted) {
    lastPrint = millis();

    // Print to Serial
    Serial.print("Rotations: ");
    Serial.println(rotationCount);

    // Print to LCD
    lcd.setCursor(0, 1);
    lcd.print("Rot: ");
    lcd.print(rotationCount);
    lcd.print("     ");  // Clear extra digits
  }

  if (!rpmPrinted && millis() - startTime >= 60000) {
    noInterrupts();
    int totalRotations = rotationCount;
    interrupts();

    int rpm = totalRotations;  // 1 minute elapsed
    rpmPrinted = true;

    Serial.print("Final RPM: ");
    Serial.println(rpm);

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Final RPM:");
    lcd.setCursor(0, 1);
    lcd.print(rpm);
  }
}

void countRotation() {
  unsigned long now = micros();
  if (now - lastPulseTime > 100000) {  // Debounce: 100ms = 1 rotation max
    rotationCount++;
    lastPulseTime = now;
  }
}