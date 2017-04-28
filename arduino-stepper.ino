#define MOTOR_STEPS 200 
int speed = 3000;

int STEPS = 11;
int DIRECTION = 9;

void setup() {
  Serial.begin(57600);
  pinMode(STEPS, OUTPUT);
  pinMode(DIRECTION, OUTPUT);
  digitalWrite(DIRECTION, LOW);
}

void loop() {
  parseSerialInput();
  turn();
}

void turn() {
  for (int i = 0; i < MOTOR_STEPS; i++) {
    digitalWrite(STEPS, HIGH);
    digitalWrite(STEPS, LOW);
    delayMicroseconds(speed);
  }
}

void parseSerialInput() {
  if (Serial.available() > 0) {
    String str = Serial.readString();
    int separatorIndex = str.indexOf(':');
    if (separatorIndex <= 0)
      return;

    String command = str.substring(0, separatorIndex);
    int value = str.substring(separatorIndex + 1).toInt();

    switch (command[0]) {
      case 's':
        speed = value;
        break;
      case 'd':
        digitalWrite(DIRECTION, value);
        break;
      default:
        break;
    }
  }
}
