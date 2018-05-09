#include "SnakePart.h"
SnakePart::SnakePart() {}
SnakePart::SnakePart(sf::Vector2i posv)
{
    rect.setSize(sf::Vector2f(GameManager::get().gridWidth - 1, GameManager::get().gridHeight - 1));
    rect.setFillColor(sf::Color(0, 255, 0));
    setPos(posv);
}