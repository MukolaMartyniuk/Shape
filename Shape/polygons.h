#ifndef POLYGONS_H
#define POLYGONS_H
#include <QtCore>
#include <QtGui>
#include <QGraphicsScene>
#include <QTextEdit>
#include <QGraphicsItem>
#include <QPainter>


class Polygons : public QGraphicsItem
{
    int a, b;
public:
    Polygons();

    Polygons(int a, int b);

    ~Polygons();

    void set_a (int new_a);

    int get_a();

    void set_b (int new_b);

    int get_b();

    void Graphics(QGraphicsScene *scene, QGraphicsRectItem *rectangle,QGraphicsEllipseItem *ellipse);

    void Info1(QTextEdit *TextEdit);

    void Info2(QTextEdit *TextEdit);

    void Info3(QTextEdit *TextEdit);

    double Area();

    double Perimetr();

    double RadiusOP();

    double RadiusVP();

    double Area_Trap();

    double Perimetr_Trap();

    double st_A();

    double st_B_C();

    double st_D();

    double sLine();

    double RadiusOPK_Trap();

    double RadiusVPK_Trap();

    double kut_A_B();

    double kut_C_D();

    QRectF boundingRect() const;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

};

#endif // POLYGONS_H
