#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "json.hpp"
#include "button.h"

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

class MainWindow
{
    private:
        int windowSize [2];
        std::string windowTitle;
        sf::RenderWindow window;
        nlohmann::json settings;
        std::vector<Button> buttons;

        bool createWindow();
        bool runWindow();
        bool createButton();
        bool checkButtonClick();

    public:
        MainWindow();

};

#endif