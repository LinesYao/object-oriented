#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets/QPushButton>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTextEdit>
#include <QMainWindow>

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

private:
    //QTextFormat *text;
    QLabel *label;
    QPushButton *operationButtons[10];
    QPushButton *buttons[10];
};

#endif // MAINWINDOW_H
