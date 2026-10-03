# Component checks and notebook fragments

The mixed `robitika1.txt` file includes these component checks before its game implementations. They are separate notebook cells, not a single sketch containing several `loop()` functions.

## Shared setup

The saved setup declares D2 to D5 as inputs and D8, D9 and D13 as outputs:

```cpp
void setup()
{
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  pinMode(5, INPUT);
  
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(13, OUTPUT);
}
```

## LED check

This loop drives D8 and D9 HIGH:

```cpp
void loop()
{
  digitalWrite(8, true);
  digitalWrite(9, true);
}
```

## Button checks

These tests light an output for 500 ms when an input reads HIGH. D2, D4 and D5 all select D8 in this cell; D3 selects D9. Those assignments are retained as written.

```cpp
void loop()
{
  if(digitalRead(2)){
    digitalWrite(8, true);
    delay(500);
    digitalWrite(8,false);
  }
  if(digitalRead(3)){
    digitalWrite(9, true);
    delay(500);
    digitalWrite(9,false);
  }
  if(digitalRead(4)){
    digitalWrite(8, true);
    delay(500);
    digitalWrite(8,false);
  }
  if(digitalRead(5)){
    digitalWrite(8, true);
    delay(500);
    digitalWrite(8,false);
  }
 
}
```

## Piezo check

This loop requests a 1000 Hz tone for 100 ms, waits 100 ms and stops the tone before repeating:

```cpp
void loop()
{
  tone(13, 1000, 100);
  delay(100);
  noTone(13);
}
```

## State-message fragment

This fragment assumes an enclosing function and an existing `isOn` variable; it is not a standalone sketch:

```cpp
if(!isOn) {
  Serial.println("zaidimas yra isjungtas.");
  return;
}
else {
  Serial.println("zaidimas yra įjungtas.");
}
```

## Saved wiring annotations

```text
resistor -> katod(led)
orange - turn off
purple - restart
```

The file's opening section is unrelated Python optimization code and is not included in the Arduino collection. The two complete game variants preserve the distinct game logic that follows these checks.
