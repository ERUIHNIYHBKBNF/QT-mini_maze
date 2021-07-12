#ifndef MAZEMAP_H
#define MAZEMAP_H
#include <vector>
using std::vector;

class MazeMap
{
public:
    MazeMap();
    int getHeight();
    int getWidth();
    vector<vector<int> > getMap();
    void setSize(int, int);
    void setMap(vector<vector<int> >);
private:
    int height, width;
    vector<vector<int> > map;
};
#endif // MAZEMAP_H
