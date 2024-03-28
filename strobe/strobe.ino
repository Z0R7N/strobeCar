// sceme of work strobe in class RegimeStrob



char regime[][7] = {
  { '10', '1000', '1101', '1111', '0111', '0010', '0000' },
  { '10', '1000', '1101', '1111', '1101', '1000', '0000' },
  { '1', '1111', '0000', '1111', '0000', '1111', '0000' }
};

// --------------------

const int buttonPin = 2;  // button pin IN - D2, open - 1, closed - 0

const int lamp_1 = 3;  // pin of lamp 1 - D3
const int lamp_2 = 4;  // pin of lamp 1 - D4
const int lamp_3 = 5;  // pin of lamp 1 - D5
const int lamp_4 = 6;  // pin of lamp 1 - D6

const int buttonLamp = 7;  // pin for button - D7

int buttonState = 0;  // variable for switching modes
unsigned long lastTimePressed;
int btnPressed = 700;  // time for anti-bounce

int cnt = 0;

bool workOn

void pressButton() {
  if (millis() - lastTimePressed > btnPressed) {
    lastTimePressed = millis();
    buttonState++;
    if (buttonState > 5) buttonState = 0;
  }
}

void setup() {
  Serial.begin(115200);
  // initialize the lamp pins as an output:
  pinMode(lamp_1, OUTPUT);
  pinMode(lamp_2, OUTPUT);
  pinMode(lamp_3, OUTPUT);
  pinMode(lamp_4, OUTPUT);
  lastTimePressed = millis();
  attachInterrupt(0, pressButton, FALLING);
}

void loop() {
  Serial.print("button: ");
  Serial.print(digitalRead(buttonPin));
  Serial.print("    state: ");
  Serial.println(buttonState);
  cnt++;
  if (cnt > 100) {
    Serial.println();
    cnt = 0;
  }
}
