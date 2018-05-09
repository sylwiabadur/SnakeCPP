#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "SnakePart.h"
#include "Food.h"
#include "../managers/GameManager.h"
#include "../managers/ViewManager.h"
#include <vector> 
class Snake
{
  std::vector<SnakePart> snake;
  sf::Vector2i moveDirection;
  sf::Vector2i moveDirectionActual;
public:
  Snake();
  void render(); 
  void move(Food *food);
  bool foodCollision(Food *food);
  bool wallCollision();
  bool bodyCollision();
  void handleEvent(sf::Event *e);
  std::vector<SnakePart> getVector();
};
