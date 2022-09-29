#include <Servo.h>

//right ultra sonic
#define echoPin 12 // attach pin D2 Arduino to pin Echo of HC-SR04
#define trigPin 8 //attach pin D3 Arduino to pin Trig of HC-SR04

//left ultra sonic

#define echoPin1 11 // attach pin D2 Arduino to pin Echo of HC-SR04
#define trigPin1 9 //attach pin D3 Arduino to pin Trig of HC-SR04

//front ultra sonic


#define echoPin2 13 // attach pin D2 Arduino to pin Echo of HC-SR04
#define trigPin2 10 //attach pin D3 Arduino to pin Trig of HC-SR04

#define DCfpin 5 //attach pin 5 to Dc motor forward motion
#define DCbpin 4 //attach pin 4 to Dc motor backward motion
#define ServoPin 3 //attach pin 4 to servo motor


// defines variables
long duration; // variable for the duration of sound wave travel
int DLeft; // variable for the distance measurement
Servo myservo;

// defines variables
long duration1; // variable for the duration of sound wave travel
int DRight; // variable for the distance measurement

// defines variables
long duration2; // variable for the duration of sound wave travel
int DFront; // variable for the distance measurement

void setup() {
  myservo.attach(3);
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT
  
  pinMode(trigPin1, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin1, INPUT); // Sets the echoPin as an INPUT
  
  pinMode(trigPin2, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin2, INPUT); // Sets the echoPin as an INPUT

  pinMode(DCfpin, OUTPUT); // Sets the forwardpin as an OUTPUT
  pinMode(DCbpin, OUTPUT); // Sets the backward as an OUTPUT


  
  Serial.begin(115200); // // Serial Communication is starting with 9600 of baudrate speed
  Serial.println("Ultrasonic Sensor HC-SR04 Test"); // print some text in Serial Monitor
  Serial.println("with Arduino UNO R3");
}
void Sright(int a)
{
  myservo.write(180);
  delay(a);
  myservo.write(90);

}
void Sleft(int a)
{
  myservo.write(0);
  delay(a);
  myservo.write(90);

}

int readultra(int a,int b){
  int d=0;
  // Clears the trigPin condition
  digitalWrite(a, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(a, HIGH);
  delayMicroseconds(10);
  digitalWrite(a, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration2 = pulseIn(b, HIGH);
  // Calculating the distance
  d = duration2 * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
  // Displays the distance on the Serial Monitor
  
  return d;
  
}
void loop() {

  


  
 
  DLeft = readultra(trigPin,echoPin);
  // Displays the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.print(DLeft);
  Serial.println(" cm");

 
  DRight = readultra(trigPin1,echoPin1);
  // Displays the distance on the Serial Monitor
  Serial.print("Distance1: ");
  Serial.print(DRight);
  Serial.println(" cm");


  DFront = readultra(trigPin2,echoPin2);
  Serial.print("Distance2: ");
  Serial.print(DFront);
  Serial.println(" cm");

  analogWrite(DCfpin, 180);

  if (DFront < 40) {
        Sleft(120);
        analogWrite(DCfpin, 250);
        delay(1000);
        Sright(120);
//      DRight = readultra(trigPin1,echoPin1);/
      
    } else if (DRight < 40) {
        Sleft(120);
        analogWrite(DCfpin, 250);
        delay(300);
        Sright(120);
//      DRight = readultra(trigPin1,echoPin1);/
    } 
   
   
      


      


      //Sright(150);


  
  delay(200);
}
