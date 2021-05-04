#ifndef MYDIALOG_H
#define MYDIALOG_H
#include "qcustomplot.h"
#include <QDialog>

namespace Ui {
class MyDialog;
}

class MyDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MyDialog(QWidget *parent = nullptr);

    ~MyDialog();

signals:

    void buttonPressed();

public slots:
    void closeEvent(QCloseEvent *e);
    //   void on_pushButton_clicked(QCloseEvent *z);
 int GIF(double no_of_digitals);



private slots:



   // void on_digital_port_valueChanged(int arg2);

    void on_plot_digital_clicked();

    void on_clear_analog_clicked();

    void on_clear_digital_clicked();

    void on_verticalScrollBar_valueChanged(int value);

    void on_horizontalScrollBar_valueChanged(int value);

    void xAxisChanged(QCPRange range);
    void yAxisChanged(QCPRange range);
    void mouseWheel();
    void mousePress();
    void selectionChanged();

    void graphClicked(QCPAbstractPlottable *plottable, int dataIndex);

    void analog_extract(int arg1);
    void extract_digital(int arg2);

    void mouseWheel_2();
    void mousePress_2();
    void on_verticalScrollBar_valueChanged_2(int value);

    void on_horizontalScrollBar_valueChanged_2(int value);

    void xAxisChanged_2(QCPRange range);
    void yAxisChanged_2(QCPRange range);
   QString HexToBin(QByteArray hexdec);








   void on_add_clicked();

   void on_delete_2_clicked();

   void on_plot_clicked();

   void on_delete_3_clicked();

   void on_add_2_clicked();

   void on_plot_2_clicked();

private:
    Ui::MyDialog *ui;
};

#endif // MYDIALOG_H
