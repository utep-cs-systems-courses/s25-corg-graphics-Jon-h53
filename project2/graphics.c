#include "graphics.h"
#include "lcdutils.h"
#include "lcddraw.h"
#include "game.h"
#include <stdio.h>

char scoreStr[10];
extern int score;

void drawGame() {
  clearScreen(COLOR_BLUE);
  // Draw dinosaur
  fillRectangle(dinosaur_x, dinosaur_y, 10, 10, COLOR_GREEN);
  // Draw obstacleo
  fillRectangle(obstacle_x, FLOOR_HEIGHT, 10, 10, COLOR_RED);
  // Draw score
  //sprintf(scoreString, "Score: %d", score);
  //drawString5x7(10, 5, scoreString, COLOR_BLACK, COLOR_WHITE);
  sprintf(scoreStr, "%d", score);
  drawString5x7(10, 10, "Score:", COLOR_WHITE, COLOR_BLUE);
  drawString5x7(50, 10, scoreStr, COLOR_WHITE, COLOR_BLUE);
}

void drawPauseScreen() {
  clearScreen(COLOR_WHITE);
  drawString5x7(40, 60, "PAUSED", COLOR_BLUE, COLOR_WHITE);
}

void drawGameOverScreen() {
  clearScreen(COLOR_RED);
  drawString5x7(40, 60, "GAME OVER", COLOR_BLACK, COLOR_RED);
  drawString5x7(20, 80, "Press to Restart", COLOR_BLACK, COLOR_RED);
}
