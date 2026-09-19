#ifndef LED_TOOLKIT_
#define LED_TOOLKIT_

void ledInit( const uint8_t r,
              const uint8_t y,
              const uint8_t g);
              
void ledWrite(const uint8_t pin);
void ledWarning();
void ledIgnite(const uint8_t mode);

#endif