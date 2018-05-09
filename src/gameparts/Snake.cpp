#include "Snake.h"
Snake::Snake()
{
    moveDirection = sf::Vector2i(1, 0); //right
    SnakePart part = SnakePart(sf::Vector2i(0, 0));
    snake.push_back(part);
    part = SnakePart(sf::Vector2i(1, 0));
    snake.push_back(part);
    part = SnakePart(sf::Vector2i(2, 0));
    snake.push_back(part);
    part = SnakePart(sf::Vector2i(3, 0));
    snake.push_back(part);
}
void Snake::render()
{
    for (auto part : snake)
    {
        part.render();
    }
}
void Snake::move(Food *food)
{
    moveDirectionActual = moveDirection;
    SnakePart element;
    element = snake.at(0);
    if (!foodCollision(food))
    {
        snake.erase(snake.begin());
    }
    else
    {
        GameManager::get().points += 10;
        GameManager::get().finalLength += 1;
        // GameManager::get().playWin();
        food->setPos(snake); //wiem ze tu nie powinno tego byc bo to food
    }
    if (wallCollision() || bodyCollision())
        ViewManager::get().changeView("score");
    element.setPos(snake.at(snake.size() - 1).getPos() + moveDirectionActual);
    snake.push_back(element);
}
bool Snake::foodCollision(Food *food)
{
    return (food->getPos() == snake.at(snake.size() - 1).getPos() + moveDirectionActual);
}

bool Snake::wallCollision()
{
    sf::Vector2i tempPos = snake.at(snake.size() - 1).getPos() + moveDirectionActual;
    int columns = GameManager::get().columns;
    int rows = GameManager::get().rows;
    return (tempPos.x >= columns || tempPos.x < 0 || tempPos.y >= rows || tempPos.y < 0); //out of board
}
bool Snake::bodyCollision()
{
    sf::Vector2i tempPos = snake.at(snake.size() - 1).getPos() + moveDirectionActual;
    for (int i = 0; i < snake.size(); i++)
    {
        if (tempPos == snake.at(i).getPos())
        {
            return true;
        }
    }
    return false;
}

void Snake::handleEvent(sf::Event *e)
{
    if (e->type == sf::Event::KeyPressed)
    {  
        if (e->key.code == sf::Keyboard::Left && moveDirectionActual != sf::Vector2i(1, 0))
        {
            moveDirection = sf::Vector2i(-1, 0);
        }
        else if (e->key.code == sf::Keyboard::Right && moveDirectionActual != sf::Vector2i(-1, 0))
        {
            moveDirection = sf::Vector2i(1, 0);
        }
        else if (e->key.code == sf::Keyboard::Up && moveDirectionActual != sf::Vector2i(0, 1))
        {
            moveDirection = sf::Vector2i(0, -1);
        }
        else if (e->key.code == sf::Keyboard::Down && moveDirectionActual != sf::Vector2i(0, -1))
        {
            moveDirection = sf::Vector2i(0, 1);
        }
    }
}
std::vector<SnakePart> Snake::getVector()
{
    return snake;
}