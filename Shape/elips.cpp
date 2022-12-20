#include <QtCore>
#include <QtGui>
#include <QGraphicsScene>
#include <QTextEdit>
#include <math.h>
#include "elips.h"
#include "mainwindow.h"
//#define M_PI        3.14159265358979323846


void elips :: set_a (double new_a){
   a =new_a;
}

double elips :: get_a(){
    return a;
}

void elips :: set_b (double new_b){
        b = new_b;
}

double elips :: get_b(){
    return b;
}


// *Коло і Овал*


void elips :: Graphics(QGraphicsScene *scene, QGraphicsEllipseItem *ellipse){
    double a1 = a*37.938105;
    double b1 = b*37.938105;
    QPen whitePen(Qt :: white);
    whitePen.setWidth(2);
    whitePen.setStyle(Qt :: DashLine);
    QBrush greenBrush(Qt :: green);
    QPen white1Pen(Qt :: white);
    white1Pen.setWidth(4);
    ellipse = scene->addEllipse(a1/2*(-1), b1/2*(-1), a1, b1, white1Pen, greenBrush);
    ellipse = scene->addEllipse(a1/2*(-1), a1/2*(-1), a1, a1, whitePen);
    ellipse = scene->addEllipse(b1/2*(-1), b1/2*(-1), b1, b1, whitePen);
    scene->addLine(0,0,a1/2,0,QPen(Qt::red));
    scene->addLine(0,0,0,b1/2,QPen(Qt::red));
}


void elips :: Info1(QTextEdit *TextEdit){
    QString s = "";
    s += "Коло — це сукупність усіх точок на площині, які знаходяться на однаковій відстані від заданої точки О, яка називається центром кола.";
    TextEdit->append(s);
}

void elips :: Info2(QTextEdit *TextEdit){
    QString s = "";
    s += "Овал — це замкнена плоска крива, сума відстаней від кожної точки якої до двох фіксованих точок F1 і F2 дорівнює сталій величині. Точки F1 і F2 називають фокусами еліпса.";
    TextEdit->append(s);
}

double elips :: Diametr(){
    return 2*a;
}

double elips :: Area(){
    return M_PI*pow(a,2);
}

double elips :: Length(){
    return 2*M_PI*a;
}

double elips :: AreaE(){
    return M_PI*a*b;
}

double elips :: PerimetrE(){
    return 4*(M_PI*a*b+pow((a-b),2))/a+b;
}

double elips :: RadiusOPK(){
    return a;
}

double elips :: RadiusVPK(){
    return b;
}

elips::elips()
{

}

elips::elips(double a)
{
    this->a = a;
}

elips::~elips()
{

}
