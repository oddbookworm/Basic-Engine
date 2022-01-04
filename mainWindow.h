#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

class MainWindow
{
    private:
        int windowSize [2];
        sf::Window window;

    public:
        MainWindow();
        bool createWindow();

};

#endif