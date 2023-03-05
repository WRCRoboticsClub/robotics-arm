#include <Servo.h>
#define ser1 70 //second motor
#define ser2 20 //third servo
#define ser3 80
#define ser4 90
#define ser5 90
#define ser6 90

Servo servo01;
Servo servo02;
Servo servo03;
Servo servo04;
Servo servo05;
Servo servo06;
int se1=ser1,se2=ser2,se3=ser3,se4=ser4,se5=ser5,se6=ser6;

//gripper sig =blue v+=black 0v=purple


void setup() {
  servo01.attach(5);
  servo02.attach(6);
  servo03.attach(7);
  servo04.attach(8);
  servo05.attach(9);
  servo06.attach(10);

  Serial.begin(9600);
  servo02.write(se2);
  servo01.write(se1);
  servo03.write(se3);
  servo04.write(se4);
  servo04.write(se5);



}

void loop() {
  if(Serial.available()>0){
    char letter=Serial.read();



/////////body part..................

    if(letter=='a'){//clockwise rotation moving down
    
     Serial.println("se1 +2");
      if(se1<120){se1=se1+5;  }
      Serial.println(se1);   
      servo01.write(se1);
        delay(50);
    }
    if(letter=='b'){//anticlockwise rotation  moving up
     Serial.println("se1-10");
       if(se1>60){se1=se1-5;}
       Serial.println(se1);
      servo01.write(se1);
        delay(50);
         servo01.write(se1+1);
    }
    

//..............................
    if(letter=='c'){//first motor up up dir anticlock wise
     Serial.println("se2 +10");
     if(se2<80){
      se2=se2+2;  }
      Serial.println(se2);   
      servo02.write(se2);
      
        delay(50);
    }
    if(letter=='d'){ //down dir clockwise rotation
       Serial.println("se2 -2");
      if(se2>20){se2=se2-2;  }
      Serial.println(se2);   
      servo02.write(se2);
        delay(50);
      
    }

//..........................................


    if(letter=='e'){//second motor up 
      Serial.println("se3 +10");
      if(se3<150){
      se3=se3+10;}  
      Serial.println(se3);   
      servo03.write(se3);
        delay(50);
    }
    if(letter=='f'){
      
          Serial.println("se3 -10");
          if(se3>80){
      se3=se3-10;  }
      Serial.println(se3);   
      servo03.write(se3);
        delay(50);
      
    }


/////////Hand parttt................................

    if(letter=='g'){//third motor up
        Serial.println("se4 +10");
      se4=se4+2;  
      Serial.println(se4);   
      servo04.write(se4);
        delay(50);
      
    }
     if(letter=='h'){
        Serial.println("se4 -10");
      se4=se4-2;  
      Serial.println(se4);   
      servo04.write(se4);
        delay(50);
      
    }

//...................................................    
    if(letter=='i'){//hand rotation for one direction open
       Serial.println("se5 +10");
      se5=se5+10;  
      Serial.println(se5);   
      servo05.write(se5);
        delay(50);
      
    }
     if(letter=='j'){//hand rotation for another direction close
            Serial.println("se5 -10");
      se5=se5-10;  
      Serial.println(se5);   
      servo05.write(se1);
        delay(50);
      
    }
    if (letter=='z')
    {
      servo02.write(ser2);
    servo01.write(ser1);
    servo03.write(ser3);
    servo04.write(ser4);
    servo04.write(ser5);

    }


//.........................................................

  }
}