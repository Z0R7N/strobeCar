
// mode operation schemes, first value in massive is time of changing lights (leading zeros are required)

String strobRegime[][7] = {
  { "00150", "11111", "00000", "11111", "00000", "11111", "00000" },
  { "00150", "11111", "11111", "11111", "11111", "11111", "11111" },
  { "00050", "11111", "00000", "11111", "00000", "11111", "00000" },
  { "00150", "10001", "11011", "11111", "01110", "00100", "00000" },
  { "00150", "10001", "11011", "11111", "11011", "10001", "00000" },
  { "00150", "10101", "01010", "10101", "01010", "10101", "01010" },
  { "00050", "10101", "01010", "10101", "01010", "10101", "01010" }
};

int countStrobRegime1 = sizeof(strobRegime) / sizeof(strobRegime[0]);
int countStrobRegime2 = 7;

// --------------------

const int buttonPin = 2;  // button pin IN - D2, open - 1, closed - 0
int stateBtnLamp;         // state for button lamp

const int lamp_1 = 3;  // pin of lamp 1 - D3
const int lamp_2 = 4;  // pin of lamp 1 - D4
const int lamp_3 = 5;  // pin of lamp 1 - D5
const int lamp_4 = 6;  // pin of lamp 1 - D6

int regime = -1;  // variable for switching modes
int countOfMassive = 1;

// time to change lights
unsigned long lastTimeChangeRegime;

bool buttonState = false;
bool btnFlag = false;

unsigned long lastTimePressed;
int btnPressedTime = 500;  // time for off strobe
int btnTimerBounce = 180;  // time for anti bounce

int time2LampButton = 300;  // delay for ligting button

bool workOn = false;

// switching lamps
void switchLamps(String swch) {
  for (int i = 0; i < 4; i++) {
    digitalWrite(i + 3, String(swch[i]).toInt());
  }
}


// lights on/off by regime
void workLights() {
  unsigned long changeRegime = millis() - lastTimeChangeRegime;
  int tm = strobRegime[regime][0].toInt();
  if (changeRegime > tm) {
    String s1 = strobRegime[regime][countOfMassive];
    switchLamps(s1);
    lastTimeChangeRegime = millis();
    countOfMassive++;
    if (countOfMassive > countStrobRegime2 - 1) {
      countOfMassive = 1;
    }
  }
}

void setup() {
  Serial.begin(115200);
  // initialize the lamp pins as an output:
  pinMode(lamp_1, OUTPUT);
  pinMode(lamp_2, OUTPUT);
  pinMode(lamp_3, OUTPUT);
  pinMode(lamp_4, OUTPUT);
  pinMode(buttonPin, INPUT);
  lastTimePressed = millis();
  digitalWrite(buttonPin, 0);
}

void loop() {
  if (workOn) {
    workLights();
  }

  unsigned long timeWhichButtonPressed = millis() - lastTimePressed;

  if (timeWhichButtonPressed > time2LampButton) {
    pinMode(buttonPin, INPUT);
    buttonState = !digitalRead(buttonPin);
    if (workOn) pinMode(buttonPin, OUTPUT);
  }


  if (buttonState && timeWhichButtonPressed > btnPressedTime && btnFlag) {
    pinMode(buttonPin, INPUT);
    workOn = false;
    stateBtnLamp = 1;
    switchLamps("00000");
  }

  if (buttonState && !btnFlag && timeWhichButtonPressed > btnTimerBounce) {
    pinMode(buttonPin, OUTPUT);
    lastTimePressed = millis();
    stateBtnLamp = 0;
    workOn = true;
    btnFlag = true;
    regime++;
    if (regime >= countStrobRegime1) regime = 0;
  }

  if (!buttonState && btnFlag && timeWhichButtonPressed > btnTimerBounce) {
    btnFlag = false;
  }
}
