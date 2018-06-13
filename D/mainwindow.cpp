#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //seting operation to perform
    connect(ui->delatacja,SIGNAL(clicked(bool)),ui->widgetOperacje,SLOT(delatacjaA()));
    connect(ui->erozja,SIGNAL(clicked(bool)),ui->widgetOperacje,SLOT(erozjaA()));
    connect(ui->zamkniecie,SIGNAL(clicked(bool)),ui->widgetOperacje,SLOT(zamkniecieA()));
    connect(ui->otwarcie,SIGNAL(clicked(bool)),ui->widgetOperacje,SLOT(otwarcieA()));

}

MainWindow::~MainWindow()
{
    delete ui;
}
