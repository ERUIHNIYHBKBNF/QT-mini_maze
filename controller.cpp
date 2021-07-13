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

void Controller::reset()
{

}
