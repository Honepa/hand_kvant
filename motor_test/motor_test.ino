#define motor2_a 20
#define motor2_b 21
#define motor2_pwm 8

#define motor3_a 14
#define motor3_b 15
#define motor3_pwm 3

void setup() {
  // put your setup code here, to run once:
  pinMode(motor2_a,      OUTPUT);
  pinMode(motor2_b,      OUTPUT);
  pinMode(motor2_pwm,    OUTPUT);


  pinMode(motor3_a,      OUTPUT);
  pinMode(motor3_b,      OUTPUT);
  pinMode(motor3_pwm,    OUTPUT);
  digitalWrite(motor2_pwm, 1);
  digitalWrite(motor3_pwm, 1);
}

void loop() 
{
  digitalWrite(motor2_a, 0);
  digitalWrite(motor2_b, 1);
  digitalWrite(motor3_a, 1);
  digitalWrite(motor3_b, 0);
  delay(1500);
  
  digitalWrite(motor2_a, 1);
  digitalWrite(motor2_b, 1);
  digitalWrite(motor3_a, 1);
  digitalWrite(motor3_b, 1);
  delay(250);
  
  digitalWrite(motor2_a, 1);
  digitalWrite(motor2_b, 0);
  digitalWrite(motor3_a, 0);
  digitalWrite(motor3_b, 1);
  delay(500);
  digitalWrite(motor2_a, 1);
  digitalWrite(motor2_b, 1);
  digitalWrite(motor3_a, 1);
  digitalWrite(motor3_b, 1);
  delay(250);
  
}
