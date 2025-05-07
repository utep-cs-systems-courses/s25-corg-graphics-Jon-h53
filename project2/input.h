#ifndef INPUT_H
#define INPUT_H

#include <msp430.h>

// Switch Definitions
#define SW1 1  // Jump button
#define SW2 2  // Pause button
#define SWITCHES 3  // Mask for all switches

// External Variable Declaration
extern int switches;  // Tracks button states

// Function Prototypes
void switch_init();                 // Initializes switch hardware
void switch_interrupt_handler();    // Handles switch interrupts
static char switch_update_interrupt_sense();  // Updates switch states

#endif /* INPUT_H */
