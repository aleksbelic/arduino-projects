// define pins
#define BLUE 3
#define GREEN 5
#define RED 6

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
	#define MAX_LIGHT 55 // from 0 to 255
	#define DELAY 50 // fading time between colors, ms

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
