#include "operacjem.h"

OperacjeM::OperacjeM(QWidget *parent) : QWidget(parent)
{

    OperationImg= QImage(width,height,QImage::Format_RGB32);
    OperationImg.fill(Qt::black);

    KopiaImg= QImage(width,height,QImage::Format_RGB32);
    KopiaImg.fill(Qt::black);

    //painter
    MarkerImg= QImage(3,3,QImage::Format_RGB32);
    MarkerImg.fill(Qt::black);

//picture from outside
  QString path= QFileDialog ::getOpenFileName();
    if(!path.isNull())
    {
        QImage obr(path);//fora po wszytskich pixelach i robić na biało

        if(obr.isNull())
        {
            qDebug("Obrazek nie załadował się");
            exit(-1);
        }
        QPainter p(&OperationImg);
        //QPainter r(&KopiaImg);
        p.drawImage(0,0,obr);
        //r.drawImage(0,0,obr);
        p.end();
        //r.end();
        OperationImg.setPixel(130,20,0xff000000);

    }
KopiaImg=OperationImg;
//memcpy(KopiaImg.bits(),OperationImg.bits(),width*height*4);

}

void OperacjeM::paintEvent(QPaintEvent *)
{
        QPainter p(this);

     //   memcpy(OperationImg.bits(),KopiaImg.bits(),width*height*4);
       //p.drawImage(0,0,KopiaImg);
        OperationImg=KopiaImg;
        p.drawImage(0,0,OperationImg);
}

void OperacjeM::mouseReleaseEvent(QMouseEvent *)
{

    //wykonaj akcje
    switch(action)
    {
    case 1:
    {
       Erozja();
    }break;
    case 2:
    {
        Delatacja();
    }break;
    case 3:
    {
        Delatacja();
        Erozja();

    }break;
    case 4:
    {

        Erozja();
        Delatacja();
    }break;

    }
    update();
}

void OperacjeM::erozjaA()
{
    action = 1;
}

void OperacjeM::delatacjaA()
{
    action = 2;
}

void OperacjeM::zamkniecieA()
{
    action = 3;
}

void OperacjeM::otwarcieA()
{
    action = 4;
}

void OperacjeM::Erozja()
{

    for(int y=1;y<height-1;y++)
    {

        uchar *liniaC = KopiaImg.scanLine(y);
        for(int x=1;x<width-1;x++)
        {

            bool f = false;
            for(int ky=y-1;ky<=y+1;ky++)
            {

                 uchar *linia = OperationImg.scanLine(ky);
                for(int kx=x-1;kx<=x+1;kx++)
                {

                    if(linia[4*kx]!=0)
                    {
                        //w drugim obrazku zgaszamy pixel x y
                        liniaC[4*x]=255;
                        liniaC[(4*x)+1]=255;
                        liniaC[(4*x)+2]=255;
                        qDebug("x %d y %d",x,y);
                        f = true;
                        break;
                    }
                    if(f)break;
                }
            }
        }
    }
}

void OperacjeM::Delatacja()
{
    for(int y=1;y<height-1;y++)
    {

        uchar *liniaC = KopiaImg.scanLine(y);
        for(int x=1;x<width-1;x++)
        {
            bool f = false;
            for(int ky=y-1;ky<=y+1;ky++)
            {

                 uchar *linia = OperationImg.scanLine(ky);
                for(int kx=x-1;kx<=x+1;kx++)
                {

                    if(linia[4*kx]==0)
                    {
                        //w drugim obrazku zapalam pixel x y
                        liniaC[4*x]=0;
                        liniaC[(4*x)+1]=0;
                        liniaC[(4*x)+2]=0;
                        qDebug("x %d y %d",x,y);
                        f = true;
                        break;
                    }
                    if(f)break;
                }
            }
        }
    }
}




void OperacjeM::Zamkniecie()
{
        //od oryginału odjemujemy delatacje
}

void OperacjeM::Otwarcie()
{
        //od oryginału odejmujemy eozje
}

