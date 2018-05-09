#ifndef UNTITLED5_SCORE_H
#define UNTITLED5_SCORE_H
#include "View.h"
#include <SFML/Graphics.hpp>
#include "../managers/ViewManager.h"
#include "../managers/GameManager.h"
class Score : public View
{
  sf::RectangleShape *rect;
  sf::Texture *png;
  sf::Sprite *image;
  sf::Text *text;
  sf::Text *text2;

public:
  Score();
  ~Score();
  void render(sf::RenderWindow *window);
  void handleEvent(sf::Event *e);
  void init();
};

#endif //UNTITLED5_SCORE_H