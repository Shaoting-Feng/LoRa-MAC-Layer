#include "domain10.h"
#include "ui_domain10.h"
#include "dialog.h"
#include "ui_dialog.h"
#include <QDebug>

domain10::domain10(QDialog *parent) :
    QDialog(parent),
    ui(new Ui::domain10)
{
    ui->setupUi(this);
    ui->lEditPreamble->setText("101010101010101010101010");
    ui->lEditId->setText("0000000000000001");
    ui->lEditType->setText("1100");
    ui->lEditSyncPattern->setText("0000000000000000");
    ui->lEditSyncMask->setText("0000000000000000");
}

domain10::~domain10()
{
    delete ui;
}



void domain10::on_btnConfirm10_clicked()
{
    emit sendConfigText("domain10 参数配置完成");
    domain10::close();
    QString d10_temp = "";
    QString d10_preamble = "";

    d10_temp = ui->lEditPreamble->text();
    while (d10_temp.length() < 24) {
        d10_temp = '0' + d10_temp;
    }
    d10_preamble += d10_temp;


    d10_temp = ui->lEditId->text();
    while (d10_temp.length() < 16) {
        d10_temp = '0' + d10_temp;
    }
    d10_preamble += d10_temp;


    d10_temp = ui->lEditType->text();
    while (d10_temp.length() < 4) {
        d10_temp = '0' + d10_temp;
    }
    d10_preamble += d10_temp;


    d10_temp = ui->lEditSyncPattern->text();
    while (d10_temp.length() < 16) {
        d10_temp = '0' + d10_temp;
    }
    d10_preamble += d10_temp;


    d10_temp = ui->lEditSyncMask->text();
    while (d10_temp.length() < 16) {
        d10_temp = '0' + d10_temp;
    }
    d10_preamble += d10_temp;
    //    if (d10_preamble.length() > 112) {
//        qDebug() << "输入ram data数据过多";
//        return;
//    }
    while (d10_preamble.length() < 112) {
        d10_preamble = d10_preamble + '0';
    }
    Dialog::SendData.resize(15);
    Dialog::SendData[0] = 0x01;
    for (int i = 1; i < 15; ++i) {
        quint8 temp = BinToHex(d10_preamble.mid((i - 1) * 8, 8));
        Dialog::SendData[i] = temp;
    }
    qDebug() << "Dialog::SendData = " << Dialog::SendData;
    qDebug() << "d10_preamble = " << d10_preamble;

}
