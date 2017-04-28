#define MOTOR_STEPS 200 
int speed = 3000;

int STEPS = 11;
int DIRECTION = 9;

void setup() {
  pinMode(STEPS, OUTPUT);
  pinMode(DIRECTION, OUTPUT);
}

void loop() {
  digitalWrite(DIRECTION, HIGH);
  turn();
}

void turn() {
  for (int i = 0; i < MOTOR_STEPS; i++) {
    digitalWrite(STEPS, HIGH);
    digitalWrite(STEPS, LOW);
    delayMicroseconds(speed);
  }
}
