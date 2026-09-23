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
float tol = DEFAULT_TOLER;


void setup() {
  Serial.begin(9600);
  Serial.println("Sonar setting up...");

  sonarInit();
  motorInit(15); // de 12 RPM

  // TODO: Inicializar periférico
  ledInit(R_PIN,Y_PIN,G_PIN);
  
  // TODO: Inicializar botão de calibração
  pinMode(CALIBRATION_BUTTON, INPUT_PULLUP);

  Serial.println("Sonar READY!");
  delay(2000);
}

void loop() {
  // ---
  // 1. LEITURA:
  dist = sonarRead();

  /***
   * // Para testar sem o sensor HC-SR04 basta apenas injetar um valor manualmente no código.
   * 
   * Exemplos:
   * dist = 10.0f;  // Que vai corresponder a: (state == IN_FOCUS (CASE 1) / state == SEARCHING (CASE 2))
   * dist = 30.0f;  // Que vai corresponder a: (state == SEARCHING (CASE 1) / state == SEARCHING (CASE 2))
   * 
   * // Desta forma poderá testar o sensor remotamente!
   */
  

  // ---
  // 2. DECISÃO (Lógica com histerese):
  // state = stateCase1(dist, ref);
  // state = stateCase2(dist, min, maj);
  state = stateCase2Extended(dist, min, maj);


  // ---
  // 3. AÇÃO (Baseada no estado atual)
  switch (state) {
    case SEARCHING:
      motorSweep();
      printLogs("Searching new object...",dist,ref,tol);
      ledWrite(R_PIN);
      break;
      
    case IN_FOCUS:
      printLogs("Focusing on close object...",dist,ref,tol);
      ledWrite(G_PIN);
      break;

    case CALIBRATING:
      Serial.println("Calibrating...");
      recordNewDist(&maj, &min, dist, &ref);
      ledWrite(Y_PIN);
      break;

    default:
      // Erro
      printError("Error!", dist, ref, tol);
      ledWarning();
      break;
  }

  delay(100);
}