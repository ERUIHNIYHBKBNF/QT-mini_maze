/**
 * 迷宫游戏的图形界面
 */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "mazemap.h"
#include "controller.h"

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
    void setGird(int, int, int);

private:
    Ui::MainWindow *ui;
    MazeMap *map;
    int mazeHeight, mazeWidth;
    int girdSize;
    void keyPressEvent(QKeyEvent *);
    Controller mainGame;
};
#endif // MAINWINDOW_H
