#include "Part.h"
Part::Part() {}
Part::Part(sf::Vector2i posv)
{
    rect.setSize(sf::Vector2f(GameManager::get().gridWidth - 1, GameManager::get().gridHeight - 1));
    setPos(posv);
}
sf::Vector2i Part::getPos()
{ 
    return pos;
}
void Part::render()
{
    ViewManager::get().getWindow()->draw(rect);
}
void Part::setPos(sf::Vector2i position) //(kolumna,rzad)
{
    pos = position;
    rect.setPosition(sf::Vector2f(position.x * GameManager::get().gridWidth, position.y * GameManager::get().gridHeight));
}