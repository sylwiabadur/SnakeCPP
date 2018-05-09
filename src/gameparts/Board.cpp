#include "Board.h"

Board::Board()
{
}

Board::~Board() {

}
void Board::renderGrid(sf::RenderWindow *window, int width, int height)
{
    sf::VertexArray grid(sf::Lines);
    for (int x = 0; x < height; x += (GameManager::get().gridHeight))
    {
        grid.append(sf::Vector2f(0 + x, 0));      // start
        grid.append(sf::Vector2f(0 + x, height)); // end
        grid.append(sf::Vector2f(0, 0 + x));
        grid.append(sf::Vector2f(width, 0 + x));  
    }
    window->draw(grid);
}

void Board::handleEvent(sf::Event *e){}