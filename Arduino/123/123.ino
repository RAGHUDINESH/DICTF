

#include<Servo.h>


int servo_pin=8;
int output=1;
int f=1;
Servo mys;

void setup() {
  // put your setup code here, to run once:
mys.attach(servo_pin);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
      
      mys.write(output);
      delay(2);
     Serial.println(output);
      if(output==180)
        f=-1;
      else if(output==0)
        f=1
        ;
      output=output+f;
  //mys.write(100);

}
