#include "button.h"

Button::Button(int x, int y, float width, float height)
{
    shape = sf::RectangleShape(sf::Vector2f(width, height));
    shape.setPosition(x, y);
    shape.setFillColor(sf::Color::Red);
}

sf::RectangleShape& Button::getShape()
{
    return shape;
}