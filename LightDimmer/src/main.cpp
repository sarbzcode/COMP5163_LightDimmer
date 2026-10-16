// Acadia University - COMP 5163
//
// Light Dimmer Lab Application
//
#include <Arduino.h>

bool ledOn = false;   
int lastButton = HIGH; 

void setup()
{
  pinMode(D5, INPUT_PULLUP);
  pinMode(D4, OUTPUT);      
  analogWriteRange(1023);    

  analogWrite(D4, 1023); 
}

void loop()
{
  int button = digitalRead(D5);
  if (button == LOW && lastButton == HIGH)
  {
    ledOn = !ledOn;
  }
  lastButton = button;

  if (ledOn)
  {
    int pot = analogRead(A0);   
    analogWrite(D4, 1023 - pot); 
  }
  else
  {
    analogWrite(D4, 1023); 
  }

  delay(1); 
}