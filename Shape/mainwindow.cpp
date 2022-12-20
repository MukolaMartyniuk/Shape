#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtCore>
#include <QtGui>
#include <QGraphicsScene>
#include <QTextEdit>
#include "polygons.h"
#include "elips.h"
#include <QMessageBox>
#include <math.h>
#include "triangle.h"
#include <QFileDialog>
#include <fstream>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = new QGraphicsScene(this);
    triangle = new Triangle;
    polygons = new Polygons;
    ui->graphicsView->setScene(scene);

    scene->addLine(-250,0,250,0,QPen(Qt::white));
    scene->addLine(0,-250,0,250,QPen(Qt::white));

    ui->graphicsView->setRenderHint(QPainter :: Antialiasing);

    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButton_clicked()
{
    ui->comboBox_2->clear();
    QString a = ui->comboBox->currentText();
    if (a == "Трикутник"){
        ui->comboBox_2->addItem("Рівнобедрений");
        ui->comboBox_2->addItem("Прямокутний");
    }

    if (a == "Чотирикутник"){
        ui->comboBox_2->addItem("Квадрат");
        ui->comboBox_2->addItem("Прямокутник");
        ui->comboBox_2->addItem("Трапеція");
    }

    if (a == "Еліпс"){
        ui->comboBox_2->addItem("Коло");
        ui->comboBox_2->addItem("Овал");
    }

}

void MainWindow::on_pushButton_2_clicked()
{
    try {

    ui->textEdit->clear();

    ui->graphicsView->items().clear();
    scene->addLine(-250,0,250,0,QPen(Qt::white));
    scene->addLine(0,-250,0,250,QPen(Qt::white));
    Polygons polygons1;
    elips ellipse1;
    Triangle triangle1;
    a = ui->lineEdit->text().toInt();
    b = ui->lineEdit_2->text().toInt();
    QString l = "";


    QString s = ui->comboBox->currentText();
    k = ui->comboBox_2->currentText();
    if (k == "") throw "Виберіть підтип фігури";
    if (a == 0 || b == 0) throw "Виберіть розмір фігури";
    if (s == "Чотирикутник"){
    polygons->set_a(a);
    polygons->set_b(b);
        if (k == "Квадрат"){
            polygons->Info1(ui->textEdit);
            polygons->Graphics( scene, rectangle, ellipse);
            l += "Усі кути рівні і мають по 90 градусів";
            l += "\n";
            l += "Радіус описаного кола: " + QString :: number(polygons->RadiusOP(),'g',2)+" см";
            l += "\n";
            l += "Радіус вписаного кола: " + QString :: number(polygons->RadiusVP(),'g',2)+" см";
            l += "\n";
            l += "Довжина середньої лінії: " + QString :: number(a)+" см";
            l += "\n";
            l += "Площа фігури: " + QString :: number(polygons->Area(),'g',2)+" см^2";
            l += "\n";
            l += "Периметр фігури: " + QString :: number(polygons->Perimetr(),'g',2)+" см";
            l += "\n";
            l += "Розмір сторони А: " + QString :: number(a)+" см";
            l += "\n";
            l += "Розмір сторони B: " + QString :: number(b)+" см";
            l += "\n";
        }

        if (k == "Прямокутник"){
            polygons->Info2(ui->textEdit);
            polygons->Graphics( scene, rectangle, ellipse);
            l += "Усі кути рівні і мають по 90 градусів";
            l += "\n";
            l += "Радіус описаного кола: " + QString :: number(polygons->RadiusOP(),'g',2)+" см";
            l += "\n";
            l += "Радіус вписаного кола: " + QString :: number(polygons->RadiusVP(),'g',2)+" см";
            l += "\n";
            l += "Довжина середньої лінії: " + QString :: number(a)+" см";
            l += "\n";
            l += "Площа фігури: " + QString :: number(polygons->Area(),'g',2)+" см^2";
            l += "\n";
            l += "Периметр фігури: " + QString :: number(polygons->Perimetr(),'g',2)+" см";
            l += "\n";
            l += "Розмір сторони А: " + QString :: number(a)+" см";
            l += "\n";
            l += "Розмір сторони B: " + QString :: number(b)+" см";
            l += "\n";
        }

        if (k == "Трапеція"){
            polygons1.Info3(ui->textEdit);
            scene->addItem(polygons);
            polygons->setPos(0,0);
            l += "Кути: "+QString :: number(polygons->kut_A_B(),'g',2)+", "+QString :: number(polygons->kut_C_D(),'g',2);
            l += "\n";
            l += "Радіус описаного кола: " + QString :: number(polygons->RadiusOPK_Trap(),'g',2)+" см";
            l += "\n";
            l += "Радіус вписаного кола: " + QString :: number(polygons->RadiusVPK_Trap(),'g',2)+" см";
            l += "\n";
            l += "Довжина середньої лінії: " + QString :: number(polygons->sLine())+" см";
            l += "\n";
            l += "Площа фігури: " + QString :: number(polygons->Area_Trap(),'g',2)+" см^2";
            l += "\n";
            l += "Периметр фігури: " + QString :: number(polygons->Perimetr_Trap(),'g',2)+" см";
            l += "\n";
            l += "Розмір сторони А: " + QString :: number(polygons->st_A())+" см";
            l += "\n";
            l += "Розмір сторони B i C: " + QString :: number(polygons->st_B_C())+" см";
            l += "\n";
            l += "Розмір сторони D: " + QString :: number(polygons->st_D())+" см";
            l += "\n";
        }
    ui->textEdit->append(l);
    }

    if (s == "Еліпс"){
        ellipse1.set_a(a);
        ellipse1.set_b(b);
        ellipse1.Graphics(scene, ellipse);
        if (k == "Коло"){
            ellipse1.Info1(ui->textEdit);
            l += "Довжина кола: " + QString :: number(ellipse1.Length(),'g',2) +" см";
            l += "\n";
            l += "Площа кола: " + QString :: number(ellipse1.Area(),'g',2) +" см^2";
            l += "\n";
            l += "Діаметр кола: " + QString :: number(ellipse1.Diametr(),'g',2) + " см";
            l += "\n";
            l += "Радіус кола: "+ QString :: number(ellipse1.get_a()) + " см";
        }
        if (k == "Овал"){
            ellipse1.Info2(ui->textEdit);
            l += "Площа еліпса: " + QString :: number(ellipse1.AreaE(),'g',2) +" см";
            l += "\n";
            l += "Периметр еліпса: ~" + QString :: number(ellipse1.PerimetrE(),'g',2) +" см^2";
            l += "\n";
            l += "Радіус описаного кола: " + QString :: number(ellipse1.RadiusOPK(),'g',2) + " см";
            l += "\n";
            l += "Радіус вписаного кола: "+ QString :: number(ellipse1.RadiusVPK(), 'g',2) + " см";
        }
    ui->textEdit->append(l);
    }

    if (s == "Трикутник"){
        triangle->set_a(a);
        triangle->set_b(b);
        triangle->set_k(k);
        scene->addItem(triangle);
        triangle->setPos(0,0);
        if (k == "Рівнобедрений"){
            triangle->Info1(ui->textEdit);
            l += "Радіус описаного кола: " + QString :: number(triangle->RadiusOPK(),'g',2)+" см";
            l += "\n";
            l += "Радіус вписаного кола: " + QString :: number(triangle->RadiusVPK(),'g',2)+" см";
            l += "\n";
            l += "Довжина середньої лінії: " + QString :: number(triangle->sLine(),'g',2)+" см";
            l += "\n";
            l += "Площа фігури: " + QString :: number(triangle->Area(),'g',2)+" см^2";
            l += "\n";
            l += "Периметр фігури: " + QString :: number(triangle->Perimetr(),'g',2)+" см";
            l += "\n";
            l += "Кути: "+QString :: number(triangle->kut_R1(),'g',2)+", "+QString :: number(triangle->kut_R1(),'g',2)+", "+QString :: number(triangle->kut_R2(),'g',2);
            l += "\n";
            l += "Розмір сторони А i B: " + QString :: number(triangle->A_and_B(),'g',2)+" см";
            l += "\n";
            l += "Розмір сторони C: " + QString :: number(triangle->st_C(),'g',2)+" см";
        }
        if (k == "Прямокутний"){
            triangle->Info2(ui->textEdit);
            l += "Радіус описаного кола: " + QString :: number(triangle->RadiusOPK_pr(),'g',2)+" см";
            l += "\n";
            l += "Радіус вписаного кола: " + QString :: number(triangle->RadiusVPK_pr(),'g',2)+" см";
            l += "\n";
            l += "Довжина середньої лінії: " + QString :: number(triangle->sLine(),'g',2)+" см";
            l += "\n";
            l += "Площа фігури: " + QString :: number(triangle->Area(),'g',2)+" см^2";
            l += "\n";
            l += "Периметр фігури: 90, " + QString :: number(triangle->kut_P1(),'g',2)+", "+QString :: number(triangle->kut_P2(),'g',2);
            l += "\n";
            l += "Кути: " + QString :: number(triangle->Perimetr(),'g',2)+" см";
            l += "\n";
            l += "Розмір сторони А: " + QString :: number(triangle->A_and_B(),'g',2)+" см";
            l += "\n";
            l += "Розмір сторони C: " + QString :: number(triangle->st_B(),'g',2)+" см";
            l += "\n";
            l += "Розмір сторони B: " + QString :: number(triangle->st_C(),'g',2)+" см";

        }
        ui->textEdit->append(l);
    }

    }catch (char const *s) {

            QMessageBox msgBox;
            msgBox.setText(s);
            msgBox.exec();

    }


}

void MainWindow::on_pushButton_3_clicked()
{
    QString fileName = QFileDialog :: getOpenFileName(this, tr("Вибрати файл"), tr("(*.txt);; Всі файли(*)"));
    QByteArray ba=fileName.toLatin1();
    /*if (fileName.isEmpty())
        return;
    else{
        QFile file(fileName);
        file.open(QIODevice::ReadOnly);
    QDataStream in(&file);*/
    try {
        std :: ifstream in(ba.data());
        in >> a >> b;
        ui->lineEdit->setText(QString ::number(a));
        ui->lineEdit_2->setText(QString ::number(b));
    } catch (...) {
        QMessageBox msgBox;
        msgBox.setText("Немає такого файлу");
        msgBox.exec();
    }


   // }
}

void MainWindow::on_pushButton_4_clicked()
{
   scene->clear();
   scene = new QGraphicsScene(this);
   triangle = new Triangle;
   polygons = new Polygons;
   ui->graphicsView->setScene(scene);
}
