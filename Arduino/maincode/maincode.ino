int lfe=4;
int lbe=5;
int rfe=6;
int rbe=7;
int lf1=30;
int lf2=31;
int lb1=32;
int lb2=33;
int rf1=34;
int rf2=35;
int rb1=36;
int rb2=37;
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


/*#include "I2Cdev.h"
#include "MPU6050_6Axis_MotionApps20.h"
#if I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE
#include "Wire.h"
#endif
MPU6050 mpu;
#define OUTPUT_READABLE_YAWPITCHROLL
#define LED_PIN 13 // (Arduino is 13, Teensy is 11, Teensy++ is 6)
bool blinkState = false;
bool dmpReady = false;  // set true if DMP init was successful
uint8_t mpuIntStatus;   // holds actual interrupt status byte from MPU
uint8_t devStatus;      // return status after each device operation (0 = success, !0 = error)
uint16_t packetSize;    // expected DMP packet size (default is 42 bytes)
uint16_t fifoCount;     // count of all bytes currently in FIFO
uint8_t fifoBuffer[64]; // FIFO storage buffer
Quaternion q;           // [w, x, y, z]         quaternion container
VectorInt16 aa;         // [x, y, z]            accel sensor measurements
VectorInt16 aaReal;     // [x, y, z]            gravity-free accel sensor measurements
VectorInt16 aaWorld;    // [x, y, z]            world-frame accel sensor measurements
VectorFloat gravity;    // [x, y, z]            gravity vector
float euler[3];         // [psi, theta, phi]    Euler angle container
float ypr[3];           // [yaw, pitch, roll]   yaw/pitch/roll container and gravity vector
uint8_t teapotPacket[14] = { '$', 0x02, 0,0, 0,0, 0,0, 0,0, 0x00, 0x00, '\r', '\n' };
volatile bool mpuInterrupt = false;     // indicates whether MPU interrupt pin has gone high
void dmpDataReady() {
    mpuInterrupt = true;
}


float yaw(){
  if (!dmpReady) return 0;
    while (!mpuInterrupt && fifoCount < packetSize) { }
    mpuInterrupt = false;
    mpuIntStatus = mpu.getIntStatus();
    fifoCount = mpu.getFIFOCount();
    if ((mpuIntStatus & 0x10) || fifoCount == 1024) {
        mpu.resetFIFO();
        Serial.println(F("FIFO overflow!"));
    } else if (mpuIntStatus & 0x02) {
        while (fifoCount < packetSize) fifoCount = mpu.getFIFOCount();
         mpu.getFIFOBytes(fifoBuffer, packetSize);
         fifoCount -= packetSize;
        #ifdef OUTPUT_READABLE_YAWPITCHROLL
            mpu.dmpGetQuaternion(&q, fifoBuffer);
            mpu.dmpGetGravity(&gravity, &q);
            mpu.dmpGetYawPitchRoll(ypr, &q, &gravity);
        #endif
        return ypr[0];
    }
}*/


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

void move1(){
float  dist=distance(TL,EL);
float error=dist-15;
float error1=constrain(error,0,10);
float error2=constrain(error,-5,0);
float scale_l=map(error1,0,10,200,0);
float scale_r=map(error2,-5,0,0,200);
if (error>0)
  {
    analogWrite(lfe,scale_l);
    analogWrite(lbe,scale_l);
    analogWrite(rfe,200);
    digitalWrite(rbe,200);
    digitalWrite(lf1,1);
    digitalWrite(lf2,0);
    digitalWrite(lb1,1);
    digitalWrite(lb2,0);
    digitalWrite(rf1,1);
    digitalWrite(rf2,0);
    digitalWrite(rb1,1);
    digitalWrite(rb2,0);
  }
  else if (error<=0&&error>-3)
  {
    analogWrite(lfe,200);
    analogWrite(lbe,200);
    analogWrite(rfe,scale_r);
    digitalWrite(rbe,scale_r);
    digitalWrite(lf1,1);
    digitalWrite(lf2,0);
    digitalWrite(lb1,1);
    digitalWrite(lb2,0);
    digitalWrite(rf1,1);
    digitalWrite(rf2,0);
    digitalWrite(rb1,1);
    digitalWrite(rb2,0);
  
 }
  else if (error<-3)
  {
    stop_bot();
    delay(500);
    analogWrite(lfe,200);
    analogWrite(lbe,200);
    analogWrite(rfe,200);
    digitalWrite(rbe,200);
    digitalWrite(lf1,1);
    digitalWrite(lf2,0);
    digitalWrite(lb1,1);
    digitalWrite(lb2,0);
    digitalWrite(rf1,1);
    digitalWrite(rf2,0);
    digitalWrite(rb1,1);
    digitalWrite(rb2,0);
    while((distance(TL,EL)-15)<-3);
    stop_bot();
    delay(500);
  }
}

/*void move2(){
float  dist=distance(TR,ER);
float error=dist-45;
float error1=constrain(error,-10,0);
float error2=constrain(error,0,5);
float scale_l=map(error1,-10,0,0,200);
float scale_r=map(error2,0,5,200,0);
if (error<0)
  {
    digitalWrite(rm1,1);
    digitalWrite(rm2,0);
    analogWrite(rme,200);
    digitalWrite(lm1,1);
    digitalWrite(lm2,0);
    analogWrite(lme,scale_l);
  }
  else if (error>=0&&error<=3)
  {
    digitalWrite(lm1,1);
    digitalWrite(lm2,0);
    analogWrite(lme,200);
    digitalWrite(rm1,1);
    digitalWrite(rm2,0);
    analogWrite(rme,scale_r);
  }
  else if (error>3)
  {
    stop_bot();
    delay(500);
    digitalWrite(lm1,1);
    digitalWrite(lm2,0);
    digitalWrite(lme,1);
    digitalWrite(rm1,0);
    digitalWrite(rm2,1);
    digitalWrite(rme,1);
    delay(500);
  }
}


void move3(){
float  dist=distance(TL,EL);
float error=dist-35;
float error1=constrain(error,0,10);
float error2=constrain(error,-5,0);
float scale_l=map(error1,0,10,200,0);
float scale_r=map(error2,-5,0,0,200);
if (error>0)
  {
    digitalWrite(rm1,1);
    digitalWrite(rm2,0);
    analogWrite(rme,200);
    digitalWrite(lm1,1);
    digitalWrite(lm2,0);
    analogWrite(lme,scale_l);
  }
  else if (error<=0)
  {
    digitalWrite(lm1,1);
    digitalWrite(lm2,0);
    analogWrite(lme,200);
    digitalWrite(rm1,1);
    digitalWrite(rm2,0);
    analogWrite(rme,scale_r);
  }

}*/

/*void move4(){
float  dist=distance(TR,ER);
float error=dist-35;
float error1=constrain(error,-10,0);
float error2=constrain(error,0,5);
float scale_l=map(error1,-10,0,0,200);
float scale_r=map(error2,0,5,200,0);
if (error<0)
  {
    analogWrite(lfe,scale_l);
    analogWrite(lbe,scale_l);
    analogWrite(rfe,1);
    digitalWrite(rbe,200);
    digitalWrite(lf1,1);
    digitalWrite(lf2,0);
    digitalWrite(lb1,1);
    digitalWrite(lb2,0);
    digitalWrite(rf1,1);
    digitalWrite(rf2,0);
    digitalWrite(rb1,1);
    digitalWrite(rb2,0);
   }
  else if (error>=0)
  {
    digitalWrite(lfe,1);
    digitalWrite(lbe,200);
    analogWrite(rfe,scale_r);
    analogWrite(rbe,scale_r);
    digitalWrite(lf1,1);
    digitalWrite(lf2,0);
    digitalWrite(lb1,1);
    digitalWrite(lb2,0);
    digitalWrite(rf1,1);
    digitalWrite(rf2,0);
    digitalWrite(rb1,1);
    digitalWrite(rb2,0);
  }

}*/


/*void climb_d()
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
*/
void stop_bot()
{
    digitalWrite(lfe,0);
    digitalWrite(lbe,0);
    digitalWrite(rfe,0);
    digitalWrite(rbe,0);
}



void setup() {
  /* //------------------------------------------------------------------------------------------------------------------------------
    // join I2C bus (I2Cdev library doesn't do this automatically)
    #if I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE
        Wire.begin();
//        TWBR = 24; // 400kHz I2C clock (200kHz if CPU is 8MHz)
    #elif I2CDEV_IMPLEMENTATION == I2CDEV_BUILTIN_FASTWIRE
        Fastwire::setup(400, true);
    #endif

    // initialize serial communication
    // (115200 chosen because it is required for Teapot Demo output, but it's
    // really up to you depending on your project)
    Serial.begin(115200);
    while (!Serial); // wait for Leonardo enumeration, others continue immediately

    // NOTE: 8MHz or slower host processors, like the Teensy @ 3.3v or Ardunio
    // Pro Mini running at 3.3v, cannot handle this baud rate reliably due to
    // the baud timing being too misaligned with processor ticks. You must use
    // 38400 or slower in these cases, or use some kind of external separate
    // crystal solution for the UART timer.

    // initialize device
    Serial.println(F("Initializing I2C devices..."));
    mpu.initialize();

    // verify connection
    Serial.println(F("Testing device connections..."));
    Serial.println(mpu.testConnection() ? F("MPU6050 connection successful") : F("MPU6050 connection failed"));

    // wait for ready
    Serial.println(F("\nSend any character to begin DMP programming and demo: "));
    //while (Serial.available() && Serial.read()); // empty buffer
    //while (!Serial.available());                 // wait for data
    //while (Serial.available() && Serial.read()); // empty buffer again

    // load and configure the DMP
    Serial.println(F("Initializing DMP..."));
    devStatus = mpu.dmpInitialize();

    // supply your own gyro offsets here, scaled for min sensitivity
    mpu.setXGyroOffset(220);
    mpu.setYGyroOffset(76);
    mpu.setZGyroOffset(-85);
    mpu.setZAccelOffset(1788); // 1688 factory default for my test chip

    // make sure it worked (returns 0 if so)
    if (devStatus == 0) {
        // turn on the DMP, now that it's ready
        Serial.println(F("Enabling DMP..."));
        mpu.setDMPEnabled(true);

        // enable Arduino interrupt detection
        Serial.println(F("Enabling interrupt detection (Arduino external interrupt 0)..."));
        attachInterrupt(0, dmpDataReady, RISING);
        mpuIntStatus = mpu.getIntStatus();

        // set our DMP Ready flag so the main loop() function knows it's okay to use it
        Serial.println(F("DMP ready! Waiting for first interrupt..."));
        dmpReady = true;

        // get expected DMP packet size for later comparison
        packetSize = mpu.dmpGetFIFOPacketSize();
    } else {
        // ERROR!
        // 1 = initial memory load failed
        // 2 = DMP configuration updates failed
        // (if it's going to break, usually the code will be 1)
        Serial.print(F("DMP Initialization failed (code "));
        Serial.print(devStatus);
        Serial.println(F(")"));
    }

    // configure LED for output
    //pinMode(LED_PIN, OUTPUT);
    //-----------------------------------------------------------------*/
pinMode(lfe,OUTPUT);
pinMode(lbe,OUTPUT);
pinMode(rfe,OUTPUT);
pinMode(rbe,OUTPUT);
pinMode(lf1,OUTPUT);
pinMode(lf2,OUTPUT);
pinMode(lb1,OUTPUT);
pinMode(lb2,OUTPUT);
pinMode(rf1,OUTPUT);
pinMode(rf2,OUTPUT);
pinMode(rb1,OUTPUT);
pinMode(rb2,OUTPUT);
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

Serial.begin(9600);

//delay(5000);
/*int ia=yaw;

   digitalWrite(lfe,1);
    digitalWrite(lbe,1);
    digitalWrite(rfe,1);
    digitalWrite(rbe,1);
    digitalWrite(lf1,1);
    digitalWrite(lf2,0);
    digitalWrite(lb1,1);
    digitalWrite(lb2,0);
    digitalWrite(rf1,0);
    digitalWrite(rf2,1);
    digitalWrite(rb1,0);
    digitalWrite(rb2,1);
    while(abs(yaw()-ia)<(1.57))
    {
      Serial.println(abs(yaw()-ia));
    }
   digitalWrite(lfe,0);
    digitalWrite(lbe,0);
    digitalWrite(rfe,0);
    digitalWrite(rbe,0);
    digitalWrite(lf1,1);
    digitalWrite(lf2,0);
    digitalWrite(lb1,1);
    digitalWrite(lb2,0);
    digitalWrite(rf1,1);
    digitalWrite(rf2,0);
    digitalWrite(rb1,1);
    digitalWrite(rb2,0);
    while(true);

/*int k=0;
while (true)
{
  k=0;
  move3();
 if (distance(TF,EF)>50)
  {
    stop_bot();
    for(int i=2;i>0;i--)
    {
      if(distance(TF,EF)>50)
      {
        k++;
      }
    }
  if (k==2)
  {
    break;
  }
 
 }
  
}

stop_bot();

delay(10000);

int ia=yaw();
    digitalWrite(lm1,0);
    digitalWrite(lm2,1);
    analogWrite(lme,200);
    digitalWrite(rm1,1);
    digitalWrite(rm2,0);
    analogWrite(rme,200);
while(abs(yaw()-ia)<3.14);
stop_bot();
delay(5000);

while (true)
{
  k=0;
  move4();
 if (distance(TF,EF)>50)
  {
    stop_bot();
    for(int i=2;i>0;i--)
    {
      if(distance(TF,EF)>50)
      {
        k++;
      }
    }
  if (k==2)
  {
    break;
  }
 }

stop_bot();
delay(5000);

}
ia=yaw();
    digitalWrite(lm1,0);
    digitalWrite(lm2,1);
    analogWrite(lme,200);
    digitalWrite(rm1,1);
    digitalWrite(rm2,0);
    analogWrite(rme,200);
while(abs(yaw()-ia)<1.57);
stop_bot();

delay(1*60*1000);


climb_d();


delay(2*60*1000);
ia=yaw();
    digitalWrite(lm1,0);
    digitalWrite(lm2,1);
    analogWrite(lme,200);
    digitalWrite(rm1,1);
    digitalWrite(rm2,0);
    analogWrite(rme,200);
while(abs(yaw()-ia)<90);
stop_bot();


 while (true)
{
  k=0;
  move1();
 if (distance(TF,EF)>38)
  {
    stop_bot();
    for(int i=2;i>0;i--)
    {
      if(distance(TF,EF)>38)
      {
        k++;
      }
    }
  if (k==2)
  {
    break;
  }
 }
  
}

stop_bot();

delay(3000);
ia=yaw();
    digitalWrite(lm1,1);
    digitalWrite(lm2,0);
    analogWrite(lme,200);
    digitalWrite(rm1,0);
    digitalWrite(rm2,1);
    analogWrite(rme,200);
while(abs(yaw()-ia)<90);
stop_bot();
 while (true)
{
  k=0;
    digitalWrite(lm1,1);
    digitalWrite(lm2,0);
    analogWrite(lme,200);
    digitalWrite(rm1,1);
    digitalWrite(rm2,0);
    analogWrite(rme,200);
 if (distance(TF,EF)>38)
  {
    stop_bot();
    for(int i=2;i>0;i--)
    {
      if(distance(TF,EF)>38)
      {
        k++;
      }
    }
  if (k==2)
  {
    break;
  }
 }

stop_bot();

delay(3000);
ia=yaw();
    digitalWrite(lm1,1);
    digitalWrite(lm2,0);
    analogWrite(lme,200);
    digitalWrite(rm1,0);
    digitalWrite(rm2,1);
    analogWrite(rme,200);
while(abs(yaw()-ia)<90);
stop_bot();
0
delay(3000);

while (true)
{
  k=0;
  move2();
 if (distance(TF,EF)>38)
  {
    for(int i=2;i>0;i--)
    {
      if(distance(TF,EF)>38)
      {
        k++;
      }
    }
  if (k==2)
  {
    break;
  }
 }
}

stop_bot();*/

}
void loop() {

 move1();
  
 }
