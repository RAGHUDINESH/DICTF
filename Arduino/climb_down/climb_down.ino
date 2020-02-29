int lm1=30;
int lm2=31;
int lme=3;
int rm1=32;
int rm2=33;
int rme=4;
int TL=40;
int EL=41;
int TF=42;
int EF=43;
int TR=44;
int ER=45;
int SD1=46;
int SD2=47;
int LRD=22;
int LRP=7;
int RRD=23;
int RRP=8;

void climb_d()
{
    digitalWrite(lm1,1);
    digitalWrite(lm2,0);
    analogWrite(lme,100);
    digitalWrite(rm1,1);
    digitalWrite(rm2,0);
    analogWrite(rme,100);
while(digitalRead(SD1)==1);
    digitalWrite(lme,0);
    digitalWrite(rme,0);
    delay(3000);
    digitalWrite(RRD,1);//dir
    digitalWrite(LRD,1);//dir
    analogWrite(LRP,130);
    analogWrite(RRP,130);
while(digitalRead(SD1)==0);
    digitalWrite(LRP,0);
    digitalWrite(RRP,0);
    digitalWrite(RRD,0);//dir
    digitalWrite(LRD,0);//dir
    delay(2000);
    digitalWrite(lme,1);
    digitalWrite(rme,1);
while(digitalRead(SD2)==1) ;
    digitalWrite(LRP,1);
    digitalWrite(RRP,1);
    digitalWrite(lme,0);
    digitalWrite(rme,0);
while(digitalRead(SD1)==0);
    digitalWrite(LRP,0);
    digitalWrite(RRP,0);
}

void setup() {
pinMode(lme,OUTPUT);
pinMode(rme,OUTPUT);
pinMode(lm1,OUTPUT);
pinMode(lm2,OUTPUT);
pinMode(rm1,OUTPUT);
pinMode(rm2,OUTPUT);
pinMode(TL,OUTPUT);
pinMode(EL,INPUT);
pinMode(TF,OUTPUT);
pinMode(EF,INPUT);
pinMode(TR,OUTPUT);
pinMode(ER,INPUT);
pinMode(SD1,INPUT);
pinMode(SD2,INPUT);
pinMode(LRD,OUTPUT);
pinMode(LRP,OUTPUT);
pinMode(RRD,OUTPUT);
pinMode(RRP,OUTPUT);
climb_d();
}

void loop() {
  // put your main code here, to run repeatedly:

}01
