#ifndef UNTITLED5_MENU_H
#define UNTITLED5_MENU_H
#include "View.h"
#include <SFML/Graphics.hpp>
#include "../managers/ViewManager.h"
#include "../managers/GameManager.h"
#include "../gameparts/Button.h"
#include <iostream>
#include <string>

class Menu : public View
{
    sf::RectangleShape *rect;
    sf::Text *text;
    sf::Texture *png;
    sf::Sprite *image;
    Button *button1;
    Button *button2;
    Button *button3;

  public:
    Menu();
    ~Menu();
    void render(sf::RenderWindow *window);
    void handleEvent(sf::Event *e);
    void init();
};

#endif //UNTITLED5_MENU_H