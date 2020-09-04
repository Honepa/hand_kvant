#include <Servo.h>

#define INIT          0
#define ST_BLUE       1
#define ST_GREEN      2
#define ST_YELLOW     3
#define ST_RED        4

#define motor1_a      18
#define motor1_b      19
#define motor1_pwm    9

#define motor2_a      20
#define motor2_b      21
#define motor2_pwm    8

#define motor3_a      14
#define motor3_b      15
#define motor3_pwm    3

#define motor4_a      16
#define motor4_b      17
#define motor4_pwm    2

#define motor5_a      26
#define motor5_b      28
#define motor5_pwm    10

#define servo_palm    7
#define servo_thumb   5
#define servo_claws   6

#define joystick_knok 12
#define joystick_x    A0
#define joystick_y    A1

#define led_red       50
#define led_yellow    48
#define led_green     46
#define led_blue      44

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

  pinMode(joystick_knok, INPUT);

  pinMode(led_red,       OUTPUT);
  pinMode(led_yellow,    OUTPUT);
  pinMode(led_green,     OUTPUT);
  pinMode(led_blue,      OUTPUT);

  aw(motor1_pwm, 200);
  dw(motor2_pwm,  1);
  dw(motor3_pwm,  1);
  dw(motor4_pwm,  1);
  dw(motor5_pwm,  1);

}

void motor1_run_rgt()
{
  dw(motor1_a, 1);
  dw(motor1_b, 0);
}

void motor1_run_lft()
{
  dw(motor1_a, 0);
  dw(motor1_b, 1);
}
/*---------*/
void shoulder_up()
{
  dw(motor2_a, 0);
  dw(motor2_b, 1);
  dw(motor3_a, 1);
  dw(motor3_b, 0);
}

void shoulder_down()
{
  dw(motor2_a, 1);
  dw(motor2_b, 0);
  dw(motor3_a, 0);
  dw(motor3_b, 1);
}

void shoulder_rgt()
{
  dw(motor2_a, 1);
  dw(motor2_b, 0);
  dw(motor3_a, 1);
  dw(motor3_b, 0);
}

void shoulder_lft()
{
  dw(motor2_a, 0);
  dw(motor2_b, 1);
  dw(motor3_a, 0);
  dw(motor3_b, 1);
}
/*---------*/
void forearm_up()
{
  dw(motor4_a, 0);
  dw(motor4_b, 1);
  dw(motor5_a, 1);
  dw(motor5_b, 0);
}

void forearm_down()
{
  dw(motor4_a, 1);
  dw(motor4_b, 0);
  dw(motor5_a, 0);
  dw(motor5_b, 1);
}

void forearm_rgt()
{
  dw(motor4_a, 1);
  dw(motor4_b, 0);
  dw(motor5_a, 1);
  dw(motor5_b, 0);
}

void forearm_lft()
{
  dw(motor4_a, 0);
  dw(motor4_b, 1);
  dw(motor5_a, 0);
  dw(motor5_b, 1);
}
/*---------*/
void motor_stop()
{
  dw(motor1_a, 1);
  dw(motor1_b, 1);
  aw(motor2_pwm, 150);
  aw(motor3_pwm, 150);
  dw(motor2_a, 0);
  dw(motor2_b, 1);
  dw(motor3_a, 1);
  dw(motor3_b, 0);
  dw(motor4_a, 1);
  dw(motor4_b, 1);
  dw(motor5_a, 1);
  dw(motor5_b, 1);
}
/*---------*/
void palm_rgt()
{
  for(int i = 0; i <= 100; i++)
  {
    palm.write(i);
    delay(10);
  }
}

void palm_lft()
{
  for(int i = 10.0; i >= 0; i--)
  {
    palm.write(i);
    delay(10);
  }
}
/*---------*/

void thumb_rgt()
{
  for(int i = 0; i <= 150; i++)
  {
    thumb.write(i);
    delay(10);
  }
}

void thumb_lft()
{
  for(int i = 150; i >= 0; i--)
  {
    thumb.write(i);
    delay(10);
  }
}
/*---------*/
int joy_knok, joy_x, joy_y, state = 0;

void setup()
{
  pin_set();
  //Serial.begin(9600);

}

void loop()
{
  joy_x =    ar(joystick_x);
  joy_y =    ar(joystick_y);
  joy_knok = !dr(joystick_knok);
  //Serial.print(joy_x);
  //Serial.print('\t');
  //Serial.print(joy_knok);
  //Serial.print('\n');
  switch(state)
  {
    case INIT:
    if(joy_knok)
    {
      Serial.print(joy_knok);
      state = ST_BLUE;
    }
    break;
    
    case ST_BLUE:
    dw(led_blue,   1);
    dw(led_green,  0);
    dw(led_yellow, 0);
    dw(led_red,    0);
    if(joy_knok)
    {
      Serial.print(joy_knok);
      state = ST_GREEN;
      motor_stop();
      delay(150);
    }
    if(joy_x > 700)
    {
      motor1_run_rgt();
    }
    else if(joy_x < 350)
    {
      motor1_run_lft();
    }
    else
    {
      motor_stop();
    }
    
    break;
    
    case ST_GREEN:
    dw(led_blue,   0);
    dw(led_green,  1);
    dw(led_yellow, 0);
    dw(led_red,    0);
    if(joy_knok)
    {
      state = ST_YELLOW;
      motor_stop();
      delay(150);
    }
    if((joy_y > 700) and (joy_x > 350) and (joy_x < 700))
    {
      dw(motor2_pwm, 1);
      dw(motor3_pwm, 1);
      shoulder_up(); 
    }
    else if ((joy_y < 350) and (joy_x > 350) and (joy_x < 700))
    {
      //dw(motor2_pwm, 1);
      //dw(motor3_pwm, 1);
      shoulder_down();
    }
    else if((joy_x > 700) and (joy_y > 350) and (joy_y < 700))
    {
      //dw(motor2_pwm, 1);
      //dw(motor3_pwm, 1);
      shoulder_rgt();
    }
    else if((joy_x < 350) and (joy_y > 350) and (joy_y < 700))
    {
      //dw(motor2_pwm, 1);
      //dw(motor3_pwm, 1);
      shoulder_lft();
    }
    else
    {
      motor_stop();
    }
    break;
    
    case ST_YELLOW:
    dw(led_blue,   0);
    dw(led_green,  0);
    dw(led_yellow, 1);
    dw(led_red,    0);
    if(joy_knok)
    {
      Serial.print(joy_knok);
      state = ST_RED;
      motor_stop();
      delay(150);
    }
    if((joy_y > 700) and (joy_x > 350) and (joy_x < 700))
    {
      forearm_up(); 
    }
    else if ((joy_y < 350) and (joy_x > 350) and (joy_x < 700))
    {
      forearm_down();
    }
    else if((joy_x > 700) and (joy_y > 350) and (joy_y < 700))
    {
      forearm_rgt();
    }
    else if((joy_x < 350) and (joy_y > 350) and (joy_y < 700))
    {
      forearm_lft();
    }
    else
    {
      motor_stop();
    }
    break;
    
    case ST_RED:
    dw(led_blue,   0);
    dw(led_green,  0);
    dw(led_yellow, 0);
    dw(led_red,    1);
    if(joy_knok)
    {
      Serial.print(joy_knok);
      state = ST_BLUE;
      motor_stop();
      delay(150);
    }
    if((joy_y > 700) and (joy_x > 350) and (joy_x < 700))
    {
      palm_rgt(); 
    }
    else if ((joy_y < 350) and (joy_x > 350) and (joy_x < 700))
    {
      palm_lft();
    }
    else if((joy_x > 700) and (joy_y > 350) and (joy_y < 700))
    {
      thumb_rgt();
    }
    else if((joy_x < 350) and (joy_y > 350) and (joy_y < 700))
    {
      thumb_lft();
    }
    else
    {
      motor_stop();
    }
    break;
  }
}
