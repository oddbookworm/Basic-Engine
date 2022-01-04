#include "mainWindow.h"

MainWindow::MainWindow()
{
    windowSize[0] = 500;
    windowSize[1] = 500;

    if (createWindow())
    {
        std::cout << "Window Opened" << std::endl;
        runWindow();
    }
}

bool MainWindow::createWindow()
{
    window.create(sf::VideoMode(windowSize[0], windowSize[1]), "Main Window");
    window.setVerticalSyncEnabled(true);
    return 1;
}

bool MainWindow::runWindow()
{
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
                std::cout << "Window Closed" << std::endl;
                return 0;
            }
        }
    }
    return 1;
}