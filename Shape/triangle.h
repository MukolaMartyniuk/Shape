#ifndef TRIANGLE_H
#define TRIANGLE_H

#include<QGraphicsItem>
#include<QPainter>
#include <QTextEdit>
#include <QComboBox>

class Triangle : public QGraphicsItem
{
    int a, b;
    QString k;
   // double a1 = a*37.938105;
   // double b1 = b*37.938105;
public:
    Triangle();

    Triangle(int a, int b);

    ~Triangle();

    void set_a (int new_a);

    int get_a();

    void set_b (int new_b);

    int get_b();

    void set_k (QString new_k);

    QString get_k();

    QRectF boundingRect() const;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    void Info1(QTextEdit *TextEdit);

    void Info2(QTextEdit *TextEdit);

    double A_and_B();

    double st_C();

    double st_B();

    double Perimetr();

    double Area();

    double RadiusOPK();

    double RadiusVPK();

    double RadiusOPK_pr();

    double RadiusVPK_pr();

    double sLine();

    double kut_R1();

    double kut_R2();

    double kut_P1();

    double kut_P2();

};



#endif // TRIANGLE_H
