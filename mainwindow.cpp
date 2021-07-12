#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>

#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //generateMaze();
    qDebug() << "qwq";

    //之后自动调paintEvent
}

void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    painter.drawLine(QPoint(0, 0), QPoint(200, 200));

    QBrush brush(Qt::blue);
    painter.setBrush(brush);

    //左上角 宽度 高度
    painter.drawRect(QRect(10, 10, 500, 500));


}

MainWindow::~MainWindow()
{
    delete ui;
}
