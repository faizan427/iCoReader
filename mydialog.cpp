#include "mydialog.h"
#include "ui_mydialog.h"

#include "mainwindow.cpp"
#include <QComboBox>
#include <qthread.h>
#include <thread>
#include <QThread>
#include <chrono>
MyDialog::MyDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MyDialog)
{
    ui->setupUi(this);







    ui->customPlot->setInteractions(QCP::iSelectPlottables |QCP::iSelectOther|QCP::iSelectLegend|QCP::iMultiSelect|QCP::iRangeDrag |QCP::iRangeZoom|QCP::iSelectAxes);

    ui->customPlot->axisRect()->setupFullAxesBox();
    ui->customPlot->setLocale(QLocale(QLocale::English, QLocale::India));


    ui->customPlot->xAxis->setNumberPrecision(5);


    ui->customPlot->xAxis->ticker()->setTickCount(10);

    ui->horizontalScrollBar->setRange(0, 50000);
      ui->verticalScrollBar->setRange(0, 50);


    connect(ui->horizontalScrollBar, SIGNAL(valueChanged(int)), this, SLOT(on_horizontalScrollBar_valueChanged(int)));
     connect(ui->verticalScrollBar, SIGNAL(valueChanged(int)), this, SLOT(on_verticalScrollBar_valueChanged(int)));
     connect(ui->customPlot->xAxis, SIGNAL(rangeChanged(QCPRange)), this, SLOT(xAxisChanged(QCPRange)));
     connect(ui->customPlot->yAxis, SIGNAL(rangeChanged(QCPRange)), this, SLOT(yAxisChanged(QCPRange)));

// connect(ui->customPlot, SIGNAL(selectionChangedByUser()), this, SLOT(selectionChanged()));
     connect(ui->customPlot, SIGNAL(mousePress(QMouseEvent*)), this, SLOT(mousePress()));
     connect(ui->customPlot, SIGNAL(mouseWheel(QWheelEvent*)), this, SLOT(mouseWheel()));

  connect(ui->customPlot, SIGNAL(plottableClick(QCPAbstractPlottable*,int,QMouseEvent*)), this, SLOT(graphClicked(QCPAbstractPlottable*,int)));


  ui->customPlot_2->setInteractions(QCP::iSelectPlottables |QCP::iSelectOther|QCP::iSelectLegend|QCP::iMultiSelect|QCP::iRangeDrag |QCP::iRangeZoom|QCP::iSelectAxes);

  ui->customPlot_2->axisRect()->setupFullAxesBox();
  ui->customPlot_2->setLocale(QLocale(QLocale::English, QLocale::India));


  ui->customPlot_2->xAxis->setNumberPrecision(5);


  ui->customPlot_2->xAxis->ticker()->setTickCount(10);

  connect(ui->horizontalScrollBar_2, SIGNAL(valueChanged(int)), this, SLOT(on_horizontalScrollBar_valueChanged_2(int)));
   connect(ui->verticalScrollBar_2, SIGNAL(valueChanged(int)), this, SLOT(on_verticalScrollBar_valueChanged_2(int)));
  connect(ui->customPlot_2->xAxis, SIGNAL(rangeChanged(QCPRange)), this, SLOT(xAxisChanged_2(QCPRange)));
   connect(ui->customPlot_2->yAxis, SIGNAL(rangeChanged(QCPRange)), this, SLOT(yAxisChanged_2(QCPRange)));

// connect(ui->customPlot, SIGNAL(selectionChangedByUser()), this, SLOT(selectionChanged()));
   connect(ui->customPlot_2, SIGNAL(mousePress(QMouseEvent*)), this, SLOT(mousePress_2()));
   connect(ui->customPlot_2, SIGNAL(mouseWheel(QWheelEvent*)), this, SLOT(mouseWheel_2()));

//connect(ui->customPlot_2, SIGNAL(plottableClick(QCPAbstractPlottable*,int,QMouseEvent*)), this, SLOT(graphClicked(QCPAbstractPlottable*,int)));


  ui->comboBox->addItems(pass_strn_1);
  ui->comboBox_2->addItems(pass_strn_2);


      // Open csv-file
      QFile file("pixels.csv");
      file.open(QIODevice::Append | QIODevice::Text);

      // Write data to file
      QTextStream stream(&file);
      QString separator(",");
      for (int i = 0; i < pass_strn_1.size(); ++i)
      {
          stream << pass_strn_1.at(i) << endl;
      }

      stream.flush();
      file.close();

}


void MyDialog::closeEvent(QCloseEvent *e){

    qDebug() << "close";
//ui->view_parameters->setEnabled(false);
    //  MyDialog::close_circle(e);
e->accept();

emit buttonPressed();


}


void MyDialog::analog_extract(int arg1){


for (int m = 0; m< no_of_analogs ; m++){

 }}




void MyDialog::extract_digital(int digitalval) {
    ui->customPlot->addGraph();
double inc_=0;
    actual_digitals = GIF(no_of_digitals);
       data_chunk_size = 16+(((no_of_analogs)*8)+(actual_digitals)*(4));

    QVector <double> x, d;
  //  int sso= 0;
QString w,l,m;
 QString y ="";
    for (int i = 0; i< (floor(((raw_data.length())/(data_chunk_size)))); i++) {
        int a;
        a = i*data_chunk_size;
          p = raw_data.mid(a,data_chunk_size);
          for (int j=0 ;j < actual_digitals ;j++){
              o = p.mid((16+(no_of_analogs)*(8))+(j*4),4);
//qDebug() << actual_digitals << "i am digital";
                 y+= "" +o[2]+o[3]+o[0]+o[1];
                 QByteArray n =y.toUtf8();
                 l = HexToBin(n);
                 m.append(l);


                 w.append("    "+y);
                 y = "";
                 l = "";
              //   __________________________-binary equilanet


          }

   //   qDebug()<< m << "digital value" << i ;
                            reverse(m.begin(),m.end());
         qDebug()<< m << "digital value" << i ;
          QString three= m.mid(digitalval-1,1);
         double dig = three.toDouble(&valid);
          qDebug()<< dig << "digital value" << i ;





 w = "";
 y ="";
 m= "";
 l= "";


 d.append(dig);
 x.append(inc_);

 inc_ = inc_ + 1/sample_freq;





}
    double max = *std::max_element(d.constBegin(), d.constEnd());
    double min = *std::min_element(d.constBegin(), d.constEnd());
    double max_2 = *std::max_element(x.constBegin(), x.constEnd());
    qDebug () << max << "max" <<  min << "  min";
    ui->customPlot->graph()->setData(x,d);
    ui->customPlot->yAxis->setRange(max+1,min-1);
    ui->customPlot->xAxis->setRange(0,max_2+1);
  ui->customPlot->graph()->setPen(QPen(Qt::blue));
    ui->customPlot->graph()->setBrush(QBrush(QColor(0, 230, 255, 150)));

   ui->customPlot->graph()->setLineStyle((QCPGraph::LineStyle)QCPGraph::lsStepLeft);
ui->customPlot->replot();}



QString MyDialog:: HexToBin(QByteArray hexdec)
{
    QString h,y;

    for(int i = 0; i< 4; i++) {

        switch (hexdec[i]) {
        case '0':
            h = "0000";
            break;
        case '1':
            h = "0001";
            break;
        case '2':
            h = "0010";
            break;
        case '3':
            h = "0011";
            break;
        case '4':
            h = "0100";
            break;
        case '5':
            h = "0101";
            break;
        case '6':
            h = "0110";
            break;
        case '7':
             h = "0111";
            break;
        case '8':
            h = "1000";
            break;
        case '9':
            h = "1001";
            break;
        case 'A':
        case 'a':
            h = "1010";
            break;
        case 'B':
        case 'b':
            h = "1011";
            break;
        case 'C':
        case 'c':
            h = "1100";
            break;
        case 'D':
        case 'd':
            h = "1101";
            break;
        case 'E':
        case 'e':
            h = "1110";
            break;
        case 'F':
        case 'f':
            h = "1111";
            break;
        default:
            cout << "\nInvalid hexadecimal digit ";

        }

        y.append(h);
                    h= ""; }
    return y;

}



void MyDialog::on_plot_digital_clicked()
{
      extract_digital(digitalval);
}

void MyDialog::on_clear_analog_clicked()
{

    ui->customPlot->clearItems();
    ui->customPlot->clearPlottables();
ui->customPlot->clearGraphs();
ui->customPlot->replot();
}

void MyDialog::on_clear_digital_clicked()
{ ui->customPlot_2->clearItems();
    ui->customPlot_2->clearPlottables();
ui->customPlot_2->clearGraphs();
ui->customPlot_2->replot();
}


void MyDialog::on_verticalScrollBar_valueChanged(int value)
{

    if (qAbs(ui->customPlot->yAxis->range().center()+value/100.0) > 0.01) // if user is dragging plot, we don't want to replot twice
      {
        ui->customPlot->yAxis->setRange(-value/100.0, ui->customPlot->yAxis->range().size(), Qt::AlignCenter);
        ui->customPlot->replot();


}}

void MyDialog::on_horizontalScrollBar_valueChanged(int value)
{
    if (qAbs(ui->customPlot->xAxis->range().center()-value/100.0) > 0.01) // if user is dragging plot, we don't want to replot twice
      {
        ui->customPlot->xAxis->setRange(value/100.0, ui->customPlot->xAxis->range().size(), Qt::AlignHCenter);
        ui->customPlot->replot();
      }

}


void MyDialog::xAxisChanged(QCPRange range)
{
  ui->horizontalScrollBar->setValue(qRound(range.center()*100.0)); // adjust position of scroll bar slider
  ui->horizontalScrollBar->setPageStep(qRound(range.size()*100.0)); // adjust size of scroll bar slider
}

void MyDialog::yAxisChanged(QCPRange range)
{
  ui->verticalScrollBar->setValue(qRound(-range.center()*100.0)); // adjust position of scroll bar slider
  ui->verticalScrollBar->setPageStep(qRound(range.size()*100.0)); // adjust size of scroll bar slider
}



void MyDialog::mousePress()
{
  // if an axis is selected, only allow the direction of that axis to be dragged
  // if no axis is selected, both directions may be dragged

  if (ui->customPlot->xAxis->selectedParts().testFlag(QCPAxis::spAxis))
    ui->customPlot->axisRect()->setRangeDrag(ui->customPlot->xAxis->orientation());
  else if (ui->customPlot->yAxis->selectedParts().testFlag(QCPAxis::spAxis))
    ui->customPlot->axisRect()->setRangeDrag(ui->customPlot->yAxis->orientation());
  else
    ui->customPlot->axisRect()->setRangeDrag(Qt::Horizontal|Qt::Vertical);
}

void MyDialog::mouseWheel()
{
  // if an axis is selected, only allow the direction of that axis to be zoomed
  // if no axis is selected, both directions may be zoomed

  if (ui->customPlot->xAxis->selectedParts().testFlag(QCPAxis::spAxis))
    ui->customPlot->axisRect()->setRangeZoom(ui->customPlot->xAxis->orientation());
  else if (ui->customPlot->yAxis->selectedParts().testFlag(QCPAxis::spAxis))
    ui->customPlot->axisRect()->setRangeZoom(ui->customPlot->yAxis->orientation());
  else
    ui->customPlot->axisRect()->setRangeZoom(Qt::Horizontal|Qt::Vertical);
}

void MyDialog::mousePress_2()
{
  // if an axis is selected, only allow the direction of that axis to be dragged
  // if no axis is selected, both directions may be dragged

  if (ui->customPlot_2->xAxis->selectedParts().testFlag(QCPAxis::spAxis))
    ui->customPlot_2->axisRect()->setRangeDrag(ui->customPlot_2->xAxis->orientation());
  else if (ui->customPlot_2->yAxis->selectedParts().testFlag(QCPAxis::spAxis))
    ui->customPlot_2->axisRect()->setRangeDrag(ui->customPlot_2->yAxis->orientation());
  else
    ui->customPlot_2->axisRect()->setRangeDrag(Qt::Horizontal|Qt::Vertical);
}

void MyDialog::mouseWheel_2()
{
  // if an axis is selected, only allow the direction of that axis to be zoomed
  // if no axis is selected, both directions may be zoomed

  if (ui->customPlot_2->xAxis->selectedParts().testFlag(QCPAxis::spAxis))
    ui->customPlot_2->axisRect()->setRangeZoom(ui->customPlot_2->xAxis->orientation());
  else if (ui->customPlot_2->yAxis->selectedParts().testFlag(QCPAxis::spAxis))
    ui->customPlot_2->axisRect()->setRangeZoom(ui->customPlot_2->yAxis->orientation());
  else
    ui->customPlot_2->axisRect()->setRangeZoom(Qt::Horizontal|Qt::Vertical);
}


void MyDialog::on_verticalScrollBar_valueChanged_2(int value)
{

    if (qAbs(ui->customPlot_2->yAxis->range().center()+value/100.0) > 0.01) // if user is dragging plot, we don't want to replot twice
      {
        ui->customPlot_2->yAxis->setRange(-value/100.0, ui->customPlot_2->yAxis->range().size(), Qt::AlignCenter);
        ui->customPlot_2->replot();


}}

void MyDialog::on_horizontalScrollBar_valueChanged_2(int value)
{
    if (qAbs(ui->customPlot_2->xAxis->range().center()-value/100.0) > 0.01) // if user is dragging plot, we don't want to replot twice
      {
        ui->customPlot_2->xAxis->setRange(value/100.0, ui->customPlot_2->xAxis->range().size(), Qt::AlignHCenter);
        ui->customPlot_2->replot();
      }

}


void MyDialog::xAxisChanged_2(QCPRange range)
{
  ui->horizontalScrollBar_2->setValue(qRound(range.center()*100.0)); // adjust position of scroll bar slider
  ui->horizontalScrollBar_2->setPageStep(qRound(range.size()*100.0)); // adjust size of scroll bar slider
}

void MyDialog::yAxisChanged_2(QCPRange range)
{
  ui->verticalScrollBar_2->setValue(qRound(-range.center()*100.0)); // adjust position of scroll bar slider
  ui->verticalScrollBar_2->setPageStep(qRound(range.size()*100.0)); // adjust size of scroll bar slider
}




void MyDialog::selectionChanged()
{
  /*
   normally, axis base line, axis tick labels and axis labels are selectable separately, but we want
   the user only to be able to select the axis as a whole, so we tie the selected states of the tick labels
   and the axis base line together. However, the axis label shall be selectable individually.

   The selection state of the left and right axes shall be synchronized as well as the state of the
   bottom and top axes.

   Further, we want to synchronize the selection of the graphs with the selection state of the respective
   legend item belonging to that graph. So the user can select a graph by either clicking on the graph itself
   or on its legend item.
  */

  // make top and bottom axes be selected synchronously, and handle axis and tick labels as one selectable object:
  if (ui->customPlot->xAxis->selectedParts().testFlag(QCPAxis::spAxis) || ui->customPlot->xAxis->selectedParts().testFlag(QCPAxis::spTickLabels) ||
      ui->customPlot->xAxis2->selectedParts().testFlag(QCPAxis::spAxis) || ui->customPlot->xAxis2->selectedParts().testFlag(QCPAxis::spTickLabels))
  {
    ui->customPlot->xAxis2->setSelectedParts(QCPAxis::spAxis|QCPAxis::spTickLabels);
    ui->customPlot->xAxis->setSelectedParts(QCPAxis::spAxis|QCPAxis::spTickLabels);
  }
  // make left and right axes be selected synchronously, and handle axis and tick labels as one selectable object:
  if (ui->customPlot->yAxis->selectedParts().testFlag(QCPAxis::spAxis) || ui->customPlot->yAxis->selectedParts().testFlag(QCPAxis::spTickLabels) ||
      ui->customPlot->yAxis2->selectedParts().testFlag(QCPAxis::spAxis) || ui->customPlot->yAxis2->selectedParts().testFlag(QCPAxis::spTickLabels))
  {
    ui->customPlot->yAxis2->setSelectedParts(QCPAxis::spAxis|QCPAxis::spTickLabels);
    ui->customPlot->yAxis->setSelectedParts(QCPAxis::spAxis|QCPAxis::spTickLabels);
  }

  // synchronize selection of graphs with selection of corresponding legend items:
  for (int i=0; i<ui->customPlot->graphCount(); ++i)
  {
    QCPGraph *graph = ui->customPlot->graph(i);
    QCPPlottableLegendItem *item = ui->customPlot->legend->itemWithPlottable(graph);
    if (item->selected() || graph->selected())
    {
      item->setSelected(true);
      graph->setSelection(QCPDataSelection(graph->data()->dataRange()));
    }
  }
}

void MyDialog::graphClicked(QCPAbstractPlottable *plottable, int dataIndex)
{
  // since we know we only have QCPGraphs in the plot, we can immediately access interface1D()
  // usually it's better to first check whether interface1D() returns non-zero, and only then use it.
  double dataValue = plottable->interface1D()->dataMainValue(dataIndex);
  QString message = QString("Clicked on graph '%1' at data point #%2 with value %3.").arg(plottable->name()).arg(dataIndex).arg(dataValue);
  //ui->statusbar->showMessage(message, 10000000);
  QString z = plottable->name();
  qDebug() << z <<"i am plottable";


}

int MyDialog::GIF (double no_of_digitals){

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


MyDialog::~MyDialog()
{
    delete ui;
}




void MyDialog::on_add_clicked()
{
    if(ui->comboBox->currentIndex() != -1){
    QTableWidgetItem *itemName =new QTableWidgetItem();
    itemName->setTextColor(QColor(16,15,150));
    itemName->setBackgroundColor(Qt::yellow);
    int insertRow = ui->tableWidget->rowCount();
    ui->tableWidget->insertRow(insertRow);

            itemName->setText(ui->comboBox->currentText());


            ui->tableWidget->setItem(insertRow, 0, itemName);
  //  ui->listWidget->addItem(ui->comboBox->currentText());

ui->comboBox->removeItem(ui->comboBox->currentIndex());
    }


}

void MyDialog::on_delete_2_clicked()

{

   if(ui->tableWidget->isItemSelected(ui->tableWidget->currentItem())){
       QString z;
            QTableWidgetItem *item = ui->tableWidget->currentItem();

    z = item->text();
    ui->comboBox->addItem(z);
ui->tableWidget->removeRow(ui->tableWidget->currentRow());
   }


}


void MyDialog::on_add_2_clicked()
{
if(ui->comboBox_2->currentIndex() != -1){
    QTableWidgetItem *itemName =new QTableWidgetItem();
        itemName->setTextColor(QColor(16,15,150));
        itemName->setBackgroundColor(Qt::yellow);
        int insertRow = ui->tableWidget_2->rowCount();
        ui->tableWidget_2->insertRow(insertRow);

                itemName->setText(ui->comboBox_2->currentText());


                ui->tableWidget_2->setItem(insertRow, 0, itemName);


    ui->comboBox_2->removeItem(ui->comboBox_2->currentIndex());


}}


void MyDialog::on_delete_3_clicked()
{


    if(ui->tableWidget_2->isItemSelected(ui->tableWidget_2->currentItem())){
         QString z;
             QTableWidgetItem *item = ui->tableWidget_2->currentItem();

     z = item->text();
     ui->comboBox_2->addItem(z);
 ui->tableWidget_2->removeRow(ui->tableWidget_2->currentRow());

}}






void MyDialog::on_plot_clicked()

{
    ui->customPlot->plotLayout()->insertRow(0);
  QCPTextElement *title = new QCPTextElement(ui->customPlot, "Data representation of instantaneous Analog values from station: "+ station_name+ " acquired through PMU ID: "+pmu_id+ " on "+samp_1+" "+event_trig_1 , QFont("sans", 11,10, QFont::Bold));
                  ui->customPlot->plotLayout()->addElement(0, 0, title);
                  ui->customPlot->legend->setVisible(true);
                  QFont legendFont = font();
                  legendFont.setPointSize(10);
                  ui->customPlot->legend->setFont(legendFont);
                  ui->customPlot->legend->setSelectedFont(legendFont);


    int k;
    actual_digitals = GIF(no_of_digitals);

    data_chunk_size = 16+(((no_of_analogs)*8)+(actual_digitals)*(4));
     qDebug()<< no_of_analogs << "actual digital" << actual_digitals << "data chunk" << data_chunk_size;

     QVector <double> x, d(floor(((raw_data.length())/(data_chunk_size)))), e[no_of_analogs], l_a[no_of_digitals];
if(ui->tableWidget->rowCount() != 0){
    double inc_=0;
 int s=0, n=0;


    QStringList current_list;
    for (int i = 0; i < ui->tableWidget->rowCount(); i++){
        QTableWidgetItem *item = ui->tableWidget->item(i,0);
        current_list << item->text();}
    for(int i =0 ;i < current_list.size(); i++)
    {

            for(int j =0; j < pass_strn_1.size(); j++){

                       if(current_list.at(i) == pass_strn_1.at(j)){


                           ui->customPlot->addGraph();
                         for (int r =0; r< (floor(((raw_data.length())/(data_chunk_size)))); r++) {
                             int a;
                             a = r*data_chunk_size;
                               p = raw_data.mid(a,data_chunk_size);

                                 k = pass_strn_1.indexOf(pass_strn_1.at(j));
                         s = 16+8*(k);

                      o = p.mid(s,8);


                          QString y ="";
                             y+= "" +o[6]+o[7]+o[4]+o[5]+o[2]+o[3]+o[0]+o[1];
                             QByteArray g =y.toUtf8();



                      st = HexToFloat(g);
                      one = st.toDouble(&valid);
                      //qDebug () <<m<< arg1 << one << "one";


                      e[ k].append(one);
                      x.append(inc_);

                       inc_ = inc_ + 1/sample_freq;
                      // qDebug() << data[i];
                         }
                      //qDebug()<< e[m]<< "oustide" << m;
                      //
                        double max = *std::max_element(e[k].constBegin(), e[k].constEnd());
                         double min = *std::min_element(e[k].constBegin(), e[k].constEnd());
                         double max_2 = *std::max_element(x.constBegin(), x.constEnd());

                      ui->customPlot->graph(n)->setData(x,e[k]);
                      ui->customPlot->yAxis->setRange(max+1,min-1);
                      ui->customPlot->xAxis->setRange(0,max_2+1);
                      ui->customPlot->graph(n)->setScatterStyle(QCPScatterStyle::ssPlusCircle);
                            ui->customPlot->graph(n)->setName(current_list.at(i));

                      ui->customPlot->graph(n)->setPen(QColor(rand()%245+10, rand()%245+10, rand()%245+10));

                ui->customPlot->replot();

                      x.clear();
                      inc_ =0;

                      k = 0;
                      n++;
                       }


}}

}


}



void MyDialog::on_plot_2_clicked()
{




    ui->customPlot_2->plotLayout()->insertRow(0);
  QCPTextElement *title = new QCPTextElement(ui->customPlot_2, "Data representation of instantaneous Digital values from station: "+ station_name+ " acquired through PMU ID: "+pmu_id+ " on "+samp_1+" "+event_trig_1 , QFont("sans", 11,10, QFont::Bold) );
                  ui->customPlot_2->plotLayout()->addElement(0, 0, title);

                  ui->customPlot_2->legend->setVisible(true);
                  QFont legendFont = font();
                  legendFont.setPointSize(10);
                  ui->customPlot_2->legend->setFont(legendFont);
                  ui->customPlot_2->legend->setSelectedFont(legendFont);



    int k;
    actual_digitals = GIF(no_of_digitals);

    data_chunk_size = 16+(((no_of_analogs)*8)+(actual_digitals)*(4));
     qDebug()<< no_of_analogs << "actual digital" << actual_digitals << "data chunk" << data_chunk_size;

     QVector <double> x, l_a[no_of_digitals];

    if(ui->tableWidget_2->rowCount() != 0)
    {       double inc_=0, n=0; QString s_s ="";
        QStringList current_list_1;
        for (int i = 0; i < ui->tableWidget_2->rowCount(); i++){
            QTableWidgetItem *item = ui->tableWidget_2->item(i,0);
            current_list_1 << item->text();}
        for(int i =0 ;i < current_list_1.size(); i++)
        {

                for(int j =0; j < pass_strn_2.size(); j++){

                           if(current_list_1.at(i) == pass_strn_2.at(j)){








                                     QString w,l,m;
                                      QString y ="";
                                         for (int q = 0; q< (floor(((raw_data.length())/(data_chunk_size)))); q++) {
                                             int a;
                                             a = q*data_chunk_size;
                                               s_s = raw_data.mid(a,data_chunk_size);
                                                k = pass_strn_2.indexOf(pass_strn_2.at(j));
                                               for (int h=0 ;h < actual_digitals ;h++){
                                                   o = s_s.mid((16+(no_of_analogs)*(8))+(h*4),4);
                                     //qDebug() << actual_digitals << "i am digital";
                                                      y+= "" +o[2]+o[3]+o[0]+o[1];
                                                      QByteArray n =y.toUtf8();
                                                      l = HexToBin(n);
                                                      m.append(l);


                                                      w.append("    "+y);
                                                      y = "";
                                                      l = "";
                                                   //   __________________________-binary equilanet


                                               }

                                        //   qDebug()<< m << "digital value" << i ;
                                                                 reverse(m.begin(),m.end());
                                             // qDebug()<< m << "digital value" << i ;
                                               QString three= m.mid(k,1);
                                              double dig = three.toDouble(&valid);
                                             // qDebug()<< dig << "digital value" << i ;





                                      w = "";
                                      y ="";
                                      m= "";
                                      l= "";


                                      l_a[k].append(dig);
                                      x.append(inc_);

                                      inc_ = inc_ + 1/sample_freq;





                                     }
                                         ui->customPlot_2->addGraph();
                                         double max = *std::max_element(l_a[k].constBegin(), l_a[k].constEnd());
                                         double min = *std::min_element(l_a[k].constBegin(), l_a[k].constEnd());
                                         double max_2 = *std::max_element(x.constBegin(), x.constEnd());
                                       //  qDebug () << max << "max" <<  min << "  min" << i << "i";
                                         ui->customPlot_2->graph(n)->setData(x,l_a[k]);
                                         ui->customPlot_2->yAxis->setRange(max+1,min-1);
                                         ui->customPlot_2->xAxis->setRange(0,max_2+1);
                                         ui->customPlot_2->graph(n)->setScatterStyle(QCPScatterStyle::ssPlusCircle);

            ui->customPlot_2->graph(n)->setLineStyle((QCPGraph::LineStyle)QCPGraph::lsStepLeft);
                                      //   ui->customPlot_2->graph(n)->setPen(QColor(rand()%245+10, rand()%245+10, rand()%245+10));
                                         ui->customPlot_2->graph(n)->setBrush(QBrush(QColor(rand()%245+10, rand()%245+10, rand()%245+10)));

                                 ui->customPlot_2->graph(n)->setName(current_list_1.at(i));
                                         ui->customPlot_2->replot();
                                     x.clear();
                                     inc_ =0;

                                     k = 0;
                                     n++;




                        }



    }}}
}



