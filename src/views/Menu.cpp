#include "Menu.h"

Menu::Menu()
{
    name = "menu";
}
Menu::~Menu() {}
void Menu::render(sf::RenderWindow *window)
{
    window->draw(*rect);
    window->draw(*text);
    window->draw(*image);
    button1->render();
    button2->render();
    button3->render();
}
void Menu::handleEvent(sf::Event *e)
{
     if (e->type == sf::Event::KeyPressed)
    {
        if (e->key.code == sf::Keyboard::Escape)
        {
            ViewManager::get().exit();
        }
    }
    button1->handleEvent(e);
    button2->handleEvent(e);
    button3->handleEvent(e);
}
void Menu::init()
{
    rect = new sf::RectangleShape;
    rect->setSize(sf::Vector2f(GameManager::get().width, GameManager::get().height));
    rect->setPosition(0, 0);
    rect->setFillColor(sf::Color(0, 100, 0));
    text = new sf::Text;
    text->setFont(*ViewManager::get().getFont());
    text->setFillColor(sf::Color(255, 204, 0));
    text->setCharacterSize(30);
    text->setOutlineThickness(2);
    text->setPosition(sf::Vector2f(0.2 * GameManager::get().width, 0.4 * GameManager::get().height));
    text->setString("Welcome! Choose speed to start!");

    png = new sf::Texture;
    png->loadFromFile("./assets/snake.png");
    image = new sf::Sprite;
    image->setTexture(*png, true);
    image->setPosition(GameManager::get().width * 0.5, GameManager::get().height * 0.7);
    //creating objects and making them class variables
    button1 = new Button(sf::Vector2f(50, 350));
    button1->setTxt("Slow");
    button2 = new Button(sf::Vector2f(275, 350));
    button2->setTxt("Normal");
    button3 = new Button(sf::Vector2f(500, 350));
    button3->setTxt("Fast");

    button1->onClick([]() {
        GameManager::get().interval=1000;
        ViewManager::get().changeView("game");
    });
      button2->onClick([]() {
        GameManager::get().interval=500;
        ViewManager::get().changeView("game");
    });
      button3->onClick([]() {
        GameManager::get().interval=200;
        ViewManager::get().changeView("game");
    });
}