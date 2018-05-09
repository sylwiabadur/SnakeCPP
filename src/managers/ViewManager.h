#ifndef UNTITLED5_VIEWMANAGER_H
#define UNTITLED5_VIEWMANAGER_H
#include <SFML/Graphics.hpp>
#include "../views/View.h"
#include <string>
#include <iostream>
/* Singleton */

class ViewManager
{
  std::map<std::string, View *> views;
  View *view = NULL;
  ViewManager();
  ViewManager(const ViewManager &);
  sf::RenderWindow *vwindow; //window for view
  sf::Font *vfont;

public:
  bool quit;
  void exit();
  void addView(View *v);
  void remoweView(std::string name);
  void changeView(std::string name);
  void updateView();
  void assignWindow(sf::RenderWindow *window);
  void assignFont(sf::Font *font);
  sf::RenderWindow *getWindow();
  sf::Font *getFont();
  void renderView();
  void handleEvent(sf::Event *e);

  static ViewManager &get();
};

#endif //UNTITLED5_VIEWMANAGER_H