#ifndef TROJ_H
#define TROJ_H

#include <QWidget>
#include <QPainter>
#include <QMouseEvent>
#include<cmath>
#include<point.h>
#include<QFileDialog>

class Troj : public QWidget
{
    Q_OBJECT
public:
    explicit Troj(QWidget *parent = 0);

protected:
   void paintEvent(QPaintEvent *);
   void mousePressEvent(QMouseEvent *);
   void mouseMoveEvent(QMouseEvent *);
   void mouseReleaseEvent(QMouseEvent *);

signals:

public slots:
   void uvChanged(int,double,double);

private:
   QImage ekran;
   QImage uvPicture;
   pointXY A,B,C;
   double U,V;
   bool moveA=false,moveB=false,moveC=false;
   int cr=0,cg=0,cb=0;

   void maredTriangles();
   void algorytm();
   void drawLineHorizontalTextured(int,int,int,double,double,double,double);
   void PutPixel(int,int,int,int,int);
   void textura(double,double);
};

#endif // TROJ_H
