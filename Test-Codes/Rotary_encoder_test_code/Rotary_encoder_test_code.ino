// Pin definitions
const int outA = 2;  // OUTA connected to IO2
const int outB = 21; // OUTB connected to IO21

volatile int position = 0; // Variable to store the position
volatile int lastStateA;   // To track the previous state of OUTA

void IRAM_ATTR handleEncoder() {
  // Read the current state of OUTA
  int currentStateA = digitalRead(outA);
  
  // Check if the state of OUTA has changed
  if (currentStateA != lastStateA) {
    // Determine direction based on OUTB
    if (digitalRead(outB) != currentStateA) {
      position++; // Clockwise
    } else {
      position--; // Counter-clockwise
    }
  }
  
  // Update last state
  lastStateA = currentStateA;
}

void setup() {
  Serial.begin(115200); // Initialize serial communication
  pinMode(outA, INPUT); // Set OUTA pin as input
  pinMode(outB, INPUT); // Set OUTB pin as input

  // Attach an interrupt to handle OUTA pin changes
  attachInterrupt(digitalPinToInterrupt(outA), handleEncoder, CHANGE);

  // Initialize last state of OUTA
  lastStateA = digitalRead(outA);

  Serial.println("Rotary encoder test started.");
}

void loop() {
  // Print the position every 100ms
  static unsigned long lastPrintTime = 0;
  if (millis() - lastPrintTime > 100) {
    lastPrintTime = millis();
    Serial.print("Position: ");
    Serial.println(position);
  }
}
