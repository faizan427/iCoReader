#ifndef WINDOW_2_H
#define WINDOW_2_H

#include <QDialog>

namespace Ui {
class window_2;
}

class window_2 : public QDialog
{
    Q_OBJECT

public:
    explicit window_2(QWidget *parent = nullptr);
    ~window_2();

private slots:


private:
    Ui::window_2 *ui;
};

#endif // WINDOW_2_H
