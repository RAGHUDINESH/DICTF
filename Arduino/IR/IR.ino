int x;

void setup() {
  // put your setup code here, to run once:
pinMode(4,INPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
x=digitalRead(4);
Serial.println(x);
}
