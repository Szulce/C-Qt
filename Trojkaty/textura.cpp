#include "textura.h"

Textura::Textura(QWidget *parent) : QWidget(parent)
{

    wzor = QImage(240,200,QImage::Format_RGB32);

    tlo = QImage(240,200,QImage::Format_RGB32);
    //wstawianie obrazka z zewnątrz

    QString path= QFileDialog ::getOpenFileName();
        if(!path.isNull())
        {
            QImage obr(path);
            if(obr.isNull())
            {
                qDebug("Obrazek nie załadował się");
                exit(-1);
            }
            QPainter p(&tlo);
            p.drawImage(0,0,obr);
            p.end();


        }


    A.u= 120;
    A.v = 20;
    B.u = 60;
    B.v = 100;
    C.u = 140;
    C.v = 150;

    frame();

     emit uvChanged(1,A.u/1000,A.v/1000);
     emit uvChanged(2,B.u/1000,B.v/1000);
     emit uvChanged(3,C.u/1000,C.v/1000);
}

void Textura::paintEvent(QPaintEvent *)
{

    QPainter p(this);
    p.drawImage(0,0,wzor);
}

void Textura::mousePressEvent(QMouseEvent *e)
{
   // emit uvChanged(1,1.0,1.0);
    if(fabs((double)e->x()-A.u)<5.0 && fabs((double)e->y()-A.v)<5.0)
    {
        moveA = true;
      //  qDebug("e %d %d,a %d %d",e->x(),e->y(),A.x,A.y);
    }
    else if(fabs(e->x()-B.u)<5 && fabs(e->y()-B.v)<5)
    {
        moveB = true;
    }
    else if(fabs(e->x()-C.u)<5 && fabs(e->y()-C.v)<5)
    {
        moveC = true;
    }
}

void Textura::mouseMoveEvent(QMouseEvent *e)
{

    //to przerob!!!
    if(moveA)
    {
        A.u = e->x();
        A.v = e->y();
      //  emit uvChanged(1,A.u/1000,A.v/1000);
    }
    else if(moveB)
    {
        B.u = e->x();
        B.v = e->y();
       // emit uvChanged(2,B.u/1000,B.v/1000);
    }
    else if(moveC)
    {
        C.u = e->x();
        C.v = e->y();
       // emit uvChanged(3,C.u/1000,C.v/1000);
    }
    wzor.fill(Qt::white);
    frame();
    update();
}

void Textura::mouseReleaseEvent(QMouseEvent *)
{
    moveA = false;
    moveB = false;
    moveC = false;
    emit uvChanged(1,A.u/1000,A.v/1000);
    emit uvChanged(2,B.u/1000,B.v/1000);
    emit uvChanged(3,C.u/1000,C.v/1000);
}

void Textura::frame()
{
    wzor = tlo;
    //zaladuj texture pod spodem
    //narysowanie lini pomiedzy ab ac bc
    //wiem ze są w odpowiedniej klejnosci
    int N=2*sqrt(pow(B.u-A.u,2)+pow(B.v-A.v,2));
    float da,dx,dy;

    for(int i=0;i<N;i++)
    {
        da=(((float)i)/(N-1));
        dx=A.u+da*(B.u-A.u);
        dy=A.v+da*(B.v-A.v);
     //qDebug("a:%f x:%f y:%f \n",da,dx,dy);
        PutPixel(dx,dy,0,0,255);
    }

     N=2*sqrt(pow(C.u-A.u,2)+pow(C.v-A.v,2));
    for(int i=0;i<N;i++)
    {
        da=(((float)i)/(N-1));
        dx=A.u+da*(C.u-A.u);
        dy=A.v+da*(C.v-A.v);
    // qDebug("a:%f x:%f y:%f \n",da,dx,dy);
        PutPixel(dx,dy,0,0,255);
    }

     N=2*sqrt(pow(C.u-B.u,2)+pow(C.v-B.v,2));

    for(int i=0;i<N;i++)
    {
        da=(((float)i)/(N-1));
        dx=B.u+da*(C.u-B.u);
        dy=B.v+da*(C.v-B.v);
    // qDebug("a:%f x:%f y:%f \n",da,dx,dy);
        PutPixel(dx,dy,0,0,255);
    }
}

void Textura::PutPixel(int x, int y, int r, int g, int b)
{
    if(x<0 || y<0 || x>=wzor.width() || y>= wzor.height())
    {
    return;
    }
    uchar *pix = wzor.scanLine(y);
        pix[4*x]=b;
        pix[4*x+1]=g;
        pix[4*x+2]=r;
}

