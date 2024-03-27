#include "domain7.h"
#include "ui_domain7.h"
#include "dialog.h"
#include "ui_dialog.h"
#include <QDebug>

domain7::domain7(QDialog *parent) :
    QDialog(parent),
    ui(new Ui::domain7)
{
    ui->setupUi(this);
    ui->lEditpreamble->setText("101010101010101010101010");
    ui->lEditid->setText("0000000000000001");
    ui->lEdittype->setText("0111");
    ui->lEditrate1->setText("20");
    ui->lEditrate2->setText("1");
};

domain7::~domain7()
{
    delete ui;
}

void domain7::on_btnConfirm7_clicked()
{
    emit sendConfigText("domain7 参数配置完成");
    domain7::close();

    QString d7_preamble = "";
    QString d7_temp = "";

    d7_temp = ui->lEditpreamble->text();

    while (d7_temp.length() < 24) {
        d7_temp = '0' + d7_temp;
    }\
    d7_preamble += d7_temp;

    d7_temp = ui->lEditid->text();
    while (d7_preamble.length() < 16) {
        d7_temp = '0' + d7_temp;
    }
    d7_preamble += d7_temp;

    d7_temp = ui->lEdittype->text();
    while (d7_temp.length() < 4) {
        d7_temp = '0' + d7_temp;
    }
    d7_preamble += d7_temp;

    d7_temp = ui->lEditrate1->text();
//    qDebug() << "d7_temp = " << d7_temp << "  " << d7_temp.toFloat();
    double d7_temp1 = d7_temp.toFloat()/40 * pow(2,16);
//    qDebug() << "d7_temp1 = " << d7_temp1;
    int d7_int = (int)d7_temp1;
//    qDebug() << "d7_int = " << d7_int;
    d7_temp = QString::number( d7_int, 2);
    qDebug() << "d7_temp = " << d7_temp;
    while (d7_temp.length() < 16) {
        d7_temp = '0' + d7_temp;
    }
    d7_preamble += d7_temp;


    d7_temp = ui->lEditrate2->text();
//    qDebug() << "d7_temp = " << d7_temp << "  " << d7_temp.toFloat();
    d7_temp1 = d7_temp.toFloat()/40 * pow(2,16);
//    qDebug() << "d7_temp1 = " << d7_temp1;
    d7_int = (int)d7_temp1;
    d7_temp = QString::number( d7_int, 2);
//    qDebug() << "d7_temp = " << d7_temp;
    while (d7_temp.length() < 16) {
        d7_temp = '0' + d7_temp;
    }
    d7_preamble += d7_temp;


    while (d7_preamble.length() < 112) {
        d7_preamble = d7_preamble + '0';
    }

//    qDebug() << "d7 preamble length   " << d7_preamble.length();
    Dialog::SendData.resize(15);
    Dialog::SendData[0] = 0x01;
    for (int i = 1; i < 15; ++i) {
        qDebug() << "tobin   " << d7_preamble.mid((i - 1) * 8, 8);
        quint8 temp = BinToHex(d7_preamble.mid((i - 1) * 8, 8));
        qDebug() << temp;
        Dialog::SendData[i] = temp;

    }
//    qDebug() << Dialog::SendData.toHex();
    qDebug() << "Dialog::SendData = " << Dialog::SendData;
    qDebug() << "d7_preamble = " << d7_preamble;
}
