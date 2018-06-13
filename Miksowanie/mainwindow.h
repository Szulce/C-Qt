#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
   void paintEvent(QPaintEvent *);
//    void mousePressEvent(QMouseEvent *);
//    void mouseReleaseEvent(QMouseEvent *);
//    void mouseMoveEvent(QMouseEvent *);
//    void wheelEvent(QWheelEvent *);
public slots:
    //sloty do oblugi przyciskow
  void AdditiveClicked();
   void DifferenceClicked();
   void StampClicked();
   void MultiplayClicked();
   void DarkClicked();
   void HardLightClicked();
   void ScreenClicked();
   void AverageClicked();
   void NegationClicked();
   //sloty do obslugi slidera
   void AlfaChange(int);
   //sloty do obslugi radio
   void Warstwa2();
   void Warstwa3();

private:
    Ui::MainWindow *ui;
     QImage img1,img2,img3;
     QImage current=img2,pod=img1,wynik;
     QImage wynik12,wynik123;
     bool nad_pod = false;
     bool first = true;
     float Alfa2=0.0,Alfa3=0.0;
    int akcjaCurrent=0,akcjaPod=0;
   int akcjaImg2=1;
   int akcjaImg3=1;
     QWidget *obrazek;

     void cykl3();
     void cykl2();

};

#endif // MAINWINDOW_H
