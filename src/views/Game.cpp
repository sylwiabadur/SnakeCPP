#include "Game.h"
Game::Game()
{
    name = "game";
}
Game::~Game()
{
}
void Game::render(sf::RenderWindow *window)
{
    window->draw(*rect);
    board->renderGrid(window, GameManager::get().width, GameManager::get().height);
    if (clock->getElapsedTime().asMilliseconds() >= GameManager::get().interval)
    {
        clock->restart();
        snake->move(food);
    }
    snake->render();
    food->render();
}
void Game::handleEvent(sf::Event *e)
{
    snake->handleEvent(e);
    if (e->type == sf::Event::KeyPressed)
    {
        if (e->key.code == sf::Keyboard::Escape)
        {
            ViewManager::get().exit();
        }
    }
}
void Game::init()
{
    GameManager::get().points=0;
    GameManager::get().finalLength=4;
    board = new Board();
    snake = new Snake();
    food = new Food(snake->getVector());
    rect = new sf::RectangleShape;
    rect->setSize(sf::Vector2f(GameManager::get().width, GameManager::get().height));
    rect->setPosition(0, 0);
    rect->setFillColor(sf::Color(80, 80, 80));
    clock = new sf::Clock;
    clock->restart();
}