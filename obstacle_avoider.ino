
#include <NewPing.h>

#define SONAR_NUM 3      // Number of sensors.
#define MAX_DISTANCE 150 // Maximum distance (in cm) to ping.

NewPing sonar[SONAR_NUM] = {   // Sensor object array.
  NewPing(44, 45, MAX_DISTANCE), // Each sensor's trigger pin, echo pin, and max distance to ping. 
  NewPing(42, 43, MAX_DISTANCE), 
  NewPing(40, 41, MAX_DISTANCE)
};
int output=70;
int output2=80;

void setup() {
  Serial2.begin(9600); 
    for(int i=0;i<=13;i++){
pinMode(i,OUTPUT);
}
}
void loop() {



 
  float sonar1, sonar2, sonar3;
  delay(50); 
  for (uint8_t i = 0; i < SONAR_NUM; i++) { // Loop through each sensor and display results.
    
   int iterations = 3;
   unsigned int  duration = sonar[i].ping_median(iterations);
   float distance = (duration / 2) * 0.0343;
   Serial2.print("sensor ");
   Serial2.print(i+1);
   Serial2.print("= ");
   Serial2.print( distance);
   Serial2.print("cm  ");
   if(i==0)
   {sonar1=distance;}
   if(i==1)
   {sonar2=distance;}
   if(i==2)
   { sonar3=distance;}
  }
  Serial2.println();
  Serial2.println(sonar1);
  Serial2.println(sonar2);
  Serial2.println(sonar3);
  if((sonar1>30.00 || sonar1==0) && (sonar2 > 30.00 || sonar2==0) && (sonar3 > 30.00 || sonar3==0)) //0-0-0
  {//forward
    
  digitalWrite(0,LOW);
  digitalWrite(1,HIGH);
  digitalWrite(2,HIGH);
  digitalWrite(3,LOW);
  analogWrite(11,output);
  analogWrite(12,output2);                        
  }
 
  else if((sonar1>30.00 || sonar1==0) && (sonar2 > 30.00 || sonar2==0) && (sonar3 <30.00))//0-0-1
  {//left
    digitalWrite(0,HIGH);
  digitalWrite(1,LOW);
  digitalWrite(2,HIGH);
  digitalWrite(3,LOW);
  analogWrite(11,output);
  analogWrite(12,output2);
}
  else if((sonar1>30.00 || sonar1==0) && (sonar2 <30.00) && (sonar3 <30.00))//0-1-1
  {
    //left
    digitalWrite(0,HIGH);
  digitalWrite(1,LOW);
  digitalWrite(2,HIGH);
  digitalWrite(3,LOW);
  analogWrite(11,output);
  analogWrite(12,output2);
}
  else if((sonar1<30.00) && (sonar2 >30.00 || sonar2==0) && (sonar3 >30.00 || sonar3==0))//1-0-0
  {
    //right
  digitalWrite(0,LOW);
  digitalWrite(1,HIGH);
  digitalWrite(2,LOW);
  digitalWrite(3,HIGH);
  analogWrite(11,output);
  analogWrite(12,output2);
  }
   else if((sonar1<30.00) && (sonar2 <30.00) && (sonar3 >30.00 || sonar3==0))//1-1-0
   {
    //right
  digitalWrite(0,LOW);
  digitalWrite(1,HIGH);
  digitalWrite(2,LOW);
  digitalWrite(3,HIGH);
  analogWrite(11,output);
  analogWrite(12,output2);
   }
   else if((sonar1>30.00 || sonar1==0) && (sonar2 <30.00) && (sonar3 >30.00 || sonar3==0))//0-1-0
   {
    //right
   digitalWrite(0,LOW);
  digitalWrite(1,HIGH);
  digitalWrite(2,LOW);
  digitalWrite(3,HIGH);
  analogWrite(11,output);
  analogWrite(12,output2);
   }
  else if((sonar1<30.00) && (sonar2 >30.00 ||sonar2==0) && (sonar3 <30.00)) //1-0-1
   {
    //back 2 sec
  digitalWrite(4,LOW);
  digitalWrite(2,HIGH);
  analogWrite(3,150);
  digitalWrite(6,LOW);
  digitalWrite(7,HIGH);
  analogWrite(9,150);
  delay(500);
    //left 2 sec
  digitalWrite(4,LOW);
  digitalWrite(2,HIGH);
  analogWrite(3,150);
  digitalWrite(6,HIGH);
  digitalWrite(7,LOW);
  analogWrite(9,150);
  delay(500);
   }
   else if ((sonar1<30.00) && (sonar2 <30.00) && (sonar3 <30.00))//1-1-1
   {
      //back 2 sec
  digitalWrite(0,HIGH);
  digitalWrite(1,LOW);
  digitalWrite(2,LOW);
  digitalWrite(3,HIGH);
  analogWrite(11,output);
  analogWrite(12,output2);
    //left 2 sec
    digitalWrite(0,HIGH);
  digitalWrite(1,LOW);
  digitalWrite(2,HIGH);
  digitalWrite(3,LOW);
  analogWrite(11,output);
  analogWrite(12,output2);
   }
   
   }
