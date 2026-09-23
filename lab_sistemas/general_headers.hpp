
#ifndef G_HEADERS_HPP
#define G_HEADERS_HPP

// Pins
#define CALIBRATION_BUTTON 2

#define PINO_TRIG 9
#define PINO_ECHO 8

#define R_PIN 10
#define Y_PIN 11
#define G_PIN 12


// Metrics (Consultar guia e documentação do HC-SR04 (Link no guia)))
#define DEFAULT_DIST    20.0f   // [cm]
#define DEFAULT_TOLER   4.0f    // tolerance [cm] - Completar e explicar a necessidade
#define TOO_CLOSE_DIST  4.0f    // [cm]
#define TOO_FAR_DIST    400.0f  // [cm]
#define OUT_OF_RANGE    999.0f  // (Não se correlaciona exatamente com o alcance do aparelho) [cm]


// States (switch-case na função void loop())
#define IN_FOCUS    0
#define SEARCHING   1
#define CALIBRATING 2
#define WARNING     3 // Por n ser referenciado no switch-case, aciona o estado default


// Motor Lib constants
#define OUTPUT1 7
#define OUTPUT2 6
#define OUTPUT3 5
#define OUTPUT4 4

#define STP_PER_ROTATION 2048
#define LIM_STP 512  // 1/4 de volta para a esquerda e direita

#endif