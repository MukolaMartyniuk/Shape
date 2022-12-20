#include "polygons.h"
#include <QtCore>
#include <QtGui>
#include <QGraphicsScene>
#include <QTextEdit>
#include <math.h>

void Polygons :: set_a (int new_a){
   a =new_a;
}

int Polygons :: get_a(){
    return a;
}

void Polygons :: set_b (int new_b){
        b = new_b;
}

int Polygons :: get_b(){
    return b;
}


// *  Квадрат і Прямокутник *

void Polygons :: Graphics(QGraphicsScene *scene, QGraphicsRectItem *rectangle, QGraphicsEllipseItem *ellipse){
    double a1 = a*37.938105;
    double b1 = b*37.938105;
    double q = (sqrt(pow(a,2)+pow(b,2)))*37.938105;
    QPen whitePen(Qt :: white);
    whitePen.setWidth(2);
    whitePen.setStyle(Qt::DashLine);
    QBrush blueBrush(Qt :: blue);
    QPen white1Pen(Qt :: white);
    white1Pen.setWidth(4);
    rectangle = scene->addRect(a1/2*(-1), b1/2*(-1), a1, b1, white1Pen, blueBrush);
    ellipse = scene->addEllipse(q/2*(-1), q/2*(-1), q, q, whitePen);
    scene->addLine(0,0,q/2,0,QPen(Qt::red));
    if (a < b){
        ellipse = scene->addEllipse(a1/2*(-1), a1/2*(-1), a1, a1, whitePen);
        scene->addLine(0,0,0,a1/2,QPen(Qt::red));
    }
    if (a > b){
        ellipse = scene->addEllipse(b1/2*(-1), b1/2*(-1), b1, b1, whitePen);
        scene->addLine(0,0,0,b1/2,QPen(Qt::red));
    }
    if (a == b){
        ellipse = scene->addEllipse(a1/2*(-1), b1/2*(-1), a1, b1, whitePen);
        scene->addLine(0,0,0,a1/2,QPen(Qt::red));
    }
}

void Polygons :: Info1 (QTextEdit *TextEdit){
    QString s = "";
    s += "Квадрат - це чотирикутник, у якого всі сторони рівні і всі кути прямі.";
    TextEdit->append(s);

};

void Polygons :: Info2 (QTextEdit *TextEdit){
    QString s = "";
    s += "Прямокутник - це чотирикутник, усі кути якого прямі.";
    TextEdit->append(s);

};

void Polygons :: Info3 (QTextEdit *TextEdit){
    QString s = "";
    s += "Трапеція — це чотирикутник, дві протилежні сторони якого паралельні, а інші дві сторони — не паралельні.";
    TextEdit->append(s);

};

double Polygons :: Area(){
    return a*b;
}

double Polygons :: Perimetr(){
    return (a+b)*2;
}

double Polygons :: RadiusOP(){
    return (sqrt(pow(a,2)+pow(b,2)))/2;
}

double Polygons :: RadiusVP(){
    return a/2;
}

QRectF Polygons :: boundingRect() const
{
    int a2 = a *37.938105;
    int b2 = b *37.938105;
    int b1 = (b/2*(-1));
    int a1 = (a/2*(-1));
    return QRectF(a1, b1, a, b);
}

void Polygons :: paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPolygon polygon;
    int a5 = a *37.938105;
    int b5 = b *37.938105;
    int a3 = a5/4*(-1);
    int a4 = (a5/4);
    int b1 = b5/2*(-1);
    int a2 = (a5/2);
    int b2 = (b5/2);
    int a1 = a5/2*(-1);
   // polygon << QPoint(0,-40) << QPoint(25, 40) << QPoint(-25, 40);
        polygon << QPoint(a3,b1) << QPoint(a4, b1) << QPoint(a2, b2) << QPoint(a1,b2);
    painter->setBrush(Qt :: blue);
    painter->drawPolygon(polygon);
    Q_UNUSED(option)
    Q_UNUSED(widget)
}

double Polygons :: Area_Trap(){
    double a1 = (a )/2;
    double b1 = a;
    return ((a1+b1)/2)*b;
}

double Polygons :: Perimetr_Trap(){
    double a1 = (a)/2;
    double b1 = a;
    double c1 = sqrt(pow(b,2)+pow(a1/2,2));
    return a1+b1+c1+c1;
}

double Polygons :: st_A(){
    return (a)/2;
}

double Polygons :: st_B_C(){
    double a1 = (a)/2;
    return sqrt(pow(b,2)+pow(a1/2,2));
}

double Polygons :: st_D(){
    return a;
}

double Polygons :: sLine(){
    double a1 = (a)/2;
    double b1 = a;
    return (a1+b1)/2;
}

double Polygons :: RadiusOPK_Trap(){
    double a1 = (a)/2;
    double b1 = a;
    double c1 = sqrt(pow(b1,2)+pow(a1/2,2));
    double p = (a1+b1+c1)/2;
    return (a1*b1*c1)/4*sqrt(p*(p-a1)*(p-b1)*(p-c1));
}

double Polygons :: RadiusVPK_Trap(){
    return (b)/2;
}

double Polygons :: kut_A_B(){
    double a1 = (a)/4;
    double b1 = b ;
    double c1 = sqrt(pow(a1,2)+pow(b1,2));
    return sin(a1/c1);
}

double Polygons :: kut_C_D(){
    double a1 = (a)/4;
    double b1 = b;
    double c1 = sqrt(pow(a1,2)+pow(b1,2));
    return (90- sin(a1/c1))+90;
}

Polygons::Polygons() : QGraphicsItem(){

}

Polygons::Polygons(int a, int b) : QGraphicsItem(){
    this->a = a;
    this->b =b;
}

 Polygons :: ~Polygons(){

}
