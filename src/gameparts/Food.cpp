#include "Food.h"
Food::Food() {}
Food::Food(std::vector<SnakePart> snake)
{
    rect.setSize(sf::Vector2f(GameManager::get().gridWidth - 1, GameManager::get().gridHeight - 1));
    rect.setFillColor(sf::Color(255, 0, 0));
    setPos(snake);
}
void Food::randPos(std::vector<SnakePart> snake)
{
    int columns = GameManager::get().columns;
    int rows = GameManager::get().rows;
    bool overlap = false;
    do
    {   
        overlap = false;
        pos.x = rand() % (columns - 1);
        pos.y = rand() % (rows - 1);
        for (auto s : snake)
        {
            if (s.getPos() == pos)
                overlap = true;
        }
    } while (overlap);
}

void Food::setPos(std::vector<SnakePart> snake) //(kolumna,rzad)
{
    randPos(snake);
    rect.setPosition(sf::Vector2f(pos.x * GameManager::get().gridWidth, pos.y * GameManager::get().gridHeight));
}

// void Food::randPos(Snake* snake) //nie moge tego uzyc bo robi sie cykliczny include
// {
//     int columns = GameManager::get().columns;
//     int rows = GameManager::get().rows;
//     bool overlap;
//     do
//     {
//         pos.x = rand() % (columns - 1);
//         pos.y = rand() % (rows - 1);
//        overlap = false;
//         for (int i = 0; i < snake.size(); i++)
//         {
//             if (pos.x == snake.at(i).getPos().x || pos.y == snake.at(i).getPos().y)
//                 overlap = true;
//         }
//     } while (overlap);
// }