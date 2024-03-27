#include "set.h"
#include "ui_set.h"
#include "dialog.h"
#include "ui_dialog.h"
#include <QDebug>
#include <QButtonGroup>

QString Dialog::setdata;

set::set(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::set)
{
    ui->setupUi(this);
    QButtonGroup *group1 = new QButtonGroup(this);

    QButtonGroup *group2 = new QButtonGroup(this);
    // 将UI中创建好的选择框全部加入按钮组
    group1->addButton(ui->ifbroadcast_y);
    group1->addButton(ui->ifbroadcast_n);
    group2->addButton(ui->if_setsleepmode_n);
    group2->addButton(ui->if_setsleepmode_y);

}

set::~set()
{
    delete ui;
}
void set::on_sure_button_clicked()
{    emit sendConfigText("相关参数配置完成");

    set::close();

   if(ui->ifbroadcast_y->isChecked()) Dialog::setdata="10";
   else{
           if(ui->if_setsleepmode_y->isChecked()) Dialog::setdata="00";
           else Dialog::setdata="01";
       }
    qDebug()<<"setdata="<<Dialog::setdata;
}


