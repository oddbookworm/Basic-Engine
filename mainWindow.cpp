#include <fstream>
#include "mainWindow.h"

MainWindow::MainWindow()
{
    std::ifstream ifs("settings.json");
    settings = nlohmann::json::parse(ifs);

    windowSize[0] = std::stoi(settings.value("MainWindowWidth", "500"));
    windowSize[1] = std::stoi(settings.value("MainWindowHeight", "500"));

    if (createWindow())
    {
        std::cout << "Window Opened" << std::endl;
        runWindow();
    }
}

bool MainWindow::createWindow()
{
    window.create(sf::VideoMode(windowSize[0], windowSize[1]), settings.value("MainWindowTitle", "Main Window"));
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