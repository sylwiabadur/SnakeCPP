#ifndef UNTITLED5_SNAKEPART_H
#define UNTITLED5_SNAKEPART_H
#include "Part.h"
#include <SFML/Graphics.hpp>
class SnakePart: public Part
{
public:
  SnakePart();
  SnakePart(sf::Vector2i posv);
};
#endif //UNTITLED5_SNAKEPART_H