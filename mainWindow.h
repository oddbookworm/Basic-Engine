#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "json.hpp"

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

class MainWindow
{
    private:
        int windowSize [2];
        std::string windowTitle;
        sf::Window window;
        nlohmann::json settings;

        bool createWindow();
        bool runWindow();

    public:
        MainWindow();

};

#endif