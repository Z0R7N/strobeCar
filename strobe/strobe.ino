#include "RegimeStrob.h"

// sceme of work strobe in class RegimeStrob

char strobRegime[][7] = {
  { '10', '10001', '11011', '11111', '01110', '00100', '00000' },
  { '10', '10001', '11011', '11111', '11011', '10001', '00000' },
  { '1', '11111', '00000', '11111', '00000', '11111', '00000' }
};

// --------------------

const int buttonPin = 2;   // button pin IN - D2, open - 1, closed - 0
const int buttonLamp = 7;  // pin for button - D7

const int lamp_1 = 3;  // pin of lamp 1 - D3
const int lamp_2 = 4;  // pin of lamp 1 - D4
const int lamp_3 = 5;  // pin of lamp 1 - D5
const int lamp_4 = 6;  // pin of lamp 1 - D6

int regime = 0;  // variable for switching modes

bool buttonState = false;
bool btnFlag = false;

unsigned long lastTimePressed;
// unsigned long lastTimeRelised;
int btnPressedTime = 600;  // time for off strobe
int btnTimerBounce = 180;  // time for anti bounce

bool workOn = false;

void pressButton() {
  if (millis() - lastTimePressed > btnTimerBounce) {
    lastTimePressed = millis();
    buttonState = digitalRead(buttonPin);
    // Serial.println(buttonState);
  }
}

void setup() {
  Serial.begin(115200);
  // initialize the lamp pins as an output:
  pinMode(lamp_1, OUTPUT);
  pinMode(lamp_2, OUTPUT);
  pinMode(lamp_3, OUTPUT);
  pinMode(lamp_4, OUTPUT);
  pinMode(buttonLamp, OUTPUT);
  lastTimePressed = millis();
  // attachInterrupt(digitalPinToInterrupt(buttonPin), pressButton, CHANGE);
}

void loop() {

  switch (regime) {
    case 0:
      digitalWrite(lamp_1, 0);
      digitalWrite(lamp_2, 0);
      digitalWrite(lamp_3, 0);
      digitalWrite(lamp_4, 0);
      digitalWrite(buttonLamp, 0);
      break;
    case 1:
      digitalWrite(buttonLamp, 1);
      break;
    case 2:
      digitalWrite(lamp_1, 1);
      break;
    case 3:
      digitalWrite(lamp_2, 1);
      break;
    case 4:
      digitalWrite(lamp_3, 1);
      break;
    case 5:
      digitalWrite(lamp_4, 1);
      break;
  }


  //-------------------------------------------------------
  buttonState = digitalRead(buttonPin);

  unsigned long timeWhichButtonPressed = millis() - lastTimePressed;

  if (buttonState && timeWhichButtonPressed > btnPressedTime && btnFlag) {// && timeWhichButtonPressed < btnPressedTime + 10) {
    regime = 0;
    workOn = false;
    // Serial.print("work off, regime = ");
    // Serial.println(regime);
    // Serial.print("button state = ");
    // Serial.println(buttonState);
    // btnFlag = false;
    // delay(300);
  }

  if (buttonState && !btnFlag && timeWhichButtonPressed > btnTimerBounce) {
    lastTimePressed = millis();
    btnFlag = true;
    regime++;
    if (regime > 5) regime = 0;
    // Serial.print("change regime to ");
    // Serial.println(regime);
  }

  if (!buttonState && btnFlag && timeWhichButtonPressed > btnTimerBounce) {
    btnFlag = false;
    // Serial.println("btn flag = false");
  }
}
