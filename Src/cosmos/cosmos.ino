

//#include <Servo.h> 
int Left_motor_back = 0;
int Left_motor_go = 1;
int Right_motor_go = 2;
int Right_motor_back = 3;

const int SensorFrontR = 4;
const int SensorFrontL = 7;
const int SensorD = 8;   //오른쪽
const int SensorB = 9;
const int SensorA = 10;
const int SensorC = 11;
const int SensorE = 12;


int SFL;
int SFR;
int Sa;
int Sb;
int Sc;
int Sd;
int Se;

void brake();

void setup()
{

  pinMode(Left_motor_go, OUTPUT); // PIN 0 (PWM)
  pinMode(Left_motor_back, OUTPUT); // PIN 1 (PWM)
  pinMode(Right_motor_go, OUTPUT);// PIN 2 (PWM) 
  pinMode(Right_motor_back, OUTPUT);// PIN 3 (PWM)
  pinMode(SensorD, INPUT);
  pinMode(SensorB, INPUT);
  pinMode(SensorA, INPUT);
  pinMode(SensorC, INPUT);
  pinMode(SensorE, INPUT);
  pinMode(SensorFrontR, INPUT);
  pinMode(SensorFrontL, INPUT);
}

void run()
{
  digitalWrite(Right_motor_go, HIGH);
  digitalWrite(Right_motor_back, LOW);
  analogWrite(Right_motor_go, 128);
  // 133
  analogWrite(Right_motor_back, 0);
  digitalWrite(Left_motor_go, HIGH);
  digitalWrite(Left_motor_back, LOW);
  analogWrite(Left_motor_go, 255);
  analogWrite(Left_motor_back, 0);
  //delay(time * 100);  
}

/*void run(int time)
{
digitalWrite(Right_motor_go,HIGH);
digitalWrite(Right_motor_back,LOW);
analogWrite(Right_motor_go,100);
analogWrite(Right_motor_back,0);
digitalWrite(Left_motor_go,HIGH);
digitalWrite(Left_motor_back,LOW);
analogWrite(Left_motor_go,100);
analogWrite(Left_motor_back,0);
delay(time * 100);
}*/


void brake()
{
  digitalWrite(Right_motor_go, LOW);
  digitalWrite(Right_motor_back, LOW);
  digitalWrite(Left_motor_go, LOW);
  digitalWrite(Left_motor_back, LOW);
  //delay(time * 100); 
}

void left()
{
  digitalWrite(Right_motor_go, HIGH);
    digitalWrite(Left_motor_go, LOW);
  digitalWrite(Right_motor_back, LOW);
    digitalWrite(Left_motor_back, LOW);
  analogWrite(Right_motor_go, 255);
    analogWrite(Left_motor_go, 0);
  analogWrite(Right_motor_back, 0);



  analogWrite(Left_motor_back, 0);
  //delay(time * 100);  
}
void left(int time)
{
digitalWrite(Right_motor_go,HIGH);
digitalWrite(Right_motor_back,LOW);
analogWrite(Right_motor_go,133);
analogWrite(Right_motor_back,0);
digitalWrite(Left_motor_go,LOW);
digitalWrite(Left_motor_back,LOW);
analogWrite(Left_motor_go,0);
analogWrite(Left_motor_back,0);
delay(time * 10);
}

void spin_left(int time)
{
  digitalWrite(Right_motor_go, HIGH);
    digitalWrite(Left_motor_go, LOW);
  digitalWrite(Right_motor_back, LOW);
    digitalWrite(Left_motor_back, HIGH);
  analogWrite(Right_motor_go, 255);
    analogWrite(Left_motor_go, 0);
  analogWrite(Right_motor_back, 0);
  analogWrite(Left_motor_back, 255);
  delay(time * 10);
  brake();
}


void right()
{
  digitalWrite(Left_motor_go, HIGH);
    digitalWrite(Right_motor_go, LOW);
    
  digitalWrite(Left_motor_back, LOW);
    digitalWrite(Right_motor_back, LOW);
  analogWrite(Left_motor_go, 255);
    analogWrite(Right_motor_go, 0);
  analogWrite(Left_motor_back, 0);
  analogWrite(Right_motor_back, 0);
//  digitalWrite(Left_motor_go, HIGH);
//  digitalWrite(Left_motor_back, LOW);
//  analogWrite(Left_motor_go, 255);
//  analogWrite(Left_motor_back, 0);
  //delay(time * 50); 
}

void right(int time)
{
digitalWrite(Right_motor_go,LOW);
digitalWrite(Right_motor_back,LOW);
analogWrite(Right_motor_go,0);
analogWrite(Right_motor_back,0);
digitalWrite(Left_motor_go,HIGH);
digitalWrite(Left_motor_back,LOW);
analogWrite(Left_motor_go,133);
analogWrite(Left_motor_back,0);
//delay(time * 100);
delay(time * 10);
brake();
}

/*
void spin_right(int time)
{
  digitalWrite(Right_motor_go, LOW);
  digitalWrite(Right_motor_back, HIGH);
  analogWrite(Right_motor_go, 0);
  analogWrite(Right_motor_back, 255);// 200->
  digitalWrite(Left_motor_go, HIGH);
  digitalWrite(Left_motor_back, LOW);
  analogWrite(Left_motor_go, 255); // 200-> 150 
  analogWrite(Left_motor_back, 0);
  delay(time * 1);
  brake();
}*/

void spin_right(int time)
{
  digitalWrite(Right_motor_go, LOW);
    digitalWrite(Left_motor_go, HIGH);
  digitalWrite(Right_motor_back, HIGH);
  digitalWrite(Left_motor_back, LOW);
  analogWrite(Right_motor_go, 0);
  analogWrite(Left_motor_go, 255); // 200-> 150 
  analogWrite(Right_motor_back, 255);
  analogWrite(Left_motor_back, 0);
  delay(time * 10);
  brake();
}


void back(int time)
{
  digitalWrite(Right_motor_go, LOW);
  digitalWrite(Right_motor_back, HIGH);
  analogWrite(Right_motor_go, 0);
  analogWrite(Right_motor_back, 200);
  digitalWrite(Left_motor_go, LOW);
  digitalWrite(Left_motor_back, HIGH);
  analogWrite(Left_motor_go, 0);
  analogWrite(Left_motor_back, 200);
  delay(time * 100);
}

void run(int time)
{
  digitalWrite(Right_motor_go, HIGH);
  digitalWrite(Right_motor_back, LOW);
  analogWrite(Right_motor_go, 128); //120X
  analogWrite(Right_motor_back, 0);
  digitalWrite(Left_motor_go, HIGH);
  digitalWrite(Left_motor_back, LOW);
  analogWrite(Left_motor_go, 128); // 133->135 100x 120X minimum 128
  analogWrite(Left_motor_back, 0);
  delay(time * 10);
}

void brake(int time)
{
  digitalWrite(Right_motor_go, LOW);
  digitalWrite(Right_motor_back, LOW);
  digitalWrite(Left_motor_go, LOW);
  digitalWrite(Left_motor_back, LOW);
  delay(time * 100);
}

void wait_long_run(){
  run(12);
  
  brake(1);
}
void wait_run(){
  run(6);
  brake(1);
}

void wait_spin_right(){
  spin_right(10);
  brake(2);
}
void wait_spin_left(){
  spin_left(10);
  brake(2);
}


void wait_right(){
  right(5);
//  delay(2);
  brake(2);
}
void spin_right_90(){
  spin_right(13);
//  delay(2);
  brake(2);
}
void spin_right_180(){
  spin_right(30);
//  delay(2);
  brake(2);
}
void spin_left_90(){
  spin_left(13);
//  delay(2);
  brake(2);
}
void wait_left(){
  left(5);
//    delay(2);
  brake(2);
}

void loop()
{

  while (1)
  {

    Sd = digitalRead(SensorD); // 오른쪽
    Sb = digitalRead(SensorB);
    Sa = digitalRead(SensorA);
    Sc = digitalRead(SensorC);
    Se = digitalRead(SensorE); // 왼쪽

    // 아래 형식 참조.
    //         SFR---SFL
    // E -----C----A----B------D

    SFR = digitalRead(SensorFrontR);
    SFL = digitalRead(SensorFrontL);

    // : 움직일 코드 삽입

    
    // run();

    /*
    if(SFL ==LOW && SFR == LOW)
    spin_right(20);// 15->20
    else if(SFL ==HIGH && SFR == LOW)
    left();
    else if(SFL ==LOW && SFR == HIGH)
    right();
    else
    wait_run();
    */


    //Serial.println(analogRead(10)); //
if (SFL == LOW && SFR == LOW) {//front 모두 흰색이면...
  if (Sd == LOW && Se == HIGH) {wait_right();spin_right(5);}
  else if (Sd == HIGH && Se == LOW) {wait_left();spin_left(5);}
  else if (Sd == LOW && Se == LOW) {spin_right_90();wait_long_run();}
  else spin_right_180(); ////
}
else if (SFL == HIGH && SFR == HIGH){ //검은색 && 검은색
  if (Sd == LOW && Se == HIGH) {spin_right_90();wait_long_run();}  //
  else if (Sd == HIGH && Se == HIGH) wait_run(); // 흰색 && 흰색
  else if (Sd == HIGH && Se == LOW) wait_left();
  else wait_right(); ///////
}
else if (SFL == LOW && SFR == HIGH){
 wait_right();

}
else if (SFL == HIGH && SFR == LOW){
 wait_left();
}


    
  }
}








