#include "snake.h"

/**
* Moves the snake in it's current direction, if stationary the snake does not move.
* Uses the cell size to move the snake the correct distance.
*/
void Snake::Move(int cellSize) {
	//Get the current direction and the segments of the snake.
	Direction cur_direction = getDirection();
	std::vector<Segment>& segments = getSegments();

	//get the x and y of the first segment
	int lastX = segments[0].getX();
	int lastY = segments[0].getY();

	//Move every segment (besides the first one) to the position of the one 
	//in front of it. Segment 2 moves to segment 1's position.
	for (int i = 1; i < segments.size(); i++) {
		int x = segments[i].getX();
		int y = segments[i].getY();
		segments[i].setX(lastX);
		segments[i].setY(lastY);
		lastX = x;
		lastY = y;

	}

	//Move the first segment in the snake's current direction.
	switch (cur_direction) {
	//up
	case Direction::Up:
		segments[0].setY(segments[0].getY() - (cellSize + 1));
		break;
	//left
	case Direction::Left:
		segments[0].setX(segments[0].getX() - (cellSize + 1));
		break;
	//right
	case Direction::Right:
		segments[0].setX(segments[0].getX() + (cellSize + 1));
		break;
	//down
	case Direction::Down:
		segments[0].setY(segments[0].getY() + (cellSize + 1));
		break;
	//stationary
	case Direction::Stationary:
		break;
	default:
		break;
	}

}

/**
* Updates the direction of the snake to the current one. First checks if the snake
* can move in that direction, if it is a valid direction then it is changed. If the
* snake's current direction is up it cannot move immediately down, it must turn left
* or right first.
*/
void Snake::updateDirection(Direction direction) {
	//Get the current direction of the snake.
	Direction cur_direction = getDirection();

	//If the current direction is stationary the only direction you cannot move is
	//down, if the desired direction is not down, then the direction can be updated.
	if (cur_direction == Direction::Stationary && direction != Direction::Down) {
		setDirection(direction);
	}
	//If the current direction is up or down the directions you can move are left
	//or right, if the desired direction is one of these, then the direction can 
	//be updated.
	else if ((cur_direction == Direction::Up || cur_direction == Direction::Down)
		&& (direction == Direction::Left || direction == Direction::Right)) {
		setDirection(direction);
	}
	//If the current direction is left or right the directions you can move are up
	//or down, if the desired direction is one of these, then the direction can 
	//be updated.
	else if ((cur_direction == Direction::Left || cur_direction == Direction::Right)
		&& (direction == Direction::Up || direction == Direction::Down)) {
		setDirection(direction);
	}
}

/**
* Adds a new segment onto the snake, this method should only be called when the
* snake has collided/eaten a food object. Uses the cell size to create the new
* segment at the correct distance from the existing segments.
*/
void Snake::Eat(int cellSize) {
	//Get the segments and current direction.
	std::vector<Segment>& segments = getSegments();
	Direction cur_direction = getDirection();
	//Get the x and y of the last segment
	int m_x = segments[segments.size() - 1].getX();
	int m_y = segments[segments.size() - 1].getY();

	//Adjust the x and y of the new segment's x and y
	//in accordance with the current direction.
	switch (cur_direction) {
	case Direction::Up:
		m_y += (cellSize + 1);
		break;
	case Direction::Left:
		m_x += (cellSize + 1);
		break;
	case Direction::Right:
		m_x -= (cellSize + 1);
		break;
	case Direction::Down:
		m_y -= (cellSize + 1);
		break;
	case Direction::Stationary:
		break;
	default:
		break;
	}

	//Create the new segment and add it to the vector
	//of segments.
	Segment seg(m_x, m_y);
	segments.push_back(seg);
	setSegments(segments);
}

/**
* Initializes the snake's variables, uses the window and cell size to start the snake
* in the center of the board at the beginning of the game. Adds segments to the
* snake's vector of segments.
*/
void Snake::initialize(int windowSize, int cellSize) {
	//Find the center of the screen.
	int centerScreen = ((windowSize*cellSize) / 2);
	std::vector<Segment> segments;
	
	//Create 3 segments for the snake to start with, and place
	//the in a vertical line in the center of the window.
	Segment s1(centerScreen, centerScreen - (cellSize + 1));
	Segment s2(centerScreen, centerScreen);
	Segment s3(centerScreen, centerScreen + (cellSize + 1));

	//Add the created segments to the vector defined above.
	segments.push_back(s1);
	segments.push_back(s2);
	segments.push_back(s3);

	//Set the segments of the snake to these.
	setSegments(segments);
}

/**
* Checks if the snake has either hit itself or gone out of bounds, if this is the
* case, one life is removed from the snake. Uses the window and cell size to determine
* if the snake has left the screen.
*/
void Snake::hit(int windowSize, int cellSize) {
	//Get the segments.
	std::vector<Segment>& segments = getSegments();
	//Get the first segment's x and y position.
	int headX = segments[0].getX();
	int headY = segments[0].getY();
	int index = 0;

	//Check if the head of the snake has left the screen on the right or bottom.
	if (headX > (windowSize * cellSize) || headY > (windowSize * cellSize)) {
		m_lives -= 1;
	}
	//Check if the head of the snake has left the screen on the left or top.
	if (headX < -5 || headY < -5) {
		m_lives -= 1;
	}

	//Check if the head of the snake has collided with any of it's segments.
	//Index is used here to make sure that the head is not colliding with itself.
	for (auto s : segments) {
		if (headX == s.getX() && headY == s.getY() && index != 0) {
			m_lives -= 1; 
		}
		index++;
	}
}