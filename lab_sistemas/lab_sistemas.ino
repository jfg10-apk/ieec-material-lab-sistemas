// Bibliotecas
#include <Arduino.h>

#include "general_headers.hpp"
#include "led_toolkit.hpp"
#include "motor_toolkit.hpp"
#include "lab_functions.hpp"
#include "sonar_toolkit.hpp"



float maj = DEFAULT_DIST + DEFAULT_TOLER;
float min = DEFAULT_DIST - DEFAULT_TOLER;
float ref = DEFAULT_DIST;

// Estados
uint8_t state = WARNING;
uint8_t last_state = WARNING;

// Globals
float dist = 0.0f;


void setup() {
  Serial.begin(9600);
  Serial.println("Sonar setting up...");

  sonarInit();
  motorInit(15); // de 12 RPM

  // TODO: Inicializar periférico
  // TODO: Inicializar botão de calibração

  Serial.println("Sonar READY!");
  delay(2000);
}

void loop() {
  // 1. LEITURA:
  dist = sonarRead();
  

  // 2. DECISÃO (Lógica com histerese):
  state = stateCase1Wrong(dist); 
  // Este caso functionará. Porém falta implementar o Schmitt trigger


  // 3. AÇÃO (Baseada no estado atual)
  switch (state) {
    case SEARCHING:
      motorSweep();
      // Ex.: ledWrite(Y_PIN);
      break;
      
    case IN_PROXIMITY:
      // O motor não faz nada, mantendo a posição trancada no alvo
      // Ex.: ledWrite(G_PIN);
      break;

    case CALIBRATING:
      // recordNewDist(dist, min, maj);
      // Ex.: ledWrite(Y_PIN);
      break;

    default:
      // Erro
      // Ex.: ledWarning(R_PIN);
      break;
  }

  delay(100);
}