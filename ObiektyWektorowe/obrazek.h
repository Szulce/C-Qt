#ifndef OBRAZEK_H
#define OBRAZEK_H

#include <vector>
#include <QWheelEvent>
#include<point.h>
#include<QPainter>
#include<cmath>
#include<QWidget>
#include <armadillo>
#include <math.h>

class Obrazek : public QWidget
{
    Q_OBJECT
public:
    explicit Obrazek(QWidget *parent = 0);
protected:
   void paintEvent(QPaintEvent *);
   void wheelEvent(QWheelEvent *);
public slots:
    //sloty do oblugi sliderow
   void SliderTx(int);
   void SliderTy(int);
   void SliderR(int);
   void SliderSx(int);
   void SliderSy(int);

private:
   std::vector<pointe> Punkty;
   std::vector<line> Linie;
   int r=0,g=0,b=0;
   int wtx=0,wty=0,wsx=1.0,wsy=1.0;
   double wr=0.0;
   QImage img;
   //definiuje Matrix
   arma::mat M;
   arma::mat matrixTt;
   arma::mat matrixR;
   arma::mat matrixSxSy;
   arma::mat matrixC;
   arma::mat matrixMC;
   //variables
   double tx=0.0,ty=0.0,sx=1.0,sy=1.0,alfa=0.0;

   void drawLineE(int x, int y,int pox,int poy);
   void PutPixel(int x,int y,int r ,int g,int b);
   void Przerysuj();
   void ComputeM();
   void Przemnoz();

};

#endif // OBRAZEK_H
