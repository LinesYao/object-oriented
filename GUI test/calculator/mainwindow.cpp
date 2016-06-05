#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtCore/QCoreApplication>

QString value = "";
QString operations[10]={"(",")","C","←","÷","×","-","+",".","="};
int numButtonPos[10][2]={0,250,0,200,50,200,100,200,0,150,50,150,100,150,0,100,50,100,100,100};
int operationPos[10][2]={0,50,50,50,100,50,150,50,150,100,150,150,150,200,150,250,50,250,100,250};

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)

{
    label = new QLabel("0",this);
    label ->setGeometry(QRect(QPoint(0,0),QSize(200,50)));
//    text = new QTextFormat("0",this);
//    text ->setGeometry(QRect(QPoint(0,0),QSize(200,50)));
    for(int i = 0; i < 10;i++) {
        operationButtons[i] = new QPushButton(operations[i],this);
        operationButtons[i] ->setGeometry(QRect(QPoint(operationPos[i][0],operationPos[i][1]),QSize(50,50)));
        connect(operationButtons[i],SIGNAL(released()),this,SLOT(operationPushed()));


    }

    for(int i = 0; i < 10 ;i++) {
            QString digit = QString::number(i);
            buttons[i] = new QPushButton(digit,this);
            buttons[i] ->setGeometry(QRect(QPoint(numButtonPos[i][0],numButtonPos[i][1]),QSize(50,50)));
            connect(buttons[i],SIGNAL(released()),this,SLOT(buttonPushed()));

    }

}
void MainWindow::operationPushed() {
    QPushButton *button = (QPushButton *)sender();
    if(button -> text()=="C") {
        value = "";
        label ->setText("0");
    }
    if(button -> text()=="←") {
        QString temp = "";
        int len = value.length();
        temp = value.left(len-1);
        value = temp;
        label ->setText(value);
    }
    if(button -> text()=="+"|| button -> text()=="-" || button -> text()=="×" || button -> text()=="÷" ||button -> text()=="(" || button -> text()==")" || button -> text()==".") {
        value+=button ->text();
        label ->setText(value);
    }

}
void MainWindow::buttonPushed() {
    QPushButton *button = (QPushButton *)sender();
    emit numberEmitted(button->text()[0].digitValue());
    value+=QString::number(button->text()[0].digitValue());
    label -> setText(value);

}

MainWindow::~MainWindow()
{

}
