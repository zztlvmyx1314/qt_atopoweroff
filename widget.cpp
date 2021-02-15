#include "widget.h"
#include "ui_widget.h"
#include <QtDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    this->timer=new QTimer(this);
    this->timer->setInterval(1000);

    this->time=new QTime;



    this->LCD_Init();

    connect(this->timer,&QTimer::timeout,this,&Widget::counter);





}

Widget::~Widget()
{
    delete ui;
}

void Widget::LCD_Init()
{

    for(int i=0;i<60;i++){

        QString num=QString("%1").arg(i);

        if(i<24){

            ui->comboBox_H->addItem(num);

        }
        ui->comboBox_M->addItem(num);
        ui->comboBox_S->addItem(num);



     }


     ui->hour->display("00");
     ui->minute->display("00");
     ui->second->display("00");







}

void Widget::counter()
{

//     this->timer->stop();




       int hour=QTime::currentTime().hour();
       int minute=QTime::currentTime().minute();
       int second=QTime::currentTime().second();

       if(this->time->hour()==hour&&this->time->minute()==minute){

           this->timer->stop();

           system("shutdown -s -t 00");

           return;

       }


       if(hour/10==0){

         QString displayh=QString("0%1").arg(hour);
         ui->hour->display(displayh);

       }else{    ui->hour->display(hour);              }

       if(minute/10==0){

         QString displaym=QString("0%1").arg(minute);
         ui->minute->display(displaym);

       }else{    ui->minute->display(minute);              }


       if(second/10==0){

         QString displays=QString("0%1").arg(second);
         ui->second->display(displays);

       }else{    ui->second->display(second);              }






}


void Widget::on_start_clicked()
{


    QString hour=ui->comboBox_H->currentText();
    QString minute=ui->comboBox_M->currentText();
    QString second=ui->comboBox_S->currentText();

//    ui->hour->display(hour);
//    ui->minute->display(minute);
//    ui->second->display(second);

     QString offh;
     QString offm;
     QString offs;

    this->time->setHMS(hour.toInt(),minute.toInt(),second.toInt());

    if((hour.toInt()/10)==0){

     offh=QString("计算机将在 0%1 :").arg(hour);

    }else{  offh=QString("计算机将在 %1 :").arg(hour);           }

    if((minute.toInt()/10)==0){

     offm=QString(" 0%1 :").arg(minute);

    }else{  offm=QString(" %1 :").arg(minute);           }

    if((second.toInt()/10)==0){

     offs=QString(" 0%1 关机").arg(second);

    }else{  offs=QString(" %1 关机").arg(second);           }



    ui->title->setText(offh+offm+offs);



    ui->start->setEnabled(false);
    ui->comboBox_H->setEnabled(false);
    ui->comboBox_M->setEnabled(false);
    ui->comboBox_S->setEnabled(false);

    this->timer->start();






}

void Widget::on_stop_clicked()
{

    this->timer->stop();
    ui->start->setEnabled(true);
    ui->comboBox_H->setEnabled(true);
    ui->comboBox_M->setEnabled(true);
    ui->comboBox_S->setEnabled(true);
    ui->title->setText("已退出定时");


}
