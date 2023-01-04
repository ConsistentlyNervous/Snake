#include "display.h"

/**
* Initializes the window and renderer pointers in the display.
*/
void Display::initialize() {
    //Use SDL to initialize the program
	SDL_Init(SDL_INIT_EVERYTHING);

    //Create the window using the display's window and cell size.
	m_window = SDL_CreateWindow("Snake", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 
        m_windowSize * m_cellSize, m_windowSize * m_cellSize, SDL_WINDOW_SHOWN);
    //Create the renderer using the window.
	m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_PRESENTVSYNC);
    //Set the render color to black and fill the whole screen.
    SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 0);
    SDL_RenderClear(m_renderer);
    //Present the renderer.
    SDL_RenderPresent(m_renderer);
}

/**
* Draws the background for the snake game using the window and
* renderer variables.
*/
void Display::drawBG() {
    //Set the render color to black and fill in the whole screen.
    SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 0);
    SDL_RenderClear(m_renderer);
}

/**
* Draws the snake for the snake game using the window and
* renderer variables.
*/
void Display::drawSnake(Snake snake) {
    //Get the snake's segments.
    std::vector<Segment>& segments = snake.getSegments();
    //set the renderer color to green.
    SDL_SetRenderDrawColor(m_renderer, 0, 255, 0, 255);
    SDL_Rect seg;

    //For each of the snake's segments, draw them.
    for (Segment s : segments) {
        //Get the x and y of the current segment.
        int x = s.getX();
        int y = s.getY();
        //Draw the segment at its x and y position 
        //and at the given cell size.
        seg.x = s.getX();
        seg.y = s.getY();
        seg.w = m_cellSize;
        seg.h = m_cellSize;
        SDL_RenderFillRect(m_renderer, &seg);
    }
}

/**
* Draws the food for the snake game using the window and
* renderer variables.
*/
void Display::drawFood(Food food) {
    //If the food has not been eaten, it can be rendered.
    if (!food.getEaten()) {
        //Set the render color to red.
        SDL_SetRenderDrawColor(m_renderer, 255, 0, 0, 255);
        //Draw a rectangle at the fruit's x and y position 
        //and at the given cell size.
        SDL_Rect fruit;
        fruit.x = food.getX();
        fruit.y = food.getY();
        fruit.w = m_cellSize;
        fruit.h = m_cellSize;
        SDL_RenderFillRect(m_renderer, &fruit);
    }
}

/**
* Draws the game over scene for the snake game using the
* window and renderer variables.
*/
void Display::drawGameOver() {
    //Set renderer to pink and color the whole screen pink.
    SDL_SetRenderDrawColor(m_renderer, 255, 169, 210, 255);
    SDL_RenderClear(m_renderer);
    SDL_RenderPresent(m_renderer);
    //Wait 3 seconds then quit the program.
	SDL_Delay(3000);
	SDL_Quit();
}

/**
* Visually presents the renderer to the user.
*/
void Display::Present() {
    SDL_RenderPresent(m_renderer);
}