

#include <Ultrasonic.h>
#include <Servo.h>
Servo myservo;
const int triggerPin = 4;
const int echoPin = 2;
const int buzzerPin = 5;
const int ledPin = 18;
const int threshold = 7; 

    // threshold distance in 7 cm
Ultrasonic ultrasonic(triggerPin, echoPin);
int pos = 0;  // analog pin used to connect the potentiometer
int val;    // variable to read the value from the analog pin
void setup() {
  Serial.begin(9600);
  pinMode(buzzerPin, OUTPUT); 
  pinMode(ledPin, OUTPUT);
  myservo.attach(21);
   }
void loop() { 
  long distance = ultrasonic.distanceRead();
  if (distance <= threshold) {
      digitalWrite(buzzerPin, HIGH);
      digitalWrite(ledPin, HIGH);
      Serial.print("Object detected within "); 
      Serial.print(threshold); Serial.println("cm!");
      myservo.write(1);   
         }
  else {
        digitalWrite(buzzerPin, LOW);
        digitalWrite(ledPin, LOW);
        Serial.print("Distance: "); 
        Serial.print(distance);
        Serial.println("cm");
         }
  delay(100); 
}