/**
 * 一个对象就是一局游戏(?)
 * 游戏主体控制器，控制游戏内部运行，包括：
 * 通过键盘获取用户按键
 * 控制人物移动
 * 胜利条件判断
 */

#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QDebug>
#include "mazemap.h"

class Controller
{
public:
    Controller();
    void setMap(MazeMap *);
    bool isOver();
    bool makeMove(int); //1 2 4 8
    void reset();
private:
    //人物位置　行 列
    int playerX, playerY;
    //0进行中，1已结束
    bool status;
    MazeMap *map;
};

#endif // CONTROLLER_H
