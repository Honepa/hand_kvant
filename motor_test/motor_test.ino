#define motor1_a 18
#define motor1_b 19
#define motor1_pwm 9

void setup() {
  // put your setup code here, to run once:
  pinMode(motor1_a,      OUTPUT);
  pinMode(motor1_b,      OUTPUT);
  pinMode(motor1_pwm,    OUTPUT);
  analogWrite(motor1_pwm, 250);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(motor1_a, 1);
  digitalWrite(motor1_b, 0);
  delay(500);
  digitalWrite(motor1_a, 1);
  digitalWrite(motor1_b, 1);
  delay(200);
  digitalWrite(motor1_a, 0);
  digitalWrite(motor1_b, 1);
  delay(500);
  digitalWrite(motor1_a, 1);
  digitalWrite(motor1_b, 1);
  delay(200);
}
