#ifndef UNTITLED5_FOOD_H
#define UNTITLED5_FOOD_H
#include <SFML/Graphics.hpp>
#include "Part.h"
#include "SnakePart.h"
#include "../managers/GameManager.h"
#include <vector>
class Food : public Part
{
public:
  Food();
  Food(std::vector<SnakePart> snake);
  void randPos(std::vector<SnakePart> snake);
  void setPos(std::vector<SnakePart> snake);
};
#endif //UNTITLED5_FOOD_H