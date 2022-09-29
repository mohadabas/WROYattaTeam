// ---------------------------------------------------------------- //
// Arduino Ultrasoninc Sensor HC-SR04
// Re-writed by Arbi Abdul Jabbaar
// Using Arduino IDE 1.8.7
// Using HC-SR04 Module
// Tested on 17 September 2019
// ---------------------------------------------------------------- //
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

// defines variables
long duration; // variable for the duration of sound wave travel
int distance; // variable for the distance measurement


// defines variables
long duration1; // variable for the duration of sound wave travel
int distance1; // variable for the distance measurement

// defines variables
long duration2; // variable for the duration of sound wave travel
int distance2; // variable for the distance measurement

void setup() {
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

  


  
 
  distance = readultra(trigPin,echoPin);
  // Displays the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

 
  distance1 = readultra(trigPin1,echoPin1);
  // Displays the distance on the Serial Monitor
  Serial.print("Distance1: ");
  Serial.print(distance1);
  Serial.println(" cm");


  distance2=readultra(trigPin2,echoPin2);
  Serial.print("Distance2: ");
  Serial.print(distance2);
  Serial.println(" cm");
  if(distance2>=10)
  {
      analogWrite(DCfpin, 0);
            analogWrite(DCbpin, 0);


  }else
  {
      analogWrite(DCbpin, 0);
            analogWrite(DCfpin, 0);


  }
  
  delay(200);
}
