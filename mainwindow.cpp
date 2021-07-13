#include "mainwindow.h"
#include "ui_mainwindow.h"

#define MAZESIZE 500

#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //generateMaze();
    this -> map = new MazeMap();
    vector<vector<int> > vec = this -> map -> getMap();
    this -> mazeHeight = this -> map -> getHeight();
    this -> mazeWidth = this -> map -> getWidth();
    this -> girdSize = MAZESIZE / this -> mazeHeight;

    this -> mainGame = new Controller();
    this -> mainGame -> setMap(this -> map);

    this -> playerX = 1, this -> playerY = 0;

    //qDebug() << girdSize;
//    for (vector<int> i : vec)
//    {
//        for (int j : i)
//            printf("%d ", j);
//        printf("\n");
//    }
}

void MainWindow::setGird(int y, int x, int color)
{
    QPainter painter(this);
    //方格颜色
    switch(color)
    {
        case 0: painter.setBrush(QBrush(Qt::white)); break;
        case 1: painter.setBrush(QBrush(Qt::blue)); break;
        case 2: painter.setBrush(QBrush(Qt::green)); break;
        case 3: painter.setBrush(QBrush(Qt::red)); break;
        default: break;
    }
    painter.drawRect(QRect(20 + this -> girdSize * x, 20 + this -> girdSize * y, girdSize, girdSize));
}

void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    //绘制地图边界 左上角坐标 宽度 高度 (其实这里不画也行)
    painter.drawRect(QRect(20, 20, MAZESIZE, MAZESIZE));

    //根据每个方格信息进行绘制
    vector<vector<int> > vec = this -> map -> getMap();
    for (unsigned int i = 0; i < vec.size(); i++)
        for (unsigned int j = 0; j < vec[i].size(); j++)
            setGird(i, j, vec[i][j]);
    setGird(1, 0, 2);
    setGird(map -> getHeight() - 2, map -> getWidth() - 1, 3);
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if (mainGame -> isOver())
        return;
    if (event -> key() == Qt::Key_Up || event -> key() == Qt::Key_W)
        if (mainGame -> makeMove(1))
        {
            setGird(playerX, playerY, 0);
            playerX--;
            setGird(playerX, playerY, 2);
        }
    else if (event -> key() == Qt::Key_Right|| event -> key() == Qt::Key_D)
        if (mainGame -> makeMove(1))
        {
            setGird(playerX, playerY, 0);
            playerY++;
            setGird(playerX, playerY, 2);
        }
    else if (event -> key() == Qt::Key_Down || event -> key() == Qt::Key_S)
        if (mainGame -> makeMove(1))
        {
            setGird(playerX, playerY, 0);
            playerX++;
            setGird(playerX, playerY, 2);
        }
    else if (event -> key() == Qt::Key_Left || event -> key() == Qt::Key_A)
        if (mainGame -> makeMove(1))
        {
            setGird(playerX, playerY, 0);
            playerY--;
            setGird(playerX, playerY, 2);
        }
}

MainWindow::~MainWindow()
{
    delete ui;
}
