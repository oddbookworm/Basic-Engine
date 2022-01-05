#include "button.h"

Button::Button(int x, int y, float width, float height, std::function<void()> func)
{
    shape = sf::RectangleShape(sf::Vector2f(width, height));
    shape.setPosition(x, y);
    shape.setFillColor(sf::Color(255, 0, 0));
    action = func;
}

sf::RectangleShape& Button::getShape()
{
    return shape;
}

void Button::doAction()
{
    action();
}