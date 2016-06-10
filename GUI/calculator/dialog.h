#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QPushButton>
#include <QFileDialog>
#include <QMessageBox>


namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();
public slots:
    void readSelectClicked();
    void writeSelectCliced();
    void detClicked();

private:
    QLabel *inlabel;
    QLabel *outlabel;
    QLineEdit *inedit;
    QLineEdit *outedit;
    QPushButton *inButton;
    QPushButton *outButton;
    QPushButton *detButton;



    Ui::Dialog *ui;
};

#endif // DIALOG_H
