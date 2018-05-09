#ifndef UNTITLED5_PART_H
#define UNTITLED5_PART_H
#include <SFML/Graphics.hpp>
#include <vector>
#include "../managers/ViewManager.h"
#include "../managers/GameManager.h"

class Part
{
  protected:
  sf::Vector2i pos; 
  sf::RectangleShape rect;

public:
  Part();
  Part(sf::Vector2i posv);
  sf::Vector2i getPos();
  void render();
  void setPos(sf::Vector2i position);
};

#endif //UNTITLED5_PART_H