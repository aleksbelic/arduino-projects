/*
  Button status
  ============
  Prints the status of a button every second.

  Components:
    - Arduino Uno R3 (1)
    - push button (1)
    - breadboard (1)
    - M-M jumper wires (2)

  Wiring:
    D8  -> One side of the push button
    GND -> Opposite side of the push button
*/

const unsigned long READ_INTERVAL_MS = 1000;  // Pause between readings
const int BUTTON_PIN = 8;

void setup() {
  // Using INPUT_PULLUP so an external resistor is not needed
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  if (digitalRead(BUTTON_PIN) == LOW) {
    Serial.println("Button pressed");
  } else {
    Serial.println("Button NOT pressed");
  }

  delay(READ_INTERVAL_MS);
}