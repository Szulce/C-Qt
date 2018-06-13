#ifndef KWATERNIONY_H
#define KWATERNIONY_H

#include <QWidget>
#include<QPainter>
#include<cmath>
#include<vector>
#include <armadillo>
#include <math.h>

struct point
{
    int x;
    int y;
    int z;
};
struct line
{
    point a;
    point b;
};

class Kwaterniony : public QWidget
{
    Q_OBJECT
public:
    explicit Kwaterniony(QWidget *parent = 0);
protected:
   void paintEvent(QPaintEvent *);

signals:

public slots:
    void changetx(int);
    void changety(int);
    void changetz(int);
    void changerx(int);
    void changery(int);
    void changerz(int);
    void changesx(int);
    void changesy(int);
    void changesz(int);

private:
     QImage img;

     //pomocnicze
     std::vector<point> Punkty;
     std::vector<line> Linie;
     int r=0,g=0,b=0;
     int wtx=0,wty=0,wtz=0,wsx=1.0,wsy=1.0,wsz=1.0;
     double wrx=0.0,wry=0.0,wrz=0.0;

     //definiuje Matrix
     arma::mat M;//maciez przeksztaucen
     arma::mat matrixTt;//translacji
     arma::mat matrixRx;//obrotu
     arma::mat matrixRy;
     arma::mat matrixRz;
     arma::mat matrixSxSy;//skalacji
     arma::mat matrixC;//c do pozycji
     arma::mat matrixMC;//c do pozycji
     //variables
     double tx=0.0,ty=0.0,tz=0.0,sx=1.0,sy=1.0,sz=1.0,alfax=0.0,alfay=0.0,alfaz=0.0;

     void drawLine(int x, int y,int pox,int poy);
     void PutPixel(int x,int y,int r ,int g,int b);
     void DarawAgain();
     void ComputeMatrix();
     void ComputePoints();


};

#endif // KWATERNIONY_H
