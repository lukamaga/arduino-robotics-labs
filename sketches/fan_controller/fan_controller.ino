#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

#define motorPin 9      
#define buttonPin 8     

int motorSpeed = 0;     
int buttonState = 0;    
int lastButtonState = 0;
int powerLevel = 0;     
void setup() {
  pinMode(motorPin, OUTPUT);       
  pinMode(buttonPin, INPUT_PULLUP); 
  
  lcd.begin(16, 2);                
  lcd.setCursor(0, 0);
  lcd.print("Fan Control");        
  delay(2000);
  lcd.clear();
}

void loop() {
  buttonState = digitalRead(buttonPin);  
  
  if (buttonState == LOW && lastButtonState == HIGH) {
    powerLevel++;                   
    if (powerLevel > 3) {          
      powerLevel = 0;
    }
    updateMotorSpeed();              
    displayPowerLevel();             
  }
  
  lastButtonState = buttonState;    
  delay(50);                      
}

void updateMotorSpeed() {
  switch (powerLevel) {
    case 0:
      motorSpeed = 0;           
      break;
    case 1:
      motorSpeed = 16;           
      break;
    case 2:
      motorSpeed = 32;          
      break;
    case 3:
      motorSpeed = 64;          
      break;
  }
  analogWrite(motorPin, motorSpeed);
}

void displayPowerLevel() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Fan Power:");

  lcd.setCursor(0, 1);
  switch (powerLevel) {
    case 0:
      lcd.print("Off");
      break;
    case 1:
      lcd.print("25%");
      break;
    case 2:
      lcd.print("50%");
      break;
    case 3:
      lcd.print("100%");
      break;
  }
}
