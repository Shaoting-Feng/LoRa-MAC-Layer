#include "domain13.h"
#include "ui_domain13.h"
#include "dialog.h"
#include "ui_dialog.h"
#include <QDebug>

domain13::domain13(QDialog *parent) :
    QDialog(parent),
    ui(new Ui::domain13)
{
    ui->setupUi(this);
    ui->lEditPreamble->setText("101010101010101010101010");
    ui->lEditId->setText("0000000000000001");
    ui->lEditType->setText("1101");
    ui->lEditSymbol1->setText("1");
}

domain13::~domain13()
{
    delete ui;
}

void domain13::on_btnConfirm13_clicked()
{
    emit sendConfigText("domain13 参数配置完成");
    domain13::close();
    QString d13_preamble = ui->lEditPreamble->text();
    while (d13_preamble.length() < 24) {
        d13_preamble = '0' + d13_preamble;
    }
    QString d13_tmp = ui->lEditId->text();
    while (d13_tmp.length() < 16) {
        d13_tmp = '0' + d13_tmp;
    }
    d13_preamble += d13_tmp;

    d13_tmp = ui->lEditType->text();
    while (d13_tmp.length() < 4) {
        d13_tmp = '0' + d13_tmp;
    }
    d13_preamble += d13_tmp;

    d13_tmp = ui->lEditSymbol1->text();
    while (d13_tmp.length() < 64) {
        d13_tmp = '0' + d13_tmp;
    }
    d13_preamble += d13_tmp;

    if (d13_preamble.length() > 112) {
        qDebug() << "输入ram data数据过多";
        return;
    }
    while (d13_preamble.length() < 112) {
        d13_preamble = d13_preamble + '0';
    }
    Dialog::SendData.resize(15);
    Dialog::SendData[0] = 0x01;
    for (int i = 1; i < 15; ++i) {
        quint8 temp = BinToHex(d13_preamble.mid((i - 1) * 8, 8));
        Dialog::SendData[i] = temp;
    }
    qDebug() << "Dialog::SendData = " << Dialog::SendData;

    qDebug() << "d13_preamble = " << d13_preamble;
}
