#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets/QPushButton>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTextEdit>
#include <QMainWindow>
#include <QKeyEvent>

#include "Calculationer.h"
#include "Printer.h"
#include "Scanner.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
signals:
    void numberEmitted(int number);

private slots:
    void buttonPushed();
    void operationPushed();
    void keyPressEvent(QKeyEvent *e);

private:
    //QTextFormat *text;
    QLabel *label;
    QPushButton *operationButtons[10];
    QPushButton *buttons[10];
};

#endif // MAINWINDOW_H
