#include "controller.h"

Controller::Controller()
{
    playerX = 1, playerY = 0;
    //qDebug() << "qwq";
    status = 0;
}

void Controller::setMap(MazeMap *map)
{
    this -> map = map;
}

bool Controller::isOver()
{
    return status;
}

void Controller::reset()
{

}

bool Controller::makeMove(int direction)
{
    return 1;
}
