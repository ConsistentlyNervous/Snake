#ifndef DISPLAY_H
#define DISPLAY_H

#include "snake.h"
#include "segment.h"
#include "food.h"
#include <string>
#include <stdio.h>
#include <SDL.h>

/**
* The Display class renders the snake game using the SDL library
* A display object has a window and cell size and SDL window and 
* SDL renderer pointers. Upon construction, the window and renderer
* are set to null and the window and cell size are given by the user.
* A display can initialize itself, draw the background, draw the snake,
* draw a food object, draw the game over scene, and present the renderer.
*/
class Display
{
private:
	int m_windowSize;
	int m_cellSize;
	SDL_Window* m_window;
	SDL_Renderer* m_renderer;

public:
	/**
	* Constructs a display object, requires a window and cell size given by the user
	* and the window and renderer pointers will be set to null values.
	*/
	Display(int windowSize, int cellSize) : m_windowSize(windowSize), m_cellSize(cellSize), m_window(NULL), m_renderer(NULL) {}
	/**
	* Destructs a display object.
	*/
	~Display() {}
	/**
	* Initializes the window and renderer pointers in the display.
	*/
	void initialize();
	/**
	* Draws the background for the snake game using the window and
	* renderer variables.
	*/
	void drawBG();
	/**
	* Draws the snake for the snake game using the window and
	* renderer variables.
	*/
	void drawSnake(Snake snake);
	/**
	* Draws the food for the snake game using the window and
	* renderer variables.
	*/
	void drawFood(Food food);
	/**
	* Draws the game over scene for the snake game using the
	* window and renderer variables.
	*/
	void drawGameOver();
	/**
	* Visually presents the renderer to the user.
	*/
	void Present();
	/**
	* Returns the current window size.
	*/
	inline int getWindowSize() { return m_windowSize; }
	/**
	* Returns the current cell size.
	*/
	inline int getCellSize() { return m_cellSize; }
};

#endif
