// Simon Memory Game - Continue pattern each round
// Arduino Nano + 4 LEDs + 4 Buttons (with internal pull-ups)

#define NUM_LEDS 4
int ledPins[NUM_LEDS] = {2, 3, 4, 5};
int buttonPins[NUM_LEDS] = {6, 7, 8, 9};

int sequence[100];    // store pattern
int level = 1;        // current level
bool gameOverFlag = false;

void setup() {
  Serial.begin(9600);

  for (int i = 0; i < NUM_LEDS; i++) {
    pinMode(ledPins[i], OUTPUT);
    pinMode(buttonPins[i], INPUT_PULLUP); // using internal pull-up
  }

  randomSeed(analogRead(A0)); // seed random number
  Serial.println("Simon Memory Game Started!");
  delay(1000);
}

void loop() {
  if (level == 1) {  // new game start
    for (int i = 0; i < 100; i++) sequence[i] = random(NUM_LEDS);
  }

  // Show sequence up to current level
  showSequence(level);

  // Wait for user input
  for (int i = 0; i < level; i++) {
    int pressed = waitForButtonPress();
    if (pressed != sequence[i]) {
      gameOver();
      return; // restart
    }
  }

  // Level complete!
  level++;
  if (level > 50) level = 1; // safety cap
  delay(800);
}

void showSequence(int upto) {
  Serial.print("Level: ");
  Serial.println(upto);
  delay(500);
  for (int i = 0; i < upto; i++) {
    int led = sequence[i];
    digitalWrite(ledPins[led], HIGH);
    delay(400);
    digitalWrite(ledPins[led], LOW);
    delay(250);
  }
}

int waitForButtonPress() {
  while (true) {
    for (int i = 0; i < NUM_LEDS; i++) {
      if (digitalRead(buttonPins[i]) == LOW) {  // LOW = pressed
        digitalWrite(ledPins[i], HIGH);
        delay(300);
        digitalWrite(ledPins[i], LOW);
        while (digitalRead(buttonPins[i]) == LOW); // wait for release
        return i;
      }
    }
  }
}

void gameOver() {
  Serial.println("Game Over!");
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < NUM_LEDS; j++) digitalWrite(ledPins[j], HIGH);
    delay(200);
    for (int j = 0; j < NUM_LEDS; j++) digitalWrite(ledPins[j], LOW);
    delay(200);
  }
  level = 1; // restart game
}
