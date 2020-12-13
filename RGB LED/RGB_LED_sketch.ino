/*
RGB LED
=======
	RGB LED should loop through red, green and blue color. 

Components:
  - Arduino Uno R3 (1)
  - RGB LED, common cathode (1)
  - 220 Ω Resistor (3)
  - breadboard (1)
  - M-M jumper wires (4)
*/

// define pins
#define BLUE 3
#define GREEN 5
#define RED 6

#define MAX_LIGHT 55 // 0 - 255
#define DELAY 50 // fading time between colors, ms

// define variables
int redValue;
int greenValue;
int blueValue;

void setup() {
	pinMode(RED, OUTPUT);
	pinMode(GREEN, OUTPUT);
	pinMode(BLUE, OUTPUT);
	digitalWrite(RED, HIGH);
	digitalWrite(GREEN, LOW);
	digitalWrite(BLUE, LOW);
}

void loop() {

	redValue = MAX_LIGHT;
	greenValue = 0;
	blueValue = 0;

	// red -> green
	for (int i = 0; i < MAX_LIGHT; i++) {
    	redValue--;
    	greenValue++;
		analogWrite(RED, redValue);
		analogWrite(GREEN, greenValue);
		delay(DELAY);
	}

	// green -> blue
	for (int i = 0; i < MAX_LIGHT; i++) {
		greenValue--;
		blueValue++;
		analogWrite(GREEN, greenValue);
		analogWrite(BLUE, blueValue);
		delay(DELAY);
	}

	// blue -> red
	for (int i = 0; i < MAX_LIGHT; i++) {
		blueValue--;
		redValue++;
		analogWrite(BLUE, blueValue);
		analogWrite(RED, redValue);
		delay(DELAY);
	}
}
