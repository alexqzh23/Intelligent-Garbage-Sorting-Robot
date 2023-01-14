#include<Servo.h>
#define DuoPIN1 2
#define DuoPIN2 3
#define DuoPIN3 4
#define DuoPIN4 5
int x=0;
int y=0;

Servo myDuoJi1, myDuoJi2, myDuoJi3, myDuoJi4;

void setup() {
  myDuoJi1.attach(DuoPIN1);
  myDuoJi2.attach(DuoPIN2);
  myDuoJi3.attach(DuoPIN3);
  myDuoJi4.attach(DuoPIN4);

  pinMode(6,INPUT);
  pinMode(7,INPUT);

  Serial.begin(115200);
}

void catchCube() {
  // 往下夹方块
  myDuoJi2.write(40);
  delay(500);
  myDuoJi2.write(20);
  delay(500);
  myDuoJi2.write(0);
  delay(500);

  // 爪子收紧
  myDuoJi4.write(100);
  delay(500);

  // 回到初始位置
  myDuoJi2.write(30);
  delay(500);
  myDuoJi2.write(50);
  delay(1000);
}

void throwCube() {
  // 第二个舵机向上
  myDuoJi3.write(30);
  delay(500);
  myDuoJi3.write(60);
  delay(500);

  // 向前（第三个舵机向下）
  myDuoJi2.write(30);
  delay(500);
  myDuoJi2.write(10);

  // 等垃圾桶识别开盖
  delay(2000);

  // 爪子松开
  myDuoJi4.write(45);
  delay(500);

  // 回到初始位置
  // 第三个舵机向上
  myDuoJi2.write(25);
  delay(500);
  myDuoJi2.write(50);
  delay(500);
  // 第二个舵机向下
  myDuoJi3.write(30);
  delay(500);
  myDuoJi3.write(0);
  delay(500);
  // 底盘回正
  myDuoJi1.write(75);
  delay(1000);
}

void classify(int x, int y) {
  if(x==HIGH && y==LOW) { // 蓝色
    myDuoJi1.write(60);
    delay(500);
  }
  if(x==LOW && y==HIGH) { // 绿色
    myDuoJi1.write(80);
    delay(500);
  }
}

void loop() {
  // 初始
  myDuoJi1.write(75); // 底盘
  myDuoJi2.write(50); // 第三个舵机
  myDuoJi3.write(0); // 第二个舵机
  myDuoJi4.write(45); // 爪子
  delay(1000);

  // 扔进垃圾桶
  // step1: 夹方块
  catchCube();
  // step2: 识别方块类别
  x=digitalRead(6); // 读取来自树莓派的输入
  y=digitalRead(7); // 读取来自树莓派的输入
  classify(x, y);
  // step3: 扔方块
  throwCube();
  delay(5000);
}
