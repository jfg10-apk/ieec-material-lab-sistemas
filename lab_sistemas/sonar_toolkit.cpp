#include <Arduino.h>

#include "sonar_toolkit.hpp"
#include "general_headers.hpp"

void sonarInit() {
  pinMode(PINO_TRIG, OUTPUT);
  digitalWrite(PINO_TRIG, LOW);
  delayMicroseconds(2);
  pinMode(PINO_ECHO, INPUT);
  delay(1000);  //Warm-Up
}

float sonarRead() {
  digitalWrite(PINO_TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(PINO_TRIG, LOW);

  // TIMEOUT 30 ms para recolher a arcada de ECHO
  long tof = pulseIn(PINO_ECHO,
                     HIGH,
                     30000);

  if (tof == 0) {
    return OUT_OF_RANGE;  // Retorna OUT_OF_RANGE se o retorno for 0 (FOR DEBUG HUSTLES)
  }
  return (tof * 0.0343) / 2.0;
}
