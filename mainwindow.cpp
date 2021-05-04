#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <cstdlib> // for exit function
#include<QFile>
#include<QDataStream>
#include <QtCore>
#include <QtGui>
#include <QApplication>
#include <QDir>
#include <QFileInfo>
#include <QDialog>
#include <QDir>
#include <QFileInfo>
#include <QDebug>
#include <QFileDialog>
#include <QFileSystemWatcher>
#include <QtAlgorithms>
#include <iomanip>
#include <stdio.h>
#include <QFileSystemWatcher>


#define  MAX_LEN  80
void analog_extract(int arg1);
void extract_digital(int arg2);
using std::cerr;
using std::cout;
using std::endl;

using std::ifstream;
using namespace std;
 bool valid= true;
 int  no_of_analogs ,  no_of_digitals;
QString HexToFloat(QByteArray z);
QString HexToBin(QByteArray hexdec);
QString comtrade_file_contents, dat_file_name, Path, file_name, cont_,samp_1, event_trig_1,station_name, pmu_id;
double sample_number,n_rate, data_chunk_size, actual_digitals, sample_freq;
QStringList pass_strn_1,pass_strn_2;
  //bool valid = true;
  void open_comtrade_file();
void parse_comtrade_file();
void cfg_file_construction();

 QString raw_data,k, chunk,num_3,num_6, st, num_5, num ,rev,p,o;
 int  digitalval;
double one , two;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)

{
    ui->setupUi(this);


 qDebug() << Path << "i am in mains";






//open_dat_file();




}






void MainWindow::addTreeChild(QTreeWidgetItem *parent,QString name)
{

    QTreeWidgetItem *treeItem_1 = new QTreeWidgetItem();


    treeItem_1->setText(0, name);



    parent->addChild(treeItem_1);
}


QString HexToFloat(QByteArray z){
    //qDebug<<"z";
    bool ok=true;
       int sign = 1;
       //qDebug()<<"lala"<<z.length();
       z = QByteArray::number(z.toLongLong(&ok,16),2);
       if(z.length()==32) {
           //qDebug()<<z.length();
           if(z.at(0)=='1')  sign =-1;                       // if bit 0 is 1 number is negative
           z.remove(0,1);                                     // remove sign bit
       }
       QByteArray fraction =z.right(23);   //get the fractional part
       //qDebug()<< fraction;
       double mantissa = 0;
       for(int i=0;i<fraction.length();i++)     // iterate through the array to calculate the fraction as a decimal.
           if(fraction.at(i)=='1')     mantissa += 1.0/(pow(2,i+1));

       int exponent = z.left(z.length()-23).toLongLong(&ok,2)-127;     //calculate the exponent
       //qDebug()<<mantissa<<",  "<<exponent;
        QString st=QString::number( sign*pow(2,exponent)*(mantissa+1.0),'f', 18);
           //qDebug()<<"lala"<<st;
           return st;
}




MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::open_dat_file() {


    qDebug() << "i am in open dat file";
      QFile dat_file(dat_file_name);
            if (!dat_file.open(QIODevice::ReadOnly ))
            { qDebug() << "dat file not opened ";}


                QByteArray line = dat_file.readAll();
                 raw_data = line.toHex();
                // k.append(z);
               //  qDebug() << "2nd";

                // z =0;


            //i++;

    dat_file.close();


}




void MainWindow::parse_comtrade_file(){  QString word = "";
   QString separate_words;

  int j= 1;
   for(auto x : comtrade_file_contents) {
   if (x == ',' || x== '\n'){




// i can obtain separate words at this line------------------------------------

           if (j==5){ qDebug() << word;

              //   ui->plainTextEdit->insertPlainText(word1+"\n");
           separate_words    = word.mid(0,word.length()-1);

           no_of_analogs = separate_words.toInt(&valid,10);
               qDebug() << separate_words << no_of_analogs <<word.length();
               word ="";

           }else{}
           if (j==6){ qDebug() << word;


                       separate_words    =  word.mid(0,word.length()-1);

                     no_of_digitals =  separate_words.toInt(&valid,10);
                          qDebug() <<separate_words << no_of_digitals <<word.length();
                           word ="";

                       }else{}
          int z = (((no_of_analogs*13)+(no_of_digitals*5))+8);

           if (j== z){ qDebug()  << word;


                          n_rate = word.toInt(&valid,10);
                                       qDebug() << word << n_rate;
                                       word ="";

                                   }else{}


           int zx = (((no_of_analogs*13)+(no_of_digitals*5))+9);

            if (j== zx){ qDebug()  << word;


                           sample_freq = word.toInt(&valid,10);
                                        qDebug() << word << sample_freq <<" iam sample freq" << 1/sample_freq;
                                        word ="";

                                    }else{}






           int zl = (((no_of_analogs*13)+(no_of_digitals*5))+11);

           if (j== zl){ qDebug()  << word;



                                       qDebug() << word << "see";
                                       word ="";

                                   }else{}


           int qe = (((no_of_analogs*13)+(no_of_digitals*5))+10);

           if (j== qe){ qDebug()  << word;


                     sample_number = word.toInt(&valid,10);
                                       qDebug() << word << "i am theoritical sample number" <<sample_number;
                                       word ="";

                                   }else{}




    j++;word ="";}else {
       word =word +x ;

   }}
                                      qDebug() << "i am analog"<< no_of_analogs << "i am digtal" << no_of_digitals;

                                                                           actual_digitals = GIF(no_of_digitals);
                                                                           data_chunk_size = 16+(((no_of_analogs)*8)+(actual_digitals)*(4));
                                                                        qDebug() << raw_data.length()/data_chunk_size << raw_data.length() << data_chunk_size;

                                                                        qDebug() << floor(((raw_data.length())/(data_chunk_size))) << "i am timbdi";

if (sample_number!= raw_data.length()/data_chunk_size){

QMessageBox::warning(this,"Match Error", "Data does not match with .cfg file ");
}



                                      }



void MainWindow::open_comtrade_file(){



QString comtrade_file_name = Path.append("/"+file_name);
qDebug() << comtrade_file_name <<"comtrade_file_name";
QString kk;
        kk = comtrade_file_name.mid(0,comtrade_file_name.length()-3);
        dat_file_name = kk.append("dat");
        qDebug() << dat_file_name;

QFile comtrade_file_cfg(comtrade_file_name);


if(!comtrade_file_cfg.open(QFile::ReadOnly | QFile::Text)){

    QMessageBox::warning(this, "Alert !","File Not Opened"); }

QTextStream in(&comtrade_file_cfg);
 comtrade_file_contents = in.readAll();






 comtrade_file_cfg.close();
Path.remove("/"+file_name);


 open_dat_file();





}



void MainWindow::on_import_2_clicked()
{  if(file_name.size() != 0){
    open_comtrade_file();
   parse_comtrade_file();

   ui->treeWidget->setColumnCount(1);


     item_tree("Analogs", "Digitals");
ui->import_2->setEnabled(false);}
}



void MainWindow::on_view_parameters_clicked()
{

   qDebug() << "view para";
new_one = new MyDialog(NULL);
ui->view_parameters->setEnabled(false);

QObject::connect(new_one, SIGNAL(buttonPressed()), this, SLOT(enable_button()));
new_one->setWindowFlags( Qt::WindowMinimizeButtonHint | Qt::WindowMaximizeButtonHint | Qt::WindowCloseButtonHint);
new_one->show();



}



void MainWindow::enable_button()
{
    ui->view_parameters->setEnabled(true);
     delete new_one;

}



void MainWindow::on_btnBrowse_clicked()
{
    QCollator collator;
    collator.setNumericMode(true);

    Path = QFileDialog::getExistingDirectory(this, tr("open Directory"), ".", QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
    ui->txtPath->setText(Path);

    watcher = new QFileSystemWatcher (this);
    watcher ->addPath(Path);

    disconnect(watcher, SIGNAL(directoryChanged(QString)), this, SLOT(NotifyChanges(QString)));
    QDir dir(Path) ;


 //  dir.setFilter( QDir::Files |QDir::NoDotAndDotDot);

    dir.setNameFilters(QStringList() << "*.cfg");
QString m,all ="";
QStringList z;
        QStringList n;
    QFileInfoList list = dir.entryInfoList();
QByteArray d;

    for (int i =0 ; i < list.size(); ++i)
    {

 QTableWidgetItem *itemName =new QTableWidgetItem();
         itemName->setTextColor(QColor(16,15,150));
         itemName->setBackgroundColor(Qt::yellow);
         int insertRow = ui->tableWidget->rowCount();
         ui->tableWidget->insertRow(insertRow);

                 itemName->setText(list.at(i).fileName());
                 all = list.at(i).fileName();

                 qDebug () <<all << " i am the all in current list";
                 z.append(all);
                 z.join(",");

                 ui->tableWidget->setItem(insertRow, 0, itemName);






  m = QString::number(converter(all));
        n.append(m);



    }qDebug() << z << " individuL FILE NAME \n" << n << "BEFORE removing duplicates \n" ;

n.removeDuplicates();
std::sort(n.begin(),n.end(), collator);
std::reverse(n.begin(), n.end());
//qDebug() << n << "after removinf duplicates \n";

make_break(n,z);



    connect(watcher, SIGNAL(directoryChanged(QString)), this, SLOT(NotifyChanges(QString)));



    connect(watcher, SIGNAL(fileChanged(QString)), this, SLOT(NotifyChanges(QString)));




}



void MainWindow::NotifyChanges(const QString &path)
{       QCollator collator;
    collator.setNumericMode(true);

    QString m, all ="";
    QStringList z ,n,o;
    QStringList oldList, newList;

    for (int i = 0; i < ui->tableWidget->rowCount(); i++){
        QTableWidgetItem *item = ui->tableWidget->item(i,0);
        oldList << item->text();


        m = QString::number(converter(item->text()));
              o.append(m);

    }       o.removeDuplicates();
    qSort(oldList);

QDir dir(path);



  dir.setNameFilters(QStringList() << "*.cfg");



QFileInfoList list = dir.entryInfoList();

for (int i =0 ; i < list.size(); ++i)
{
    newList << list.at(i).fileName();
           all =list.at(i).fileName();

           m = QString::number(converter(all));
                 n.append(m);
     }   n.removeDuplicates();

qSort(newList);

QSet <QString> intersection;
if(oldList.count() > newList.count())
{
ui->treeWidget_2->clear();


    intersection = oldList.toSet().intersect(newList.toSet());
     int insertRow =0;
    foreach(const QString &value, intersection)
    {
                ui->tableWidget->removeRow(insertRow);
 QTableWidgetItem *itemName =new QTableWidgetItem();
        itemName->setTextColor(QColor(16,15,150));
        itemName->setBackgroundColor(Qt::yellow);


        ui->tableWidget->insertRow(insertRow);
                itemName->setText(value);
z.append(value);
                ui->tableWidget->setItem(insertRow, 0, itemName);


insertRow++;

    }


    make_break(o,z);
ui->tableWidget->removeRow(insertRow);
    ui->lblResult->setText( "File Removed");

} else if(oldList.count() < newList.count())
   {
m="", z.clear(), all ="";
    ui->treeWidget_2->clear();
   intersection = newList.toSet().subtract(oldList.toSet());
     foreach(const QString &value, intersection) {




     QTableWidgetItem *itemName =new QTableWidgetItem();
     itemName->setTextColor(QColor(16,15,150));
     itemName->setBackgroundColor(Qt::gray);
     int insertRow = ui->tableWidget->rowCount();
     ui->tableWidget->insertRow(insertRow);
             itemName->setText(value);

             ui->tableWidget->setItem(insertRow, 0, itemName);

                     all =value;


              qDebug () << newList << all << " i am the all when file is added";



     }

std::sort(n.begin(),n.end(), collator);
std::reverse(n.begin(), n.end());
     make_break(n,newList);
ui->lblResult->setText("File Added");
}

}



void MainWindow::on_tableWidget_clicked(const QModelIndex &index)
{ ui->lblResult->clear();
    int row= index.row();
   file_name= index.sibling(row, 0).data().toString();

    Path.append("/"+ file_name);


    QFileInfo get ( Path);



    qDebug() <<file_name << "file name" <<Path<< "i am selected" << get.completeSuffix() ;

    QFile file (Path);

    file.open(QIODevice::ReadOnly | QIODevice::Text);

    QString show =file.readAll();
    QString  anal  ,digi, samp_2, event_trig_2;  QString word = "";
int anal_=0,digi_=0;
   int j= 1;
    for(auto x : show) {
    if (x == ',' || x== '\n'){




 // i can obtain separate words at this line------------------------------------

        if (j==1){ qDebug() << word;

           //   ui->plainTextEdit->insertPlainText(word1+"\n");
      station_name    = word;

       word ="";

        }else{}

        if (j==2){ qDebug() << word;

           //   ui->plainTextEdit->insertPlainText(word1+"\n");
      pmu_id   = word;

       word ="";

        }else{}



        if (j==5){ qDebug() << word;

               //   ui->plainTextEdit->insertPlainText(word1+"\n");
          anal    = word.mid(0,word.length()-1);

           anal_  = anal.toInt(&valid,10);
                qDebug() << anal << anal_ <<word.length();
                word ="";

            }else{}
            if (j==6){ qDebug() << word;

 digi  =  word.mid(0,word.length()-1);

                       digi_ =  digi.toInt(&valid,10);
                           qDebug() <<digi << digi_ <<word.length();
                            word ="";

                        }else{}










            int zl = (((anal_*13)+(digi_*5))+11);

            if (j== zl){ qDebug()  << word;

                              samp_1 = word;

                                        qDebug() << samp_1<< word << "see1";
                                        word ="";

                                    }else{}



             zl = (((anal_*13)+(digi_*5))+12);

            if (j== zl){ qDebug()  << word;

                              event_trig_1 = word;

                                        qDebug() << event_trig_1<< word << "see2";
                                        word ="";

                                    }else{}

            zl = (((anal_*13)+(digi_*5))+13);

           if (j== zl){ qDebug()  << word;

                             samp_2 = word;

                                       qDebug() << samp_2<< word << "see3";
                                       word ="";

                                   }else{}

           zl = (((anal_*13)+(digi_*5))+14);

          if (j== zl){ qDebug()  << word;

                           event_trig_2 = word;

                                      qDebug() << event_trig_2<< word << "see4";
                                      word ="";

                                  }else{}



     j++;word ="";}else {
        word =word +x ;

    }}



 ui->lblResult->setText("Station Name:  "+ station_name+ "\n\n Number of Analog Channels :"+ anal+"\n\n"+"Number of Digital Status :"+digi + "\n\n"+ "First Capture Time :"+samp_1+" "+event_trig_1+ "\n\n"+"Event Trigger Time :"+samp_2+ " "+event_trig_2 );
    Path.remove("/"+file_name);
    qDebug() <<Path<< "i am new path" ;



    file.close();

}



void MainWindow::item_tree(QString root_name_1, QString root_name_2){
    QString word = "" , name_1= "", name_2="", name_3="" , name_4 ="";
    int j=0 , s=0, m=0;
    QTreeWidgetItem *treeItem_1 = new QTreeWidgetItem(ui->treeWidget);
    QTreeWidgetItem *treeItem_2 = new QTreeWidgetItem(ui->treeWidget);
 treeItem_1->setText(0, root_name_1);
    // QTreeWidgetItem::setText(int column, const QString & text)
    treeItem_2->setText(0, root_name_2);



    // QTreeWidgetItem::setText(int column, const QString & text)

    for(auto x : comtrade_file_contents){
         if (x == ',' || x== '\n'){
             if(x== '\n'  && s <  no_of_analogs+2){
                 s++;
                 if(s > 2){
               cont_ = name_1.append(" "+name_2.append(" "+name_3));
                 qDebug() << cont_ << "here";


                 addTreeChild(treeItem_1, cont_ );
                 name_1= "", name_2="", name_3="";}
  }


             if (j==7+13*(s-2) && s < no_of_analogs+2){

         name_1 =  word;

pass_strn_1.append(name_1);
                 word ="";

             }else{}


             if (j==8+13*(s-2) && s < no_of_analogs+2){

         name_2 =  word;

                 word ="";

             }else{}

             if (j==10+13*(s-2) && s < no_of_analogs+2){

         name_3 =  word;

                 word ="";

             }else{}

             if (j==(13*(no_of_analogs))+7+(5*(m)) && m< no_of_digitals ){


         name_4 =  word;
        qDebug() << name_4 << "digi here";
        pass_strn_2.append(name_4);
         addTreeChild(treeItem_2, name_4 );
                 word ="";
                 m++;

             }else{}















             j++;word ="";}else {
                word =word +x ;

            }



    }


}



int MainWindow::GIF (double no_of_digitals){

    float q = ((no_of_digitals)/(16));
    int n =q;

    if (q == 0 ||(q/n) == 1){
        return n;
   qDebug() << "i am " <<n;
    }else{
        return n +1 ;
         qDebug() << "here it is" <<n +1;
    }

   //return n;
}




int MainWindow::converter(QString all){
    QString word = "", hello ="";


     int j= 1;
      for(auto x : all) {
      if (x == '_'){




   // i can obtain separate words at this line------------------------------------
if (j ==1){

  hello.append(word);
         word ="";

      }


   if (j == 2)
{    hello.append("_"+word);
     word ="";

   }



       j++;
       word ="";}else {
          word =word +x ;

      }}
qDebug() << hello.append("_");

qDebug() << all.remove(hello);
qDebug() << all.remove(".cfg");
qDebug() << all.toInt(&valid,10);
return all.toInt(&valid,10);


}

void MainWindow::make_break(QStringList n, QStringList z){

    for(int i =0 ;i < n.size(); i++)
    {  QTreeWidgetItem *treeItem_2= new QTreeWidgetItem(ui->treeWidget_2);
            QString time = n.at(i);
            int k= time.toInt(&valid,10);
             QString stamp=QDateTime::fromSecsSinceEpoch(k).toString("dddd d MMMM yyyy hh:mm:ss zzz ap");
                treeItem_2->setText(0, stamp);

        for(int j =0; j < z.size(); ++j){


            QString word = "", hello ="";

            QString full = z.at(j);
                 int p= 1;
                  for(auto x : full) {
                  if (x == '_'){




               // i can obtain separate words at this line------------------------------------
            if (p ==1){

              hello.append(word);
                     word ="";

                  }


               if (p == 2)
            {    hello.append("_"+word);
                 word ="";

               }



                   p++;
                   word ="";}else {
                      word =word +x ;

                  }}



                   hello.append("_"); // here is the make --------

                  full.remove(hello);
                  full.remove(".cfg");// here is the break++++++++++++
                  qDebug() << full << "in serch of";
                  if (full == n.at(i)){
                      qDebug() << hello.append(full) <<n.at(i);



                          // QTreeWidgetItem::setText(int column, const QString & text)
                         // treeItem_2->setText(0, root_name_2);
                         addTreeChild(treeItem_2,  hello );
                  }




        }
    }





}

void MainWindow::on_view_cfg_file_clicked()
{
    new_one_2 = new MyDialog_2(this);
    new_one_2->setWindowTitle("Configuration File");
    new_one_2->show();

}


void MainWindow::on_reset_all_clicked()
{

    QMessageBox::StandardButton reply;
     reply = QMessageBox::question(this, "Restart session", "All data will be lost\n\nAre you sure ?",
                                   QMessageBox::Yes|QMessageBox::No);
     if (reply == QMessageBox::Yes)
     {

         comtrade_file_contents.clear();
                 dat_file_name.clear();
                 Path.clear();
                 file_name.clear();

                         cont_.clear();
                         pass_strn_1.clear();
                         pass_strn_2.clear();


                           raw_data.clear();
                           k.clear();
                           chunk.clear();
                           num_3.clear();
                           num_6.clear();
                           st.clear();
                           num_5.clear();
                           num.clear();
                           rev.clear();
                           p.clear();
                           o.clear();

                         sample_number = 0;
                         no_of_digitals = 0;
                         n_rate= 0;
                         data_chunk_size= 0;
                         actual_digitals= 0;
                         sample_freq= 0;
                         digitalval= 0;
                          one = 0; two= 0;
                          ui->tableWidget->setRowCount(0);

     ui->tableWidget->clearContents();


                         ui->treeWidget->clear();
                         ui->treeWidget_2->clear();
                         ui->lblResult->clear();
                         ui->txtPath->clear();
                         ui->import_2->setEnabled(true);
     }



}
