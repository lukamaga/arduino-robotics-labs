#define GAME_TIME 5

#define PLAYER1_LED_PIN 9
#define PLAYER1_BUTTON_PIN 5

#define PLAYER2_LED_PIN 8
#define PLAYER2_BUTTON_PIN 4

#define ON_BUTTON_PIN 2
#define RESET_BUTTON_PIN 3

#define TONE_PIN 13

bool isPlayer1Click = false;
bool isPlayer2Click = false;
word score1 = 0;
word score2 = 0;

unsigned long time = 0;

void setup()
{
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  pinMode(5, INPUT);
  
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(13, OUTPUT);
  
  Serial.begin(9600); 
  
  time = millis();
  tone(13,50,100);
}

void loop(){
  if(buttonClick(4, isPlayer1Click)){ 
    score2 +=1;
    Serial.println(score2);
  }
  if(buttonClick(5, isPlayer2Click)){ 
    score1 +=1;
    Serial.println(score1);
  }
  
  if(millis() - time >= GAME_TIME *1000)
  {
    if(score1>score2){
      digitalWrite(9,true);
    }
    else if(score2>score1){
      digitalWrite(8,true);
    }
      else{
      digitalWrite(9,true);
      digitalWrite(8,true);
    }
    tone(13,100,100); 
    delay(500);
    digitalWrite(9,false);
    digitalWrite(8,false);
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
