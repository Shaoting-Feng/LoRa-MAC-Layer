#include "domain15.h"
#include "ui_domain15.h"
#include "dialog.h"
#include "ui_dialog.h"
#include <QDebug>
#include <cmath>
#include <qstring.h>


domain15::domain15(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::domain15)
{
    ui->setupUi(this);
    ui->lEditPreamble->setText("101010101010101010101010");
    ui->lEditID->setText("0000000000000001");
    ui->lEditType->setText("1111");
    ui->lEditMode->setText("1");
    ui->lEditDataLength->setText("10");
    ui->lEditSymbolLen->setText("11");
}

domain15::~domain15()
{
    delete ui;
}

void domain15::on_btnConfirm15_clicked()
{
    emit sendConfigText("domain15 参数配置完成");
    domain15::close();

    QString d15_tmp = "";
    QString d15_preamble = ui->lEditPreamble->text();
    while (d15_preamble.length() < 24) {
        d15_preamble = '0' + d15_preamble;
    }

    d15_tmp = ui->lEditID->text();
    while (d15_tmp.length() < 16) {
        d15_tmp = '0' + d15_tmp;
    }
    d15_preamble += d15_tmp;

    d15_tmp = ui->lEditType->text();
    while (d15_tmp.length() < 4) {
        d15_tmp = '0' + d15_tmp;
    }
    d15_preamble += d15_tmp;


    d15_tmp = ui->lEditMode->text();
    while (d15_tmp.length() < 1) {
        d15_tmp = '0' + d15_tmp;
    }
    d15_preamble += d15_tmp;

    d15_tmp = ui->lEditDataLength->text();
    int d15_tmp1 = d15_tmp.toInt();
    d15_tmp = QString::number( d15_tmp1, 2);
    while (d15_tmp.length() < 10) {
        d15_tmp = '0' + d15_tmp;
    }
    d15_preamble += d15_tmp;


    d15_tmp = ui->lEditSymbolLen->text();
    d15_tmp1 = d15_tmp.toInt();
    d15_tmp = QString::number( d15_tmp1, 2);
    while (d15_tmp.length() < 16) {
        d15_tmp = '0' + d15_tmp;
    }
    d15_preamble += d15_tmp;


    while (d15_preamble.length() < 112) {
        d15_preamble = d15_preamble + '0';
    }
    Dialog::SendData.resize(15);
    Dialog::SendData[0] = 0x01;
    for (int i = 1; i < 15; ++i) {
        quint8 temp = BinToHex(d15_preamble.mid((i - 1) * 8, 8));
        Dialog::SendData[i] = temp;
    }
    qDebug() << "Dialog::SendData = " << Dialog::SendData;

    qDebug() << "d15_preamble = " << d15_preamble;
}
