#define INIT      0
#define ST_BLUE   1
#define ST_GREEN  2
#define ST_YELLOW 3
#define ST_RED    4

#define motor1_a 18
#define motor1_b 19
#define motor1_pwm 9

#define motor2_a 20
#define motor2_b 21
#define motor2_pwm 8

#define motor3_a 14
#define motor3_b 15
#define motor3_pwm 3

#define motor4_a 16
#define motor4_b 17
#define motor4_pwm 4

#define motor5_a 26
#define motor5_b 28
#define motor5_pwm 10

#define servo_palm   7
#define servo_thumb 6
#define servo_claws 5

#define joystick_knok
#define joystick_x
#define joystick_y

#define led_red
#define led_yellow
#define led_green
#define led_blue

#define pm pinMode
#define dw digitalWrite
#define aw analogWrite
#define dr digitalRead
#define ar analogRead

Servo palm;
Servo thumb;
Servo claws;

void pin_set()
{
  pinMode(motor1_a,      OUTPUT);
  pinMode(motor1_b,      OUTPUT);
  pinMode(motor1_pwm,    OUTPUT);

  pinMode(motor2_a,      OUTPUT);
  pinMode(motor2_b,      OUTPUT);
  pinMode(motor2_pwm,    OUTPUT);


  pinMode(motor3_a,      OUTPUT);
  pinMode(motor3_b,      OUTPUT);
  pinMode(motor3_pwm,    OUTPUT);

  pinMode(motor4_a,      OUTPUT);
  pinMode(motor4_b,      OUTPUT);
  pinMode(motor4_pwm,    OUTPUT);

  pinMode(motor5_a,      OUTPUT);
  pinMode(motor5_b,      OUTPUT);
  pinMode(motor5_pwm,    OUTPUT);

  palm.attach(servo_palm);
  thumb.attach(servo_thumb);
  claws.attach(servo_claws);

  pinMode(joystick_knok, OUTPUT);
  pinMode(joystick_x,    OUTPUT);
  pinMode(joystick_y,    OUTPUT);

  pinMode(led_red,       OUTPUT);
  pinMode(led_yellow,    OUTPUT);
  pinMode(led_green,     OUTPUT);
  pinMode(led_blue,      OUTPUT);
}

int joy_knok, joy_x, joy_y, state = 0;

void setup() 
{
  pin_set();
  Serial.begin(9600);   

}

void loop() 
{
  

}
