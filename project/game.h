#ifndef GAME_INCLUDED
#define GAME_INCLUDED

#include "lcdtypes.h"

// Global variables for game state
extern u_char dinosaur_x;    // Dinosaur's horizontal position
extern u_char dinosaur_y;    // Dinosaur's vertical position
extern u_char obstacle_x;    // Obstacle's horizontal position
extern u_char obstacle_y;    // Obstacle's vertical position
// Mark as volatile since it's updated by an interrupt
extern volatile u_int score;          // Current score
extern volatile u_char game_over;     // Game over flag

void check_collision();
void jump_dinosaur();
void update_positions();

#endif // GAME_INCLUDED
