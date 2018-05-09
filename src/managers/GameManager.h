#ifndef UNTITLED5_GAMEMANAGER_H
#define UNTITLED5_GAMEMANAGER_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

class GameManager{
    public:
    int height;
    int width;
    int interval;
    int gridHeight;
    int gridWidth;
    int rows;
    int columns;
    int points;
    int finalLength;
    GameManager();
    static GameManager &get();
    void playWin();
};

#endif //UNTITLED5_GAMEMANAGER_H