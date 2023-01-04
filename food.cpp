#include "food.h"

/**
* Determines if the given snake reference has collided with this
* food object. If this is the case, eaten is set to true. Uses
* cell size to help determine if the snake has collided with
* the food object.
*/
void Food::hasBeenEaten(Snake& snake, int cellSize) {
	//Gets the food's x and y position.
	int fruitX = getX();
	int fruitY = getY();

	//Check if any of the snake's segments are within the fruit's range.
	for (Segment s : snake.getSegments()) {
		//Get the x and y for the current segment.
		int snakeX = s.getX();
		int snakeY = s.getY();
		//Checks if top left of segment is in range.
		if (((snakeX >= fruitX) && (snakeX <= (fruitX + cellSize))) && ((snakeY >= fruitY)
			&& (snakeY <= fruitY + cellSize))) {
			//If the segment is in range, eat the fruit and add a new
			//segment to the snake. Then break from the loop.
			m_eaten = true;
			snake.Eat(cellSize);
			continue;
		}
		//Checks if top right of segment is in range.
		else if ((((snakeX + cellSize) >= fruitX) && ((snakeX + cellSize) <= (fruitX + cellSize)))
			&& ((snakeY >= fruitY) && (snakeY <= fruitY + cellSize))) {
			//If the segment is in range, eat the fruit and add a new
			//segment to the snake. Then break from the loop.
			m_eaten = true;
			snake.Eat(cellSize);
			continue;
		}
		//Checks if bottom left of segment is in range.
		else if (((snakeX >= fruitX) && (snakeX <= (fruitX + cellSize)))
			&& (((snakeY + cellSize) >= fruitY) && ((snakeY + cellSize) <= fruitY + cellSize))) {
			//If the segment is in range, eat the fruit and add a new
			//segment to the snake. Then break from the loop.
			m_eaten = true;
			snake.Eat(cellSize);
			continue;
		}
		//Checks if bottom right of segment is in range.
		else if ((((snakeX + cellSize) >= fruitX) && ((snakeX + cellSize) <= (fruitX + cellSize)))
			&& (((snakeY + cellSize) >= fruitY) && ((snakeY + cellSize) <= fruitY + cellSize))) {
			//If the segment is in range, eat the fruit and add a new
			//segment to the snake. Then break from the loop.
			m_eaten = true;
			snake.Eat(cellSize);
			continue;
		}
	}
}

/**
* Resets the food's variables and spawns it to a new, random
* location. The boolean eaten is set to false again. This method
* uses the window and cell size to determine possible spawn points.
*/
void Food::spawn(int windowSize, int cellSize) {
	srand(time(nullptr));

	//Find a random position within the window's range.
	int x = (rand() % windowSize) * cellSize;
	int y = (rand() % windowSize) * cellSize;

	//Update the food's variables with the new random x and y 
	//positions and set eaten to false.
	m_x = x;
	m_y = y;
	m_eaten = false;
}