#include<Servo.h>
Servo myservo;
Servo myservo1;
int input;
int o=30;
int c=90;
int wwc=60;
void setup() {
  myservo.attach(9);
  myservo1.attach(10);
  Serial.begin(9600);
  // put your setup code here, to run once:
}

void loop() {
  if(Serial.available()>0){
    input=Serial.read();
    if(input=='a'){
     
  myservo.write(o);
  delay(500);}
  if(input=='b'){
  
  myservo.write(c);
  delay(500);
  // put your main code here, to run repeatedly:
    }
    //wrist
    
    if(input=='x'){
     
      myservo1.write(wwc-10);
      delay(500);
      return;
      }
 // if(input=='y'){
  
  //myservo1.write(wwc+10);
  //delay(500);
  // put your main code here, to run repeatedly:
   // }
    //myservo1.write(90);
}
}
