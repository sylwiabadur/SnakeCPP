#include "GameManager.h"

GameManager::GameManager()
{
    height = 700;
    width = 700;
    interval = 300; //miliseconds
    rows = 10;
    columns = 10;
    gridHeight = height / rows;
    gridWidth = width / columns;
    points = 0; //zero punktow na starcie
    finalLength = 4;
}

GameManager &GameManager::get()
{
    static GameManager manager;
    return manager;
}
// void GameManager::playWin()
// {
//     sf::Music sound;
//     sound.openFromFile("C:/Users/Sylwiabadur/Desktop/snake/assets/Pickup_Coin8.ogg");
//     sound.setVolume(100);
//     sound.play();
// }