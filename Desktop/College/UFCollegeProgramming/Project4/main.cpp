#include <SFML/Graphics.hpp>
#include <string>
#include <array>
#include "Toolbox.h"
#include "GameState.h"
// #include "Button.h"

int launch();
void restart();
int gameloop();
bool getDebugMode();


int main()
{
    return launch();
}


//Launcher
int launch()
{
    //reset all vars
    // Toolbox<GameState, Button> &toolbox = Toolbox<GameState, Button>::getInstance();
    // delete &toolbox;
    int check_repeat = gameloop();
    if (check_repeat)
    {
        restart();
    }
    return 0;
}


//Restarts the game loop
void restart()
{
    launch();
}

int gameloop()
{
        // Declare and create a new render-window
    Toolbox &toolbox = Toolbox::getInstance();
    GameState Game = GameState();
    sf::Mouse mouse;
    sf::Font font;
    // sf::RenderWindow window(sf::VideoMode(800, 600), "P4 - Minesweeper, Aiden Thomas");
    // sf::WindowBase WinBase(window.getSystemHandle());
    // Limit the framerate to 60 frames per second (this step is optional)
    toolbox.window.isOpen();
    // Tile TestTile = Tile(sf::Vector2i(125,125), 0);
    // sf::RenderWindow nwindow(toolbox.window);
    toolbox.window.setFramerateLimit(60);
    // The main loop - ends as soon as the window is closed
    while (toolbox.window.isOpen())
    {
        //Mouse Tracking 
        sf::Vector2i mousevec = mouse.getPosition(toolbox.window);
        std::string debugx = "x:>" + std::to_string(mousevec.x);
        std::string debugy = "y:>" + std::to_string(mousevec.y);

        //Mouse Printing {Deactivate at the end}
        font.loadFromFile("../Cave-Story.ttf");
        sf::Text debugTextx(debugx, font);
        sf::Text debugTexty(debugy, font);
        sf::Vector2f vec;
        sf::Vector2u nvec = toolbox.window.getSize();
        vec.x = 0;
        vec.y = 500;
        debugTextx.move(vec);
        vec.y = 520;
        debugTexty.move(vec);



        // Event processing
        sf::Event event;
        while (toolbox.window.pollEvent(event))
        {
            // Request for closing the window
            if (event.type == sf::Event::Closed)
                toolbox.window.close();
        }
        
        // Clear the whole window before rendering a new frame
        toolbox.window.clear();
        
        // Draw some graphical entities
        // window.draw(sprite);
        // window.draw(circle);
        Game.run();
        toolbox.window.draw(debugTextx);
        toolbox.window.draw(debugTexty);
        // TestTile.draw();
        // End the current frame and display its contents on screen
        toolbox.window.display();
    }
    return 0;
}


bool getDebugMode()
{
    return true;
}