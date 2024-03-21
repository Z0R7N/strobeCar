
const int buttonPin = 2;  // button pin IN - D2

const int lamp_1 = 3;  // pin of lamp 1 - D3
const int lamp_2 = 4;  // pin of lamp 1 - D4
const int lamp_3 = 5;  // pin of lamp 1 - D5
const int lamp_4 = 6;  // pin of lamp 1 - D6

int buttonState = 0;  // variable for switching modes

void pressButton() {
}

void setup() {
  Serial.begin(115200);
  // initialize the lamp pins as an output:
  pinMode(lamp_1, OUTPUT);
  pinMode(lamp_2, OUTPUT);
  pinMode(lamp_3, OUTPUT);
  pinMode(lamp_4, OUTPUT);
  pinMode(buttonPin, INPUT);
  attachInterrupt(0, pressButton, CHANGE);
}

void loop() {
}
