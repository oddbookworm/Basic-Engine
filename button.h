#include <SFML/Graphics.hpp>

#ifndef BUTTON_H
#define BUTTON_H

class Button
{
    public:
        Button(int, int, float, float);
        sf::RectangleShape getShape();

    private:
        sf::RectangleShape shape;

};

#endif