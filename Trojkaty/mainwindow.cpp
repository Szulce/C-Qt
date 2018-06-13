#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->wzor,SIGNAL(uvChanged(int,double,double)),ui->ekran,SLOT(uvChanged(int,double,double)));
}

MainWindow::~MainWindow()
{
    delete ui;
}
