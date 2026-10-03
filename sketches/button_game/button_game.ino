#define GAME_TIME 5

#define PLAYER1_LED_PIN 9
#define PLAYER1_BUTTON_PIN 5

#define PLAYER2_LED_PIN 8
#define PLAYER2_BUTTON_PIN 4

#define ON_BUTTON_PIN 2
#define RESTART_BUTTON_PIN 3

#define TONE_PIN 13

bool isPlayer1Click = false;
bool isPlayer2Click = false;
bool isOnButtonClick = false;
bool isRestartButtonClick = false;
word score1 = 0;
word score2 = 0;

unsigned long startTime = 0; // Renamed from 'time' to 'startTime'

bool isOn = false;
bool isGameOn = false;

void setup()
{
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  pinMode(5, INPUT);
  
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(13, OUTPUT);
  
  randomSeed(analogRead(0));
  
  Serial.begin(9600); 
}

void loop(){
  if(buttonClick(ON_BUTTON_PIN, isOnButtonClick ))
  {
    isOn = !isOn;
    if(isOn)
    {
      tone(TONE_PIN,50,500);
      digitalWrite(PLAYER1_LED_PIN,true);
      digitalWrite(PLAYER2_LED_PIN,true);
      delay(1000);
      digitalWrite(PLAYER1_LED_PIN,false);
      digitalWrite(PLAYER2_LED_PIN,false);
      noTone(TONE_PIN);
    }
    else
    {
      digitalWrite(PLAYER1_LED_PIN,false);
      digitalWrite(PLAYER2_LED_PIN,false);
      noTone(TONE_PIN);
    }
  } 
  
  if(!isOn) return;
  
  if(buttonClick(RESTART_BUTTON_PIN, isRestartButtonClick ))
  {
    delay(random(1,3)*1000);
    
    startTime = millis();
    tone(13,50,100);
    digitalWrite(PLAYER1_LED_PIN,true);
    digitalWrite(PLAYER2_LED_PIN,true);
    delay(500);
    digitalWrite(PLAYER1_LED_PIN,false);
    digitalWrite(PLAYER2_LED_PIN,false);
    noTone(TONE_PIN);
    
    isGameOn = true;
    
    score1 = 0;
    score2 = 0;
  }
  
  if(!isGameOn) return;
  if(millis() - startTime >= GAME_TIME *1000)
  {
    if(score1 > score2){
      digitalWrite(PLAYER1_LED_PIN,true);
    }
    else if(score2 > score1){
      digitalWrite(PLAYER2_LED_PIN,true);
    }
    else{
      digitalWrite(PLAYER1_LED_PIN,true);
      digitalWrite(PLAYER2_LED_PIN,true);
    }
    isGameOn = false;
    tone(TONE_PIN,100,100); 
    delay(500);
    digitalWrite(PLAYER1_LED_PIN,false);
    digitalWrite(PLAYER2_LED_PIN,false);
  }
  
  if(buttonClick(PLAYER2_BUTTON_PIN, isPlayer1Click)){ 
    score2 +=1;
    Serial.println(score2);
  }
  if(buttonClick(PLAYER1_BUTTON_PIN, isPlayer2Click)){ 
    score1 +=1;
    Serial.println(score1);
  }
}

bool buttonClick(byte pin, bool& isClick)
{
  if (digitalRead(pin))
  {
    if(!isClick)
    {
      isClick = true;
      return true;
    }
  }
  else
  {
    if(isClick)
    {
      isClick = false;
    }
  }
  return false;
}
