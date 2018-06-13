#include "obrazek.h"



Obrazek::Obrazek(QWidget *parent) : QWidget(parent)
{

    img= QImage(250,200,QImage::Format_RGB32);

    //matrix set
       //nie ustawiam zer
        M.zeros();
        M.set_size(3,3);
        M(0,0)=1;
        M(1,1)=1;
        M(2,2)=1;
        matrixC.zeros();
        matrixC.set_size(3,3);
        matrixC(0,0)=1;
        matrixC(0,2)=125;
        matrixC(1,1)=1;
        matrixC(1,2)=100;
        matrixC(2,2)=1;

        matrixMC.zeros();
        matrixMC.set_size(3,3);
        matrixMC(0,0)=1;
        matrixMC(0,2)=-125;
        matrixMC(1,1)=1;
        matrixMC(1,2)=-100;
        matrixMC(2,2)=1;





    //definiuje punkty jak na razie 5
    pointe p1;
    p1.x = 125;
    p1.y = 62;
    Punkty.push_back(p1);
    pointe p2;
    p2.x = 100;
    p2.y = 90;
    Punkty.push_back(p2);
    pointe p3;
    p3.x = 150;
    p3.y = 90;
    Punkty.push_back(p3);
    pointe p4;
    p4.x = 100;
    p4.y = 150;
    Punkty.push_back(p4);
    pointe p5;
    p5.x = 150;
    p5.y = 150;
    Punkty.push_back(p5);



 //ComputeM();
   Przerysuj();

}

void Obrazek::paintEvent(QPaintEvent *)
{
    //paint here object
    QPainter p(this);
   // p.fillRect(0,0,250,200,Qt::white);
   // img.fill(Qt::white);
    p.drawImage(0,0,img);

}

void Obrazek::wheelEvent(QWheelEvent *)
{
    r= rand()%256;
    g= rand()%256;
    b= rand()%256;
  //  qDebug("g: %d r: %d b: %d",r,g,b);
    update();
}

void Obrazek::SliderTx(int t)
{

//set t
//    if(t>abs(tx))tx = t;
//    else tx=-t;
//    qDebug("%d",t);
//    if(t>(wtx))tx=1;
//    else tx=-1;
//    wtx =t;
 tx= t;


    //compute M
    ComputeM();





}

void Obrazek::SliderTy(int t)
{
//    if(t>abs(ty))ty=-t;
//    else ty=t;
//    if(t>(wty))ty=wty-t;
//    else ty=wty;
//    wty =t;
    ty = t;
    ComputeM();

}

void Obrazek::SliderR(int l)
{
        //alfa = l;
//    if(l*2*M_PI/360>(wr))alfa+=2*2*M_PI/360;
//    else alfa-=2*M_PI/360;
//    wr =l*2*2*M_PI/360;
    alfa = l*2*M_PI/360;
        ComputeM();
}

void Obrazek::SliderSx(int s)
{
        //sx=s;
//    if(s>(wsx))sx+=1;
//    else sx-=1;
//    wsx=s;
    sx =(double)s/100;
        ComputeM();
}

void Obrazek::SliderSy(int s)
{
        //sy = s;
//    if(s>(wsy))sy+=1;
//    else sy-=1;
//    wsy=s;
    sy = (double)s/100;
        ComputeM();
}

void Obrazek::drawLineE(int x, int y, int pox, int poy)
{

    if(pox>250)
    {
        pox=250;

    }
    if(poy>200)
    {
        poy=200;

    }
    if(x<0)
    {
        x=0;

    }
    if(y<0)
    {
        y=0;

    }

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

void Obrazek::PutPixel(int x, int y, int r, int g, int b)
{
    if((x>0 && x<250) && (y>0 && y<200))
    {
        uchar *pix = img.scanLine(y);
        pix[4*x]=b;
        pix[(4*x)+1]=g;
        pix[(4*x)+2]=r;
    }


}

void Obrazek::Przerysuj()
{
    img.fill(Qt::white);
    //definiuje linie
    line l1;
    l1.a = Punkty[0];
    l1.b = Punkty[1];
    Linie.push_back(l1);
    line l2;
    l2.a = Punkty[0];
    l2.b = Punkty[2];
    Linie.push_back(l2);
    line l3;
    l3.a = Punkty[2];
    l3.b = Punkty[4];
    Linie.push_back(l3);
    line l4;
    l4.a=Punkty[1];
    l4.b=Punkty[3];
    Linie.push_back(l4);
    line l5;
    l5.a=Punkty[3];
    l5.b=Punkty[4];
    Linie.push_back(l5);
    //dla kazdej lini na obrazku rysuje linie:>
    for(int i=0;i<Linie.size();i++)
    {
        drawLineE(Linie[i].a.x,Linie[i].a.y,Linie[i].b.x,Linie[i].b.y);
    }
    update();
    //ciesze sie piknym obrazkiem
     Linie.clear();
}

void Obrazek::ComputeM()
{
    //to potem nadpisywac

   // M.zeros();



    matrixTt.zeros();
    matrixTt.set_size(3,3);
    matrixTt(0,0)=1;
    matrixTt(0,2)=tx;
    matrixTt(1,1)=1;
    matrixTt(1,2)=ty;
    matrixTt(2,2)=1;

    matrixR.zeros();
    matrixR.set_size(3,3);
    matrixR(0,0)=cos(alfa);
    matrixR(0,1)=-sin(alfa);
    matrixR(1,0)=sin(alfa);
    matrixR(1,1)=cos(alfa);
    matrixR(2,2)=1;

    matrixSxSy.zeros();
    matrixSxSy.set_size(3,3);
    matrixSxSy(0,0)=sx;
    matrixSxSy(1,1)=sy;
    matrixSxSy(2,2)=1;

    qDebug("tx=%f,ty=%f,sx=%f,sy=%f,alfa=%f",tx,ty,sx,sy,alfa);

    //M=(matrixSxSy*(mat0rixC*matrixR*matrixMC)*matrixTt);
    M=((matrixC*matrixTt*matrixMC)*(matrixC*matrixR*matrixMC)*(matrixC*matrixSxSy*matrixMC));
    Przemnoz();
}

void Obrazek::Przemnoz()
{
    //przemnozkazdy vektor punktu razy M
        //tworze maciez dla kazdego punkty i wynikowa
        arma::mat Wynikowa;
        Wynikowa.set_size(3,1);

        arma::mat Mp1;
        Mp1.set_size(3,1);
       // Mp1(0,0)=Punkty[0].x;
       // Mp1(1,0)=Punkty[0].y;
         Mp1(0,0)=125;
         Mp1(1,0)=62;
        Mp1(2,0)=1;
        arma::mat Mp2;
        Mp2.set_size(3,1);
//        Mp2(0,0)=Punkty[1].x;
//        Mp2(1,0)=Punkty[1].y;
        Mp2(0,0)=100;
        Mp2(1,0)=90;
        Mp2(2,0)=1;
        arma::mat Mp3;
        Mp3.set_size(3,1);
//        Mp3(0,0)=Punkty[2].x;
//        Mp3(1,0)=Punkty[2].y;
        Mp3(0,0)=150;
        Mp3(1,0)=90;
        Mp3(2,0)=1;
        arma::mat Mp4;
        Mp4.set_size(3,1);
//        Mp4(0,0)=Punkty[3].x;
//        Mp4(1,0)=Punkty[3].y;
        Mp4(0,0)=100;
        Mp4(1,0)=150;
        Mp4(2,0)=1;
        arma::mat Mp5;
        Mp5.set_size(3,1);
//        Mp5(0,0)=Punkty[4].x;
//        Mp5(1,0)=Punkty[4].y;
        Mp5(0,0)=150;
        Mp5(1,0)=150;
        Mp5(2,0)=1;
        //przeliczam i odczytuje wynik do punktu
        Wynikowa=M*Mp1;
        Punkty[0].x=Wynikowa(0,0);
        Punkty[0].y=Wynikowa(1,0);
        Wynikowa=M*Mp2;
        Punkty[1].x=Wynikowa(0,0);
        Punkty[1].y=Wynikowa(1,0);
        Wynikowa=M*Mp3;
        Punkty[2].x=Wynikowa(0,0);
        Punkty[2].y=Wynikowa(1,0);
        Wynikowa=M*Mp4;
        Punkty[3].x=Wynikowa(0,0);
        Punkty[3].y=Wynikowa(1,0);
        Wynikowa=M*Mp5;
        Punkty[4].x=Wynikowa(0,0);
        Punkty[4].y=Wynikowa(1,0);
    update();

    //wyswietl wynik
    Przerysuj();
}

