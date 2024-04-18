#pragma once
#include "Toolbox.h"


class Tile
{
    // extern Toolbox * Toolbox::getInstance();
    private:
        sf::Vector2f Position;
        bool bomb;
        sf::Sprite basesprite;
        sf::Sprite FlagS;
        sf::Texture baseTile;
        sf::Texture Flag;
        // sf::Sprite nums[8];
        sf::Sprite number;
        sf::Texture settter;
        sf::Texture emptyTile;
        sf::Sprite emptySprite;
        sf::Texture BombText;
        sf::Sprite Bomber;
        // const bool neigh[3][3] = {{true, false, false}, {false, false, false},{false, false,false}};
        // Toolbox &toolbox = Toolbox::getInstance();

        // sf::WindowHandle handler;
        // std::array<Tile*,8> neighbor;
    public:
        enum State { REVEALED, HIDDEN, FLAGGED, EXPLODED};
        Tile()
        {
            ;
        }
        Tile(bool neighbor[3][3], sf::Vector2i _dimension = sf::Vector2i(0,0), bool _bomb = false)
        {
            baseTile.loadFromFile("../images/tile_hidden.png");
            basesprite = sf::Sprite(baseTile);
            Flag.loadFromFile("../images/flag.png");
            BombText.loadFromFile("../images/mine.png");
            Bomber = sf::Sprite(BombText);
            emptyTile.loadFromFile("../images/tile_revealed.png");
            emptySprite = sf::Sprite(emptyTile);
            int count = 0;
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    if (neighbor[i][j])
                    {
                        count++;
                    }
                }
            }

            if (count != 0 && _bomb==false)
            {

                settter.loadFromFile("../images/number_"+std::to_string(count)+".png");
                number = sf::Sprite(settter);
            }

            //This Can be used to store a array of Sprites

            // for (int i =0; i < 8; i++)
            // {
            //     std::string testStringer = "../images/number_"+std::to_string(i+1)+".png";
            //     sf::Texture *settter = new sf::Texture();
            //     settter->loadFromFile(testStringer);
            //     nums[i] = sf::Sprite(*settter);
            // }
            FlagS = sf::Sprite(Flag);
            sf::FloatRect BaseRect = basesprite.getLocalBounds();
            Position.x = _dimension.x*BaseRect.width;
            Position.y = _dimension.y*BaseRect.height;
            basesprite.move(Position);
            FlagS.move(Position);
            number.move(Position);
            emptySprite.move(Position);
            Bomber.move(Position);
            
            bomb = _bomb;
            // handler = _handler;
        };

        State getState()
        {
            return shown;
        }

        void OnLeftClick()
        {
            if (shown != FLAGGED)
            {
                if (bomb)
                {
                    shown = EXPLODED;
                }
                else
                {
                    shown = REVEALED;
                }
            }
        }

        void OnRightClick()
        {
            if (shown = HIDDEN)
            {
                shown = FLAGGED;
            }
            else if (shown = FLAGGED)
            {
                shown = HIDDEN;
            }
        }

        void draw()
        {
            //Draw the sprite into the window class in the toolbox
            // toolbox = Toolbox::getInstance();
            // sf::RectangleShape recter(sf::Vector2f(15,15));
            Toolbox &toolbox = Toolbox::getInstance();
            if (bomb)
            {
                shown = EXPLODED;
            }
            else
            {
                shown = REVEALED;
            }
            switch (shown)
            {
            case FLAGGED:
                toolbox.window.draw(basesprite);
                toolbox.window.draw(FlagS);
                break;
            case REVEALED:
                toolbox.window.draw(emptySprite);
                toolbox.window.draw(number);
                break;
            case EXPLODED:
                toolbox.window.draw(emptySprite);
                toolbox.window.draw(Bomber);
                break;
            default:
                toolbox.window.draw(basesprite);
            }
        }
    private:
        State shown = HIDDEN;
};