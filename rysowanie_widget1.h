#ifndef RYSOWANIE_WIDGET1_H
#define RYSOWANIE_WIDGET1_H

#include <QWidget>
#include <vector>


struct point
{
    int x;
    int y;
};


class Rysowanie_widget1 : public QWidget
{
    Q_OBJECT
public:
    explicit Rysowanie_widget1(QWidget *parent = 0);
protected:
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);
    void wheelEvent(QWheelEvent *);

signals:

public slots:
     void rotate(int k);
     void TrybDOD();
     void TrybODD();
     void TrybPRZ();

  private:
    int x=0,y=0,r=255,g=255,b=255;
    int pox=0,poy=0;
    QImage im;
    double deg=0;
    int Trybix=0;
    std::vector<point> Punkty;
    int index=0;
    bool nacisniety=false;

    void PutPixel(int x,int y,int r ,int g,int b);
    void drawLineZajecia(float x, float y,float pox, float poy,int r, int g,int b);
    void drawLineAlgorytm(int x,int y,int pox,int poy,int r,int g,int b);
    void drawKolo(int x,int y,int pox,int poy,int r,int g,int b);
    void drawPelneKolo(int x,int y,int pox,int poy,int r,int g,int b);
    void drawElips(int x, int y, int pox, int poy, int r, int g, int b,double deg);
    void drawKrzywaBsklejane(std::vector<point> Punkty,int r ,int g ,int b);
    void drwaKrzywaB(std::vector<point> Punkty,int r, int g, int b);


};

#endif // RYSOWANIE_WIDGET1_H
