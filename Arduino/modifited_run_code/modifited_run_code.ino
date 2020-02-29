
int lf1 = 30;
int lf2 = 31;
int lb1 = 32;
int lb2 = 33;
int rf1 = 34;
int rf2 = 35;
int rb1 = 36;
int rb2 = 37;
int lfe = 4;
int lbe = 5;
int rfe = 6;
int rbe = 7;
void forward()
{
  digitalWrite(lf1,1);
  digitalWrite(lf2,0);
  digitalWrite(lb1,1);
  digitalWrite(lb2,0);
  digitalWrite(rf1,1);
  digitalWrite(rf2,0);
  digitalWrite(rb1,1);
  digitalWrite(rb2,0);
  analogWrite(lfe,255);
  analogWrite(lbe,255);
  analogWrite(rfe,255);
  analogWrite(rbe,255);
  
  
}
void backward()
{
  digitalWrite(lf1,0);
  digitalWrite(lf2,1);
  digitalWrite(lb1,0);
  digitalWrite(lb2,1);
  digitalWrite(rf1,0);
  digitalWrite(rf2,1);
  digitalWrite(rb1,0);
  digitalWrite(rb2,1);
  analogWrite(lfe,255);
  analogWrite(lbe,255);
  analogWrite(rfe,255);
  analogWrite(rbe,255);
  
  
}
void right()
{
  digitalWrite(lf1,1);
  digitalWrite(lf2,0);
  digitalWrite(lb1,1);
  digitalWrite(lb2,0);
  digitalWrite(rf1,0);
  digitalWrite(rf2,1);
  digitalWrite(rb1,0);
  digitalWrite(rb2,1);
  analogWrite(lfe,255);
  analogWrite(lbe,255);
  analogWrite(rfe,255);
  analogWrite(rbe,255);
  
}
void left()
{
  digitalWrite(lf1,0);
  digitalWrite(lf2,1);
  digitalWrite(lb1,0);
  digitalWrite(lb2,1);
  digitalWrite(rf1,1);
  digitalWrite(rf2,0);
  digitalWrite(rb1,1);
  digitalWrite(rb2,0);
  analogWrite(lfe,255);
  analogWrite(lbe,255);
  analogWrite(rfe,255);
  analogWrite(rbe,255);
  
}


void setup() {
  // put your setup code here, to run once:
pinMode(lf1,OUTPUT);
pinMode(lf2,OUTPUT);
pinMode(lb1,OUTPUT);
pinMode(lb2,OUTPUT);
pinMode(rb1,OUTPUT);
pinMode(rb2,OUTPUT);
pinMode(rf1,OUTPUT);
pinMode(rf2,OUTPUT);
pinMode(lfe,OUTPUT);
pinMode(lbe,OUTPUT);
pinMode(rfe,OUTPUT);
pinMode(lbe,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  forward();

}
