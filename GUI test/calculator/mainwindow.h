#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets/QPushButton>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QLineEdit>
#include <QMainWindow>
#include <QKeyEvent>
#include <QMouseEvent>
#include <QAction>
#include <QMenuBar>
#include <QMessageBox>
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
    QAction *fileAction;
    QLineEdit *inedit;
    QLineEdit *outedit;
    QLabel *label;
    QLabel *inlabel;
    QLabel *outlabel;
    QPushButton *operationButtons[10];
    QPushButton *buttons[10];
};

#endif // MAINWINDOW_H
