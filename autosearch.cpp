#include "autosearch.h"
autoSearch::autoSearch(vector<vector<int> > fMaze)
{
    int i;
    Ma = fMaze;
    row = fMaze.size();
    col = fMaze[1].size();
    book.resize(row);
    for(i = 0; i<row;i++)
        book[i].resize(col);
}
void autoSearch::dfs(int x,int y,int step)
{
    int next[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
    int tx, ty, i, k;
    if (x == row-2 && y == col-1)
    {
        if (step < mini)
        {
            mini = step;
            for (i = 0; i < mini; i++)
            {
                way[i].x = memo[i].x;
                way[i].y = memo[i].y;
            }
        }
        return ;
    }
    for (k = 0; k <= 3; k++)
    {
        tx = x + next[k][0];
        ty = y + next[k][1];
        if (tx < 1 || tx > row || ty < 1 || ty > col)
            continue;

        if (Ma[tx][ty] == 0 && book[tx][ty] == 0)
        {

            memo[top].x = tx;
            memo[top++].y = ty;
            book[tx][ty] = 1;
            dfs(tx, ty, step+1);
            book[tx][ty] = 0;
            top--;
        }
    }
    return ;
}
void autoSearch::genRoute()
{
    int i, startx=1, starty=0;
    book[startx][starty] = 1;   // 标记起点已经在路径中，防止后面重复走
    dfs(startx, starty, 0);
    for (i = 0; i < mini; i++)
    {
        que.push(make_pair(way[i].x, way[i].y));
    }
}
queue <pair<int, int>> autoSearch::getQueue()
{
    return que;
}
