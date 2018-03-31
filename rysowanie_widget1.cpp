#include "rysowanie_widget1.h"

#include <QPainter>
#include <QMouseEvent>
#include <QWheelEvent>
#include <cmath>
#include <algorithm>

Rysowanie_widget1::Rysowanie_widget1(QWidget *parent) : QWidget(parent)
{
    im= QImage(300,200,QImage::Format_RGB32);
    im.fill(Qt::black);
}

void Rysowanie_widget1::paintEvent(QPaintEvent *)
{
     QPainter r(this);
     r.fillRect(0,0,width(),height(),Qt::green);
     r.drawImage(0,0,im);
}

void Rysowanie_widget1::mousePressEvent(QMouseEvent *e)
{
    x = e ->x();
    y = e ->y();

    if(Trybix == 2)
   {
        for(int i=0;i<Punkty.size();i++)
        {
            if(Punkty[i].x>=x-5 && Punkty[i].x<x+5 && Punkty[i].y>=y-5 && Punkty[i].y<y+5)
            {
                //przesuń ten punkt
                  index = i ;
                 nacisniety = true;
            }
        }

   }
}

void Rysowanie_widget1::mouseReleaseEvent(QMouseEvent *e)
{
    pox = e->x();
    poy = e->y();

    //drawLineZajecia(x,y,pox,poy,r,g,b);
    //drawKolo(x,y,pox,poy,r,g,b);
   // drawPelneKolo(x,y,pox,poy,r,g,b);
   // drawElips(x,y,pox,poy,r,g,b,deg);

    if(Trybix == 0)
    {
        point a;
        a.x=pox;
        a.y=poy;
        Punkty.push_back(a);
    }
    else if(Trybix == 1)
    {
        for(int i=0;i<Punkty.size();i++)
        {
            if(Punkty[i].x>=pox-10 && Punkty[i].x<pox+10 && Punkty[i].y>=poy-10 && Punkty[i].y<poy+10)
            {
                //usuń ten punkt
                for(int j=i+1;j<Punkty.size()-1;j++)
                {
                    Punkty[j-1]=Punkty[j];
                }
                Punkty.pop_back();
            }
        }
    }
    im.fill(Qt::black);
   //drwaKrzywaB(Punkty,r,g,b);
   drawKrzywaBsklejane(Punkty,r,g,b);
    nacisniety = false;

    update();
}

void Rysowanie_widget1::mouseMoveEvent(QMouseEvent *e)
{

        pox = e->x();
        poy = e->y();

         //drawLineZajecia(x,y,pox,poy,r,g,b);
         //drawKolo(x,y,pox,poy,r,g,b);
        // drawPelneKolo(x,y,pox,poy,r,g,b);
         //drawElips(x,y,pox,poy,r,g,b,deg);

        if(nacisniety)
        {

           Punkty[index].x=pox;
           Punkty[index].y=poy;

           im.fill(Qt::black);
           //drwaKrzywaB(Punkty,r,g,b);
           drawKrzywaBsklejane(Punkty,r,g,b);

        }

     update();
}

void Rysowanie_widget1::wheelEvent(QWheelEvent *e)
{
    //QPoint deg = e->angleDelta()/15;

        r= rand()%256;
        g= rand()%256;
        b= rand()%256;

        update();
}

void Rysowanie_widget1::PutPixel(int x, int y, int r, int g, int b)
{
    if(x<0 || y<0 || x>=im.width() || y>= im.height())
    {
        return;
    }

        uchar *pix = im.scanLine(y);
        pix[4*x]=b;
        pix[4*x+1]=g;
        pix[4*x+2]=r;

}

void Rysowanie_widget1::drawLineZajecia(float x, float y, float pox, float poy, int r, int g, int b)
{
    if(pox>300)
    {
        pox=300;
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
        if(x<=pox)
        {
             for(dx=x;dx<=pox;dx++)
             {
                 dy=((poy-y)/(pox-x))*(dx-x)+y;
                 PutPixel(dx,dy,r,g,b);
             }
        }

        else
        {
            for(dx=x;dx>=pox;dx--)
            {
                dy=((poy-y)/(pox-x))*(dx-x)+y;
                PutPixel(dx,dy,r,g,b);}
            }

         }

    else
    {

        if(y<=poy)
        {
            for(dy=y;dy<=poy;dy++)
             {
                dx=((pox-x)/(poy-y))*(dy-y)+x;
                PutPixel(dx,dy,r,g,b);
             }
        }

        else
        {
            for(dy=y;dy>=poy;dy--)
            {
                dx=((pox-x)/(poy-y))*(dy-y)+x;
                PutPixel(dx,dy,r,g,b);
            }
        }
    }
}

void Rysowanie_widget1::drawLineAlgorytm(int x, int y, int pox, int poy, int r, int g, int b)
{

    if(pox>300)
    {
        pox=300;
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
    if(pox<0)
    {
        pox=0;
    }
    if(poy<0)
    {
        poy=0;
    }

    int dx,dy,kx,ky;
    double e;

    if(x<=pox)kx=1;
    else kx=-1;

    if(y<=poy)ky=1;
    else ky=-1;

    dx=abs(pox-x);
    dy=abs(poy-y);

    uchar *linia =im.scanLine(y);
    linia[4*x]=r;
    linia[4*x+1]=g;
    linia[4*x+2]=b;


    if(dx>=dy)
    {
        e=dx/2;

        for(int i=0;i<dx;i++)
        {
            x+=kx;
            e-=dy;

            if(e<0)
            {
                y+=ky;
                e+=dx;
            }

            uchar *linia = im.scanLine(y);
            linia[4*x]=r;
            linia[4*x+1]=g;
            linia[4*x+2]=b;
        }
    }

    else
    {
       e=dy/2;

       for(int j=0;j<dy;j++)
       {
          y+=ky;
          e-=dx;

          if(e<0)
          {
              x+=kx;
              e+=dy;
          }

          uchar *linia = im.scanLine(y);
          linia[4*x]=r;
          linia[4*x+1]=g;
          linia[4*x+2]=b;
       }
    }
}

void Rysowanie_widget1::drawKolo(int x, int y, int pox, int poy, int r, int g, int b)
{
    int ro=sqrt((pox-x)*(pox-x)+(poy-y)*(poy-y));
    int xx;

    for(int yt=0;yt<=ro/sqrt(2);yt++)
    {
         xx=sqrt(ro*ro-yt*yt);

        PutPixel(xx+x,yt+y,r,g,b);
        PutPixel(-xx+x,yt+y,r,g,b);
        PutPixel(xx+x,-yt+y,r,g,b);
        PutPixel(-xx+x,-yt+y,r,g,b);

        PutPixel(yt+x,xx+y,r,g,b);
        PutPixel(yt+x,-xx+y,r,g,b);
        PutPixel(-yt+x,xx+y,r,g,b);
        PutPixel(-yt+x,-xx+y,r,g,b);

    }
}


void Rysowanie_widget1::drawPelneKolo(int x, int y, int pox, int poy, int r, int g, int b)
{
    int ro=sqrt((pox-x)*(pox-x)+(poy-y)*(poy-y));
    int xx;

    for(int yt=0;yt<=ro;yt++)
    {
         xx=sqrt(ro*ro-yt*yt);

        drawLineZajecia(xx+x,yt+y,-xx+x,yt+y,r,g,b);
        drawLineZajecia(-xx+x,-yt+y,xx+x,-yt+y,r,g,b);

    }
}

void Rysowanie_widget1::drawElips(int x, int y, int pox, int poy, int r, int g, int b,double deg)
{
     int r1=abs(pox-x)/2;
     int r2=abs(poy-y)/2;
     int N=64,xt=0,yt=0;
     int srx=(x+pox)/2;
     int sry=(y+poy)/2;
     int xp=0,yp=0;
     float alpha=0.0;
     int actualxpocz=1*r1,actualypocz=0*r2,actualx,actualy;

     actualx=actualxpocz*cos(deg)-actualypocz*sin(deg);
     actualy=actualxpocz*sin(deg)+actualypocz*cos(deg);


     for(int i=-1;i<N;i++)
     {
         alpha = 2* M_PI *i/N;

         xt=r1*cos(alpha);
         yt=r2*sin(alpha);

         xp=xt*cos(deg)-yt*sin(deg);
         yp=xt*sin(deg)+yt*cos(deg);

         drawLineZajecia((float)actualx+srx,(float)actualy+sry,(float)xp+srx,(float)yp+sry,r,g,b);

         actualx=xp;actualy=yp;

     }
}

void Rysowanie_widget1::drwaKrzywaB(std::vector<point> Punkty, int r, int g, int b)
{
    //zaznaczam swoje punkty kontrolne
    for(int j=0;j<Punkty.size();j++)
    {
            //poszerzam je
           PutPixel(Punkty[j].x,Punkty[j].y,255,0,0);
           PutPixel(Punkty[j].x+1,Punkty[j].y,255,0,0);
           PutPixel(Punkty[j].x+1,Punkty[j].y+1,255,0,0);
           PutPixel(Punkty[j].x+1,Punkty[j].y-1,255,0,0);
           PutPixel(Punkty[j].x,Punkty[j].y+1,255,0,0);
           PutPixel(Punkty[j].x,Punkty[j].y-1,255,0,0);
           PutPixel(Punkty[j].x-1,Punkty[j].y,255,0,0);
           PutPixel(Punkty[j].x-1,Punkty[j].y+1,255,0,0);
           PutPixel(Punkty[j].x-1,Punkty[j].y-1,255,0,0);

    }

    if(Punkty.size()>3)
    {
     int N=16;
     float xt=0.,yt=0.;
     float xp=0.,yp=0.;

    //Rysowanie odcinkami
    for(int j=0;j<Punkty.size()-3;j+=3)
        {
         for(int i=0;i<N+1;i++)
            {
                xt=pow((1-((float)i/N)),3)*Punkty[j].x+3*pow(1-((float)i/N),2)*((float)i/N)*Punkty[j+1].x+3*(1-((float)i/N))*((float)i/N)*((float)i/N)*Punkty[j+2].x+pow(((float)i/N),3)*Punkty[j+3].x;
                yt=pow((1-((float)i/N)),3)*Punkty[j].y+3*pow(1-((float)i/N),2)*((float)i/N)*Punkty[j+1].y+3*(1-((float)i/N))*((float)i/N)*((float)i/N)*Punkty[j+2].y+pow(((float)i/N),3)*Punkty[j+3].y;
                if(i==0)
                {
                    xp=xt;
                    yp=yt;
                }
               else drawLineZajecia(xp,yp,xt,yt,r,g,b);

                xp=xt;
                yp=yt;
            }
          }
        }
}

void Rysowanie_widget1::drawKrzywaBsklejane(std::vector<point> Punkty, int r, int g, int b)
{
    //zaznaczam swoje punkty kontrolne
    for(int j=0;j<Punkty.size();j++)
    {

           PutPixel(Punkty[j].x,Punkty[j].y,255,0,0);
           PutPixel(Punkty[j].x+1,Punkty[j].y,255,0,0);
           PutPixel(Punkty[j].x+1,Punkty[j].y+1,255,0,0);
           PutPixel(Punkty[j].x+1,Punkty[j].y-1,255,0,0);
           PutPixel(Punkty[j].x,Punkty[j].y+1,255,0,0);
           PutPixel(Punkty[j].x,Punkty[j].y-1,255,0,0);
           PutPixel(Punkty[j].x-1,Punkty[j].y,255,0,0);
           PutPixel(Punkty[j].x-1,Punkty[j].y+1,255,0,0);
           PutPixel(Punkty[j].x-1,Punkty[j].y-1,255,0,0);

    }
    if(Punkty.size()>3)
    {
     int N=64;
     float xt=0.,yt=0.;
     float xp=0.,yp=0.;
     float t=0.;

    //Rysowanie odcinkami
    for(int j=0;j<Punkty.size()-3;j++)
        {
         for(int i=0;i<N+1;i++)
            {
                t=(float)i/N;
                xt=(1.0/6)*((-t*t*t+3*t*t-3*t+1)*Punkty[j].x+(3*t*t*t-6*t*t+4)*Punkty[j+1].x+((-3)*t*t*t+3*t*t+3*t+1)*Punkty[j+2].x+(t*t*t)*Punkty[j+3].x);
                yt=(1.0/6)*((-t*t*t+3*t*t-3*t+1)*Punkty[j].y+(3*t*t*t-6*t*t+4)*Punkty[j+1].y+((-3)*t*t*t+3*t*t+3*t+1)*Punkty[j+2].y+(t*t*t)*Punkty[j+3].y);

               if(i==0)
               {
                   xp=xt;
                   yp=yt;
               }
               else drawLineZajecia(xp,yp,xt,yt,r,g,b);

               xp=xt;
               yp=yt;

            }
       }

     }



}

void Rysowanie_widget1::rotate(int k)
{
    deg=k*M_PI/180;

    im.fill(Qt::color1);

    drawElips(x,y,pox,poy,r,g,b,deg);

    update();
}


void Rysowanie_widget1::TrybDOD()
{
    Trybix = 0;

}

void Rysowanie_widget1::TrybODD()
{
    Trybix =1;
}

void Rysowanie_widget1::TrybPRZ()
{
    Trybix = 2;
}

