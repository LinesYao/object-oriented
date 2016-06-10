#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtCore/QCoreApplication>
#include <string>


QString value = "";
QString inputExpression = "";
QString operations[10]={"(",")","C","←","÷","×","-","+",".","="};
QString inpath = "";
QString outpath = "";

int numButtonPos[10][2]={10,250,10,200,60,200,110,200,10,150,60,150,110,150,10,100,60,100,110,100};
int operationPos[10][2]={10,50,60,50,110,50,160,50,160,100,160,150,160,200,160,250,60,250,110,250};

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)

{


    label = new QLabel("",this);
    label ->setGeometry(QRect(QPoint(0,0),QSize(200,50)));


    fileButton = new QPushButton("FILE_IN_OUT",this);
    fileButton -> setGeometry (QRect(QPoint(50,310),QSize(120,25)));
    connect(fileButton,SIGNAL(clicked(bool)),this,SLOT(fileDialogClicked()));

    for(int i = 0; i < 10;i++) {
        operationButtons[i] = new QPushButton(operations[i],this);
        operationButtons[i] ->setGeometry(QRect(QPoint(operationPos[i][0],operationPos[i][1]),QSize(45,45)));
        connect(operationButtons[i],SIGNAL(released()),this,SLOT(operationPushed()));

    }

    for(int i = 0; i < 10 ;i++) {
            QString digit = QString::number(i);
            buttons[i] = new QPushButton(digit,this);
            buttons[i] ->setGeometry(QRect(QPoint(numButtonPos[i][0],numButtonPos[i][1]),QSize(45,45)));
            connect(buttons[i],SIGNAL(released()),this,SLOT(buttonPushed()));
    }

}

void MainWindow::fileDialogClicked() {
    fileDialog.show();

}
void MainWindow::operationPushed() {
    QPushButton *button = (QPushButton *)sender();
    if(button -> text()=="C") {
        value = "";
        inputExpression = "";
    }
    if(button -> text()=="←") {
        QString temp = "";
        int len = value.length();
        temp = value.left(len-1);
        value = temp;
        len = inputExpression.length();
        temp = inputExpression.left(len-1);
        inputExpression = temp;
    }
    if(button -> text()=="+"|| button -> text()=="-" || button -> text()=="×" || button -> text()=="÷" ||button -> text()=="(" || button -> text()==")" || button -> text()==".") {

        value+=button ->text();
        if(button -> text()=="×") {
            inputExpression+="*";
        }
        else if(button -> text()=="÷") {
            inputExpression+="/";
        }
        else {
            inputExpression+=button ->text();
        }

    }
    label ->setText(value);
    if(button -> text()=="=") {
        string input = inputExpression.toStdString();
        Scanner scan;
        Calculation cal;
        Printer pr;
        queue<string> q = scan.toStringQueue(input);
        scan.clearQue();
        value = QString::fromStdString(pr.getInfomation(scan.getFlag(), cal.getResult(q)));
        label ->setText(value);
        inputExpression = value = "";
    }

}
void MainWindow::buttonPushed() {
    QPushButton *button = (QPushButton *)sender();
    emit numberEmitted(button->text()[0].digitValue());
    value+=QString::number(button->text()[0].digitValue());
    inputExpression+=QString::number(button->text()[0].digitValue());
    label -> setText(value);

}

void MainWindow::keyPressEvent(QKeyEvent *e)
{


    if(e->key()== Qt::Key_0||e->key()== Qt::Key_1||e->key()== Qt::Key_2||e->key()== Qt::Key_3||e->key()== Qt::Key_4||e->key()== Qt::Key_5||
            e->key()== Qt::Key_6||e->key()== Qt::Key_7||e->key()== Qt::Key_8||e->key()== Qt::Key_9||e->key()==Qt::Key_ParenLeft||e->key()==Qt::Key_ParenRight
            ||e->key()==Qt::Key_Plus||e->key()==Qt::Key_Minus||e->key()==Qt::Key_Asterisk||e->key()==Qt::Key_Slash || e->key() == Qt::Key_Period) {
        if(e->key()==Qt::Key_Asterisk) {
            value+="×";
            inputExpression+="*";
        }
        else if(e->key()==Qt::Key_Slash) {
            value+="÷";
            inputExpression+="/";
        }
        else {
            value+=e -> text();
            inputExpression+=e -> text();
        }

    }


    else if(e->key() == Qt::Key_Backspace) {
        QString temp = "";
        int len = value.length();
        temp = value.left(len-1);
        value = temp;

        len = inputExpression.length();
        temp = inputExpression.left(len-1);
        inputExpression = temp;
    }
    else if(e->key() == Qt::Key_Escape) {
        value = "";
        inputExpression = "";

    }
    label ->setText(value);

    if(e->key() == Qt::Key_Equal) {
        string input = inputExpression.toStdString();
        Scanner scan;
        Calculation cal;
        Printer pr;
        queue<string> q = scan.toStringQueue(input);
        scan.clearQue();
        value = QString::fromStdString(pr.getInfomation(scan.getFlag(), cal.getResult(q)));
        label ->setText(value);
        inputExpression = value = "";
    }

}
MainWindow::~MainWindow()
{

}
