#include "window_2.h"
#include "ui_window_2.h"




window_2::window_2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::window_2)
{
    ui->setupUi(this);

   }

window_2::~window_2()
{

    delete ui;
}

