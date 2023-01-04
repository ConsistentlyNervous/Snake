#ifndef SNAKE_H
#define SNAKE_H

#include "segment.h"
#include "direction.h"
#include <vector>

/**
* The snake class represents the snake object within the game. A snake has a direction, 
* a vector of segments, and an amount of lives. The initial values for these variables are:
* Stationary, an empty vector, and 1 life respectively. A Snake can move, eat, update it's direction,
* and get/set it's variables.
*/
class Snake
{
private:
	int m_lives;
	Direction m_direction;
	std::vector<Segment> m_segments;
	/**
	* Sets the snake's current direction to the one given.
	*/
	inline void setDirection(Direction dir) { m_direction = dir; }


public:
	/**
	* Constructs a base snake object, with values: Direction -> Stationary, lives -> 1, 
	* and vector of segments -> empty.
	*/
	Snake() : m_direction(Direction::Stationary), m_lives(1) {}
	/**
	* Destructs a snake object.
	*/
	~Snake() {}
	/**
	* Moves the snake in it's current direction, if stationary the snake does not move.
	* Uses the cell size to move the snake the correct distance.
	*/
	void Move(int cellSize);
	/**
	* Updates the direction of the snake to the current one. First checks if the snake 
	* can move in that direction, if it is a valid direction then it is changed. If the
	* snake's current direction is up it cannot move immediately down, it must turn left
	* or right first.
	*/
	void updateDirection(Direction direction);
	/**
	* Adds a new segment onto the snake, this method should only be called when the
	* snake has collided/eaten a food object. Uses the cell size to create the new
	* segment at the correct distance from the existing segments.
	*/
	void Eat(int cellSize);
	/**
	* Initializes the snake's variables, uses the window and cell size to start the snake
	* in the center of the board at the beginning of the game. Adds segments to the
	* snake's vector of segments.
	*/
	void initialize(int windowSize, int cellSize);
	/**
	* Checks if the snake has either hit itself or gone out of bounds, if this is the
	* case, one life is removed from the snake. Uses the window and cell size to determine
	* if the snake has left the screen.
	*/
	void hit(int windowSize, int cellSize);
	/**
	* Returns the snake's current direction.
	*/
	inline Direction getDirection() { return m_direction; }
	/**
	* Returns a reference to the snake's vector of segments.
	*/
	inline std::vector<Segment>& getSegments() { return m_segments; }
	/**
	* Sets the segments to the given reference of segments.
	*/
	inline void setSegments(std::vector<Segment>& segments) { m_segments = segments; }
	/**
	* Returns the amount of lives the snake has.
	*/
	inline int getLives() { return m_lives;}
};

#endif
