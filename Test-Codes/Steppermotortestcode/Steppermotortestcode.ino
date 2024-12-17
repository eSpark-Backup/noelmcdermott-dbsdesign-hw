#include <Preferences.h>

// Pin definitions
const int STEP_PIN = 9;  // STEP connected to IO9
const int DIR_PIN = 10; // DIR connected to IO10
const int ENABLE_PIN = 11; // ENABLE connected to IO11
const int DRV_STEP = 36; // Feedback pin for STEP
const int DRV_DIR = 37;  // Feedback pin for DIR
const int DRV_ENABLE = 35; // Feedback pin for ENABLE

// Variables for timing
unsigned long previousMicros = 0;
unsigned long interval = 0;
int stepState = LOW; // Current state of the step pin

void setup() {
  Serial.begin(115200); // Initialize serial communication

  pinMode(STEP_PIN, OUTPUT); // Configure STEP_PIN as output
  pinMode(DIR_PIN, OUTPUT);  // Configure DIR_PIN as output
  pinMode(ENABLE_PIN, OUTPUT); // Configure ENABLE_PIN as output
  pinMode(DRV_STEP, INPUT);  // Configure DRV_STEP as input
  pinMode(DRV_DIR, INPUT);   // Configure DRV_DIR as input
  pinMode(DRV_ENABLE, INPUT); // Configure DRV_ENABLE as input

  digitalWrite(ENABLE_PIN, LOW); // Disable motor initially

  Serial.println("Stepper motor test started.");
}

void loop() {
  // Enable motor
  digitalWrite(ENABLE_PIN, HIGH);
  delay(100); // Small delay to ensure motor is enabled

  // Test stepper motor at 10 Hz for 5 seconds in one direction
  testStepper(10, 5000, HIGH);

  // Test stepper motor at 5 Hz for 8 seconds in the opposite direction
  testStepper(5, 8000, LOW);

  // Disable motor
  digitalWrite(ENABLE_PIN, LOW);
  delay(1000); // Delay to observe motor disabled state
}

void testStepper(int frequency, int duration, int direction) {
  interval = 1000000 / frequency; // Calculate interval in microseconds
  unsigned long startTime = millis();

  digitalWrite(DIR_PIN, direction); // Set the direction pin

  while (millis() - startTime < duration) {
    unsigned long currentMicros = micros();

    // Toggle STEP pin state at the given frequency
    if (currentMicros - previousMicros >= interval / 2) {
      previousMicros = currentMicros;
      stepState = !stepState;
      digitalWrite(STEP_PIN, stepState);
    }

    // Read and print feedback pins
    int drvStepState = digitalRead(DRV_STEP);
    int drvDirState = digitalRead(DRV_DIR);
    int drvEnableState = digitalRead(DRV_ENABLE);

    Serial.print("DRV_STEP: ");
    Serial.print(drvStepState);
    Serial.print(" | DRV_DIR: ");
    Serial.print(drvDirState);
    Serial.print(" | DRV_ENABLE: ");
    Serial.println(drvEnableState);
  }
}
