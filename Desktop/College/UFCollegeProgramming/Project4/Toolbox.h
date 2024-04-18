#pragma once
// #include "GameState.h"
// #include "Button.h"

class Toolbox
{
    private:
        Toolbox()
        {
            ;
        };
    public:
        static Toolbox &getInstance()
        // : window(element)
        {
            static Toolbox mine;
            return mine;
        };
        //This was the Hardest ^
        sf::RenderWindow window = sf::RenderWindow(sf::VideoMode(800, 600), "P4 - Minesweeper, Aiden Thomas");
        // T* gameState;
        // P* debugBut;
        // P* newGameButton;
        // P* testButton1;
        // P* testButton2;
};