#include "mazemap.h"

mazemap::mazemap()
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

void mazemap::setSize(int height, int width)
{
    this -> height = height;
    this -> width = width;
}

void mazemap::setMap(vector<vector<int>> map)
{
    this -> map = map;
}

int mazemap::getHeight()
{
    return this -> height;
}

int mazemap::getWidth()
{
    return this -> width;
}

vector<vector<int> > mazemap::getMap()
{
    return this -> map;
}
