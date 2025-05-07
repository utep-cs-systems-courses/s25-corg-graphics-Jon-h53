#ifndef GAME_H
#define GAME_H

#include "lcdutils.h"

// Game Constants
#define GRAVITY 2
#define JUMP_VELOCITY -20
#define FLOOR_HEIGHT 100
#define OBSTACLE_SPEED 5


// External Global Variables
extern u_int dinosaur_x, dinosaur_y;
extern int obstacle_x;
extern u_int obstacle_y;
extern u_int obstacle_width, obstacle_height;
extern u_int dino_width, dino_height;
extern u_int gameOver;
extern int score;
extern u_int redrawScreen;
extern short velocity;
extern char isJumping;
extern char isPaused;


// Game Function Prototypes
void updateGame();
void jump();
void restartGame();
char checkCollision();

#endif /* GAME_H */
