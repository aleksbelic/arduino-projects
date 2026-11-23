/*
  Staircase Time Switch
  =====================
  Turns on an LED for 5 seconds when a button is pressed.
  Every new press restarts the timer.

  Components:
    - Arduino Uno R3 (1)
    - Push button (1)
    - LED (1)
    - 220 ohm resistor (1)
    - Breadboard (1)
    - M-M jumper wires (4)

  Wiring:
    D2  -> One side of the push button
    GND -> Opposite side of the push button
    D9  -> 220 ohm resistor -> Anode of the LED (long leg)
    GND -> Cathode of the LED (short leg)
*/

const int button_pin = 2;
const int led_pin = 9;
const unsigned long interval = 5000;  // ms

unsigned long last_press_time = 0;
bool led_on = false;

void setup() {
  pinMode(button_pin, INPUT_PULLUP);
  pinMode(led_pin, OUTPUT);
}

void loop() {
  // Button pressed (LOW because of INPUT_PULLUP): turn on and restart the timer
  if (digitalRead(button_pin) == LOW) {
    last_press_time = millis();
    led_on = true;
    digitalWrite(led_pin, HIGH);
  }

  // Time is up: turn off
  if (led_on && millis() - last_press_time >= interval) {
    digitalWrite(led_pin, LOW);
    led_on = false;
  }
}