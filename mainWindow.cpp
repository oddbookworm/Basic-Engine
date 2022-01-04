#include "mainWindow.h"

MainWindow::MainWindow()
{
    if (createWindow())
    {
        std::cout << "Window Successfully Created" << std::endl;
    }
}

bool MainWindow::createWindow()
{
    sf::Window window(sf::VideoMode(windowSize[0], windowSize[1]), "Main Window");

    return 1;
}