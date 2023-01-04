#include "snake.h"
#include "food.h"
#include "display.h"
#include "controller.h"
#include "direction.h"
#include "segment.h"
#include <stdio.h>
#include <SDL.h>

//Window and cell size.
const int windowSize = 20;
const int cellSize = 20;

/**
* The main method for this project.
*/
int main(int argc, char** argv) {

	//Create and initialize the snake.
	Snake snake;
	snake.initialize(windowSize, cellSize);

	//Create the controller with the snake as an argument.
	Controller controller(snake);

	//Run the game given the window and cell size.
	controller.runGame(windowSize, cellSize);

	//SDL clean up
	SDL_Quit();
	return 0;
}