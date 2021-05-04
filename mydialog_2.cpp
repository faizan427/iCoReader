#include "mydialog_2.h"
#include "ui_mydialog_2.h"
#include "mydialog.cpp"


MyDialog_2::MyDialog_2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MyDialog_2)
{
    ui->setupUi(this);
   ui->listWidget->addItem(comtrade_file_contents);

}

MyDialog_2::~MyDialog_2()
{
    delete ui;
}
