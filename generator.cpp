#include "generator.h"
generator::generator(int row0, int column0)
{
    row1 = row0;
    column1 = column0;
    qwq.setSize(row0,column0);
}

void generator::init()
{
    memset(M,WALL,sizeof(M));
    M[1][1] = NOTHING;
    startX = startY = 1;
    //定义起始点
}
void generator::findBlock()
{
        //找出与当前位置相邻的墙
    if(x+1<=row1 && M[x+1][y] == WALL)
    {//down
        myblock.push_back(block(x+1,y,down));
    }
    if(y+1<=column1 && M[x][y+1] == WALL)
    {//right
        myblock.push_back(block(x,y+1,right));
    }
    if(x-1>=1 && M[x-1][y] == WALL)
    {//up
        myblock.push_back(block(x-1,y,up));
    }
    if(y-1>=1 && M[x][y-1] == WALL)
    {//left
        myblock.push_back(block(x,y-1,left));
    }
}
void generator::genMaze()
{
    int i,j;
    init();
    srand((unsigned)time(NULL));//随机数种子
    findBlock();
    while(myblock.size()) {
        int BlockSize = myblock.size();
        //随机选择一堵墙（生成0 ~ BlockSize-1之间的随机数，同时也是vector里墙的下标）
        int randnum = rand() % BlockSize;
        block SelectBlock = myblock[randnum];
        x = SelectBlock.row;
        y = SelectBlock.column;
        //根据当前选择的墙的方向进行后续操作
        switch(SelectBlock.direction) {
            case down: {
                x++;
                break;
            }
            case right: {
                y++;
                break;
            }
            case left: {
                y--;
                break;
            }
            case up: {
                x--;
                break;
            }
        }
        //目标块如果是墙
        if(M[x][y]==WALL) {
            M[SelectBlock.row][SelectBlock.column] = M[x][y] = NOTHING;
            findBlock();
        }
        //删除这堵墙(把用不了的墙删了，确保跳出循环)
        myblock.erase(myblock.begin()+randnum);
    }
    maze.resize(row1+2);
    for(i = 0; i<=row1+1;i++)
        maze[i].resize(column1+2);
    for (i=0;i<=row1+1;i++) {
        for (j=0;j<=column1+1;j++) {
            if(i == startX && j == startY) {
                printf("%c%c",0xa7,0xb0 );
            }
            else if(M[i][j] == NOTHING) {
                maze[i][j] = 0;
                printf("  ");
            }
            else if(i==1&&j==0)
            {
                maze[i][j] = 0;
                printf("  ");
            }
            else if(i==row1&&j==column1+1)
            {
                maze[i][j] = 0;
                printf("  ");
            }
            else
            {
                maze[i][j] = 1;
                printf("%c%c", 0xa8, 0x80);
            }
        }
    qwq.setMap(maze);
        printf("\n");
}
}
