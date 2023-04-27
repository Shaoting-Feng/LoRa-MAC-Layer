#include "domain11.h"
#include "ui_domain11.h"
#include <cmath>
#include "dialog.h"
#include "ui_dialog.h"
#include <QDebug>

domain11::domain11(QDialog *parent) :
    QDialog(parent),
    ui(new Ui::domain11)
{
    ui->setupUi(this);
    ui->lEditPreamble->setText("101010101010101010101010");
    ui->lEditId->setText("0000000000000001");
    ui->lEditType->setText("1011");
    ui->lEditSample->setText("2");
    ui->lEditSyncRate->setText("0.5");
}

domain11::~domain11()
{
    delete ui;
}

void domain11::on_btnConfirm11_clicked()
{
    emit sendConfigText("domain11 参数配置完成");
    domain11::close();

    QString d11_temp = "";
    QString d11_preamble = "";

    d11_temp = ui->lEditPreamble->text();
    while (d11_temp.length() < 24) {
        d11_temp = '0' + d11_temp;
    }
    d11_preamble += d11_temp;

    d11_temp = ui->lEditId->text();
    while (d11_temp.length() < 16) {
        d11_temp = '0' + d11_temp;
    }
    d11_preamble += d11_temp;


    d11_temp = ui->lEditType->text();
    while (d11_temp.length() < 4) {
        d11_temp = '0' + d11_temp;
    }
    d11_preamble += d11_temp;


    d11_temp = ui->lEditSample->text();
//    qDebug() << "d11_temp = " << d11_temp << "  " << d11_temp.toFloat();
    double d11_temp1 = d11_temp.toFloat()/40 * pow(2,16);
//    qDebug() << "d11_temp1 = " << d11_temp1;
    int d11_int = (int)d11_temp1;
//    qDebug() << "d11_int = " << d11_int;
    d11_temp = QString::number( d11_int, 2);
//    qDebug() << "d11_temp = " << d11_temp;
    while (d11_temp.length() < 16) {
        d11_temp = '0' + d11_temp;
    }
    d11_preamble += d11_temp;


    d11_temp = ui->lEditSyncRate->text();
//    qDebug() << "d11_temp = " << d11_temp << "  " << d11_temp.toFloat();
    d11_temp1 = d11_temp.toFloat()/2 * pow(2,10);
//    qDebug() << "d11_temp1 = " << d11_temp1;
    d11_int = (int)d11_temp1;
    d11_temp = QString::number( d11_int, 2);
//    qDebug() << "d11_temp = " << d11_temp;
    while (d11_temp.length() < 10) {
        d11_temp = '0' + d11_temp;
    }
    d11_preamble += d11_temp;

    while (d11_preamble.length() < 112) {
        d11_preamble = d11_preamble + '0';
    }
    Dialog::SendData.resize(15);
    Dialog::SendData[0] = 0x01;
    for (int i = 1; i < 15; ++i) {
        quint8 temp = BinToHex(d11_preamble.mid((i - 1) * 8, 8));
        Dialog::SendData[i] = temp;
    }
    qDebug() << "Dialog::SendData = " << Dialog::SendData;
    qDebug() << "d11_preamble = " << d11_preamble;
}
