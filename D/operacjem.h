#ifndef OPERACJEM_H
#define OPERACJEM_H

#include <QWidget>
#include <QImage>
#include <QFileDialog>
#include <QMouseEvent>
#include <QPainter>


class OperacjeM : public QWidget
{
    Q_OBJECT
public:
    explicit OperacjeM(QWidget *parent = 0);

signals:
protected:
    void paintEvent(QPaintEvent *);
   // void mousePressEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);
   // void mouseMoveEvent(QMouseEvent *);

public slots:
    void erozjaA();
    void delatacjaA();
    void zamkniecieA();
    void otwarcieA();

private:
        int action = 0;
        int width =191;
        int height =171;
        QImage OperationImg;
        QImage KopiaImg;
        QImage MarkerImg;

        void Erozja();
        void Delatacja();
        void Zamkniecie();
        void Otwarcie();

};

#endif // OPERACJEM_H
