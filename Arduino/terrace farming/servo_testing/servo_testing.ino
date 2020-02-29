int dir2=7;
int dir1=6;
int pwm2=5;
int pwm1=3;

void setup() {

pinMode(dir2,OUTPUT);
pinMode(dir1,OUTPUT);
pinMode(pwm2,OUTPUT);
pinMode(pwm1,OUTPUT);


}
void up()
  {
  digitalWrite(dir1,0);
  digitalWrite(dir2,0);
  analogWrite(pwm1,130);
  analogWrite(pwm2,130);

  }

void loop() {
up();
}
