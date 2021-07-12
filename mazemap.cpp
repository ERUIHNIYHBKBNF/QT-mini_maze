#include "MazeMap.h"

MazeMap::MazeMap()
{
    //暂时用作测试数据
    this -> height = 5;
    this -> width = 5;
    this -> map = vector<vector<int> >{
        {1, 1, 1, 1, 1},
        {3, 0, 1, 0, 1},
        {1, 0, 1, 0, 1},
        {1, 0, 0, 0, 4},
        {1, 1, 1, 1, 1}};
}

void MazeMap::setSize(int height, int width)
{
    this -> height = height;
    this -> width = width;
}

void MazeMap::setMap(vector<vector<int>> map)
{
    this -> map = map;
}

int MazeMap::getHeight()
{
    return this -> height;
}

int MazeMap::getWidth()
{
    return this -> width;
}

vector<vector<int> > MazeMap::getMap()
{
    return this -> map;
}
