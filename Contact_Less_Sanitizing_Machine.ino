#include <Servo.h>

const int trigPin = 8;
const int echoPin = 11;

long duration;
int distance;

Servo myservo; 

int pos = 0; 

void setup() {
  myservo.attach(9);  
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}

void loop()
{
  digitalWrite(trigPin, LOW);
  delay(1000);
  digitalWrite(trigPin, HIGH);
  delay(1000);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);

  distance = duration * 0.034/2;

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  myservo.write(180); 
  if(distance <= 15)
  {       
    myservo.write(0);
    }
}
