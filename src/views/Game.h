#ifndef UNTITLED5_GAME_H
#define UNTITLED5_GAME_H
#include "View.h"
#include <SFML/Graphics.hpp>
#include "../managers/ViewManager.h"
#include "../managers/GameManager.h"
#include "../gameparts/Board.h"
#include "../gameparts/SnakePart.h"
#include "../gameparts/Snake.h"
#include "../gameparts/Food.h" 
class Game : public View 
{
  sf::RectangleShape *rect;
  sf::Clock *clock;

public:
  Game();
  ~Game();
  void render(sf::RenderWindow *window);
  void handleEvent(sf::Event *e);
  void init();
  Board *board;
  Snake *snake;
  Food *food;
};

#endif //UNTITLED5_GAME_H