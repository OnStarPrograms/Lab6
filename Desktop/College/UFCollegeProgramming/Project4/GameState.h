#pragma once
#include <SFML/Graphics.hpp>
#include "tile.h"
#include "Toolbox.h"
// #include <array>

/*

Goal:

    Implement a board of 1's and 0's to figure out where to place the mines
    Navigate through that board to build a teensy board of 3x3 and manually turn the [1][1] to false
    and put that into the Tile being built rn, if the [0][0], [2][0], [0][2], and [2],[2] arent in the list,
        register as false permenantly
    set it like

    abba[0][0] = Listp[i-1][i-1]
    abba[0][1] = Listp[i-1][i]
    ...

    then for tiles

        where there is a 0 just put in Listp[i][j];

*/


class GameState
{
    public:
        enum PlayStatus { WIN, LOSS, PLAYING};
        GameState(sf::Vector2i _dimensions = sf::Vector2i(25, 16), int _numberOfMines = 50)
        {
            dimensions = _dimensions;
            MineCount = _numberOfMines;
            FlagCount = 0;
            Status = PLAYING;
            for (int i = 1; i < 26; i++)
            {
                for (int j = 1; j < 17; j++)
                {
                    map[i][j] = false;
                    if ((i+j)%3 == 0)
                    {
                        map[i][j] = true;
                    }
                }
            }
            for (int i = 0; i < 27; i++)
            {
                map[i][0] = false;
                map[i][17] = false;
            }
            for (int i = 0; i < 18; i++)
            {
                map[0][i] = false;
                map[26][i] = false;
            }


            for (int i =0; i < 25; i++)
            {
                for (int j = 0; j < 16; j++)
                {
                    bool lilmap[3][3];
                    //for Some reason this works as is, dont touch it ig
                    // if(i != 0 && i != 24 && j != 0 && j != 15)
                    // {
                        lilmap[0][0] = map[i][j];
                        lilmap[0][1] = map[i][j+1];
                        lilmap[0][2] = map[i][j+2];
                        lilmap[2][0] = map[i+2][j];
                        lilmap[2][1] = map[i+2][j+1];
                        lilmap[2][2] = map[i+2][j+2];
                        lilmap[1][0] = map[i+1][j];
                        lilmap[1][2] = map[i+1][j+2];   
                    // }
                    lilmap[1][1] = false;
                    bool abba[3][3] = {{false, false, false}, {false, false, false},{false, false,false}};
                    Tile* aba = new Tile(lilmap, sf::Vector2i(i,j), map[i+1][j+1]);
                    tileMap[i][j] = *aba;
                }
            }
            //Implement a Tile Builder
        };

        //Need to build a File Reader
        GameState(const char* filepath);


        int getFlagCount(){return FlagCount;};
        int getMineCount(){return MineCount;};
        PlayStatus getPlayStatus()
        {
            return Status;
        };
        void setPlayStatus(PlayStatus _status)
        {
            Status = _status;
        };
        void run()
        {
            for (int i = 0; i < 25; i++)
            {
                for (int j = 0; j < 16; j++)
                {
                    tileMap[i][j].draw();
                }
            }
        }
    private:
        PlayStatus Status;
        int FlagCount;
        int MineCount;
        sf::Vector2i dimensions;
        Tile tileMap[25][16];
        bool map[27][18];
};