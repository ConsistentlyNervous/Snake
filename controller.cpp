#include "controller.h"

/**
* Parses user input using the SDL library. Determines
* if the player wishes to move the snake or end the game
* and calls appropriate methods.
*/
void Controller::parseInput() {
	SDL_Event event;

	//While there is an event, parse it and call the corresponding functions.
	while (SDL_PollEvent(&event)) {
		switch (event.type) {
			//Event Quit: set running to false and quit the program.
			case SDL_QUIT:
				m_running = false;
				SDL_Quit();
				break;
			//Event Keydown: parse the key pressed and update the direction.
			case SDL_KEYDOWN:
				switch (event.key.keysym.sym) {
					//Case Left:
					case SDLK_LEFT:
						m_snake.updateDirection(Direction::Left);
						break;
					//Case Right:
					case SDLK_RIGHT:
						m_snake.updateDirection(Direction::Right);
						break;
					//Case Down:
					case SDLK_DOWN:
						m_snake.updateDirection(Direction::Down);
						break;
					//Case Up:
					case SDLK_UP:
						m_snake.updateDirection(Direction::Up);
						break;
					//Default or Stationary: Don't do anything.
					default:
						break;
				}
				break;
		}
	}
}

/**
* Runs the game loop while the boolean running is true.
* Takes in the window and cell size for the display creation.
*/
void Controller::runGame(int windowSize, int cellSize) {
	//Create the display given the window and cell size.
	Display display(windowSize, cellSize);

	//Create the food object and then randomize it's position
	//using spawn.
	Food food(0, 0);
	food.spawn(display.getWindowSize(), display.getCellSize());

	//Intialize display conditions and background.
	display.initialize();
	display.drawBG();
	display.drawFood(food);
	display.drawSnake(m_snake);
	display.Present();

	//Game play loop: while the game is running perform these 
	//actions each turn.
	while (m_running) {
		//Draw the background.
		display.drawBG();

		//If the current food object has been eaten, spawn a 
		//new one in and display it.
		if (food.getEaten()) {
			food.spawn(display.getWindowSize(), display.getCellSize());
			display.drawFood(food);
		}

		//Parse the user's input.
		parseInput();

		//If the snake is not stationary, move it.
		if (m_snake.getDirection() != Direction::Stationary) {
			m_snake.Move(display.getCellSize());
		}
		//Check if the snake has eaten the food.
		food.hasBeenEaten(m_snake, display.getCellSize());

		//Redraw all objects.
		display.drawSnake(m_snake);
		display.drawFood(food);

		//Present the renderer.
		display.Present();
		
		//Check if snake has hit or collided with anything.
		m_snake.hit(display.getWindowSize(), display.getCellSize());

		//Check if the snake is out of lives.
		if (m_snake.getLives() <= 0) {
			//If the snake is out of lives, draw the game over scene 
			//and set running to false.
			display.drawGameOver();
			m_running = false;
		}

		//Delay each turn by 0.5 seconds.
		SDL_Delay(500);
	}
}