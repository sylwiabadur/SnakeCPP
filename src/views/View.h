#ifndef UNTITLED5_VIEW_H
#define UNTITLED5_VIEW_H
#include <SFML/Graphics.hpp>
#include <string>

class View{
    protected:
    std::string name; //name particular for every view-based class
    public:
    std::string getName();
    void setName (std::string n);
    virtual void render(sf::RenderWindow *window)=0; //pure virtual functions
    virtual void handleEvent(sf::Event *event)=0;
    virtual void init()=0;
    View();
    ~View();

};
#endif //UNTITLED5_VIEW_H