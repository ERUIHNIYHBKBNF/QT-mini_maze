/**
 * 迷宫游戏的图形界面
 */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "mazemap.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void paintEvent(QPaintEvent *);

private:
    Ui::MainWindow *ui;
    MazeMap *map;
    int mazeHeight, mazeWidth;
    int girdSize;
    void paintGird(int, int, QBrush);
};
#endif // MAINWINDOW_H
