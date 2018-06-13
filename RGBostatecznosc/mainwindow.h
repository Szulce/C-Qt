#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QMouseEvent>
#include <cmath>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
 void paintEvent(QPaintEvent *);
 void mousePressEvent(QMouseEvent *);
 void mouseReleaseEvent(QMouseEvent *);
 void mouseMoveEvent(QMouseEvent *);

public slots:
    void changeR(int);
    void changeG(int);
    void changeB(int);
    void changeH(int);
    void changeS(int);
    void changeV(int);

private:
    Ui::MainWindow *ui;
    float R=0,G=0,B=0;
    float H=0,S=0,V=0;
    int pointhY=0;
    int pointsvX=0,pointsvY=0;
    QImage imH;
    QImage tloH;
    QImage imSV,tloSV;
    bool drag = false;
    bool dragSV =false;
int svR,svG,svB;

    void computeRGB();
    void computeHSV();
    void rysuj_Linie(int);
    void rysujX();
    void GetPixelColor(int x,int y);


};

#endif // MAINWINDOW_H
