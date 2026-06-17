#include<Servo.h>
int buzzer = 6;
int trig =8;
int echo= 9;
int pot = A0;
long duration;
float distance;
Servo myservo;
int value;
int angle;
int r =10;
int g = 11;
int b = 3;
void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  pinMode(pot,INPUT);
  myservo.attach(5);
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  pinMode(buzzer,OUTPUT);
  pinMode(r,OUTPUT);
  pinMode(g,OUTPUT);
  pinMode(b,OUTPUT);


}

void loop() {
  // put your main code here, to run repeatedly:
  //tone(buzzer, 700);
  
  


  for(int i = 0; i<= 180; i+=5){
    myservo.write(i);
    checkdistance();
    delay(30);
  }
  for(int i = 180; i>= 0; i-=5){
    myservo.write(i);
    checkdistance();
    delay(30);
  }
  
}
void checkdistance(){
  digitalWrite(trig,LOW);
  delay(10);
  digitalWrite(trig,HIGH);
  delayMicroseconds(100);
  digitalWrite(trig,LOW);

  duration = pulseIn(echo,HIGH);
  distance = duration * 0.017;
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println("cm");
  
  if(distance < 20){
    digitalWrite(r,HIGH);
    digitalWrite(g,LOW);
    digitalWrite(b,LOW);
    tone(buzzer,700);
    
    

  }
  if(distance > 20){
    digitalWrite(r,LOW);
    digitalWrite(b,HIGH);
    digitalWrite(g,LOW);
    noTone(buzzer);
    
  }
}
