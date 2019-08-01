#include <SoftwareSerial.h>
#include <Servo.h>

//int LED_PIN = 13;
int servopin1 = 9;    //Define servo interface digital interface 9
int servopin2 = 6;    //Define servo interface digital interface 6
int servopin3 = 5;    //Define servo interface digital interface 5
int servopin4 = 3;    //Define servo interface digital interface 3
int servopin5 = 11;   //Define servo interface digital interface 11

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
int angle = 90;        //Angle of rotation of the servo

//SoftwareSerial bluetoothSerial(0, 1);

void setup() 
{
//  pinMode(LED_PIN, OUTPUT);
  
//  Serial.begin(9600);
//  bluetoothSerial.begin(9600);
//  Serial.println("Ready");

  pinMode(servopin1,OUTPUT);//Set the servo interface as the output interface
  pinMode(servopin2,OUTPUT);//Set the servo interface as the output interface
  pinMode(servopin3,OUTPUT);//Set the servo interface as the output interface
  pinMode(servopin4,OUTPUT);//Set the servo interface as the output interface
  pinMode(servopin5,OUTPUT);//Set the servo interface as the output interface
  Serial.begin(9600);
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
//  if(bluetoothSerial.available())
//  {
//    String message = bluetoothSerial.readString();
//
//    if(message == "on")
//      digitalWrite(LED_PIN, HIGH);
//    else if(message == "off")
//      digitalWrite(LED_PIN, LOW);
//  }
}
