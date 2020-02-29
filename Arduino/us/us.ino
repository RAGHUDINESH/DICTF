int trig=9;
int echo=8;
float distance(int T,int echo_pin){
  
  long duration;
  float distance;
  digitalWrite(T,1);
  delayMicroseconds(10);
  digitalWrite(T,0);
  duration= pulseIn(echo_pin,1);
  distance = duration*0.034/2;
  return distance;
}
void setup() {

  // put your setup code here, to run once:
pinMode(echo,INPUT);
pinMode(trig,OUTPUT);
Serial.begin(9600);
}

void loop() {
Serial.println(distance(trig,echo));
  // put your main code here, to run repeatedly:

}
