#include "triangle.h"
#include <QTextEdit>
#include <math.h>
#include <QGraphicsScene>

Triangle::Triangle() : QGraphicsItem()
{

}

Triangle::Triangle(int a, int b)  : QGraphicsItem()
{
    this->a = a;
    this->b = b;
}

Triangle ::~Triangle()
{

}

void Triangle :: set_a (int new_a){
   a =new_a;
}

int Triangle :: get_a(){
    return a;
}

void Triangle :: set_k (QString new_k){
   k = new_k;
}

QString Triangle :: get_k(){
    return k;
}

void Triangle :: set_b (int new_b){
        b = new_b;
}

int Triangle :: get_b(){
    return b;
}


// *Трикутник*


QRectF Triangle :: boundingRect() const
{
    int b1 = b/2*(-1);
    int a1 = a/2*(-1);
    //return QRectF(-25, -40, 50, 80);
    return QRectF(a1*37.938105, b1*37.938105, a*37.938105, b*37.938105);
}

void Triangle :: paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPolygon polygon;
    int b1 = b/2*(-1)*37.938105;
    int a2 = a/2*37.938105;
    int b2 = b/2*37.938105;
    int a1 = a/2*(-1)*37.938105;
   // polygon << QPoint(0,-40) << QPoint(25, 40) << QPoint(-25, 40);
    if (k == "Рівнобедрений")
        polygon << QPoint(0,b1) << QPoint(a2, b2) << QPoint(a1, b2);
    if (k == "Прямокутний")
        polygon << QPoint(a1,b1) << QPoint(a2, b2) << QPoint(a1, b2);
    painter->setBrush(Qt :: red);
    painter->drawPolygon(polygon);
    Q_UNUSED(option)
    Q_UNUSED(widget)

}

void Triangle :: Info1(QTextEdit *TextEdit){
    QString s = "";
    s += "Рівнобедрений трикутник — трикутник, в якому дві сторони рівні між собою.";
    TextEdit->append(s);
}

void Triangle :: Info2(QTextEdit *TextEdit){
    QString s = "";
    s += "Прямокутний трикутник — трикутник, один із кутів якого прямий.";
    TextEdit->append(s);
}

double Triangle :: A_and_B(){
    double a1 = a ;
    double b1 = b ;
    return sqrt(pow(a1,2)+pow(b1,2));
}

double Triangle :: st_C(){
    return b ;

}

double Triangle :: st_B(){
    return a ;
}

double Triangle :: Perimetr(){
    double a1 = a ;
    double b1 = b ;
    double c1 = sqrt(pow(a1,2)+pow(b1,2));
    return a1+c1+c1;
}

double Triangle :: Area(){
    double a1 = a ;
    double b1 = b ;
    return a1*b1/2;
}

double Triangle :: RadiusOPK(){
    double a1 = a ;
    double b1 = b ;
    double c1 = sqrt(pow(a1,2)+pow(b1,2));
    double s = a1*b1/2;
    return  a1*b1*c1/4*s;
}

double Triangle :: RadiusVPK(){
    double a1 = a ;
    double b1 = b ;
    return b1*a1/b1+sqrt(4*pow(a1,2)+pow(b1,2));
}

double Triangle :: RadiusOPK_pr(){
    double a1 = a ;
    double b1 = b ;
    double c1 = sqrt(pow(a1,2)+pow(b1,2));
    return  c1/2;
}

double Triangle :: RadiusVPK_pr(){
    double a1 = a ;
    double b1 = b ;
    double c1 = sqrt(pow(a1,2)+pow(b1,2));
    double s = a1*b1/2;
    double p = (a1+b1+c1)/2;
    return s/p;
}

double Triangle ::sLine(){
    return (b)/2;
}

double Triangle :: kut_P1(){
    double a1 = a ;
    double b1 = b ;
    double c1 = sqrt(pow(a1,2)+pow(b1,2));
    return sin(a1/c1);
}

double Triangle :: kut_P2(){
    double a1 = a ;
    double b1 = b ;
    double c1 = sqrt(pow(a1,2)+pow(b1,2));
    return 90 - sin(a1/c1);
}

double Triangle :: kut_R1(){
    double a1 = a/2 ;
    double b1 = b ;
    double c1 = sqrt(pow(a1,2)+pow(b1,2));
    return sin(a1/c1);
}

double Triangle :: kut_R2(){
    double a1 = a/2 ;
    double b1 = b ;
    double c1 = sqrt(pow(a1,2)+pow(b1,2));
    return 180 - 2*sin(a1/c1);
}
