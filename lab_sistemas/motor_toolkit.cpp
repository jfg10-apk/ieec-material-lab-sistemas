#include <Arduino.h>
#include <Stepper.h>

#include "motor_toolkit.hpp"
#include "general_headers.hpp"


Stepper motor(  STP_PER_ROTATION,
                OUTPUT1,
                OUTPUT3,
                OUTPUT2,
                OUTPUT4);

int cur_stp = 0;
int direct = 1;



void motorInit(int speed_rpm) {
  motor.setSpeed(speed_rpm);
}

void motorSweep() {
  motor.step(direct * 5);  // Avança 5 passos de cada vez
  cur_stp += (direct * 5);

  // Inverte a direção (LIM_STP configura os limites de passada)
  if (cur_stp >= LIM_STP || cur_stp <= -LIM_STP) {
    direct *= -1;
  }
}