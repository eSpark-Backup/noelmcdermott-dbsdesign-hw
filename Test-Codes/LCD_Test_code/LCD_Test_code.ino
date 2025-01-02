#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Set the I2C addresses of your 20x4 LCDs. Default addresses are usually 0x27 or 0x3F.
#define LCD1_I2C_ADDRESS 0x27
#define LCD2_I2C_ADDRESS 0x3F

// Initialize the LCDs, specifying their dimensions (20 columns x 4 rows).
LiquidCrystal_I2C lcd1(LCD1_I2C_ADDRESS, 20, 4);
LiquidCrystal_I2C lcd2(LCD2_I2C_ADDRESS, 20, 4);

void setup() {
  // Set up custom I2C pins for the ESP32
  Wire.begin(18, 17); // SDA on GPIO18, SCL on GPIO17

  // Initialize the LCDs
  lcd1.init();
  lcd1.backlight();

  lcd2.init();
  lcd2.backlight();

  // Print "abcdefghijk" on all four lines of both LCDs
  for (int i = 0; i < 4; i++) {
    lcd1.setCursor(0, i); // Set cursor to the beginning of the i-th line on LCD1
    lcd1.print("abcdefghijk"); // Print text on the current line of LCD1

    lcd2.setCursor(0, i); // Set cursor to the beginning of the i-th line on LCD2
    lcd2.print("abcdefghijk"); // Print text on the current line of LCD2
  }
}

void loop() {
  // Nothing to do here for this test
}
