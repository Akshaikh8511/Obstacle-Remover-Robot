#define RMS 2
#define RMP 3
#define RMN 4
#define LMS 5
#define LMP 6
#define LMN 7

#include <Servo.h>
Servo servo_1;
int i = 0;
int j = 0;
int k = 0;

const int trigPin = 11;
const int echoPin = 12;

float duration, distance;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(RMS, OUTPUT);
  pinMode(RMP, OUTPUT);
  pinMode(RMN, OUTPUT);
  pinMode(LMS, OUTPUT);
  pinMode(LMP, OUTPUT);
  pinMode(LMN, OUTPUT);
  digitalWrite(RMS, HIGH); 
  digitalWrite(LMS, HIGH);
  
  servo_1.attach(10);
  Serial.begin(9600);
  }

void loop() {
  
  sense();
  
  if ( distance > 15 ){
 
    forward();
  }
  else {

    stops();
  }
  if (distance <15){
    for (i = 0; i <= 180; i += 1) {
      servo_1.write(i);
      delay(5); // Wait for 5 millisecond(s)
    }
    for (k = 180; k >= 0; k -= 1) {
      servo_1.write(k);
      delay(5); // Wait for 5 millisecond(s)
    }
  }
    
}

void sense() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = (duration*.0343)/2;
  delay(100);
}

void forward() {
  digitalWrite(RMS, HIGH); 
  digitalWrite(LMS, HIGH);
  digitalWrite(RMP, HIGH);
  digitalWrite(RMN, LOW);
  digitalWrite(LMP, HIGH);
  digitalWrite(LMN, LOW);
  
}

void stops(){
  digitalWrite(RMP, LOW);
  digitalWrite(RMN, LOW);
  digitalWrite(LMP, LOW);
  digitalWrite(LMN, LOW);
 
}
