#include "dialog.h"
#include "ui_dialog.h"
#include <string>
#include <fstream>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    setWindowTitle( tr( "FILE_IN_OUT" ) );
    setFixedSize(300,220);
    inlabel = new QLabel("FILE_IN",this);
    inlabel ->setGeometry(QRect(QPoint(10,30),QSize(50,30)));

    outlabel= new QLabel("FILE_OUT",this);
    outlabel ->setGeometry(QRect(QPoint(10,90),QSize(50,30)));

    inedit = new QLineEdit ("",this);
    inedit ->setGeometry(QRect(QPoint(80,35),QSize(130,20)));

    outedit = new QLineEdit ("",this);
    outedit ->setGeometry(QRect(QPoint(80,95),QSize(130,20)));

    inButton = new QPushButton("read",this);
    inButton -> setGeometry (QRect(QPoint(220,35),QSize(50,20)));
    connect(inButton,SIGNAL(clicked(bool)),this,SLOT(readSelectClicked()));

    outButton = new QPushButton("write",this);
    outButton -> setGeometry (QRect(QPoint(220,95),QSize(50,20)));
    connect(outButton,SIGNAL(clicked(bool)),this,SLOT(writeSelectCliced()));

    sureButton = new QPushButton(tr("确定"),this);
    sureButton -> setGeometry (QRect(QPoint(120,145),QSize(50,25)));
    connect(sureButton,SIGNAL(clicked(bool)),this,SLOT(sureClicked));


}
void Dialog::sureClicked() {
//    ifstream in(argv[2], ios::in);   //为读而打开文件
//    ofstream out(argv[3], ios::out);  //为写而打开文件
//    string s;
//    while (getline(in, s))
//    {
//        input = s;
//        q = sc.toStringQueue(input);  //存放获取的队列
//        sc.clearQue();
//        out << pr.write(sc.getFlag(), cal.getResult(q)) << endl;
//    }
//    in.close();
//    out.close();

}

void Dialog::readSelectClicked() {
    QString file=QFileDialog::getOpenFileName(this,"open file","/","text file(*.txt)");
    inedit -> setText(file);

}
void Dialog::writeSelectCliced() {
    QString filee=QFileDialog::getOpenFileName(this,"open file","/","text file(*.txt)");
    outedit -> setText(filee);

}

Dialog::~Dialog()
{
    delete ui;
}
