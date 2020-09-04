#include <Servo.h>
#define servo_palm   7
#define servo_thumb 6
#define servo_claws 5

Servo palm;
Servo thumb;
Servo claws;

void setup() 
{
 // pinMode(servo_palm,     OUTPUT);
  //pinMode(servo_thumb,   OUTPUT);
  //pinMode(servo_claws,   OUTPUT);

  palm.attach(servo_palm);
  thumb.attach(servo_thumb);
  claws.attach(servo_claws);
  Serial.begin(9600);
  Serial.println("ready");
}

void loop() 
{
  // put your main code here, to run repeatedly:
  /*for(int i = 0; i <= 270; i++)
  {
    palm.write(i);
    delay(50);
  }
  for(int i = 270; i >= 0; i--)
  {
    palm.write(i);
    delay(50);
  }
  delay(500); */
  for(int i = 0; i <= 270; i++)
  {
    thumb.write(i);
    delay(50);
  }
  for(int i = 270; i >= 0; i--)
  {
    thumb.write(i);
    delay(50);
  }
  delay(500);
  for(int i = 0; i <= 270; i++)
  {
    claws.write(i);
    delay(50);
  }
  for(int i = 270; i >= 0; i--)
  {
    claws.write(i);
    delay(50);
  }
  //palm.write(120);
  //delay(1500);
  //thumb.write(0);
  //delay(1500);
  // claws.write(0);
  //delay(1000);
}
