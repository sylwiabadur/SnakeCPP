#include "Score.h"
Score::Score()
{
    name = "score";
} 
Score::~Score()
{
}
void Score::render(sf::RenderWindow *window)
{
    window->draw(*rect);
    window->draw(*image);
    window->draw(*text);
    window->draw(*text2);
}
void Score::handleEvent(sf::Event *e)
{
    if (e->type == sf::Event::KeyPressed)
    {
        if (e->key.code == sf::Keyboard::Escape)
        {
            ViewManager::get().exit();
        }
        else if(e->key.code ==sf::Keyboard::Space)
        {
            ViewManager::get().changeView("game");
        }
    }
}
void Score::init()
{
    rect = new sf::RectangleShape;
    rect->setSize(sf::Vector2f(GameManager::get().width, GameManager::get().height));
    rect->setPosition(0, 0);
    rect->setFillColor(sf::Color(0, 100, 0));
    png = new sf::Texture;
    png->loadFromFile("./assets/gameover.png");
    image = new sf::Sprite;
    image->setTexture(*png, true);
    image->setPosition(GameManager::get().width * 0.6, GameManager::get().height * 0.7);
    text = new sf::Text;
    text->setFont(*ViewManager::get().getFont());
    text->setFillColor(sf::Color(255, 204, 0));
    text->setCharacterSize(30);
    text->setPosition(sf::Vector2f(0.4 * GameManager::get().width, 0.4 * GameManager::get().height));
    if (GameManager::get().points >= 150)
    {
        text->setString("Good job!");
    }
    else
        text->setString("Try again!");
    text2 = new sf::Text;
    text2->setFont(*ViewManager::get().getFont());
    text2->setFillColor(sf::Color(255, 204, 0));
    text2->setCharacterSize(30);
    text2->setPosition(sf::Vector2f(0.35 * GameManager::get().width, 0.5 * GameManager::get().height));
    text2->setString("Lenght:" + std::to_string(GameManager::get().finalLength) + " Points:" + std::to_string(GameManager::get().points));
}