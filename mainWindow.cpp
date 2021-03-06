#include <fstream>
#include "mainWindow.h"
#include <SFML/Window/Mouse.hpp>

MainWindow::MainWindow()
{
    std::ifstream ifs("settings.json");
    settings = nlohmann::json::parse(ifs);

    windowSize[0] = std::stoi(settings.value("MainWindowWidth", "1280"));
    windowSize[1] = std::stoi(settings.value("MainWindowHeight", "720"));

    createButton();
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
            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    int xPos = event.mouseButton.x;
                    int yPos = event.mouseButton.y;

                    for (int i = 0; i < buttons.size(); i++)
                    {
                        Button button = buttons[i];
                        int xMin = button.getShape().getPosition().x;
                        int xMax = button.getShape().getPosition().x + buttons[i].getShape().getSize().x;
                        int yMin = button.getShape().getPosition().y;
                        int yMax = button.getShape().getPosition().y + buttons[i].getShape().getSize().y;

                        if (xPos >= xMin && xPos <= xMax && yPos >= yMin && yPos <= yMax)
                        {
                            std::cout << "Button Pressed" << std::endl;
                            button.doAction();
                        }
                    }
                }
            }

            window.clear();
            for (int i = 0; i < buttons.size(); i++)
            {
                window.draw(buttons[i].getShape());
            }
            window.display();
        }
    }
    return 1;
}

void tempFunction()
{
    std::cout << "Function Performed" << std::endl;
}

bool MainWindow::createButton()
{
    Button newButton = Button(100, 50, 20, 10, tempFunction);
    buttons.push_back(newButton);
}