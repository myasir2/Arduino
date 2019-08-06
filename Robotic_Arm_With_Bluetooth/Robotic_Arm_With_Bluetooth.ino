#include <SoftwareSerial.h>
#include <Servo.h>

//int LED_PIN = 13;
int servopin1 = 8;    //Define servo interface digital interface 9
int servopin2 = 9;    //Define servo interface digital interface 6
int servopin3 = 10;    //Define servo interface digital interface 5
int servopin4 = 11;    //Define servo interface digital interface 3
int servopin5 = 12;   //Define servo interface digital interface 11

int moveServoData;
int servo1Angle=90;
int servo2Angle=90;
int servo3Angle=90;
int servo4Angle=90;
int servo5Angle=90;
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;

SoftwareSerial bluetoothSerial(0, 1);

void setup() 
{
//  pinMode(LED_PIN, OUTPUT);
  
  Serial.begin(9600);
  bluetoothSerial.begin(9600);
  Serial.println("Ready");

  pinMode(servopin1,OUTPUT);//Set the servo interface as the output interface
  pinMode(servopin2,OUTPUT);//Set the servo interface as the output interface
  pinMode(servopin3,OUTPUT);//Set the servo interface as the output interface
  pinMode(servopin4,OUTPUT);//Set the servo interface as the output interface
  pinMode(servopin5,OUTPUT);//Set the servo interface as the output interface

  servo1.attach(servopin1);
  servo2.attach(servopin2);
  servo3.attach(servopin3);
  servo4.attach(servopin4);
  servo5.attach(servopin5);
  servo1.write(90);
  servo2.write(90);
  servo3.write(90);
  servo4.write(90);
  servo5.write(90); 
}

void loop() 
{
  if(bluetoothSerial.available())
  {
    String message = bluetoothSerial.readString();
    int angle = message.substring(2).toInt();

    if(message.startsWith("s1"))
    {
      if(angle > 180)
        servo1Angle = 180;
      else if(angle < 0)
        servo1Angle = 0;
      else
        servo1Angle = angle;

      servo1.write(servo1Angle);
    }
    else if(message.startsWith("s2"))
    {
      if(angle > 180)
        servo2Angle = 180;
      else if(angle < 0)
        servo2Angle = 0;
      else
        servo2Angle = angle;

      servo2.write(servo2Angle);
    }
    else if(message.startsWith("s3"))
    {
      if(angle > 180)
        servo3Angle = 180;
      else if(angle < 0)
        servo3Angle = 0;
      else
        servo3Angle = angle;

      servo3.write(servo3Angle);
    }
    else if(message.startsWith("s4"))
    {
      if(angle > 180)
        servo4Angle = 180;
      else if(angle < 0)
        servo4Angle = 0;
      else
        servo4Angle = angle;

      servo4.write(servo4Angle);
    }
    else if(message.startsWith("s5"))
    {
      if(angle > 180)
        servo5Angle = 180;
      else if(angle < 0)
        servo5Angle = 0;
      else
        servo5Angle = angle;

      servo5.write(servo5Angle);
    }

    delay(20);
  }
}
