#include "Button.h"

Button::Button(sf::Vector2f pos)
{
    position = pos;
    width = 150;
    height = 80;
    border=3;
    active=false;

    rect.setSize(sf::Vector2f(width, height));
    rect.setPosition(pos);
    rect.setFillColor(sf::Color(255, 204, 0));
    rect.setOutlineThickness(border);
    rect.setOutlineColor(sf::Color(0, 50, 0));
}
void Button::render()
{
    ViewManager::get().getWindow()->draw(rect);
    ViewManager::get().getWindow()->draw(text);
}
Button *Button::onClick(void (*cb)(void))
{
    callback = cb;
    return this;
}

Button *Button::setTxt(std::string txt)
{
    text.setPosition(sf::Vector2f(position.x+width*0.3,position.y+height*0.3));
    text.setFillColor(sf::Color(0, 0, 0));
    text.setCharacterSize(25);
    text.setFont(*ViewManager::get().getFont());
    text.setString(txt);
}
void Button::handleEvent(sf::Event *e)
{
    
  if (e->type == sf::Event::MouseMoved || e->type == 9 || e->type == 10)
  {

    int x, y; //pozycja 
    x=e->mouseButton.x;
    y=e->mouseButton.y;

    bool inside = true;
    if (x < position.x-border)
    {
      inside = false;
    }
    else if (x > position.x + width + border)
    {
      inside = false;
    }
    else if (y < position.y - border)
    {
      inside = false;
    }
    else if (y > position.y + height + border)
    {
      inside = false;
    }
    if (!inside)
    {

    }
    else
    {
      switch (e->type)
      {
      case sf::Event::MouseMoved:
        break;

      case 9:
        active = true;
        break;

      case 10:
        if (active)
        {
          callback();
        }
        active = false;
        break;
      }
    }
  }
}