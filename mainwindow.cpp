#include "mainwindow.h"
#include "ui_mainwindow.h"

#define MAZESIZE 500

#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    generator *gen = new generator(11, 11);
    gen -> genMaze();
    map = gen ->getMap();
    //map = new MazeMap();
    vector<vector<int> > vec = map -> getMap();
    mazeHeight = map -> getHeight();
    mazeWidth = map -> getWidth();
    girdSize = MAZESIZE / mazeHeight;

    player = new QPushButton();
    player -> setParent(this);
    player -> resize(girdSize / 2, girdSize / 2);
    player -> move(20 + girdSize / 4, 20 + girdSize * 5 / 4);
    //this -> resize(750, 750);

    mainGame = new Controller(map);
    playerX = 1, playerY = 0;

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
        case 2: painter.setBrush(QBrush(Qt::red)); break;
        case 3: painter.setBrush(QBrush(Qt::green)); break;
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
    vector<vector<int> > vec = map -> getMap();
    for (unsigned int i = 0; i < vec.size(); i++)
        for (unsigned int j = 0; j < vec[i].size(); j++)
            setGird(i, j, vec[i][j]);
    setGird(1, 0, 2);
    setGird(map -> getHeight() - 2, map -> getWidth() - 1, 3);
}

void MainWindow::movePlayer(int x, int y)
{
    player -> move(20 + girdSize / 4 + y * girdSize, 20 + girdSize / 4 + x * girdSize);
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    //qDebug() << (event -> key() == Qt::Key_W);
    if (mainGame -> isOver())
        return;
    if (event -> key() == Qt::Key_Up || event -> key() == Qt::Key_W)
    {
        if (mainGame -> makeMove(1))
        {
            playerX--;
            movePlayer(playerX, playerY);
        }
    }
    else if (event -> key() == Qt::Key_Right || event -> key() == Qt::Key_D)
    {
        if (mainGame -> makeMove(2))
        {
            playerY++;
            movePlayer(playerX, playerY);
        }
    }
    else if (event -> key() == Qt::Key_Down || event -> key() == Qt::Key_S)
    {
        if (mainGame -> makeMove(4))
        {
            playerX++;
            movePlayer(playerX, playerY);
        }
    }
    else if (event -> key() == Qt::Key_Left || event -> key() == Qt::Key_A)
    {
        if (mainGame -> makeMove(8))
        {
            playerY--;
            movePlayer(playerX, playerY);
        }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
