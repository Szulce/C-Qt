#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QPainter>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);



    //Widget obrazka
//    obrazek = new QWidget(ui->ObrazekWidget);
//    obrazek->setGeometry(QRect(30,20,250,160));
//    obrazek->setStyleSheet("background-color:black;");
//    obrazek->show();

 //sloty
    //buttons
    connect(ui->pushButtonAdditive,SIGNAL(clicked()),this,SLOT(AdditiveClicked()));
    connect(ui->pushButtonMultiplay,SIGNAL(clicked()),this,SLOT(MultiplayClicked()));
    connect(ui->pushButtonAverage,SIGNAL(clicked()),this,SLOT(AverageClicked()));
    connect(ui->pushButtonDark,SIGNAL(clicked()),this,SLOT(DarkClicked()));
    connect(ui->pushButtonDifference,SIGNAL(clicked()),this,SLOT(DifferenceClicked()));
    connect(ui->pushButtonNegation,SIGNAL(clicked()),this,SLOT(NegationClicked()));
    connect(ui->pushButtonScreen,SIGNAL(clicked()),this,SLOT(ScreenClicked()));
    connect(ui->pushButtonStamp,SIGNAL(clicked()),this,SLOT(StampClicked()));
    connect(ui->pushButtonHard,SIGNAL(clicked()),this,SLOT(HardLightClicked()));
    //radio
    connect(ui->radioButtonWarstwa2,SIGNAL(clicked(bool)),this,SLOT(Warstwa2()));
    connect(ui->radioButtonWarstwa3,SIGNAL(clicked(bool)),this,SLOT(Warstwa3()));
    //slider
    connect(ui->horizontalSliderAlfa,SIGNAL(sliderMoved(int)),this,SLOT(AlfaChange(int)));


    //obrazek 1
    QString path1= QFileDialog ::getOpenFileName();
        if(!path1.isNull())
        {
            QImage obr(path1);
            if(obr.isNull())
            {
                qDebug("Obrazek 0 nie załadował się");
                exit(-1);
            }
            img1=obr;
            wynik = img1;
        }


        //obrazek 2
        QString path2= QFileDialog ::getOpenFileName();
            if(!path2.isNull())
            {
                QImage obr(path2);
                if(obr.isNull())
                {
                    qDebug("Obrazek 1 nie załadował się");
                    exit(-1);
                }
                img2 = obr;

            }


            //obrazek 3
            QString path3= QFileDialog ::getOpenFileName();
                if(!path3.isNull())
                {
                    QImage obr(path3);
                    if(obr.isNull())
                    {
                        qDebug("Obrazek 2 nie załadował się");
                        exit(-1);
                    }
                  img3 = obr;

                }

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *)
{
    //tutaj ta petle nieskonczona

       QPainter p(this);
       p.drawImage(30,20,wynik);


}

void MainWindow::SliderTx(int)
{

}

//1
void MainWindow::AdditiveClicked()
{


    if(nad_pod)
    {
   // if(!first){
        akcjaCurrent = 1;
        akcjaImg3 = 1;
         ui->horizontalSliderAlfa->setValue(Alfa3);
         //cykl3();
         cykl2();
         wynik123 = wynik;
    }
    else
    {
        akcjaPod = 1;
        akcjaImg2 = 1;
         ui->horizontalSliderAlfa->setValue(Alfa2);
        cykl2();
        wynik12=wynik;

    }




}

void MainWindow::DifferenceClicked()
{
    //difference
    if(nad_pod)
    {
        akcjaCurrent = 2;
        akcjaImg3 = 2;
         ui->horizontalSliderAlfa->setValue(Alfa3);
        cykl2();
    }
    else
    {
        akcjaPod = 2;
        akcjaImg2 = 2;
         ui->horizontalSliderAlfa->setValue(Alfa2);
        cykl2();
    }


}

void MainWindow::StampClicked()
{
    if(nad_pod)
    {
        akcjaCurrent = 3;
        akcjaImg3 = 3;
        cykl2();
    }
    else
    {
        akcjaPod = 3;
        akcjaImg2 = 3;
        cykl2();
    }


}

void MainWindow::MultiplayClicked()
{
    //multiplay
    if(nad_pod)
    {
        akcjaCurrent = 4;
        akcjaImg3 = 4;
        cykl2();
    }
    else
    {
        akcjaPod = 4;
        akcjaImg2 = 4;
        cykl2();
    }



}

void MainWindow::DarkClicked()
{
    //dark
    if(nad_pod)
    {
        akcjaCurrent = 5;
        akcjaImg3 = 5;
        cykl2();
    }
    else
    {
        akcjaPod = 5;
        akcjaImg2 = 5;
        cykl2();
    }



}

void MainWindow::HardLightClicked()
{
    //hard
    if(nad_pod)
    {
        akcjaCurrent = 6;
        akcjaImg3 = 6;
        cykl2();
    }
    else
    {
        akcjaPod = 6;
        akcjaImg2 = 6;
        cykl2();
    }


}

void MainWindow::ScreenClicked()
{
    //screen
    if(nad_pod)
    {
        akcjaCurrent = 7;
        akcjaImg3 = 7;
        cykl2();
    }
    else
    {
        akcjaPod = 7;
        akcjaImg2 = 7;
        cykl2();
    }


}

void MainWindow::AverageClicked()
{
    //average
    if(nad_pod)
    {
        akcjaCurrent = 8;
        akcjaImg3 = 8;
        cykl2();
    }
    else
    {
        akcjaPod = 8;
        akcjaImg2 = 8;
        cykl2();
    }



}

void MainWindow::NegationClicked()
{
    //negation
    if(nad_pod)
    {
        akcjaCurrent = 9;
        akcjaImg3 = 9;
        cykl2();
    }
    else
    {
        akcjaPod = 9;
        akcjaImg2 =9;
        cykl2();
    }


}

void MainWindow::AlfaChange(int c)
{


    if(nad_pod){Alfa3 = (float)c/100;}
        //cykl3();}
        else {Alfa2 = (float)c/100;}
        cykl2();

//    QImage zast = current;

//    //adding
//    for(int i=0;i<160;i++)
//    {

//        uchar *lineWynik = zast.scanLine(i);

//        for(int j=0;j<250;j++)
//        {

//                lineWynik[(4*j)+3]=Alfa;

//        }
//    }


}

void MainWindow::Warstwa2()
{
    current = img2;
    pod = img1;
    nad_pod = false;
    first = false;
    //set lider on
    ui->horizontalSliderAlfa->setValue(Alfa2);
}

void MainWindow::Warstwa3()
{
    current = img3;
    pod = img2;
    nad_pod = true;
    first = false;
    ui->horizontalSliderAlfa->setValue(Alfa3);
}

void MainWindow::cykl3()
{

    //wykonaj wszystko od nowa
   // cykl2();
   /* current = img2;
    pod = img1;
    switch(akcjaImg2)
        {
         case 1:{
        QImage zast = pod;

        //adding
        for(int i=0;i<160;i++)
        {
            uchar *lineCurrent = current.scanLine(i);
            uchar *lineWynik = zast.scanLine(i);

            for(int j=0;j<250;j++)
            {

                int c1 = lineCurrent[4*j]+lineWynik[4*j];
                int c2 = lineCurrent[(4*j)+1]+lineWynik[(4*j)+1];
                int c3 = lineCurrent[(4*j)+2]+lineWynik[(4*j)+2];

                //tutaj kanal alfa

                if(c1>255)
                {
                    lineWynik[4*j]=255;

                }
                else
                {
                    lineWynik[4*j]=c1;

                }

                if(c2>255)
                {
                    lineWynik[(4*j)+1]=255;

                }
                else
                {
                    lineWynik[(4*j)+1]=c2;

                }

                if(c3>255)
                {
                    lineWynik[(4*j)+2]=255;

                }
                else
                {
                    lineWynik[(4*j)+2]=c3;

                }

            }
        }

       wynik = zast;
       }
            break;
        case 2:
           {
        QImage zast = pod;

        for(int i=0;i<160;i++)
        {
            uchar *lineCurrent = current.scanLine(i);
            uchar *lineWynik = zast.scanLine(i);

            for(int j=0;j<250;j++)
            {

                 lineWynik[4*j]=abs(lineWynik[4*j]-lineCurrent[4*j]);

                 lineWynik[(4*j)+1]=abs(lineWynik[(4*j)+1]-lineCurrent[(4*j)+1]);

                 lineWynik[(4*j)+2]=abs(lineWynik[(4*j)+2]-lineCurrent[(4*j)+2]);
            }
        }

       wynik = zast;
       update();}
            break;
         case 3:
            {
        //stamp
        QImage zast = pod;

        for(int i=0;i<160;i++)
        {

            uchar *lineCurrent = current.scanLine(i);
            uchar *lineWynik = zast.scanLine(i);

            for(int j=0;j<250;j++)
            {

                int c1 = lineCurrent[4*j]+2*lineWynik[4*j]-256;
                int c2 = lineCurrent[(4*j)+1]+2*lineWynik[(4*j)+1]-256;
                int c3 = lineCurrent[(4*j)+2]+2*lineWynik[(4*j)+2]-256;

                //tutaj kanal alfa

                if(c1<0)
                {
                    lineWynik[4*j]=0;

                }
                else if(c1>255)
                {
                    lineWynik[4*j]=255;
                }
                else
                {
                    lineWynik[4*j]=c1;

                }

                if(c2<0)
                {
                    lineWynik[(4*j)+1]=0;
                }
                else if(c2>255)
                {
                    lineWynik[(4*j)+1]=255;

                }
                else
                {
                    lineWynik[(4*j)+1]=c2;

                }

                if(c3<0)
                {
                     lineWynik[(4*j)+2]=0;
                }
                else if(c3>255)
                {
                    lineWynik[(4*j)+2]=255;

                }
                else
                {
                    lineWynik[(4*j)+2]=c3;

                }

            }
        }

       wynik = zast;
       update();
    }
            break;
         case 4:
           {QImage zast = pod;

        //adding
        for(int i=0;i<160;i++)
        {
            uchar *lineCurrent = current.scanLine(i);
            uchar *lineWynik = zast.scanLine(i);

            for(int j=0;j<250;j++)
            {

                int c1 = lineCurrent[4*j]*lineWynik[4*j];
                int c2 = lineCurrent[(4*j)+1]*lineWynik[(4*j)+1];
                int c3 = lineCurrent[(4*j)+2]*lineWynik[(4*j)+2];

                //tutaj kanal alfa


                    lineWynik[4*j]=c1>>8;

                    lineWynik[(4*j)+1]=c2>>8;

                    lineWynik[(4*j)+2]=c3>>8;


            }
        }

       wynik = zast;
       update();}
            break;
        case 5:
            {
        QImage zast = pod;

        //adding
        for(int i=0;i<160;i++)
        {
            uchar *lineCurrent = current.scanLine(i);
            uchar *lineWynik = zast.scanLine(i);

            for(int j=0;j<250;j++)
            {
                if(lineCurrent[4*j]<lineWynik[4*j])lineWynik[4*j]=lineCurrent[4*j];
                 else lineWynik[4*j]=lineWynik[4*j];

                if(lineCurrent[(4*j)+1]<lineWynik[(4*j)+1]) lineWynik[(4*j)+1]=lineCurrent[(4*j)+1];
                 else lineWynik[(4*j)+1]=lineWynik[(4*j)+1];

                if(lineCurrent[(4*j)+2]<lineWynik[(4*j)+2])lineWynik[(4*j)+2]=lineCurrent[(4*j)+2];
                  else lineWynik[(4*j)+2]=lineWynik[(4*j)+2];


            }
        }

       wynik = zast;
       update();
    }
            break;
        case 6:
            {QImage zast = pod;

        for(int i=0;i<160;i++)
        {
            uchar *lineCurrent = current.scanLine(i);
            uchar *lineWynik = zast.scanLine(i);

            for(int j=0;j<250;j++)
            {
                if(lineWynik[4*j]<128)lineWynik[4*j]=lineWynik[4*j]*lineCurrent[4*j]>>7;
                 else lineWynik[4*j]=255-((255-lineWynik[4*j])*(255-lineCurrent[4*j])>>7);

                if(lineWynik[(4*j)+1]<128)lineWynik[(4*j)+1]=lineWynik[(4*j)+1]*lineCurrent[(4*j)+1]>>7;
                 else lineWynik[(4*j)+1]=255-((255-lineWynik[(4*j)+1])*(255-lineCurrent[(4*j)+1])>>7);

                if(lineWynik[(4*j)+2]<128)lineWynik[(4*j)+2]=lineWynik[(4*j)+2]*lineCurrent[(4*j)+2]>>7;
                 else lineWynik[(4*j)+2]=255-((255-lineWynik[(4*j)+2])*(255-lineCurrent[(4*j)+2])>>7);


            }
        }

       wynik = zast;
       update();}
            break;
        case 7:
            { QImage zast = pod;

        for(int i=0;i<160;i++)
        {
            uchar *lineCurrent = current.scanLine(i);
            uchar *lineWynik = zast.scanLine(i);

            for(int j=0;j<250;j++)
            {

                 lineWynik[4*j]=255-((255-lineWynik[4*j])*(255-lineCurrent[4*j])>>8);

                 lineWynik[(4*j)+1]=255-((255-lineWynik[(4*j)+1])*(255-lineCurrent[(4*j)+1])>>8);

                 lineWynik[(4*j)+2]=255-((255-lineWynik[(4*j)+2])*(255-lineCurrent[(4*j)+2])>>8);
            }
        }

       wynik = zast;
       update();}
            break;
        case 8:
            { QImage zast = pod;

        for(int i=0;i<160;i++)
        {
            uchar *lineCurrent = current.scanLine(i);
            uchar *lineWynik = zast.scanLine(i);

            for(int j=0;j<250;j++)
            {

                 lineWynik[4*j]=(lineWynik[4*j]+lineCurrent[4*j])>>1;

                 lineWynik[(4*j)+1]=(lineWynik[(4*j)+1]+lineCurrent[(4*j)+1])>>1;

                 lineWynik[(4*j)+2]=(lineWynik[(4*j)+2]+lineCurrent[(4*j)+2])>>1;
            }
        }

       wynik = zast;
       update();}
            break;
        case 9:
            {QImage zast = pod;

        for(int i=0;i<160;i++)
        {
            uchar *lineCurrent = current.scanLine(i);
            uchar *lineWynik = zast.scanLine(i);

            for(int j=0;j<250;j++)
            {

                 lineWynik[4*j]=255-abs(255-lineWynik[4*j]-lineCurrent[4*j]);

                 lineWynik[(4*j)+1]=255-(255-lineWynik[(4*j)+1]-lineCurrent[(4*j)+1]);

                 lineWynik[(4*j)+2]=255-(255-lineWynik[(4*j)+2]-lineCurrent[(4*j)+2]);
            }
        }

       wynik = zast;
       update();}
            break;

        }

    update();
    //blending
        QImage zast22= wynik ;

        for(int i=0;i<160;i++)
        {

            uchar *lineWynik = zast22.scanLine(i);
            uchar *curline = img2.scanLine(i);
            uchar *podline = img1.scanLine(i);

            for(int j=0;j<250;j++)
            {

                    lineWynik[(4*j)]=(1-Alfa2)*podline[(4*j)]+Alfa2*curline[(4*j)];
                    lineWynik[(4*j)+1]=(1-Alfa2)*podline[(4*j)+1]+Alfa2*curline[(4*j)+1];
                    lineWynik[(4*j)+2]=(1-Alfa2)*podline[(4*j)+2]+Alfa2*curline[(4*j)+2];

            }
        }
        wynik = zast22;
*/
        current = wynik;
        pod = img3;

        switch(akcjaImg3)
            {
             case 1:
                {
            QImage zast = pod;

            //adding
            for(int i=0;i<160;i++)
            {
                uchar *lineCurrent = current.scanLine(i);
                uchar *lineWynik = zast.scanLine(i);

                for(int j=0;j<250;j++)
                {

                    int c1 = lineCurrent[4*j]+lineWynik[4*j];
                    int c2 = lineCurrent[(4*j)+1]+lineWynik[(4*j)+1];
                    int c3 = lineCurrent[(4*j)+2]+lineWynik[(4*j)+2];

                    //tutaj kanal alfa

                    if(c1>255)
                    {
                        lineWynik[4*j]=255;

                    }
                    else
                    {
                        lineWynik[4*j]=c1;

                    }

                    if(c2>255)
                    {
                        lineWynik[(4*j)+1]=255;

                    }
                    else
                    {
                        lineWynik[(4*j)+1]=c2;

                    }

                    if(c3>255)
                    {
                        lineWynik[(4*j)+2]=255;

                    }
                    else
                    {
                        lineWynik[(4*j)+2]=c3;

                    }

                }
            }

           wynik = zast;
           update();
        }
                break;
            case 2:
                {QImage zast = pod;

            for(int i=0;i<160;i++)
            {
                uchar *lineCurrent = current.scanLine(i);
                uchar *lineWynik = zast.scanLine(i);

                for(int j=0;j<250;j++)
                {

                     lineWynik[4*j]=abs(lineWynik[4*j]-lineCurrent[4*j]);

                     lineWynik[(4*j)+1]=abs(lineWynik[(4*j)+1]-lineCurrent[(4*j)+1]);

                     lineWynik[(4*j)+2]=abs(lineWynik[(4*j)+2]-lineCurrent[(4*j)+2]);
                }
            }

           wynik = zast;
           update();}
                break;
             case 3:
        { //stamp
            QImage zast = pod;

            for(int i=0;i<160;i++)
            {

                uchar *lineCurrent = current.scanLine(i);
                uchar *lineWynik = zast.scanLine(i);

                for(int j=0;j<250;j++)
                {

                    int c1 = lineCurrent[4*j]+2*lineWynik[4*j]-256;
                    int c2 = lineCurrent[(4*j)+1]+2*lineWynik[(4*j)+1]-256;
                    int c3 = lineCurrent[(4*j)+2]+2*lineWynik[(4*j)+2]-256;

                    //tutaj kanal alfa

                    if(c1<0)
                    {
                        lineWynik[4*j]=0;

                    }
                    else if(c1>255)
                    {
                        lineWynik[4*j]=255;
                    }
                    else
                    {
                        lineWynik[4*j]=c1;

                    }

                    if(c2<0)
                    {
                        lineWynik[(4*j)+1]=0;
                    }
                    else if(c2>255)
                    {
                        lineWynik[(4*j)+1]=255;

                    }
                    else
                    {
                        lineWynik[(4*j)+1]=c2;

                    }

                    if(c3<0)
                    {
                         lineWynik[(4*j)+2]=0;
                    }
                    else if(c3>255)
                    {
                        lineWynik[(4*j)+2]=255;

                    }
                    else
                    {
                        lineWynik[(4*j)+2]=c3;

                    }

                }
            }

           wynik = zast;
           update();
        }

                break;
             case 4:
             {
            QImage zast = pod;

            //adding
            for(int i=0;i<160;i++)
            {
                uchar *lineCurrent = current.scanLine(i);
                uchar *lineWynik = zast.scanLine(i);

                for(int j=0;j<250;j++)
                {

                    int c1 = lineCurrent[4*j]*lineWynik[4*j];
                    int c2 = lineCurrent[(4*j)+1]*lineWynik[(4*j)+1];
                    int c3 = lineCurrent[(4*j)+2]*lineWynik[(4*j)+2];

                    //tutaj kanal alfa


                        lineWynik[4*j]=c1>>8;

                        lineWynik[(4*j)+1]=c2>>8;

                        lineWynik[(4*j)+2]=c3>>8;


                }
            }

           wynik = zast;
           update();}
                break;
            case 5:
        {QImage zast = pod;

            //adding
            for(int i=0;i<160;i++)
            {
                uchar *lineCurrent = current.scanLine(i);
                uchar *lineWynik = zast.scanLine(i);

                for(int j=0;j<250;j++)
                {
                    if(lineCurrent[4*j]<lineWynik[4*j])lineWynik[4*j]=lineCurrent[4*j];
                     else lineWynik[4*j]=lineWynik[4*j];

                    if(lineCurrent[(4*j)+1]<lineWynik[(4*j)+1]) lineWynik[(4*j)+1]=lineCurrent[(4*j)+1];
                     else lineWynik[(4*j)+1]=lineWynik[(4*j)+1];

                    if(lineCurrent[(4*j)+2]<lineWynik[(4*j)+2])lineWynik[(4*j)+2]=lineCurrent[(4*j)+2];
                      else lineWynik[(4*j)+2]=lineWynik[(4*j)+2];


                }
            }

           wynik = zast;
           update();}
                break;
            case 6:
                {QImage zast = pod;

            for(int i=0;i<160;i++)
            {
                uchar *lineCurrent = current.scanLine(i);
                uchar *lineWynik = zast.scanLine(i);

                for(int j=0;j<250;j++)
                {
                    if(lineWynik[4*j]<128)lineWynik[4*j]=lineWynik[4*j]*lineCurrent[4*j]>>7;
                     else lineWynik[4*j]=255-((255-lineWynik[4*j])*(255-lineCurrent[4*j])>>7);

                    if(lineWynik[(4*j)+1]<128)lineWynik[(4*j)+1]=lineWynik[(4*j)+1]*lineCurrent[(4*j)+1]>>7;
                     else lineWynik[(4*j)+1]=255-((255-lineWynik[(4*j)+1])*(255-lineCurrent[(4*j)+1])>>7);

                    if(lineWynik[(4*j)+2]<128)lineWynik[(4*j)+2]=lineWynik[(4*j)+2]*lineCurrent[(4*j)+2]>>7;
                     else lineWynik[(4*j)+2]=255-((255-lineWynik[(4*j)+2])*(255-lineCurrent[(4*j)+2])>>7);


                }
            }

           wynik = zast;
           update();}
                break;
            case 7:
                { QImage zast = pod;

            for(int i=0;i<160;i++)
            {
                uchar *lineCurrent = current.scanLine(i);
                uchar *lineWynik = zast.scanLine(i);

                for(int j=0;j<250;j++)
                {

                     lineWynik[4*j]=255-((255-lineWynik[4*j])*(255-lineCurrent[4*j])>>8);

                     lineWynik[(4*j)+1]=255-((255-lineWynik[(4*j)+1])*(255-lineCurrent[(4*j)+1])>>8);

                     lineWynik[(4*j)+2]=255-((255-lineWynik[(4*j)+2])*(255-lineCurrent[(4*j)+2])>>8);
                }
            }

           wynik = zast;
           update();}
                break;
            case 8:
               { QImage zast = pod;

            for(int i=0;i<160;i++)
            {
                uchar *lineCurrent = current.scanLine(i);
                uchar *lineWynik = zast.scanLine(i);

                for(int j=0;j<250;j++)
                {

                     lineWynik[4*j]=(lineWynik[4*j]+lineCurrent[4*j])>>1;

                     lineWynik[(4*j)+1]=(lineWynik[(4*j)+1]+lineCurrent[(4*j)+1])>>1;

                     lineWynik[(4*j)+2]=(lineWynik[(4*j)+2]+lineCurrent[(4*j)+2])>>1;
                }
            }

           wynik = zast;
           update();}
                break;
            case 9:
                {QImage zast = pod;

            for(int i=0;i<160;i++)
            {
                uchar *lineCurrent = current.scanLine(i);
                uchar *lineWynik = zast.scanLine(i);

                for(int j=0;j<250;j++)
                {

                     lineWynik[4*j]=255-abs(255-lineWynik[4*j]-lineCurrent[4*j]);

                     lineWynik[(4*j)+1]=255-(255-lineWynik[(4*j)+1]-lineCurrent[(4*j)+1]);

                     lineWynik[(4*j)+2]=255-(255-lineWynik[(4*j)+2]-lineCurrent[(4*j)+2]);
                }
            }

           wynik = zast;
           update();}
                break;

            }

        //blending
        QImage zast123 = wynik;

            for(int i=0;i<160;i++)
            {

                uchar *lineWynik = zast123.scanLine(i);
                uchar *curline = img3.scanLine(i);
                uchar *podline = wynik.scanLine(i);

                for(int j=0;j<250;j++)
                {

                        lineWynik[(4*j)]=(1-Alfa3)*podline[(4*j)]+Alfa3*curline[(4*j)];
                        lineWynik[(4*j)+1]=(1-Alfa3)*podline[(4*j)+1]+Alfa3*curline[(4*j)+1];
                        lineWynik[(4*j)+2]=(1-Alfa3)*podline[(4*j)+2]+Alfa3*curline[(4*j)+2];

                }
            }
            wynik = zast123;

            update();

    //kolejna warstwa

//    switch(akcjaPod)
//    {
//     case 1:
//        AdditiveClicked();
//        break;
//    case 2:
//        DifferenceClicked();
//        break;
//     case 3:
//        StampClicked();
//        break;
//     case 4:
//        MultiplayClicked();
//        break;
//    case 5:
//        DarkClicked();
//        break;
//    case 6:
//        HardLightClicked();
//        break;
//    case 7:
//        ScreenClicked();
//        break;
//    case 8:
//        AverageClicked();
//        break;
//    case 9:
//        NegationClicked();
//        break;

//    }
//    //blending
//    QImage zast ;

//    //adding
//    for(int i=0;i<160;i++)
//    {

//        uchar *lineWynik = zast.scanLine(i);
//        uchar *curline = img2.scanLine(i);
//        uchar *podline = img1.scanLine(i);

//        for(int j=0;j<250;j++)
//        {

//                lineWynik[(4*j)]=(1-Alfa)*podline[(4*j)]+Alfa*curline[(4*j)];
//                lineWynik[(4*j)+1]=(1-Alfa)*podline[(4*j)+1]+Alfa*curline[(4*j)+1];
//                lineWynik[(4*j)+2]=(1-Alfa)*podline[(4*j)+2]+Alfa*curline[(4*j)+2];

//        }
//    }
//    wynik = zast;


//    switch(akcjaCurrent)
//    {
//     case 1:
//        AdditiveClicked();
//        break;
//    case 2:
//        DifferenceClicked();
//        break;
//     case 3:
//        StampClicked();
//        break;
//     case 4:
//        MultiplayClicked();
//        break;
//    case 5:
//        DarkClicked();
//        break;
//    case 6:
//        HardLightClicked();
//        break;
//    case 7:
//        ScreenClicked();
//        break;
//    case 8:
//        AverageClicked();
//        break;
//    case 9:
//        NegationClicked();
//        break;

//    }



//    //adding
//    for(int i=0;i<160;i++)
//    {

//        uchar *lineWynik = zast.scanLine(i);
//        uchar *curline = img3.scanLine(i);
//        uchar *podline = wynik.scanLine(i);

//        for(int j=0;j<250;j++)
//        {

//                lineWynik[(4*j)]=(1-Alfa)*podline[(4*j)]+Alfa*curline[(4*j)];
//                lineWynik[(4*j)+1]=(1-Alfa)*podline[(4*j)+1]+Alfa*curline[(4*j)+1];
//                lineWynik[(4*j)+2]=(1-Alfa)*podline[(4*j)+2]+Alfa*curline[(4*j)+2];

//        }
//    }
//    wynik = zast;



}

void MainWindow::cykl2()
{
    //wykonaj wszystko od nowa
    current = img2;
    pod = img1;
    switch(akcjaImg2)
        {
         case 1:{
        QImage zast = pod;

        //adding
        for(int i=0;i<160;i++)
        {
            uchar *lineCurrent = current.scanLine(i);
            uchar *lineWynik = zast.scanLine(i);

            for(int j=0;j<250;j++)
            {

                int c1 = lineCurrent[4*j]+lineWynik[4*j];
                int c2 = lineCurrent[(4*j)+1]+lineWynik[(4*j)+1];
                int c3 = lineCurrent[(4*j)+2]+lineWynik[(4*j)+2];

                //tutaj kanal alfa

                if(c1>255)
                {
                    lineWynik[4*j]=255;

                }
                else
                {
                    lineWynik[4*j]=c1;

                }

                if(c2>255)
                {
                    lineWynik[(4*j)+1]=255;

                }
                else
                {
                    lineWynik[(4*j)+1]=c2;

                }

                if(c3>255)
                {
                    lineWynik[(4*j)+2]=255;

                }
                else
                {
                    lineWynik[(4*j)+2]=c3;

                }

            }
        }

       wynik = zast;
       update();
       }
            break;
        case 2:
           {
        QImage zast = pod;

        for(int i=0;i<160;i++)
        {
            uchar *lineCurrent = current.scanLine(i);
            uchar *lineWynik = zast.scanLine(i);

            for(int j=0;j<250;j++)
            {

                 lineWynik[4*j]=abs(lineWynik[4*j]-lineCurrent[4*j]);

                 lineWynik[(4*j)+1]=abs(lineWynik[(4*j)+1]-lineCurrent[(4*j)+1]);

                 lineWynik[(4*j)+2]=abs(lineWynik[(4*j)+2]-lineCurrent[(4*j)+2]);
            }
        }

       wynik = zast;
       update();}
            break;
         case 3:
            {
        //stamp
        QImage zast = pod;

        for(int i=0;i<160;i++)
        {

            uchar *lineCurrent = current.scanLine(i);
            uchar *lineWynik = zast.scanLine(i);

            for(int j=0;j<250;j++)
            {

                int c1 = lineCurrent[4*j]+2*lineWynik[4*j]-256;
                int c2 = lineCurrent[(4*j)+1]+2*lineWynik[(4*j)+1]-256;
                int c3 = lineCurrent[(4*j)+2]+2*lineWynik[(4*j)+2]-256;

                //tutaj kanal alfa

                if(c1<0)
                {
                    lineWynik[4*j]=0;

                }
                else if(c1>255)
                {
                    lineWynik[4*j]=255;
                }
                else
                {
                    lineWynik[4*j]=c1;

                }

                if(c2<0)
                {
                    lineWynik[(4*j)+1]=0;
                }
                else if(c2>255)
                {
                    lineWynik[(4*j)+1]=255;

                }
                else
                {
                    lineWynik[(4*j)+1]=c2;

                }

                if(c3<0)
                {
                     lineWynik[(4*j)+2]=0;
                }
                else if(c3>255)
                {
                    lineWynik[(4*j)+2]=255;

                }
                else
                {
                    lineWynik[(4*j)+2]=c3;

                }

            }
        }

       wynik = zast;
       update();
    }
            break;
         case 4:
           {QImage zast = pod;

        //adding
        for(int i=0;i<160;i++)
        {
            uchar *lineCurrent = current.scanLine(i);
            uchar *lineWynik = zast.scanLine(i);

            for(int j=0;j<250;j++)
            {

                int c1 = lineCurrent[4*j]*lineWynik[4*j];
                int c2 = lineCurrent[(4*j)+1]*lineWynik[(4*j)+1];
                int c3 = lineCurrent[(4*j)+2]*lineWynik[(4*j)+2];

                //tutaj kanal alfa


                    lineWynik[4*j]=c1>>8;

                    lineWynik[(4*j)+1]=c2>>8;

                    lineWynik[(4*j)+2]=c3>>8;


            }
        }

       wynik = zast;
       update();}
            break;
        case 5:
            {
        QImage zast = pod;

        //adding
        for(int i=0;i<160;i++)
        {
            uchar *lineCurrent = current.scanLine(i);
            uchar *lineWynik = zast.scanLine(i);

            for(int j=0;j<250;j++)
            {
                if(lineCurrent[4*j]<lineWynik[4*j])lineWynik[4*j]=lineCurrent[4*j];
                 else lineWynik[4*j]=lineWynik[4*j];

                if(lineCurrent[(4*j)+1]<lineWynik[(4*j)+1]) lineWynik[(4*j)+1]=lineCurrent[(4*j)+1];
                 else lineWynik[(4*j)+1]=lineWynik[(4*j)+1];

                if(lineCurrent[(4*j)+2]<lineWynik[(4*j)+2])lineWynik[(4*j)+2]=lineCurrent[(4*j)+2];
                  else lineWynik[(4*j)+2]=lineWynik[(4*j)+2];


            }
        }

       wynik = zast;
       update();
    }
            break;
        case 6:
            {QImage zast = pod;

        for(int i=0;i<160;i++)
        {
            uchar *lineCurrent = current.scanLine(i);
            uchar *lineWynik = zast.scanLine(i);

            for(int j=0;j<250;j++)
            {
                if(lineWynik[4*j]<128)lineWynik[4*j]=lineWynik[4*j]*lineCurrent[4*j]>>7;
                 else lineWynik[4*j]=255-((255-lineWynik[4*j])*(255-lineCurrent[4*j])>>7);

                if(lineWynik[(4*j)+1]<128)lineWynik[(4*j)+1]=lineWynik[(4*j)+1]*lineCurrent[(4*j)+1]>>7;
                 else lineWynik[(4*j)+1]=255-((255-lineWynik[(4*j)+1])*(255-lineCurrent[(4*j)+1])>>7);

                if(lineWynik[(4*j)+2]<128)lineWynik[(4*j)+2]=lineWynik[(4*j)+2]*lineCurrent[(4*j)+2]>>7;
                 else lineWynik[(4*j)+2]=255-((255-lineWynik[(4*j)+2])*(255-lineCurrent[(4*j)+2])>>7);


            }
        }

       wynik = zast;
       update();}
            break;
        case 7:
            { QImage zast = pod;

        for(int i=0;i<160;i++)
        {
            uchar *lineCurrent = current.scanLine(i);
            uchar *lineWynik = zast.scanLine(i);

            for(int j=0;j<250;j++)
            {

                 lineWynik[4*j]=255-((255-lineWynik[4*j])*(255-lineCurrent[4*j])>>8);

                 lineWynik[(4*j)+1]=255-((255-lineWynik[(4*j)+1])*(255-lineCurrent[(4*j)+1])>>8);

                 lineWynik[(4*j)+2]=255-((255-lineWynik[(4*j)+2])*(255-lineCurrent[(4*j)+2])>>8);
            }
        }

       wynik = zast;
       update();}
            break;
        case 8:
            { QImage zast = pod;

        for(int i=0;i<160;i++)
        {
            uchar *lineCurrent = current.scanLine(i);
            uchar *lineWynik = zast.scanLine(i);

            for(int j=0;j<250;j++)
            {

                 lineWynik[4*j]=(lineWynik[4*j]+lineCurrent[4*j])>>1;

                 lineWynik[(4*j)+1]=(lineWynik[(4*j)+1]+lineCurrent[(4*j)+1])>>1;

                 lineWynik[(4*j)+2]=(lineWynik[(4*j)+2]+lineCurrent[(4*j)+2])>>1;
            }
        }

       wynik = zast;
       update();}
            break;
        case 9:
            {QImage zast = pod;

        for(int i=0;i<160;i++)
        {
            uchar *lineCurrent = current.scanLine(i);
            uchar *lineWynik = zast.scanLine(i);

            for(int j=0;j<250;j++)
            {

                 lineWynik[4*j]=255-abs(255-lineWynik[4*j]-lineCurrent[4*j]);

                 lineWynik[(4*j)+1]=255-(255-lineWynik[(4*j)+1]-lineCurrent[(4*j)+1]);

                 lineWynik[(4*j)+2]=255-(255-lineWynik[(4*j)+2]-lineCurrent[(4*j)+2]);
            }
        }

       wynik = zast;
       update();}
            break;

        }

    update();
    //blending
        QImage zast =wynik;

        for(int i=0;i<160;i++)
        {

            uchar *lineWynik = zast.scanLine(i);
            uchar *curline = wynik.scanLine(i);
            uchar *podline = img1.scanLine(i);

            for(int j=0;j<250;j++)
            {

                    lineWynik[(4*j)]=(1-Alfa2)*podline[(4*j)]+Alfa2*curline[(4*j)];
                    lineWynik[(4*j)+1]=(1-Alfa2)*podline[(4*j)+1]+Alfa2*curline[(4*j)+1];
                    lineWynik[(4*j)+2]=(1-Alfa2)*podline[(4*j)+2]+Alfa2*curline[(4*j)+2];

            }
        }
        wynik = zast;
        update();
        if(!first)cykl3();
}
