#include<Servo.h>


int servoPin=10;
int trigPin=7;
int echoPin=8;
int output=90;
int f=1;

Servo myServo;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,OUTPUT);
  
  myServo.attach(servoPin);
  Serial.println("attached");
  myServo.write(90);
  delay(2000);
  Serial.println("init done");
}

void loop() {
  // put your main code here, to run repeatedly:
  myServo.write(output);
      delay(2);
     Serial.println(output);
      if(output==90)
        f=-1;
      else if(output==0)
        f=1;
      output=output+f;
  Serial.println("loop done");
}
