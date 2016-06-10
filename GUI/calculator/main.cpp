#include "mainwindow.h"
#include "dialog.h"
#include "Calculation.h"
#include "Printer.h"
#include "Scanner.h"
#include <QApplication>
#include <QDesktopWidget>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.showMaximized();
    w.setFixedSize(220,350);
    w.move(QApplication::desktop()->screen()->rect().center()-w.rect().center());
    w.show();

    return a.exec();
}
