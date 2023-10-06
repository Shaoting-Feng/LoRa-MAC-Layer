#include "clients.h"
#include "ui_clients.h"
#include "dialog.h"
#include "ui_dialog.h"
#include <QDebug>

QString Dialog::tag_ID;

clients::clients(QDialog *parent) :
    QDialog(parent),
    ui(new Ui::clients)
{
    ui->setupUi(this);
    ui->ObjectNum->setText("0000");
}

clients::~clients()
{
    delete ui;
}

//add by zc
void clients::on_pushButton_clicked()
{    emit sendConfigText("tag ID 参数配置完成");
    clients::close();
    QString clinents_temp = "";
    clinents_temp = ui->ObjectNum->text();
    while (clinents_temp.length() < 4) {
        clinents_temp = '0' + clinents_temp;
    }
  Dialog::tag_ID=clinents_temp;
  qDebug()<<"tag ID = "<<Dialog::tag_ID;
}

void clients::on_pushButton2_clicked()
{    ui->ObjectNum->clear();
}
