#include <msp430.h>
#include "buzzer.h"
#include "led.h"
#include "input.h"
#include "game.h"
#include "graphics.h"
#include "lcdutils.h"
#include "lcddraw.h"
#include "libTimer.h"

// WARNING: LCD DISPLAY USES P1.0.  Do not touch!!!

#define LED BIT6       /* note that bit zero required for display */
#define SW1 1 //jump
#define SW2 2 //pause
#define SWITCHES 3

extern int switches;
extern u_int gameOver;
void switch_init();
void switch_interrupt_handler();
static char switch_update_interrupt_sense();
void wdt_c_handler();
//control mechanics
void wdt_c_handler(){
  //updateGame();
  if(gameOver){
    if(switches){
      restartGame();
    }
    return;
  }

  if(switches & SW1){
    jump();
  }
  if(switches & SW2){
      isPaused = !isPaused;
  }
  
  P1OUT &= ~(LED_RED | LED_GREEN);

  if(switches & SW1) P1OUT |= LED_GREEN;
  if(switches & SW2) P1OUT |= LED_GREEN;

  //buzzer sound on each button
  if(switches & SW1){
    buzzer_set_period(1000);
  } else if (switches & SW2){
    buzzer_set_period(800);
    //__delay_cycles(1600);
    buzzer_set_period(800);
  } else {
    buzzer_set_period(0);
  }
}

int main(){
  configureClocks();
  lcd_init();
  clearScreen(COLOR_BLUE);
  switch_init();
  led_init();
  buzzer_init();
  
  enableWDTInterrupts();
  or_sr(0x8);

  while(1){
    updateGame();  // Handles ALL game mechanics
    if (!gameOver) {
      drawGame();
    } else if (gameOver) {
      drawGameOverScreen();
    } else {
      drawPauseScreen();
    }
    //P1OUT &= ~BIT6;
    //or_sr(0x10);
    //P1OUT |= BIT6;
  }
  return 0;
}

void __interrupt_vec(PORT2_VECTOR) Port_2(){
  if(P2IFG & SWITCHES){
    P2IFG &= ~SWITCHES;
    switch_interrupt_handler();
  }
}
