#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>


#include <QTreeWidget>
#include "qcustomplot.h"
#include "mydialog.h"
#include "mydialog_2.h"


using namespace std;
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

       void addTreeChild(QTreeWidgetItem *parent,
                         QString name);


public slots:
 int GIF(double no_of_digitals);
    void parse_comtrade_file();

    void open_comtrade_file();
    void on_view_parameters_clicked();
  void enable_button();
void on_tableWidget_clicked(const QModelIndex &index);

private slots:



    //void on_port_valueChanged(int arg1);

    //void on_port_2_valueChanged(int arg2);

    //void on_pushButton_clicked();

    //void on_pushButton_2_clicked();


   // void on_pushButton_3_clicked();





    void open_dat_file();
   // void on_plot_digital_2_clicked();



    void on_import_2_clicked();


  //  void on_pushButton_2_clicked();




void on_btnBrowse_clicked();
void NotifyChanges(const QString &path);

int converter(QString all);
void make_break(QStringList n,  QStringList z);


void item_tree(QString root_name_1, QString root_name_2);
void on_view_cfg_file_clicked();



void on_reset_all_clicked();

private:
    Ui::MainWindow *ui;


MyDialog *new_one;

MyDialog *set_enable;

QFileSystemWatcher *watcher;


MyDialog_2 *new_one_2;


};





#endif // MAINWINDOW_H
