#include "RegimeStrob.h"

// sceme of work strobe in class RegimeStrob

// char regime[][7] = {
//   { '10', '1000', '1101', '1111', '0111', '0010', '0000' },
//   { '10', '1000', '1101', '1111', '1101', '1000', '0000' },
//   { '1', '1111', '0000', '1111', '0000', '1111', '0000' }
// };

// --------------------

const int buttonPin = 2;  // button pin IN - D2, open - 1, closed - 0

const int lamp_1 = 3;  // pin of lamp 1 - D3
const int lamp_2 = 4;  // pin of lamp 1 - D4
const int lamp_3 = 5;  // pin of lamp 1 - D5
const int lamp_4 = 6;  // pin of lamp 1 - D6

const int buttonLamp = 7;  // pin for button - D7

int regime = 0;  // variable for switching modes
bool buttonState = false;
unsigned long lastTimePressed;
int btnPressed = 600;      // time for off strobe
int btnTimerBounce = 130;  // time for anti bounce

bool btnFlag = false;

int cnt = 0;

bool workOn = false;

void pressButton() {
  if (millis() - lastTimePressed > btnTimerBounce) {
    lastTimePressed = millis();
    buttonState = true;
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
  attachInterrupt(0, pressButton, RISING);
}

void loop() {
  // Serial.print("button: ");
  // Serial.print(digitalRead(buttonPin));
  // Serial.print("    state: ");
  // Serial.println(buttonState);
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

  if (buttonState) {
    buttonState = false;
    regime++;
    if (regime > 5) regime = 1;
    if (millis() - lastTimePressed > btnPressed) regime = 0;
  }


  // bool btnState = digitalRead(buttonPin);

  // if (btnState && millis() - lastTimePressed > btnTimerBounce && !btnFlag) {
  //   lastTimePressed = millis();
  //   buttonState++;
  //   if (buttonState > 5) buttonState = 0;
  //   btnFlag = true;
  //   while (btnState) {
  //     btnState = digitalRead(buttonPin);
  //     if (millis() - lastTimePressed > btnPressed) {
  //       buttonState = 0;
  //       lastTimePressed = millis();
  //       break;
  //     }
  //   }
  // }
  // if (!btnState && btnFlag && millis() - lastTimePressed > btnTimerBounce) {
  //   btnFlag = false;
  //   lastTimePressed = millis();
  // }
}
