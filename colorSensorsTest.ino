#define s0 29      //Module pins wiring
#define s1 23
#define s2 24
#define s3 27
#define out 26

#define s01 40      //Module pins wiring
#define s11 42
#define s21 41
#define s31 43
#define out1 39


int data=0;        //This is where we're going to stock our values
int r=0;
int g=0;
int b=0;
int c=0;

int data1=0;        //This is where we're going to stock our values
int r1=0;
int g1=0;
int b1=0;
int c1=0;
void setup() 
{
   pinMode(s0,OUTPUT);    //pin modes
   pinMode(s1,OUTPUT);
   pinMode(s2,OUTPUT);
   pinMode(s3,OUTPUT);
   pinMode(out,INPUT);

   pinMode(s01,OUTPUT);    //pin modes
   pinMode(s11,OUTPUT);
   pinMode(s21,OUTPUT);
   pinMode(s31,OUTPUT);
   pinMode(out1,INPUT);

   Serial.begin(115200);   //intialize the serial monitor baud rate
   
   digitalWrite(s0,HIGH); //Putting S0/S1 on HIGH/HIGH levels means the output frequency scalling is at 100% (recommended)
   digitalWrite(s1,HIGH); //LOW/LOW is off HIGH/LOW is 20% and LOW/HIGH is  2%
   
   digitalWrite(s01,HIGH); //Putting S0/S1 on HIGH/HIGH levels means the output frequency scalling is at 100% (recommended)
   digitalWrite(s11,HIGH); //LOW/LOW is off HIGH/LOW is 20% and LOW/HIGH is  2%
   
}

void loop()                  //Every 2s we select a photodiodes set and read its data
{

   digitalWrite(s2,LOW);        //S2/S3 levels define which set of photodiodes we are using LOW/LOW is for RED LOW/HIGH is for Blue and HIGH/HIGH is for green
   digitalWrite(s3,LOW);
   r=GetData();                   //Executing GetData function to get the value

   digitalWrite(s2,LOW);
   digitalWrite(s3,HIGH);
   g=GetData();                   //Executing GetData function to get the value

   digitalWrite(s2,HIGH);
   digitalWrite(s3,HIGH);
   b=GetData();  

   digitalWrite(s21,LOW);        //S2/S3 levels define which set of photodiodes we are using LOW/LOW is for RED LOW/HIGH is for Blue and HIGH/HIGH is for green
   digitalWrite(s31,LOW);
   r1=GetData1();                   //Executing GetData function to get the value

   digitalWrite(s21,LOW);
   digitalWrite(s31,HIGH);
   g1=GetData1();                   //Executing GetData function to get the value

   digitalWrite(s21,HIGH);
   digitalWrite(s31,HIGH);
   b1=GetData1();  
   
   //Executing GetData function to get the value
   /*
Serial.print("r=");
Serial.print(r);
Serial.print("g=");
Serial.print(g);
Serial.print("b=");
Serial.println(b);
*/
  if(r-g<-2 && r-b<-2)
Serial.println("the color is orange");  
else if( g-r<0 && r>10 )
Serial.println("the color is blue");  
 if(r1-g1<-2 && r1-b1<-2)
Serial.println("the color 1 is orange");  
else if( g1-r1<0 && r1>10 )
Serial.println("the color 1 is blue"); 
  //else
//Serial.println("the color is white");  

  delay(5);

}

int GetData(){
   data=pulseIn(out,LOW);       //here we wait until "out" go LOW, we start measuring the duration and stops when "out" is HIGH again
  
   return data;          //The higher the frequency the lower the duration
   delay(20);
}
int GetData1(){
   data1=pulseIn(out1,LOW);       //here we wait until "out" go LOW, we start measuring the duration and stops when "out" is HIGH again
  
   return data1;          //The higher the frequency the lower the duration
   delay(20);
}
