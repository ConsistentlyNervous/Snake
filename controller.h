#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "snake.h"
#include "food.h"
#include "display.h"
#include "controller.h"
#include "direction.h"
#include "segment.h"
#include <vector>
#include <string>
#include <stdio.h>
#include <SDL.h>

/**
* The Controller class handles the interaction between the user
* and the program. The class has a snake object and an boolean
* that represents if the program is running. The class parses
* user input, using the SDL library and runs the program.
*/
class Controller
{
private:
	Snake m_snake;
	bool m_running;

public:
	/**
	* Contructs a controller object using the given snake and
	* automatically sets the boolean runnning to true.
	*/
	Controller(Snake s) : m_snake(s), m_running(true) {}
	/**
	* Destructs the controller object.
	*/
	~Controller() {}
	/**
	* Parses user input using the SDL library. Determines
	* if the player wishes to move the snake or end the game
	* and calls appropriate methods.
	*/
	void parseInput();
	/**
	* Runs the game loop while the boolean running is true.
	* Takes in the window and cell size for the display creation.
	*/
	void runGame(int windowSize, int cellSize);
	/**
	* Returns a reference to the snake variable.
	*/
	inline Snake& getSnake() { return m_snake; }
};

#endif

