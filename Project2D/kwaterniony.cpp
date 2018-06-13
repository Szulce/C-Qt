#include "kwaterniony.h"

Kwaterniony::Kwaterniony(QWidget *parent) : QWidget(parent)
{
    img= QImage(200,200,QImage::Format_RGB32);

    //matrix set
       //nie ustawiam zer
        M.zeros();
        M.set_size(4,4);
        M(0,0)=1;
        M(1,1)=1;
        M(2,2)=1;
        M(3,3)=1;
        matrixC.zeros();
        matrixC.set_size(4,4);
        matrixC(0,0)=1;
        matrixC(0,3)=50;
        matrixC(1,1)=1;
        matrixC(1,3)=50;
        matrixC(2,3)=0;
        matrixC(2,2)=1;
        matrixC(3,3)=1;

        matrixMC.zeros();
        matrixMC.set_size(4,4);
        matrixMC(0,0)=1;
        matrixMC(0,3)=-50;
        matrixMC(1,1)=1;
        matrixMC(1,3)=-50;
        matrixMC(2,2)=1;
        matrixMC(2,3)=0;
        matrixMC(3,3)=1;

        //definiuje punkty jak na razie 8
        point p1;
//        p1.x = 150;
//        p1.y = 50;
//        p1.z = 50;
           p1.x = 100;
           p1.y = 0;
           p1.z = 50;
        Punkty.push_back(p1);
        point p2;
//        p2.x = 50;
//        p2.y = 50;
//        p2.z = 50;
        p2.x = 0;
        p2.y = 0;
        p2.z = 50;
        Punkty.push_back(p2);
//        point p3;
//        p3.x = 50;
//        p3.y = 150;
//        p3.z = 50;
        point p3;
        p3.x = 0;
        p3.y = 100;
        p3.z = 50;

        Punkty.push_back(p3);
        point p4;
//        p4.x = 150;
//        p4.y = 150;
//        p4.z = 50;
        p4.x = 100;
        p4.y = 100;
        p4.z = 50;
        Punkty.push_back(p4);
        point p5;
//        p5.x = 150;
//        p5.y = 50;
//        p5.z =-50;
        p5.x = 100;
        p5.y = 0;
        p5.z =-50;
        Punkty.push_back(p5);
        point p6;
//        p6.x = 50;
//        p6.y = 50;
//        p6.z = -50;
        p6.x = 0;
        p6.y = 0;
        p6.z = -50;
        Punkty.push_back(p6);
        point p7;
//        p7.x = 50;
//        p7.y = 150;
//        p7.z = -50;
        p7.x = 0;
        p7.y = 100;
        p7.z = -50;
        Punkty.push_back(p7);
        point p8;
//        p8.x = 150;
//        p8.y = 150;
//        p8.z = -50;
        p8.x = 100;
        p8.y = 100;
        p8.z = -50;
        Punkty.push_back(p8);

        DarawAgain();

}

void Kwaterniony::paintEvent(QPaintEvent *)
{
  QPainter p(this);
  p.drawImage(0,0,img);
}

void Kwaterniony::changetx(int t)
{
    tx = t;
    ComputeMatrix();
}

void Kwaterniony::changety(int t)
{

    ty = t;
    ComputeMatrix();

}

void Kwaterniony::changetz(int t)
{
    tz = t;
    ComputeMatrix();
}

void Kwaterniony::changerx(int l)
{
    alfax = (double)l*2*M_PI/360;
    ComputeMatrix();

}

void Kwaterniony::changery(int l)
{
    alfay = (double)l*2*M_PI/360;
    ComputeMatrix();
}

void Kwaterniony::changerz(int l)
{
    alfaz = (double)l*2*M_PI/360;
    ComputeMatrix();
}

void Kwaterniony::changesx(int s)
{
    sx =(double)s/100;
        ComputeMatrix();
}

void Kwaterniony::changesy(int s)
{
    sy =(double)s/100;
        ComputeMatrix();
}

void Kwaterniony::changesz(int s)
{
    sz =(double)s/100;
        ComputeMatrix();
}

void Kwaterniony::drawLine(int x, int y, int pox, int poy)
{

//    if(pox>250)
//    {
//        pox=250;

//    }
//    if(poy>200)
//    {
//        poy=200;

//    }
//    if(x<0)
//    {
//        x=0;

//    }
//    if(y<0)
//    {
//        y=0;

//    }

    int dx,dy;
    if(x==pox && y==poy)
    {
        PutPixel(x,y,r,g,b);
    }
    else if(fabs(pox-x)>fabs(poy-y))
    {
        if(x<=pox){
       for(dx=x;dx<=pox;dx++)
        {
            dy=(((float)(poy-y))/(pox-x))*(dx-x)+y;

            PutPixel(dx,dy,r,g,b);
        }
        }
        else
        {

            for(dx=x;dx>=pox;dx--)
            {

                dy=((float)(poy-y)/(pox-x))*(dx-x)+y;

                PutPixel(dx,dy,r,g,b);}

        }

    }
    else
    {

        if(y<=poy)
        {

        for(dy=y;dy<=poy;dy++)
        {

            dx=((float)(pox-x)/(poy-y))*(dy-y)+x;
            PutPixel(dx,dy,r,g,b);
        }
}
        else{

            for(dy=y;dy>=poy;dy--)
            {

                dx=(((float)(pox-x))/(poy-y))*(dy-y)+x;
                PutPixel(dx,dy,r,g,b);
            }
        }
    }
}

void Kwaterniony::PutPixel(int x, int y, int r, int g, int b)
{
    if((x>0 && x<250) && (y>0 && y<200))
    {
        uchar *pix = img.scanLine(y);
        pix[4*x]=b;
        pix[(4*x)+1]=g;
        pix[(4*x)+2]=r;
    }

}

void Kwaterniony::DarawAgain()
{
    img.fill(Qt::white);
    //definiuje linie 12
    line l1;
    l1.a = Punkty[0];
    l1.b = Punkty[1];
    Linie.push_back(l1);
    line l2;
    l2.a = Punkty[0];
    l2.b = Punkty[3];
    Linie.push_back(l2);
    line l3;
    l3.a = Punkty[0];
    l3.b = Punkty[4];
    Linie.push_back(l3);
    line l4;
    l4.a=Punkty[1];
    l4.b=Punkty[2];
    Linie.push_back(l4);
    line l5;
    l5.a=Punkty[2];
    l5.b=Punkty[3];
    Linie.push_back(l5);
    line l6;
    l6.a = Punkty[2];
    l6.b = Punkty[6];
    Linie.push_back(l6);
    line l7;
    l7.a = Punkty[7];
    l7.b = Punkty[3];
    Linie.push_back(l7);
    line l8;
    l8.a = Punkty[7];
    l8.b = Punkty[4];
    Linie.push_back(l8);
    line l9;
    l9.a=Punkty[7];
    l9.b=Punkty[6];
    Linie.push_back(l9);
    line l10;
    l10.a=Punkty[6];
    l10.b=Punkty[5];
    Linie.push_back(l10);
    line l11;
    l11.a = Punkty[5];
    l11.b = Punkty[4];
    Linie.push_back(l11);
    line l12;
    l12.a = Punkty[5];
    l12.b = Punkty[1];
    Linie.push_back(l12);

    double f = 3000;
    double cx=70.0,cy=70.0;
    double plus = 8000;
    //dla kazdej lini na obrazku rysuje linie:>
    for(int i=0;i<Linie.size();i++)
    {
       //float mnoznik =
        //floaty

       // qDebug("%f %f %f %f",(Linie[i].a.x/Linie[i].a.z)*f+cx,(Linie[i].a.y/Linie[i].a.z)*f+cy,(Linie[i].b.x/Linie[i].b.z)*f+cy,(Linie[i].b.y/Linie[i].b.z)*f+cy);
//        drawLine((Linie[i].a.x/Linie[i].a.z)*f+cx,(Linie[i].a.y/Linie[i].a.z)*f+cy,(Linie[i].b.x/Linie[i].b.z)*f+cy,(Linie[i].b.y/Linie[i].b.z)*f+cy);
        drawLine(((double)Linie[i].a.x/(Linie[i].a.z+plus))*f+cx,((double)Linie[i].a.y/(Linie[i].a.z+plus))*f+cy,((double)Linie[i].b.x/(Linie[i].b.z+plus))*f+cy,((double)Linie[i].b.y/(Linie[i].b.z+plus))*f+cy);

    }
    update();
    //ciesze sie piknym obrazkiem
     Linie.clear();
}

void Kwaterniony::ComputeMatrix()
{

 matrixTt.set_size(4,4);
    matrixTt.zeros();

    matrixTt(0,0)=1;
    matrixTt(0,3)=tx;
    matrixTt(1,1)=1;
    matrixTt(1,3)=ty;
    matrixTt(2,2)=1;
    matrixTt(2,3)=tz;
    matrixTt(3,3)=1;

  //  M=M*matrixTt;

    matrixRx.set_size(4,4);
    matrixRx.zeros();
    matrixRx(0,0)=1;
    matrixRx(1,1)=cos(alfax);
    matrixRx(2,2)=cos(alfax);
    matrixRx(3,3)=1;
    matrixRx(2,1)=-sin(alfax);
    matrixRx(1,2)=sin(alfax);

    //M=M*matrixRx;

     matrixRy.set_size(4,4);
    matrixRy.zeros();

    matrixRy(0,0)=cos(alfay);
    matrixRy(0,2)=sin(alfay);
    matrixRy(1,1)=1;
    matrixRy(2,2)=cos(alfay);
    matrixRy(2,0)=-sin(alfay);
    matrixRy(3,3)=1;

      //M=M*matrixRy;

      matrixRz.set_size(4,4);
    matrixRz.zeros();

    matrixRz(0,0)=cos(alfaz);
    matrixRz(1,1)=cos(alfaz);
    matrixRz(2,2)=1;
    matrixRz(3,3)=1;
    matrixRz(1,0)=-sin(alfaz);
    matrixRz(0,1)=sin(alfaz);

//      M=M*matrixRz;

      matrixSxSy.set_size(4,4);
    matrixSxSy.zeros();

    matrixSxSy(0,0)=sx;
    matrixSxSy(1,1)=sy;
    matrixSxSy(2,2)=sz;
    matrixSxSy(3,3)=1;

  //    M=M*matrixSxSy;

    //qDebug("tx=%f,ty=%f,sx=%f,sy=%f,alfa=%f",tx,ty,sx,sy,alfaz);
   // M=matrixC*M*matrixMC;
    //M=(matrixSxSy*(mat0rixC*matrixR*matrixMC)*matrixTt);
    //SKROC
    M=matrixTt*matrixC*matrixRz*matrixRy*matrixRx*matrixSxSy*matrixMC;
    ComputePoints();
}

void Kwaterniony::ComputePoints()
{

    //przemnozkazdy vektor punktu razy M
        //tworze maciez dla kazdego punktu(12) i wynikowa(1)
        arma::mat Wynikowa;
        Wynikowa.set_size(4,1);
        Wynikowa.zeros();

        arma::mat Mp1;
        Mp1.set_size(4,1);
        Mp1.zeros();
        Mp1(0,0)=100;
        Mp1(1,0)=0;
        Mp1(2,0)=50;
        Mp1(3,0)=1;
        arma::mat Mp2;
        Mp2.set_size(4,1);
        Mp2.zeros();
        Mp2(0,0)=0;
        Mp2(1,0)=0;
        Mp2(2,0)=50;
        Mp2(3,0)=1;
        arma::mat Mp3;
        Mp3.set_size(4,1);
        Mp3.zeros();
        Mp3(0,0)=0;
        Mp3(1,0)=100;
        Mp3(2,0)=50;
        Mp3(3,0)=1;
        arma::mat Mp4;
        Mp4.set_size(4,1);
        Mp4.zeros();
        Mp4(0,0)=100;
        Mp4(1,0)=100;
        Mp4(2,0)=50;
        Mp4(3,0)=1;
        arma::mat Mp5;
        Mp5.set_size(4,1);
        Mp5.zeros();
        Mp5(0,0)=100;
        Mp5(1,0)=0;
        Mp5(2,0)=-50;
        Mp5(3,0)=1;
        arma::mat Mp6;
        Mp6.set_size(4,1);
        Mp6.zeros();
        Mp6(0,0)=0;
        Mp6(1,0)=0;
        Mp6(2,0)=-50;
        Mp6(3,0)=1;
        arma::mat Mp7;
        Mp7.set_size(4,1);
        Mp7.zeros();
        Mp7(0,0)=0;
        Mp7(1,0)=100;
        Mp7(2,0)=-50;
        Mp7(3,0)=1;
        arma::mat Mp8;
        Mp8.set_size(4,1);
        Mp8.zeros();
        Mp8(0,0)=100;
        Mp8(1,0)=100;
        Mp8(2,0)=-50;
        Mp8(3,0)=1;

        //przeliczam i odczytuje wynik do punktu
        Wynikowa=M*Mp1;
        Punkty[0].x=Wynikowa(0,0);
        Punkty[0].y=Wynikowa(1,0);
        Punkty[0].z=Wynikowa(2,0);
        Wynikowa=M*Mp2;
        Punkty[1].x=Wynikowa(0,0);
        Punkty[1].y=Wynikowa(1,0);
        Punkty[1].z=Wynikowa(2,0);
        Wynikowa=M*Mp3;
        Punkty[2].x=Wynikowa(0,0);
        Punkty[2].y=Wynikowa(1,0);
        Punkty[2].z=Wynikowa(2,0);
        Wynikowa=M*Mp4;
        Punkty[3].x=Wynikowa(0,0);
        Punkty[3].y=Wynikowa(1,0);
        Punkty[3].z=Wynikowa(2,0);
        Wynikowa=M*Mp5;
        Punkty[4].x=Wynikowa(0,0);
        Punkty[4].y=Wynikowa(1,0);
        Punkty[4].z=Wynikowa(2,0);
        Wynikowa=M*Mp6;
        Punkty[5].x=Wynikowa(0,0);
        Punkty[5].y=Wynikowa(1,0);
        Punkty[5].z=Wynikowa(2,0);
        Wynikowa=M*Mp7;
        Punkty[6].x=Wynikowa(0,0);
        Punkty[6].y=Wynikowa(1,0);
        Punkty[6].z=Wynikowa(2,0);
        Wynikowa=M*Mp8;
        Punkty[7].x=Wynikowa(0,0);
        Punkty[7].y=Wynikowa(1,0);
        Punkty[7].z=Wynikowa(2,0);
    update();

    //wyswietl wynik
    DarawAgain();
}

