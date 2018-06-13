#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <cmath>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->horizontalSliderTx,SIGNAL(sliderMoved(int)),ui->obrazek,SLOT(SliderTx(int)));
    connect(ui->horizontalSliderTy,SIGNAL(sliderMoved(int)),ui->obrazek,SLOT(SliderTy(int)));
    connect(ui->horizontalSliderR,SIGNAL(sliderMoved(int)),ui->obrazek,SLOT(SliderR(int)));
    connect(ui->horizontalSliderSx,SIGNAL(sliderMoved(int)),ui->obrazek,SLOT(SliderSx(int)));
    connect(ui->horizontalSliderSy,SIGNAL(sliderMoved(int)),ui->obrazek,SLOT(SliderSy(int)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

