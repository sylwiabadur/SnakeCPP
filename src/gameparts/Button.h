#ifndef UNTITLED5_SNAKE_H
#define UNTITLED5_SNAKE_H
#include <SFML/Graphics.hpp>
#include "../managers/ViewManager.h"
#include <string>
class Button
{
    int width;
    int height;
    int border;
    bool active;
    sf::RectangleShape rect;
    sf::Text text;
    void (*callback)(void);
    sf::Vector2f position;

  public:
    Button(sf::Vector2f pos);
    Button *onClick(void (*cb)(void));
    Button *setTxt(std::string txt);
    void handleEvent(sf::Event *e);
    void render();
};
#endif //UNTITLED5_SNAKE_H