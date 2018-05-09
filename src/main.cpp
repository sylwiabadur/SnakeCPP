#include <SFML/Graphics.hpp>
#include <iostream>
#include <ctime>
#include "./managers/ViewManager.h"
#include "./managers/GameManager.h"
#include "./views/View.h"
#include "./views/Menu.h"
#include "./views/Game.h"
#include "./views/Score.h"
using namespace std;
int main()
{
    srand(time(NULL));
    sf::RenderWindow *window = new sf::RenderWindow(sf::VideoMode(GameManager::get().width, GameManager::get().height), "SFML window");
    View *menu = new Menu();
    View *game = new Game();
    View *score = new Score();
    sf::Font *font = new sf::Font;
    ViewManager::get().assignFont(font);
    if (!font->loadFromFile("./assets/arial.ttf"))
    {
        cout << "Blad w ladowaniu czcionki" << endl;
    }
    window->setFramerateLimit(30);
    ViewManager::get().addView(menu);
    ViewManager::get().addView(game);
    ViewManager::get().addView(score);
    ViewManager::get().assignWindow(window);

    ViewManager::get().changeView("menu");
    // Start the game loop
    while (!ViewManager::get().quit)
    {
        // Process events
        sf::Event event;
        while (window->pollEvent(event))
        {
            ViewManager::get().handleEvent(&event);
            // Close window : exit
            if (event.type == sf::Event::Closed)
                window->close();
        }
        ViewManager::get().renderView();
    }
    return EXIT_SUCCESS;
}