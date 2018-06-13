#include "troj.h"
#include <algorithm>

Troj::Troj(QWidget *parent) : QWidget(parent)
{
    ekran = QImage(240,200,QImage::Format_RGB32);
    ekran.fill(Qt::white);

    uvPicture = QImage(240,200,QImage::Format_RGB32);
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
            QPainter p(&uvPicture);
            p.drawImage(0,0,obr);
            p.end();


        }
    A.x = 120;
    A.y = 20;
    A.u = 0.12;
    A.v = 0.02;
    B.x = 60;
    B.y = 100;
    B.u = 0.06;
    B.v = 0.10;
    C.x = 140;
    C.y = 150;
    C.u = 0.14;
    C.v = 0.15;

//maredTriangles();
    algorytm();

}

void Troj::paintEvent(QPaintEvent *)
{
     QPainter p(this);

     p.drawImage(0,0,ekran);
}

void Troj::mousePressEvent(QMouseEvent *e)
{

    if(abs(e->x()-A.x)<5 && abs(e->y()-A.y)<5)
    {
        moveA = true;
      //  qDebug("e %d %d,a %d %d",e->x(),e->y(),A.x,A.y);
    }
    else if(abs(e->x()-B.x)<5 && abs(e->y()-B.y)<5)
    {
        moveB = true;
    }
    else if(abs(e->x()-C.x)<5 && abs(e->y()-C.y)<5)
    {
        moveC = true;
    }
}

void Troj::mouseMoveEvent(QMouseEvent *e)
{
    if(moveA)
    {
        A.x = e->x();
        A.y = e->y();
    }
    else if(moveB)
    {
        B.x = e->x();
        B.y = e->y();
    }
    else if(moveC)
    {
        C.x = e->x();
        C.y = e->y();
    }
    ekran.fill(Qt::white);
    //maredTriangles();
    algorytm();
    update();
}

void Troj::mouseReleaseEvent(QMouseEvent *)
{
    moveA = false;
    moveB = false;
    moveC = false;
}

void Troj::uvChanged(int p, double u, double v)
{

    //zmiana danych dla danego punktu
    switch(p)
    {
    case 1:
    {
        A.u = u;
        A.v = v;
    }
        break;
    case 2:
    {
        B.u=u;
        B.v=v;
    }
        break;
     case 3:
    {
        C.u= u;
        C.v= v;
    }
        break;
    }

    //od nowa wykonaj algorytm
    algorytm();

    update();

}

void Troj::maredTriangles()
{
    //sorujemy punkty względem y
    pointXY Z;
    if(A.y<B.y)
    {
        if(B.y<C.y)
        {
            //do nothing
        }
        else if(A.y<C.y)
        {
            Z = B;
            B = C;
            C = Z;
        }
        else
        {
            Z = A;
            A = C;
            C = Z;
            Z = B;
            B = C;
            C = Z;
        }
    }
    else
    {
        if(A.y<C.y)
        {
            Z = A;
            A = B;
            B = Z;
        }
        else if(C.y<B.y)
        {
            Z = A;
            A = C;
            C = Z;
        }
        else
        {
            Z = A;
            A = B;
            B = Z;
            Z = B;
            B = C;
            C = Z;
        }
    }
    //część 1
    int x1,x2;
    double ab  = (double)(B.y-A.y)/(B.x-A.x);
    double ac = (double)(C.y-A.y)/(C.x-A.x);
    double bc  = (double)(C.y-B.y)/(C.x-B.x);

    for(int y = A.y;y<=B.y;y++)
    {
        //znajdowanie punktów przeciecia
        x1 =(y +ab*A.x-A.y)/ab;
        x2 = (y+ ac*A.x-A.y)/ac;
        //zamalowwywanie pomiedzy x1 a x2
        uchar *lin = ekran.scanLine(y);
        for(int i=x1;i<=x2;i++)
        {
            lin[4*i] = 0;
            lin[(4*i)+1]=0;
            lin[(4*i)+2]=255;

        }
    }
    //część 2
    for(int y = B.y;y<=C.y;y++)
    {

        x1 =(y +bc*B.x-B.y)/bc;
        x2 = (y+ ac*C.x-C.y)/ac;
        uchar *lin = ekran.scanLine(y);
        for(int i=x1;i<=x2;i++)
        {
            lin[4*i] = 255;
            lin[(4*i)+1]=0;
            lin[(4*i)+2]=0;

        }
    }
    update();
}

void Troj::algorytm()
{
    //sortowanie
    pointXY Z;
    if(A.y<B.y)
    {
        if(B.y<C.y)
        {
            //do nothing
        }
        else if(A.y<C.y)
        {
            Z = B;
            B = C;
            C = Z;
        }
        else
        {
            Z = A;
            A = C;
            C = Z;
            Z = B;
            B = C;
            C = Z;
        }
    }
    else
    {
        if(A.y<C.y)
        {
            Z = A;
            A = B;
            B = Z;
        }
        else if(C.y<B.y)
        {
            Z = A;
            A = C;
            C = Z;
        }
        else
        {
            Z = A;
            A = B;
            B = Z;
            Z = B;
            B = C;
            C = Z;
        }
    }
    //1 czesc
    double alfa_l,alfa_p,x_l,x_p,u_l,u_p,v_l,v_p;
    for (int y = A.y;y<=B.y;y++)
    {
        alfa_l =((double)(y-A.y))/(B.y-A.y);
        alfa_p =((double)(y-A.y))/(C.y-A.y);

        x_l = A.x + alfa_l*(B.x-A.x);
        x_p = A.x + alfa_p*(C.x-A.x);

        u_l = A.u + alfa_l*(B.u-A.u);
        u_p = A.u + alfa_p*(C.u-A.u);

        v_l = A.v + alfa_l*(B.v-A.v);
        v_p = A.v + alfa_p*(C.v-A.v);

        drawLineHorizontalTextured(x_l,x_p,y,u_l,v_l,u_p,v_p);
    }
    //2 czesc
    for(int y=B.y;y<=C.y;y++)
    {
        alfa_l =((double)(y-B.y))/(C.y-B.y);
        alfa_p =((double)(y-A.y))/(C.y-A.y);
        x_l = B.x + alfa_l*(C.x - B.x);
        x_p = A.x + alfa_p*(C.x - A.x);
        u_l = B.u + alfa_l*(C.u-B.u);
        u_p = A.u + alfa_p*(C.u-A.u);
        v_l = B.v + alfa_l*(C.v-B.v);
        v_p = A.v + alfa_p*(C.v-A.v);

        drawLineHorizontalTextured(x_l,x_p,y,u_l,v_l,u_p,v_p);
    }
}

void Troj::drawLineHorizontalTextured(int x1, int x2, int y, double u1, double v1, double u2, double v2)
{
    //KOLEJNOSc
    if(x1>x2)
    {
        std::swap(x1,x2);
        std::swap(v1,v2);
        std::swap(u1,u2);
    }else if(x1 == x2)return;

    double alfa,u,v;
    for(int x=x1;x<x2;x++)
    {
        alfa = ((double)(x-x1))/(x2-x1);
        u = u1 + alfa * (u2 - u1);
        v = v1 + alfa * (v2 - v1);
        textura(u,v); //it should set rgb
       PutPixel(x,y,cr,cg,cb);
    }
}

void Troj::PutPixel(int x, int y, int r, int g, int b)
{
    if(x<0 || y<0 || x>=ekran.width() || y>= ekran.height())
    {
    return;
    }
    uchar *pix = ekran.scanLine(y);
        pix[4*x]=b;
        pix[4*x+1]=g;
        pix[4*x+2]=r;
}

void Troj::textura(double u, double v)
{
    //to powinno set textura
    QColor b = QColor(uvPicture.pixel(u*1000,v*1000));

    cr = b.red();
    cg = b.green();
    cb = b.blue();

//        cr = 0;
//        cg = 0;
//        cb = 255;



}

