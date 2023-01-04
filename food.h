#ifndef FOOD_H
#define FOOD_H

#include "snake.h"
#include <cstdlib>
#include <time.h>

/**
* The food class represents consumable objects within the snake game.
* A Food object has an x,y position, and a boolean representing if
* the object has been eaten. A food object can determine if a snake has
* collided with it (has eaten it), respawn in the fruit to a new location,
* and get/set it's variables.
*/
class Food
{
private:
	int m_x;
	int m_y;
	bool m_eaten;

public:
	/**
	* Constructs a food object given an x,y position. The boolean
	* eaten is set to false by default.
	*/
	Food(int x, int y) : m_x(x), m_y(y), m_eaten(false) {}
	/**
	* Destructs a food object.
	*/
	~Food() {}
	/**
	* Determines if the given snake reference has collided with this
	* food object. If this is the case, eaten is set to true. Uses
	* cell size to help determine if the snake has collided with 
	* the food object.
	*/
	void hasBeenEaten(Snake& s, int cellSize);
	/**
	* Resets the food's variables and spawns it to a new, random
	* location. The boolean eaten is set to false again. This method
	* uses the window and cell size to determine possible spawn points.
	*/
	void spawn(int windowSize, int cellSize);
	/**
	* Returns the x value of the food object.
	*/
	inline int getX() { return m_x; }
	/**
	* Sets the x value of the food object.
	*/
	inline void setX(int x) { m_x = x; }
	/**
	* Returns the y value of the food object.
	*/
	inline int getY() { return m_y; }
	/**
	* Sets the y value of the food object.
	*/
	inline void setY(int y) { m_y = y; }
	/**
	* Returns the boolean eaten variable for the food object.
	*/
	inline bool getEaten() { return m_eaten; }
	

};

#endif

