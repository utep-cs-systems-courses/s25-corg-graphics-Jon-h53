#include <msp430.h>
#include "clocksTimer.h"
#include "game.h"
#include "lcddraw.h"
#include "lcdtypes.h"
#include "lcdutils.h"
#include "graphics.h"
#include "led.h"
#include "libTimer.h"

//Global Variables
u_int dinosaur_x = 20, dinosaur_y = 100;
int obstacle_x = 160;
u_int obstacle_y = 100;
u_int obstacle_width = 10, obstacle_height = 20;
u_int dino_width = 10, dino_height = 20;
u_int gameOver = 0;
int score = 0;
u_int redrawScreen = 1;
short velocity = 0;
char isJumping = 0;
char isPaused = 0;

void updateGame() {
  if (isPaused) {
    drawPauseScreen();
    P1OUT &= ~BIT6;
    or_sr(0x10);
    P1OUT |= BIT6;
    return;  // Exit function early to prevent game updates
  }

  if (!gameOver) {
    velocity += GRAVITY;
    dinosaur_y += velocity;

    if (dinosaur_y >= FLOOR_HEIGHT) {
      dinosaur_y = FLOOR_HEIGHT;
      velocity = 0;
      isJumping = 0;
    }

    obstacle_x -= OBSTACLE_SPEED;
    if (obstacle_x <= 0) {
      obstacle_x = screenWidth;
      score++;  // Increase score as obstacles are cleared
    }

    if (checkCollision()) {
      gameOver = 1;
    }
  }
  if (gameOver){
    drawGameOverScreen();
    P1OUT &= ~BIT6;
    or_sr(0x10);
    P1OUT |= BIT6;
    return;
  }
}

void jump() {
  if (!isJumping && !gameOver) {
    velocity = JUMP_VELOCITY;
    isJumping = 1;
  }
}

char checkCollision() {
  return (dinosaur_x < obstacle_x + obstacle_width &&
	  dinosaur_x + dino_width > obstacle_x &&
	  dinosaur_y < FLOOR_HEIGHT + obstacle_height &&
	  dinosaur_y + dino_height > FLOOR_HEIGHT);
}

void restartGame() {
  dinosaur_y = FLOOR_HEIGHT;
  velocity = 0;
  isJumping = 0;
  obstacle_x = screenWidth;
  score = 0;
  gameOver = 0;
}
