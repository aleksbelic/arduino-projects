/*
PUSH BUTTONS
============
	Button A turns LED on and button B turns it off. 

Components:
	- Arduino Uno R3 (1)
	- breadboard (1)
	- 220 Ω Resistor (1)
	- M-M jumper wires (7)
	- LED (1)
	- push button (2)

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
