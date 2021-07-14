/**
 * 迷宫游戏的图形界面
 */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "mazemap.h"
#include "controller.h"
#include "generator.h"
#include <QPainter>
#include <vector>
using std::vector;
#include <QKeyEvent>
#include <QPushButton>
#include <QLineEdit>
#include <QComboBox>
#include <queue>
using std::queue;

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
    void newGame();

private:
    Ui::MainWindow *ui;
    MazeMap *map;
    int mazeHeight, mazeWidth;
    int playerX, playerY;
    int girdSize;
    void setGird(int, int, int);
    void keyPressEvent(QKeyEvent *);
    void movePlayer(int, int);
    Controller *mainGame;
    QPushButton *player;
    QLineEdit *info;
    QComboBox *checkSize;
    void getAns();
};
#endif // MAINWINDOW_H
