#include "controller.h"

Controller::Controller(MazeMap *map)
{
    playerX = 1, playerY = 0;
    //qDebug() << "qwq";
    status = 0;
    this -> map = map;
    this -> maze = map -> getMap();
    this -> maze[map -> getHeight() - 2][map -> getWidth() - 1] = 3;
}

bool Controller::isOver()
{
    return status;
}

bool Controller::makeMove(int direction)
{
    if (direction == 1)
    {
        if (playerX - 1 >= 0 && maze[playerX - 1][playerY] == 0)
        {
            playerX--;
            return 1;
        }
        else
            return 0;
    }
    else if (direction == 2)
    {
        if (maze[playerX][playerY + 1] == 3)
        {
            status = 1;
            return 1;
        }
        if (playerY + 1 < map -> getWidth() && maze[playerX][playerY + 1] == 0)
        {
            playerY++;
            return 1;
        }
        else
            return 0;
    }
    else if (direction == 4)
    {
        if (playerX + 1 < map -> getHeight() && maze[playerX + 1][playerY] == 0)
        {
            playerX++;
            return 1;
        }
        else
            return 0;
    }
    else if (direction == 8)
    {
        if (playerY - 1 >= 0 && maze[playerX][playerY - 1] == 0)
        {
            playerY--;
            return 1;
        }
        else
            return 0;
    }
    return 0;
}
