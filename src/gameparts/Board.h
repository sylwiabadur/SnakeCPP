#ifndef UNTITLED5_BOARD_H
#define UNTITLED5_BOARD_H
#include <string>
#include <SFML/Graphics.hpp>
#include "../managers/GameManager.h"
class Board
{
  public:
    Board();
    ~Board();
    void renderGrid(sf::RenderWindow *window, int width, int height);
    void handleEvent(sf::Event *e);
};
#endif //UNTITLED5_BOARD_H