#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect (
                ui->poziom,
                SIGNAL(sliderMoved(int)),
                ui-> Obrazek1,
                SLOT(rotate(int))
                );
    connect( ui->TrybDodawania,
             SIGNAL(clicked(bool)),
             ui->Obrazek1,
             SLOT(TrybDOD())
                 );
    connect (ui->TrybOdejmowania,
               SIGNAL(clicked(bool)),
                ui->Obrazek1,
            SLOT(TrybODD())
                 );
     connect(ui->TrybPrzesowania,
             SIGNAL(clicked(bool)),
            ui->Obrazek1,
             SLOT(TrybPRZ())
                );
}

MainWindow::~MainWindow()
{
    delete ui;
}
