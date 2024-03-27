#include "domain8.h"
#include "ui_domain8.h"
#include "dialog.h"
#include "ui_dialog.h"
#include <QDebug>

domain8::domain8(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::domain8)
{
    ui->setupUi(this);
    ui->lEditPreamble->setText("101010101010101010101010");
    ui->lEditId->setText("0000000000000001");
    ui->lEditType->setText("1001");\
    ui->lEditB2->setText("1 2");
    ui->lEditB1->setText("1 2");
    ui->lEditB0->setText("0.5");
}

domain8::~domain8()
{
    delete ui;
}

void domain8::on_btnConfirm8_clicked()
{
    emit sendConfigText("domain8 参数配置完成");
    domain8::close();

    QString d8_tmp = "";
    QString d8_preamble = ui->lEditPreamble->text();
    while (d8_preamble.length() < 24) {
        d8_preamble = '0' + d8_preamble;
    }

    d8_tmp = ui->lEditId->text();
    while (d8_tmp.length() < 16) {
        d8_tmp = '0' + d8_tmp;
    }
    d8_preamble += d8_tmp;

    d8_tmp = ui->lEditType->text();
    while (d8_tmp.length() < 4) {
        d8_tmp = '0' + d8_tmp;
    }
    d8_preamble += d8_tmp;


    QStringList d8blist = ui->lEditB2->text().split(" ");
    qDebug() << d8blist[0].toFloat() << d8blist[1].toInt() << pow(d8blist[1].toInt(), 2);

    double d8_tmp1 = d8blist[0].toFloat() / pow(d8blist[1].toInt(), 2) * pow(2, 16);
    qDebug() << "d8_tmp1    " << d8_tmp1;
    int d8_int = (int)d8_tmp1;
    qDebug() << "d8_int   " << d8_int;
    d8_tmp = QString::number(d8_int, 2);
    qDebug() << "d8_tmp" << d8_tmp << d8_tmp.length();
    while (d8_tmp.length() < 16) {
        d8_tmp = d8_tmp + '0';
    }
    qDebug() << "d8_tmp" << d8_tmp;
    d8_preamble += d8_tmp;


    d8blist = ui->lEditB1->text().split(" ");
    d8_tmp1 = d8blist[0].toFloat() / pow(d8blist[1].toInt(), 1) * pow(2, 16);
    d8_int = (int)d8_tmp1;
    d8_tmp = QString::number(d8_int, 2);
    while (d8_tmp.length() < 16) {
        d8_tmp = d8_tmp + '0';
    }
    d8_preamble += d8_tmp;

    d8_tmp = ui->lEditB0->text();
    d8_tmp1 = d8_tmp.toFloat()/2 * pow(2,16);
    d8_int = (int)d8_tmp1;
    d8_tmp = QString::number(d8_int, 2);
    while (d8_tmp.length() < 16) {
        d8_tmp = '0' + d8_tmp;
    }
    d8_preamble += d8_tmp;

//    double d7_temp1 = d7_temp.toFloat()/40 * pow(2,16);
//    qDebug() << "d7_temp1 = " << d7_temp1;
//    int d7_int = (int)d7_temp1;
//    qDebug() << "d7_int = " << d7_int;
//      d7_temp = QString::number( d7_int, 2);


    if (d8_preamble.length() > 112) {
        qDebug() << "输入ram data数据过多";
        return;
    }
    while (d8_preamble.length() < 112) {
        d8_preamble = d8_preamble + '0';
    }
    Dialog::SendData.resize(15);
    Dialog::SendData[0] = 0x01;
    for (int i = 1; i < 15; ++i) {
        quint8 temp = BinToHex(d8_preamble.mid((i - 1) * 8, 8));
        Dialog::SendData[i] = temp;
    }
    qDebug() << "Dialog::SendData = " << Dialog::SendData;

    qDebug() << "d8_preamble = " << d8_preamble;
}
