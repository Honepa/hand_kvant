#define joystick_knok 12
#define joystick_x A0
#define joystick_y A1

#define led_red 50
#define led_yellow 48
#define led_green 46
#define led_blue 44

void setup() 
{
  pinMode(12, INPUT);

  pinMode(led_red,       OUTPUT);
  pinMode(led_yellow,    OUTPUT);
  pinMode(led_green,     OUTPUT);
  pinMode(led_blue,      OUTPUT);

  //digitalWrite(12, 1);
  
  Serial.begin(9600);

  Serial.print("joy_x");
  Serial.print('\t');
  Serial.print("joy_y");
  Serial.print('\t');
  Serial.print("KNOK");
  Serial.print('\n');
}

int joy_x, joy_y, state = 0;

void loop() 
{
  joy_x = analogRead(joystick_x);
  joy_y = analogRead(joystick_y);
  int joy_knok = digitalRead(12);
  
  Serial.print(joy_x);
  Serial.print('\t');
  Serial.print(joy_y);
  Serial.print('\t');
  Serial.print(joy_knok);
  Serial.print('\n');
  digitalWrite(led_red, 1);
}
