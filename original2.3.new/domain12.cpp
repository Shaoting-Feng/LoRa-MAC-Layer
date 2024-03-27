#include "domain12.h"
#include "ui_domain12.h"
#include "dialog.h"
#include "ui_dialog.h"
#include <QDebug>


domain12::domain12(QDialog *parent) :
    QDialog(parent),
    ui(new Ui::domain12)
{
    ui->setupUi(this);
    ui->lEditPreamble->setText("101010101010101010101010");
    ui->lEditId->setText("0000000000000001");
    ui->lEditType->setText("1100");
    ui->lEditSymbol2->setText("0000000000000000");
}

domain12::~domain12()
{
    delete ui;
}

void domain12::on_btnConfirm12_clicked()
{
    emit sendConfigText("domain12 参数配置完成");
    domain12::close();
    QString d12_preamble = ui->lEditPreamble->text();
    while (d12_preamble.length() < 24) {
        d12_preamble = '0' + d12_preamble;
    }
    QString d12_tmp = ui->lEditId->text();
    while (d12_tmp.length() < 16) {
        d12_tmp = '0' + d12_tmp;
    }
    d12_preamble += d12_tmp;

    d12_tmp = ui->lEditType->text();
    while (d12_tmp.length() < 4) {
        d12_tmp = '0' + d12_tmp;
    }
    d12_preamble += d12_tmp;

    d12_tmp = ui->lEditSymbol2->text();
    while (d12_tmp.length() < 64) {
        d12_tmp = '0' + d12_tmp;
    }
    d12_preamble += d12_tmp;

    if (d12_preamble.length() > 112) {
        qDebug() << "输入ram data数据过多";
        return;
    }
    while (d12_preamble.length() < 112) {
        d12_preamble = d12_preamble + '0';
    }

    Dialog::SendData.resize(15);
    Dialog::SendData[0] = 0x01;
    for (int i = 1; i < 15; ++i) {
        quint8 temp = BinToHex(d12_preamble.mid((i - 1) * 8, 8));
        Dialog::SendData[i] = temp;
    }

    qDebug() << "Dialog::SendData = " << Dialog::SendData;

    qDebug() << "d12_preamble = " << d12_preamble;
}
