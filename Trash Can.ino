#include<Servo.h>
#define Trig 8
#define Echo 2
#define DuoPIN 5
#define Led 11
#define Echo2 6
#define Trig2 7
#define DuoPIN2 13
#define Echo3 9
#define Trig3 10

Servo myDuoJi, myDuoJi2;
long gettime()
{
    digitalWrite(Trig,HIGH);
    delayMicroseconds(10);
    digitalWrite(Trig,LOW);
    return  pulseIn(Echo,HIGH);
  }
long gettime2()
{
    digitalWrite(Trig2,HIGH);
    delayMicroseconds(10);
    digitalWrite(Trig2,LOW);
    return  pulseIn(Echo2,HIGH);
  }
long gettime3()
{
    digitalWrite(Trig3,HIGH);
    delayMicroseconds(10);
    digitalWrite(Trig3,LOW);
    return  pulseIn(Echo3,HIGH);
  }
void setup() {
  pinMode(Trig,OUTPUT);
  pinMode(Trig2,OUTPUT);
  pinMode(Trig3,OUTPUT);
  pinMode(Led, OUTPUT);
  pinMode(Echo,INPUT);
  pinMode(Echo2,INPUT);
  pinMode(Echo3,INPUT);
  myDuoJi.attach(DuoPIN);
  myDuoJi2.attach(DuoPIN2);
  Serial.begin(115200);
  myDuoJi.write(0);
  myDuoJi2.write(0);
}

void loop() {
  long dis;
  long dis2;
  long dis3;
  dis = gettime()/58;
  dis2 = gettime2()/58;
  dis3 = gettime3()/58;
  
  if(dis < 10 && dis2 < 5){
    digitalWrite(Led, HIGH);
    delay(500);
    digitalWrite(Led, LOW);
    delay(500);
   }
  else if(dis < 10 && dis2 >= 5){
    myDuoJi.write(90);
    delay(3000);   
    myDuoJi.write(0); 
  }
  else if(dis3 < 10){
    myDuoJi2.write(90); 
    delay(3000); 
    myDuoJi2.write(0);
  }
  else{
    myDuoJi.write(0);
    myDuoJi2.write(0);
  }
}
