#include <msp430.h>
#include "libTimer.h"
#include "led.h"
#include "input.h"

void led_init(){
  P1DIR |= LEDS;
  P1OUT &= ~LEDS;
}
