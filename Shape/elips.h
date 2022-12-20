#ifndef ELIPS_H
#define ELIPS_H
#include <QtCore>
#include <QtGui>
#include <QGraphicsScene>
#include <QTextEdit>
#include <math.h>


class elips{
    double a, b;
public:
    elips();

    elips(double a);

    ~elips();

    void set_a (double new_a);

    double get_a();

    void set_b (double new_b);

    double get_b();

    void Graphics(QGraphicsScene *scene, QGraphicsEllipseItem *ellipse);

    void Info1(QTextEdit *TextEdit);

    void Info2(QTextEdit *TextEdit);

    double Diametr();

    double Area();

    double Length();

    double AreaE();

    double PerimetrE();

    double RadiusOPK();

    double RadiusVPK();
};

#endif // ELIPS_H
