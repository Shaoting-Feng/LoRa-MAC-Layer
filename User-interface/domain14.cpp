#include "domain14.h"
#include "ui_domain14.h"
#include "dialog.h"
#include "ui_dialog.h"
#include <QDebug>

domain14::domain14(QDialog *parent) :
    QDialog(parent),
    ui(new Ui::domain14)
{
    ui->setupUi(this);
    ui->lEditPreamble->setText("101010101010101010101010");
    ui->lEditId->setText("0000000000000001");
    ui->lEditType->setText("1110");
    ui->lEditTagID->setText("0000000000000001");
}

domain14::~domain14()
{
    delete ui;
}

void domain14::on_btnConfirm14_clicked()
{
    emit sendConfigText("domain14 参数配置完成");
    domain14::close();
    QString d14_preamble = ui->lEditPreamble->text();
    while (d14_preamble.length() < 24) {
        d14_preamble = '0' + d14_preamble;
    }
    QString d14_tmp = ui->lEditId->text();
    while (d14_tmp.length() < 16) {
        d14_tmp = '0' + d14_tmp;
    }
    d14_preamble += d14_tmp;

    d14_tmp = ui->lEditType->text();
    while (d14_tmp.length() < 4) {
        d14_tmp = '0' + d14_tmp;
    }
    d14_preamble += d14_tmp;

    d14_tmp = ui->lEditTagID->text();
    while (d14_tmp.length() < 16) {
        d14_tmp = '0' + d14_tmp;
    }
    d14_preamble += d14_tmp;

    if (d14_preamble.length() > 112) {
        qDebug() << "输入ram data数据过多";
        return;
    }
    while (d14_preamble.length() < 112) {
        d14_preamble = d14_preamble + '0';
    }
    Dialog::SendData.resize(15);
    Dialog::SendData[0] = 0x01;
    for (int i = 1; i < 15; ++i) {
        quint8 temp = BinToHex(d14_preamble.mid((i - 1) * 8, 8));
        Dialog::SendData[i] = temp;
    }
    qDebug() << "Dialog::SendData = " << Dialog::SendData;

    qDebug() << "d14_preamble = " << d14_preamble;
}
