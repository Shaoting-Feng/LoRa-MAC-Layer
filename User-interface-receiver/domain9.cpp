#include "domain9.h"
#include "ui_domain9.h"
#include "dialog.h"
#include "ui_dialog.h"
#include <QDebug>

domain9::domain9(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::domain9)
{
    ui->setupUi(this);
    ui->lEditPreamble->setText("101010101010101010101010");
    ui->lEditId->setText("0000000000000001");
    ui->lEditType->setText("1001");\
    ui->lEditA2->setText("1 2");
    ui->lEditA1->setText("1 2");
    ui->lEditA0->setText("0.5");
}

domain9::~domain9()
{
    delete ui;
}

void domain9::on_btnConfirm9_clicked()
{
    emit sendConfigText("domain9 参数配置完成");
    domain9::close();

    QString d9_tmp = "";
    QString d9_preamble = ui->lEditPreamble->text();
    while (d9_preamble.length() < 24) {
        d9_preamble = '0' + d9_preamble;
    }

    d9_tmp = ui->lEditId->text();
    while (d9_tmp.length() < 16) {
        d9_tmp = '0' + d9_tmp;
    }
    d9_preamble += d9_tmp;

    d9_tmp = ui->lEditType->text();
    while (d9_tmp.length() < 4) {
        d9_tmp = '0' + d9_tmp;
    }
    d9_preamble += d9_tmp;


    QStringList d9blist = ui->lEditA2->text().split(" ");
    qDebug() << d9blist[0].toFloat() << d9blist[1].toInt() << pow(d9blist[1].toInt(), 2);

    double d9_tmp1 = d9blist[0].toFloat() / pow(d9blist[1].toInt(), 2) * pow(2, 16);
    qDebug() << "d9_tmp1    " << d9_tmp1;
    int d9_int = (int)d9_tmp1;
    qDebug() << "d9_int   " << d9_int;
    d9_tmp = QString::number(d9_int, 2);
    qDebug() << "d9_tmp" << d9_tmp << d9_tmp.length();
    while (d9_tmp.length() < 16) {
        d9_tmp = d9_tmp + '0';
    }
    qDebug() << "d9_tmp" << d9_tmp;
    d9_preamble += d9_tmp;


    d9blist = ui->lEditA1->text().split(" ");
    d9_tmp1 = d9blist[0].toFloat() / pow(d9blist[1].toInt(), 1) * pow(2, 16);
    d9_int = (int)d9_tmp1;
    d9_tmp = QString::number(d9_int, 2);
    while (d9_tmp.length() < 16) {
        d9_tmp = d9_tmp + '0';
    }
    d9_preamble += d9_tmp;

    d9_tmp = ui->lEditA0->text();
    d9_tmp1 = d9_tmp.toFloat()/2 * pow(2,16);
    d9_int = (int)d9_tmp1;
    d9_tmp = QString::number(d9_int, 2);
    while (d9_tmp.length() < 16) {
        d9_tmp = '0' + d9_tmp;
    }
    d9_preamble += d9_tmp;

//    double d7_temp1 = d7_temp.toFloat()/40 * pow(2,16);
//    qDebug() << "d7_temp1 = " << d7_temp1;
//    int d7_int = (int)d7_temp1;
//    qDebug() << "d7_int = " << d7_int;
//      d7_temp = QString::number( d7_int, 2);


    if (d9_preamble.length() > 112) {
        qDebug() << "输入ram data数据过多";
        return;
    }
    while (d9_preamble.length() < 112) {
        d9_preamble = d9_preamble + '0';
    }
    Dialog::SendData.resize(15);
    Dialog::SendData[0] = 0x01;
    for (int i = 1; i < 15; ++i) {
        quint8 temp = BinToHex(d9_preamble.mid((i - 1) * 8, 8));
        Dialog::SendData[i] = temp;
    }
    qDebug() << "Dialog::SendData = " << Dialog::SendData;

    qDebug() << "d9_preamble = " << d9_preamble;
}
