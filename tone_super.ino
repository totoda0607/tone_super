#include<Servo.h>
#define TRIG 2 // 초음파센서 TRIG 2번핀 할당
#define ECHO 3 // 초음파센서 ECHO 3번핀 할당
int button = 5;  //버튼센서 입력 5번핀 할당
 
Servo servo;
boolean isNear = false;
 
void setup(){
  pinMode(TRIG,OUTPUT); // 아두이노 송신
  pinMode(ECHO,INPUT);  // 아두이노 수신
  pinMode(button,INPUT); // 아두이노 수신
  servo.attach(9);      // 서보모터 제어 9번핀 할당
  servo.write(180);     // 서보모터 초기각도 180도 셋팅
}
void loop()
{
  digitalWrite(TRIG,LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG,HIGH);
  delayMicroseconds(5);
  digitalWrite(TRIG,LOW);
 
  long distance = pulseIn(ECHO,HIGH)/58; // 초음파 간격   
   
  //만약 버튼이 눌러졌다면
  if (digitalRead(button)) { 
      servo.write(0); // 서보모터 0도로 회전
  }
  
  else if(distance < 10){ // 만약 10cm보다 가까우운 곳에 물체가 있으면 
  delay(5000); // 5초 뒤에
  servo.write(180); // 서보모터 180도로 회전
  }
}