#include <LiquidCrystal.h>
#include <Servo.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

Servo gateServo;

const int trigPin = 9;
const int echoPin = 8;
const int buttonPin = 7;
const int buzzerPin = 10;
const int ledPin = 13;

bool systemOn = false; 
bool barrierOpen = false; 

void setup() {
  lcd.begin(16, 2);
  lcd.print("Barrier System");
  lcd.setCursor(0, 1);
  lcd.print("Press Button");
  delay(2000);
  lcd.clear();
  
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(buzzerPin, OUTPUT);
  pinMode(ledPin, OUTPUT);

  gateServo.attach(6);
  gateServo.write(0);  
}

void loop() {
  if (digitalRead(buttonPin) == LOW) {
    systemOn = !systemOn;  
    delay(500); 
    if (systemOn) {
      lcd.clear();
      lcd.print("System: ON");
      delay(500);
    } else {
      lcd.clear();
      lcd.print("System: OFF");
      delay(500);
    }
  }

  if (systemOn) {
    long distance = measureDistance();

    if (!barrierOpen) {
      lcd.clear();
      lcd.print("Scan your car");
    }

    if (distance > 5 && distance < 10 && !barrierOpen) { 
      openBarrier();
      delay(5000);  
      closeBarrier();
    }
  }
}

long measureDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH);
  return duration * 0.034 / 2; 
}

void openBarrier() {
  lcd.clear();
  lcd.print("Opening...");
  gateServo.write(90); 
  signalBarrier();      
  barrierOpen = true;   
}

void closeBarrier() {
  lcd.clear();
  lcd.print("Closing...");
  gateServo.write(0);  
  signalBarrier();     
  barrierOpen = false; 
}

void signalBarrier() {
  for (int i = 0; i < 5; i++) { 
    digitalWrite(ledPin, HIGH);
    tone(buzzerPin, 1000);
    delay(200);
    digitalWrite(ledPin, LOW);
    noTone(buzzerPin);
    delay(200);
  }
}
