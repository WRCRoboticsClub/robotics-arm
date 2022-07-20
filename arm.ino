// Stepper Motor X
  #define stepx 2
  #define dirx 5 // X.DIR
  #define stepy 3
  #define diry 6
  #define stepz 4
  #define dirz 7
  int input;
 void setup() {
 // Sets the two pins as Outputs
 pinMode(stepx,OUTPUT); 
 pinMode(dirx,OUTPUT);
 pinMode(stepy,OUTPUT); 
 pinMode(diry,OUTPUT);
 pinMode(stepz,OUTPUT); 
 pinMode(dirz,OUTPUT);
 Serial.begin(9600);
 }
 void loop() {
  if (Serial.available()>0)
  {
    input=Serial.read();
    Serial.println(input);
    if(input=='b')
    {
      digitalWrite(dirx,HIGH);//clockwise rotation
      for(int x=0;x<10;x++)
        {
          digitalWrite(stepx,HIGH);//10 step movement
          delayMicroseconds(500);//controls speed of motor
          digitalWrite(stepx,LOW);
          delayMicroseconds(500);
        }
    }
    if(input=='c')//for reverse
    {
      digitalWrite(dirx,LOW);//clockwise rotation
      for(int x=0;x<10;x++)
        {
          digitalWrite(stepx,HIGH);//10 step movement
          delayMicroseconds(500);//controls speed of motor
          digitalWrite(stepx,LOW);
          delayMicroseconds(500);
        }
    }
//    //for arm
if(input=='e')
    {
      digitalWrite(diry,HIGH);//clockwise rotation
      for(int x=0;x<10;x++)
        {
          digitalWrite(stepy,HIGH);//10 step movement
          delayMicroseconds(500);//controls speed of motor
          digitalWrite(stepy,LOW);
          delayMicroseconds(500);
        }
    }
    if(input=='f')//for reverse
    {
      digitalWrite(diry,LOW);//clockwise rotation
      for(int x=0;x<10;x++)
        {
          digitalWrite(stepy,HIGH);//10 step movement
          delayMicroseconds(500);//controls speed of motor
          digitalWrite(stepy,LOW);
          delayMicroseconds(500);
        }
    }
    //for shoulder
    if(input=='g')
    {
      digitalWrite(dirz,HIGH);//clockwise rotation
      for(int x=0;x<10;x++)
        {
          digitalWrite(stepz,HIGH);//10 step movement
          delayMicroseconds(500);//controls speed of motor
          digitalWrite(stepz,LOW);
          delayMicroseconds(500);
        }
    }
    if(input=='h')//for reverse
    {
      digitalWrite(dirz,LOW);//clockwise rotation
      for(int x=0;x<10;x++)
        {
          digitalWrite(stepz,HIGH);//10 step movement
          delayMicroseconds(500);//controls speed of motor
          digitalWrite(stepz,LOW);
          delayMicroseconds(500);
        }
    }
  }




  
// digitalWrite(dirx,HIGH); // Enables the motor to move in a particular direction
// // Makes 200 pulses for making one full cycle rotation
// for(int x = 0; x < 10; x++) {
// digitalWrite(stepx,HIGH); 
// delayMicroseconds(500); 
// digitalWrite(stepy,LOW); 
// delayMicroseconds(500); 
//}
// delay(1000); // One second delay
// 
 }
