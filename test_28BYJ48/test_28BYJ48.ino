#include <Arduino.h>
#include <Stepper.h>

#define OUTPUT1 7
#define OUTPUT2 6
#define OUTPUT3 5
#define OUTPUT4 4

#define STP_PER_ROTATION 2048
#define LIM_STP 512  // 1/4 de volta para a esquerda e direita

Stepper motor(STP_PER_ROTATION, OUTPUT1, OUTPUT3, OUTPUT2, OUTPUT4);

int cur_stp = 0;
int direct = 1;

void motorInit(int speed_rpm) 
{
  motor.setSpeed(speed_rpm);
  Serial.println("== MOTOR OK ==");
}

void motorSweep() {
  motor.step(direct * 5);  // Avança 5 passos de cada vez
  cur_stp += (direct * 5);

  // Inverte a direção (LIM_STP configura os limites de passada)
  if (cur_stp >= LIM_STP || cur_stp <= -LIM_STP) {
    direct *= -1;
  }
}

void setup() {
  Serial.begin(9600);
  motorInit(12); // de 12 RPM
}

void loop() {
  motorSweep();
}
