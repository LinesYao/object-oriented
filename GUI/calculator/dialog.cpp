#include "dialog.h"
#include "ui_dialog.h"
#include <fstream>
#include <string>
#include "Scanner.h"
QString infile,outfile;
string ipath,opath;
Scanner scan;

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    //this -> setGeometry(QRect(QPoint(10,40),QSize(50,30)));

    setWindowTitle( tr( "FILE_IN_OUT" ) );
    setFixedSize(290,220);
    inlabel = new QLabel("FILE_IN",this);
    inlabel ->setGeometry(QRect(QPoint(10,40),QSize(50,30)));

    outlabel= new QLabel("FILE_OUT",this);
    outlabel ->setGeometry(QRect(QPoint(10,100),QSize(50,30)));

    inedit = new QLineEdit ("",this);
    inedit ->setGeometry(QRect(QPoint(80,45),QSize(130,20)));

    outedit = new QLineEdit ("",this);
    outedit ->setGeometry(QRect(QPoint(80,105),QSize(130,20)));

    inButton = new QPushButton("read",this);
    inButton -> setGeometry (QRect(QPoint(220,45),QSize(50,20)));
    connect(inButton,SIGNAL(clicked(bool)),this,SLOT(readSelectClicked()));

    outButton = new QPushButton("write",this);
    outButton -> setGeometry (QRect(QPoint(220,105),QSize(50,20)));
    connect(outButton,SIGNAL(clicked(bool)),this,SLOT(writeSelectCliced()));



    detButton = new QPushButton("确定",this);
    detButton -> setGeometry (QRect(QPoint(120,150),QSize(50,20)));
    connect(detButton,SIGNAL(clicked(bool)),this,SLOT(detClicked()));


}

void Dialog::detClicked() {
    scan.read(ipath,opath);
    if(infile!="" && outfile!="") {
        QMessageBox::about(NULL, " ", "Finish!");
    }
    infile = "";
    outfile = "";
    inedit -> setText(infile);
    outedit -> setText(outfile);
}

void Dialog::readSelectClicked() {
    infile=QFileDialog::getOpenFileName(this,"open file","/","text file(*.txt)");
    inedit -> setText(infile);
    ipath = infile.toStdString();

}
void Dialog::writeSelectCliced() {

    outfile=QFileDialog::getOpenFileName(this,"open file","/","text file(*.txt)");
    outedit -> setText(outfile);
    opath = outfile.toStdString();

}

Dialog::~Dialog()
{
    delete ui;
}
