#include "domain6.h"
#include "ui_domain6.h"
#include "dialog.h"
#include "ui_dialog.h"
#include <QDebug>


QByteArray Dialog::SendData;

domain6::domain6(QDialog *parent) :
    QDialog(parent),
    ui(new Ui::domain6)
{
    ui->setupUi(this);

    ui->lEditPreamble->setText("101010101010101010101010");

    ui->lEditId->setText("0000000000000001");

    ui->lEditType->setText("0110");
    ui->lEditRamData->setText("1");

}

domain6::~domain6()
{
    delete ui;
}



void domain6::on_btnConfirm6_clicked()
{
    emit sendConfigText("domain6 参数配置完成");
    domain6::close();

    QString d6_tmp = "";
    QString d6_preamble = ui->lEditPreamble->text();
    while (d6_preamble.length() < 24) {
        d6_preamble = '0' + d6_preamble;
    }

    d6_tmp = ui->lEditId->text();
    while (d6_tmp.length() < 16) {
        d6_tmp = '0' + d6_tmp;
    }
    d6_preamble += d6_tmp;

    d6_tmp = ui->lEditType->text();
    while (d6_tmp.length() < 4) {
        d6_tmp = '0' + d6_tmp;
    }
    d6_preamble += d6_tmp;

    d6_preamble = d6_preamble + ui->lEditRamData->text();

    if (d6_preamble.length() > 112) {
        qDebug() << "输入ram data数据过多";
        return;
    }
    while (d6_preamble.length() < 112) { // 112 = 8 * 14
        d6_preamble = d6_preamble + '0';
    }
    Dialog::SendData.resize(15);
    Dialog::SendData[0] = 0x01;
    for (int i = 1; i < 15; ++i) {
        quint8 temp = BinToHex(d6_preamble.mid((i - 1) * 8, 8));
        Dialog::SendData[i] = temp;
    }
    qDebug() << "Dialog::SendData = " << Dialog::SendData;

    qDebug() << "d6_preamble = " << d6_preamble;
}

