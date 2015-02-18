#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "checker.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    iniGame();
}
MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::mousePressEvent(QMouseEvent *ev)
{
    GameLogic(ev,this);
}
void MainWindow::paintEvent(QPaintEvent *ev)
{
    Draw(this);
}
