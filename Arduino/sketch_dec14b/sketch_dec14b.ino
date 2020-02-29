int lm1=3;
int lm2=2;
int lme=11;
int rm1=6;
int rm2=5;
int rme=10;
int T=8;
int EL=9;
int EF=10;
l_len=20;
r_len=;

float distance(int echo_pin){
  long duration;
  float distance;
  digitalWrite(T,1);
  delayMicroseconds(10);
  digitalWrite(T,0);
  duration= pulseIn(echo_pin,1);
  distance = duration*0.034/2;
  return distance;
}

void move(int echo_pin, int const_len){
float  dist=distance(echo_pin);
float error=dist-const_len;
float error1=constrain(error,0,10);
float error2=constrain(error,-5,0);
float scale_l=map(error1,0,10,255,0);
float scale_r=map(error2,-5,0,0,255);
if (error>0)
  {
    digitalWrite(rm1,1);
    digitalWrite(rm2,0);
    digitalWrite(rme,1);
    digitalWrite(lm1,1);
    digitalWrite(lm2,0);
    analogWrite(lme,scale_l);
  }
  else if (error<=0&&error>-3)
  {
    digitalWrite(lm1,1);
    digitalWrite(lm2,0);
    digitalWrite(lme,1);
    digitalWrite(rm1,1);
    digitalWrite(rm2,0);
    analogWrite(rme,scale_r);
  }
  else if (error<-3)
  {//clockwise
    digitalWrite(lm1,1);
    digitalWrite(lm2,0);
    digitalWrite(lme,1);
    digitalWrite(rm1,0);
    digitalWrite(rm2,1);
    digitalWrite(rme,1);
  }
}

void setup() {
pinMode(lme,OUTPUT);
pinMode(rme,OUTPUT);
pinMode(lm1,OUTPUT);
pinMode(lm2,OUTPUT);
pinMode(rm1,OUTPUT);
pinMode(rm2,OUTPUT);
pinMode(T,OUTPUT);
pinMode(EL,INPUT);
pinMode(EF,INPUT);
Serial.begin(9600);
}

void loop() {
  move(EL,l_len);

 
 }
