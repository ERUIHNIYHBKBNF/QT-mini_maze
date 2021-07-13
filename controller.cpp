#include "controller.h"

Controller::Controller()
{
    this -> playerX = 1, this -> playerY = 0;
    qDebug() << "qwq";
}

void Controller::setMap(MazeMap *map)
{
    this -> map = map;
}

bool Controller::isOver()
{
    return !this -> status;
}

void Controller::reset()
{

}

bool Controller::makeMove(int direction)
{
    return 1;
}
