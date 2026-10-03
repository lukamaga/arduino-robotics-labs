// C++ code
//
void setup()
{
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{
  digitalWrite(5, HIGH);
  digitalWrite(LED_BUILTIN, HIGH);
  
  delay(1000); // Wait for 1000 millisecond(s)
  
  digitalWrite(6, HIGH);
  digitalWrite(LED_BUILTIN, LOW);
  digitalWrite(5, LOW);
  
  delay(1000); // Wait for 1000 millisecond(s)
  
  digitalWrite(6, LOW);
  digitalWrite(4, HIGH);
  
  delay(1000);
  
  digitalWrite(4, LOW);
  digitalWrite(3, HIGH);
  
  delay(1000);
  
  digitalWrite(3, LOW);
}