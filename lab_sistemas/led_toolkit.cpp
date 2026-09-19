#include <Arduino.h>

#include "led_toolkit.hpp"

// Pinos de aviso
uint8_t r_pin = 0;
uint8_t y_pin = 0;
uint8_t g_pin = 0;

void ledIgnite(const uint8_t mode){
  digitalWrite(r_pin, mode);
  digitalWrite(y_pin, mode);
  digitalWrite(g_pin, mode);
}

void ledInit( const uint8_t r,
              const uint8_t y,
              const uint8_t g) 
{
  pinMode((r_pin = r), OUTPUT);
  pinMode((y_pin = y), OUTPUT);
  pinMode((g_pin = g), OUTPUT);

  for(int i = 0; i < 3; i++){
    ledIgnite(HIGH);
    delay(200);
    ledIgnite(LOW);
    delay(200);
  }
}

void ledWrite(const uint8_t pin){
  ledIgnite(LOW);
  delay(10);
  digitalWrite(pin, HIGH); 
}

void ledWarning(){
  ledIgnite(HIGH);
  delay(100);
  ledIgnite(LOW);
}