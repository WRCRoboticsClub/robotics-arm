#include <Servo.h>
#define ser1 100 //second motor //60
#define ser2 54 //third servo
#define ser3 80
#define ser4 78 //fourth servo  g=contract h=expand 52
#define ser5 90
#define ser6 90

Servo servo01;
Servo servo02;
Servo servo03;
Servo servo04;
Servo servo05;//first servo
Servo servo06;
int se1=ser1,se2=ser2,se3=ser3,se4=ser4,se5=ser5,se6=ser6;

//gripper sig =blue v+=black 0v=purple
//  //blue=8 black 7 green 6

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
  servo04.write(ser4);
  
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
     if(se2<90){
      se2=se2+2;  }
      Serial.println(se2);   
      servo02.write(se2);
      
        delay(50);
    }
    if(letter=='d'){ //down dir clockwise rotation
       Serial.println("se2 -2");
      if(se2>40){se2=se2-2;  }
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
          if(se3>70){
      se3=se3-10;  }
      Serial.println(se3);   
      servo03.write(se3);
        delay(50);
      
    }


/////////Hand parttt................................

    if(letter=='g'){//third motor up
        Serial.println("se4 +10");
      if(se4<100){se4=se4+2;  }
      Serial.println(se4);   
      servo04.write(se4);
        delay(50);
      
    }
     if(letter=='h'){
        if (se4 >0){se4=se4-2;}
        Serial.println("se4 -10");
      Serial.println(se4);   
      servo04.write(se4);
        delay(50);
      
    }

//...................................................    
    if(letter=='i'){//hand rotation for one direction open
       Serial.println("se5 +10");
      if(se5<110){se5=se5+2;}  
      Serial.println(se5);   
      servo05.write(se5);
        delay(50);
      
    }
     if(letter=='j'){//hand rotation for another direction close
            Serial.println("se5 -10");
      if(se5>10){se5=se5-2; } 
      Serial.println(se5);   
      servo05.write(se5);
        delay(50);
      
    }
    if (letter == 'k')
    {
      for (se5;se5<90;se5++)
      {
        servo05.write(se5);
        delay(100);
      }
    }
    if (letter=='z')
    {
      servo02.write(ser2);
    servo01.write(ser1);
    servo03.write(ser3);
    servo04.write(78);
    servo05.write(90);

    }
    if(letter =='p')
    {
      servo02.write(66);  //bringing up
        delay(1000);
        servo03.write(130); //grippr open
        delay(1000);
        Serial.println(se5);

        for(se5;se5<110;se5++){ //rotataion
          
        servo05.write(se5);
        delay(100);
        }
        delay(1000);
        servo01.write(110);//bringing down
        delay(1000);
        servo04.write(72);
      delay(1000);
      //servo03.write(80);
        Serial.println("gripper close");
        delay(1000);
        servo02.write(54);
        delay(1000);
              servo03.write(80);

        delay(1000);
        servo02.write(64);
        delay(1000);
        servo01.write(90);
        delay(1000);
        for(se5;se5>48;se5--){
          //Serial.print("looped");
        servo05.write(se5);
        delay(100);
        }
        servo02.write(50);
        delay(1000);
        servo02.write(40);
        delay(1000);
        servo03.write(110);//gripper open
        delay(1000);
         for (se5;se5<90;se5++)
      {
        servo05.write(se5);
        delay(100);
      }
      servo03.write(80);      
        
    
        
            }//end of p
if(letter =='q')
    {
         servo02.write(66);  //bringing up
        delay(1000);
        servo03.write(130); //grippr open
        delay(1000);
        Serial.println(se5);

        for(se5;se5<110;se5++){ //rotataion
          
        servo05.write(se5);
        delay(100);
        }
        delay(1000);
        servo01.write(110);//bringing down
        delay(1000);
        servo04.write(72);
      delay(1000);
      //servo03.write(80);
        Serial.println("gripper close");
        delay(1000);
        servo02.write(54);
        delay(1000);
              servo03.write(80);

        delay(1000);
        servo02.write(64);
        delay(1000);
        servo01.write(90);
        delay(1000);
        for(se5;se5>70;se5--){
          //Serial.print("looped");
        servo05.write(se5);
        delay(100);
        }
        servo02.write(50);
        delay(1000);
        servo02.write(40);
        delay(1000);
        servo03.write(110);//gripper open
        delay(1000);
         for (se5;se5<90;se5++)
      {
        servo05.write(se5);
        delay(100);
      }
      servo03.write(70);      
        
    
       }//end of p




//.........................................................

  }
}