#ifndef AUTOSEARCH_H
#define AUTOSEARCH_H
#include <iostream>
#include <utility>
#include <queue>
#include <vector>
using namespace std;
typedef struct CUR{
    int x;
    int y;
}now;
class autoSearch
{
public:
    autoSearch(vector<vector<int> >);
    void dfs(int x, int y, int step);
    void genRoute();
    queue<pair<int, int>> getQueue();
private:
    int col,row;
    now memo[1000], way[1000];
    int mini = 100000;
    int top = 0;
    vector<vector<int> > Ma,book;
    queue <pair<int, int>> que;
};
#endif // AUTOSEARCH_H
