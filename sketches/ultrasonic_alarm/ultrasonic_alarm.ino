#include <TimerOne.h>

const int trigPin = 9;
const int echoPin = 10;
const int buzzer = 11;
const int ledPin = 13;
const int buttonPin = 2;

long duration;
int distance;
int safetyDistance;
bool systemOn = false; 

unsigned long previousMillis = 0;
const long interval = 100;

volatile unsigned int timerCounter = 0;
unsigned long blinkPreviousMillis = 0;
const long blinkInterval = 500;     
bool blinkState = false;              

void setup() {
  pinMode(trigPin, OUTPUT);  
  pinMode(echoPin, INPUT);  
  pinMode(buzzer, OUTPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);

  attachInterrupt(digitalPinToInterrupt(buttonPin), toggleSystem, FALLING); 

  Timer1.initialize(1000000);
  Timer1.attachInterrupt(timerIsr);

  Serial.begin(9600);
}

void loop() {
  unsigned long currentMillis = millis(); 

  if (systemOn) {
    if (currentMillis - previousMillis >= interval) {
      previousMillis = currentMillis;

      triggerUltrasonicPulse();

      duration = pulseIn(echoPin, HIGH);

      distance = duration * 0.034 / 2;

      safetyDistance = distance;

      if (safetyDistance <= 50) {
        digitalWrite(buzzer, HIGH);
        digitalWrite(ledPin, HIGH);
        timerCounter = 0;
      } else {
        digitalWrite(buzzer, LOW);
        digitalWrite(ledPin, LOW);
      }

      Serial.print("Atstumas: ");
      Serial.println(distance);
    }

    if (timerCounter >= 5) {
      if (currentMillis - blinkPreviousMillis >= blinkInterval) {
        blinkPreviousMillis = currentMillis;
        blinkState = !blinkState;

        digitalWrite(buzzer, blinkState ? HIGH : LOW);
        digitalWrite(ledPin, blinkState ? HIGH : LOW);
      }

      if (safetyDistance <= 50) {  
        timerCounter = 0;          
        blinkState = false;       
        digitalWrite(buzzer, HIGH);
        digitalWrite(ledPin, HIGH);
      }
    }

  } else {
    digitalWrite(buzzer, LOW);
    digitalWrite(ledPin, LOW);
    timerCounter = 0; 
    blinkState = false;
  }
}

void triggerUltrasonicPulse() {
  unsigned long startMicros = micros();

  digitalWrite(trigPin, HIGH);
  while (micros() - startMicros < 10); 
  digitalWrite(trigPin, LOW);
}

void toggleSystem() {
  systemOn = !systemOn;  
  Serial.print("Sistema dabar: ");
  Serial.println(systemOn ? "ON" : "OFF");
}

void timerIsr() {
  if (systemOn) {
    timerCounter++;  
  } else {
    timerCounter = 0; 
  }
}
