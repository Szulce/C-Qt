#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->SliderTX,SIGNAL(sliderMoved(int)),ui->ekranTRS,SLOT(changetx(int)));
    connect(ui->SliderTY,SIGNAL(sliderMoved(int)),ui->ekranTRS,SLOT(changety(int)));
    connect(ui->SliderTZ,SIGNAL(sliderMoved(int)),ui->ekranTRS,SLOT(changetz(int)));
    connect(ui->SliderRX,SIGNAL(sliderMoved(int)),ui->ekranTRS,SLOT(changerx(int)));
    connect(ui->SliderRY,SIGNAL(sliderMoved(int)),ui->ekranTRS,SLOT(changery(int)));
    connect(ui->SliderRZ,SIGNAL(sliderMoved(int)),ui->ekranTRS,SLOT(changerz(int)));
    connect(ui->SliderSX,SIGNAL(sliderMoved(int)),ui->ekranTRS,SLOT(changesx(int)));
    connect(ui->SliderSY,SIGNAL(sliderMoved(int)),ui->ekranTRS,SLOT(changesy(int)));
    connect(ui->SliderSZ,SIGNAL(sliderMoved(int)),ui->ekranTRS,SLOT(changesz(int)));


}

MainWindow::~MainWindow()
{
    delete ui;
}
