#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //rysowanie image SV
        imSV = QImage(120,120,QImage::Format_RGB32);
        tloSV = QImage(120,120,QImage::Format_RGB32);
        imSV.fill(Qt::black);

        for(int i = 0;i<120;i++){
         uchar *linia = imSV.scanLine(i);
         for(int j = 0;j<120;j++)
         {

             S =((double)5/6)*j;
             V =((double)5/6)*i;
             computeRGB();
             linia[4*j] =R;
             linia[(4*j)+1]=G;
             linia[(4*j)+2]=B;
         }
        }
        tloSV = imSV;
      //narysowanie punktu w 0
          rysujX();

    //rysowanie H
          imH = QImage(30,120,QImage::Format_RGB32);
          tloH = QImage(30,120,QImage::Format_RGB32);
          imH.fill(Qt::black);
            S=100.0;
            V=100.0;
          for(int i = 0;i<120;i++){
           uchar *linia = imH.scanLine(i);
           H =3*i;
         // Hwidok();
           computeRGB();
          // qDebug("i=%d ,hsv=%f,%f,%f  rgb=%f,%f,%f\n",i,H,S,V,R,G,B);
           for(int j = 0;j<30;j++)
           {

              linia[4*j] =R;
               linia[(4*j)+1]=G;
               linia[(4*j)+2]=B;
           }
          }
          tloH = imH;
        //narysowanie punktu w 0

            rysuj_Linie(0);

            //definicja sliderów




        //sówaki i przeliczanie w main window
         connect(ui->hSlider,SIGNAL(sliderMoved(int)),this,SLOT(changeH(int)));
         connect(ui->sSlider,SIGNAL(sliderMoved(int)),this,SLOT(changeS(int)));
         connect(ui->vSlider,SIGNAL(sliderMoved(int)),this,SLOT(changeV(int)));

         connect(ui->rSlider,SIGNAL(sliderMoved(int)),this,SLOT(changeR(int)));
         connect(ui->gSlider,SIGNAL(sliderMoved(int)),this,SLOT(changeG(int)));
         connect(ui->bSlider,SIGNAL(sliderMoved(int)),this,SLOT(changeB(int)));



}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter svP(this);
    QPainter hP(this);
     svP.drawImage(15,20,imSV);
     hP.drawImage(150,20,imH);
}

void MainWindow::mousePressEvent(QMouseEvent *e)
{


    if(abs(e->y() - (pointhY+20))<10)
    {
        drag = true;

    }

    if((abs(e->y() - pointsvY-20)<10) && (abs(e->x()-pointsvX-15)<10))
    {
        dragSV = true;

    }
}

void MainWindow::mouseReleaseEvent(QMouseEvent *e)
{
  drag = false;
  dragSV = false;

  //tutaj pobrac color z pxeli
  GetPixelColor(e->x(),e->y());
  computeHSV();
  //zmienic slidery
}

void MainWindow::mouseMoveEvent(QMouseEvent *e)
{
    if((e->x()>14 && e->x()<135)||(e->x()>150 && e->x()<180)){
    if(drag)
    {
        pointhY = e -> y()-20 ;

        H = pointhY*3;
        //set slider
        ui->hSlider->setSliderPosition(H/3);
        qDebug("%f %f",H, pointhY);
        for(int i = 0;i<120;i++){

         uchar *linia = tloSV.scanLine(i);

         for(int j = 0;j<120;j++)
         {

             S =((double)5/6)*j;
             V =((double)5/6)*i;
             computeRGB();
             linia[4*j] =R;
             linia[(4*j)+1]=G;
             linia[(4*j)+2]=B;
         }
        }
        imSV  = tloSV;
        rysujX();
        rysuj_Linie(pointhY);
    }

    if(dragSV)
    {
        pointsvY = e->y()-20 ;
        pointsvX = e->x()-15;
        //przerysowanie punktu

        S = pointsvY;
        V = pointsvX;
        ui->sSlider->setSliderPosition(S);
        ui->vSlider->setSliderPosition(V);

        rysujX();
    }

    ui->rSlider->setSliderPosition(R);
    ui->gSlider->setSliderPosition(G);
    ui->bSlider->setSliderPosition(B);
    update();
    }
}

void MainWindow::changeR(int c)
{
    //zmien woartosci
        R=c;
        //przelicz pozostałe wartości
        computeHSV();
        ui->hSlider->setSliderPosition(H);
        ui->sSlider->setSliderPosition(S);
        ui->vSlider->setSliderPosition(V);

        //przemlauj od nowa

        update();
        //przemaluj widget

        qDebug("%f",H);
       // rysuj_Linie(H*3);
        update();
        //svh_rgb_get(R,G,B,H,S,V);
}

void MainWindow::changeG(int c)
{
    //zmien woartosci
        G=c;
        //przelicz pozostałe wartości
        computeHSV();
        update();

       // rysuj_Linie(H*3);
       update();
}

void MainWindow::changeB(int c)
{
    //zmien woartosci
        B=c;
        //przelicz pozostałe wartości
        computeHSV();
        update();

       // rysuj_Linie(H*3);
        update();
}

void MainWindow::changeH(int c)
{
    //przesówam pozycje punktu w y
        pointhY=c;
           H = c*3;
      //przerysowanie punktu


        for(int i = 0;i<120;i++){
         uchar *linia = tloSV.scanLine(i);

         for(int j = 0;j<120;j++)
         {

             S =((double)5/6)*j;
             V =((double)5/6)*i;
             computeRGB();
             linia[4*j] =R;
             linia[(4*j)+1]=G;
             linia[(4*j)+2]=B;
         }
        }
        imSV  = tloSV;
        rysujX();
        update();


        rysuj_Linie(pointhY);
        update();

}

void MainWindow::changeS(int c)
{
    //przesówam pozycje punktu
        //S JEST POZIOMY
        pointsvX=c;
        S = c;

         //przerysowanie punktu
           rysujX();
           update();
}

void MainWindow::changeV(int c)
{
    //przesówam pozycje punktu
      //V JEST PINOWY
      pointsvY=c;
      V= c;

       //przerysowanie punktu
          rysujX();
          update();
}

void MainWindow::computeRGB()
{
//    float h=floor(H/60);
//    float v=V/100,s=S/100;
//    float f = H/60-h;
//    float p = v*(1-s);
//    float q = v*(1-(s*f));
//    float t = v*(1-(s*(1-f)));
//     if (i==0) {R=v; G=t; B=p;}
//     else if (i==1) {R=q; G=v; B=p;}
//     else if (i==2) {R=p; G=v; B=t;}
//     else if (i==3) {R=p; G=q; B=v;}
//     else if (i==4) {R=t; G=p; B=v;}
//     else if (i==5) {R=v; G=p; B=q;}

   //  R*=255;B*=255;G*=255;
  //  }

    float h = H,s = S/100,v = V/100;
    float C = v*s;
    float X = C*(1-fabs((fmod((h/60),2) )-1));
    float m = v-C;

    float r,g,b;

    if(0<=h && h<60)
    {
        r=C;
        b=X;
        g=0;
    }
    else if(60<=h && h<120)
    {
        r=X;
        b=C;
        g=0;
    }
    else if(120<=h && h<180)
    {
        r=0;
        b=C;
        g=X;
    }
    else if(180<=h && h<240)
    {
        r=0;
        b=X;
        g=C;
    }
    else if(240<=h && h<300)
    {
        r=X;
        b=0;
        g=C;
    }
    else if(300<=h && h<360)
    {
        r=C;
        b=0;
        g=X;
    }

    R=(r+m)*255;
    G=(g+m)*255;
    B=(b+m)*255;

  // qDebug("rgb=(%f,%f,%f)",R,G,B);


}

void MainWindow::computeHSV()
{
    float r=R/255;
       float g=G/255;
       float b=B/255;

       float Cmax;
       char Max;
       float Cmin;
       float delta;

       //find min and max beetween three values
      if(r>=g){
          if(g>=b){
              Cmax = r;
              Cmin = b;
              Max = 'r';

          }
          else if(r>=b){
              Cmax=r;
              Cmin=g;
              Max = 'r';

          }
          else{
              Cmax = b;
              Cmin = g;
              Max = 'b';

          }

          }
      else if(g>=r)
      {
          if(r>=b)
          {
              Cmax=g;
              Cmin=b;
              Max = 'g';

          }
          else if(g>=b)
          {
              Cmax=g;
              Cmin=r;
              Max = 'g';

          }
          else{
              Cmax=b;
              Cmin=r;
              Max = 'b';

          }
      }

      delta = Cmax - Cmin;

      //final calculation

      //H
      if(delta == 0){H=0;}
      else if(Max=='r'){
          H=60*((int)((g-b)/delta)%6);
      }
      else if(Max=='g'){
          H=60*(((b-r)/delta)+2);
      }
      else if(Max=='b'){
           H=60*(((r-g)/delta)+4);
      }

      //S
      if(Cmax==0){
          S=0;

      }
      else{
          S=100*delta/Cmax;
      }

      //V
      V=100*Cmax;
     // qDebug("SHV\nr %f g %f b %f\n",R,G,B);
     // qDebug("h %f s %f v %f\n",H,S,V);
}

void MainWindow::rysuj_Linie(int i)
{
    imH = tloH;
    uchar  *linia = imH.scanLine(i);
    for(int i=0;i<30;i++)
    {
        linia[4*i] = 0;
        linia[(4*i)+1]=0;
        linia[(4*i)+2]=255;
    }
}

void MainWindow::rysujX()
{
    imSV = tloSV;
    for(int i=0;i<120;i++)
    {
        uchar *linia = imSV.scanLine(i);
        if(i == pointsvY)
        {
            for(int j=0;j<120;j++)
            {
                if(j==pointsvX)
                {
                  // qDebug("wykonuje sie");
                    linia[4*j]=0;
                    linia[(4*j)+1]=0;
                    linia[(4*j)+2]=255;
                }
                else{
                    // qDebug("nie wykonuje sie");
                linia[4*j]=0;
                linia[(4*j)+1]=0;
                linia[(4*j)+2]=255;
                }
            }
        }
        else
        {
            linia[4*pointsvX]=0;
            linia[(4*pointsvX)+1]=0;
            linia[(4*pointsvX)+2]=255;
        }
    }

}

void MainWindow::GetPixelColor(int x, int y)
{
    QColor b = QColor(imSV.pixel(x,y));

    svR = b.red();
    svG = b.green();
    svB = b.blue();
}

