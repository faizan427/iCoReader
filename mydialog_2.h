#ifndef MYDIALOG_2_H
#define MYDIALOG_2_H

#include <QDialog>

namespace Ui {
class MyDialog_2;
}

class MyDialog_2 : public QDialog
{
    Q_OBJECT

public:
    explicit MyDialog_2(QWidget *parent = nullptr);
    ~MyDialog_2();

private:
    Ui::MyDialog_2 *ui;
};

#endif // MYDIALOG_2_H
