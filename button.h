#include <SFML/Graphics.hpp>
#include <functional>

#ifndef BUTTON_H
#define BUTTON_H

class Button
{
    public:
        Button(int, int, float, float, std::function<void()>);
        sf::RectangleShape& getShape();
        void doAction();

    private:
        sf::RectangleShape shape;
        std::function<void()> action;

};

#endif