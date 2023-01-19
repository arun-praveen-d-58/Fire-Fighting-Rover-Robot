#include <Servo.h>  
Servo myservo;
 
int pos = 0;    
boolean fire = false;
 
#define Left 3     
#define Right 4    
#define Forward 5   

#define LM1 6      
#define LM2  7      
#define RM1 8       
#define RM2 9       
#define pump 10    

int val;

void setup() {

Serial.begin(9600);

  pinMode(Left, INPUT);
 
  pinMode(Right, INPUT);
  
  pinMode(Forward, INPUT);

  pinMode(pump, OUTPUT);
  
  pinMode(LM1,OUTPUT);

  pinMode(LM2,OUTPUT);

  pinMode(RM1,OUTPUT);

  pinMode(RM2,OUTPUT);

  myservo.attach(12);
  myservo.write(90); 

}

void loop()

{
 myservo.write(90);   
 
   
    if (digitalRead(Left) ==1 && digitalRead(Right)==1 && digitalRead(Forward) ==1) 
    {
    
    digitalWrite(LM1, HIGH);
    digitalWrite(LM2, HIGH);
    digitalWrite(RM1, HIGH);
    digitalWrite(RM2, HIGH);
    }
    
    else if (digitalRead(Forward) ==0) 
    {
    digitalWrite(LM1, LOW);
    digitalWrite(LM2, HIGH);
    digitalWrite(RM1, HIGH);
    digitalWrite(RM2, LOW);
    fire = true;
    }
    
    else if (digitalRead(Left) ==0)
    {
   digitalWrite(LM1, LOW);
    digitalWrite(LM2, HIGH);
    digitalWrite(RM1, HIGH);
    digitalWrite(RM2, HIGH);
    }
    
    else if (digitalRead(Right) ==0) 
    {
    digitalWrite(LM1, HIGH);
    digitalWrite(LM2, HIGH);
    digitalWrite(RM1, HIGH);
    digitalWrite(RM2, LOW);
    }
    
    delay(300);

     while (fire == true)
     {
      put_off_fire();
     } 

    Serial.println(data);

}
void Stop()

{

digitalWrite(RM2,LOW);

digitalWrite(RM1,LOW);

digitalWrite(LM1,LOW);

digitalWrite(LM2,LOW);

}

void put_off_fire()
{
    delay (500);
 
    digitalWrite(LM1, HIGH);
    digitalWrite(LM2, HIGH);
    digitalWrite(RM1, HIGH);
    digitalWrite(RM2, HIGH);
    
   digitalWrite(pump, HIGH);

   delay(500);
    
    for (pos = 50; pos <= 130; pos += 1) { 
    myservo.write(pos); 
    delay(10);  
  }
  for (pos = 130; pos >= 50; pos -= 1) { 
    myservo.write(pos); 
    delay(10);
  }
  
  digitalWrite(pump,LOW);
  
  myservo.write(90);
  
  fire=false;
}
