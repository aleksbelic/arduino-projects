/*
  Push buttons
  ============
  Button A turns the LED on, button B turns it off.

  Components:
    - Arduino Uno R3 (1)
    - LED (1)
    - 220 ohm resistor (1)
    - push button (2)
    - breadboard (1)
    - M-M jumper wires (7)

  Wiring:
    D5  -> 220 ohm -> LED anode (long leg), LED cathode -> GND
    D8  -> button A -> GND
    D9  -> button B -> GND
  The buttons need no resistors: INPUT_PULLUP uses the Arduino's internal
  pull-ups, so a pin reads HIGH when released and LOW when pressed.
*/

// define pins
#define LED_PIN 5
#define BUTTON_A 8
#define BUTTON_B 9

void setup() {
    pinMode(LED_PIN, OUTPUT);
    pinMode(BUTTON_A, INPUT_PULLUP);  
    pinMode(BUTTON_B, INPUT_PULLUP);  
}

void loop() {
	// button A is pressed
    if (digitalRead(BUTTON_A) == LOW) {
		digitalWrite(LED_PIN, HIGH);
    }
	// button B is pressed
	if (digitalRead(BUTTON_B) == LOW) {
		digitalWrite(LED_PIN, LOW);
	}
}
