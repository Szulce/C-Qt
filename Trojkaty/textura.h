#ifndef TEXTURA_H
#define TEXTURA_H

#include <QWidget>
#include <QPainter>
#include <QMouseEvent>
#include<cmath>
#include<point.h>
#include<QFileDialog>

class Textura : public QWidget
{
    Q_OBJECT
public:
    explicit Textura(QWidget *parent = 0);

protected:
   void paintEvent(QPaintEvent *);
   void mousePressEvent(QMouseEvent *);
   void mouseMoveEvent(QMouseEvent *);
   void mouseReleaseEvent(QMouseEvent *);
signals:
void uvChanged(int,double,double);//punkt ,nowe u ,nowe v
public slots:
private:
   QImage wzor;
   QImage tlo;
   pointUV A,B,C;
   bool moveA=false,moveB=false,moveC=false;

    void frame();
    void PutPixel(int x,int y,int r ,int g,int b);
};

#endif // TEXTURA_H
