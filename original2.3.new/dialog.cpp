#include "dialog.h"
#include "ui_dialog.h"
#include "domain6.h"
#include "domain7.h"
#include "domain8.h"
#include "domain9.h"
#include "domain10.h"
#include "domain11.h"
#include "domain12.h"
#include "domain13.h"
#include "domain14.h"
#include "domain15.h"
//添加的库文件
#include "clients.h"
#include "set.h"
//
#include <QDebug>
#include <QSerialPortInfo>
#include <QList>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    //初始化，设置串口为关闭状态
    mIsOpen = false;

    //智能识别当前系统的有效串口号
    QList<QSerialPortInfo> serialPortInfo = QSerialPortInfo::availablePorts();
    int count = serialPortInfo.count();
    for (int i = 0; i < count; ++i) {
        ui->cBoxSerialPort->addItem(serialPortInfo.at(i).portName());
    }

    //连接串口的接收模块
    connect(&mSerialPort, SIGNAL(readyRead()), this, SLOT(SerialPort_readyRead()));

    //设置最小化和关闭按钮
    this->setWindowFlags(Qt::Dialog | Qt::WindowMinimizeButtonHint | Qt::WindowCloseButtonHint);
     }
 //


Dialog::~Dialog()
{
    delete ui;
}



void Dialog::on_btnOpen_clicked()
{
    if (mIsOpen == true) {
        //当前串口助手已打开，执行关闭动作
        mSerialPort.close();
        ui->btnOpen->setText("打开");
        mIsOpen = false;

        qDebug() << "成功关闭串口";

        ui->btnSend->setEnabled(false);
        ui->cBoxSerialPort->setEnabled(true);
    } else {
        //当前串口没有打开，执行打开动作
        if (true == getSerialPortConfig()) {
            mIsOpen = true;
            ui->btnOpen->setText("关闭");

            qDebug() << "成功打开串口" << mPortName;

            ui->btnSend->setEnabled(true);
            ui->cBoxSerialPort->setEnabled(false);
        } /*else {
            mIsOpen = false;
        }*/
    }
}


bool Dialog::getSerialPortConfig(void) {
    //获取串口配置
    mPortName = ui->cBoxSerialPort->currentText();
    //设置串口配置

    //端口号
    mSerialPort.setPortName(mPortName);

    //波特率
    mSerialPort.setBaudRate(QSerialPort::Baud115200);

    //校验位
    mSerialPort.setParity(QSerialPort::NoParity);

    //数据位
    mSerialPort.setDataBits(QSerialPort::Data8);

    //停止位
    mSerialPort.setStopBits(QSerialPort::OneStop);

    return mSerialPort.open(QSerialPort::ReadWrite);
}

void Dialog::on_btnSend_clicked()
{
    if (mIsOpen == true) {
//add by zc
    tag_ID.append(setdata);
    tag_ID.append("00");
    while (tag_ID.length() < 8) {
        tag_ID = '0' + tag_ID;
    }
    qDebug()<<"tag_ID type 00 is:"<<tag_ID;
        SendData.resize(16);
        for (int i = 14; i >=0;i=i-1) {
            SendData[i+1] = SendData[i];
        }
       SendData[0] = BinToHex(tag_ID);
   //   if(tag_ID=="00110000") SendData[0]=0x30;
   //   else SendData[0]=0x01;
       // qDebug()<<temp;
        qDebug()<<"senddata is:"<<SendData;
        qDebug()<<"SendData[0]"<<SendData[0];
        mSerialPort.write(SendData);
        tag_ID=tag_ID.mid(0,4);
        for (int i = 0; i <15;i++) {
            SendData[i] = SendData[i+1];
        }
        SendData.resize(15);

//        mSerialPort.write(ui->tEditSend->toPlainText().toStdString().c_str());
    }
}

void Dialog::SerialPort_readyRead() {
    if (mIsOpen == true) {
        QByteArray recvData = mSerialPort.readAll();

        ui->tEditReceived->append(QString(recvData));
    }
}



void Dialog::recvConfigText(QString ConfigInfo) {
    ui->tEditSend->append(ConfigInfo);
}

void Dialog::on_btnClearReceive_clicked()
{
    ui->tEditReceived->clear();
}

void Dialog::on_btnClearSend_clicked()
{
    ui->tEditSend->clear();
}

//add clients connection
//connect(button, &QPushbutton::clicked, this, [=](){myslot(int i, int j);});

//add by sfp&zc
void Dialog::on_clientsButton_clicked()
{
    clients *clientsWindow = new clients(this);
    clientsWindow->open();
    ui->tEditSend->append("tag ID参数正在配置......");
    //连接各个配置模块和接受text框
    connect(clientsWindow, &clients::sendConfigText, this, &Dialog::recvConfigText);

}
//add by zc
void Dialog::on_set_clicked()
{
    set *setWindow = new set(this);
    setWindow->open();
    ui->tEditSend->append("正在配置相关参数......");
    //连接各个配置模块和接受text框
    connect(setWindow, &set::sendConfigText, this, &Dialog::recvConfigText);

}

void Dialog::on_btnDomain6_clicked()
{
    domain6 *domain6configWindow = new domain6(this);
    domain6configWindow->open();

    ui->tEditSend->append("domain6 参数正在配置......");
    //连接各个配置模块和接受text框
    connect(domain6configWindow, &domain6::sendConfigText, this, &Dialog::recvConfigText);
}

void Dialog::on_btmDomain7_clicked()
{
    domain7 *domain7configWindow = new domain7(this);
    domain7configWindow->open();

    ui->tEditSend->append("domain7 参数正在配置......");
    //连接各个配置模块和接受text框
    connect(domain7configWindow, &domain7::sendConfigText, this, &Dialog::recvConfigText);
}

void Dialog::on_btnDomain8_clicked()
{
    domain8 *domain8configWindow = new domain8(this);
    domain8configWindow->open();

    ui->tEditSend->append("domain8 参数正在配置......");
    //连接各个配置模块和接受text框
    connect(domain8configWindow, &domain8::sendConfigText, this, &Dialog::recvConfigText);
}

void Dialog::on_btnDomain9_clicked()
{
    domain9 *domain9configWindow = new domain9(this);
    domain9configWindow->open();

    ui->tEditSend->append("domain9 参数正在配置......");
    //连接各个配置模块和接受text框
    connect(domain9configWindow, &domain9::sendConfigText, this, &Dialog::recvConfigText);
}


void Dialog::on_btnDomain10_clicked()
{
    domain10 *domain10configWindow = new domain10(this);
    //在未关闭状态不可修改主窗口
    domain10configWindow->open();

    ui->tEditSend->append("domain10 参数正在配置......");
    //连接各个配置模块和接受text框
    connect(domain10configWindow, &domain10::sendConfigText, this, &Dialog::recvConfigText);
}

void Dialog::on_btnDomain11_clicked()
{
    domain11 *domain11configWindow = new domain11(this);
    domain11configWindow->open();

    ui->tEditSend->append("domain11 参数正在配置......");
    //连接各个配置模块和接受text框
    connect(domain11configWindow, &domain11::sendConfigText, this, &Dialog::recvConfigText);

}

void Dialog::on_btnDomain12_clicked()
{
    domain12 *domain12configWindow = new domain12(this);
    domain12configWindow->open();

    ui->tEditSend->append("domain12 参数正在配置......");
    //连接各个配置模块和接受text框
    connect(domain12configWindow, &domain12::sendConfigText, this, &Dialog::recvConfigText);

}

void Dialog::on_btnDomain13_clicked()
{
    domain13 *domain13configWindow = new domain13(this);
    domain13configWindow->open();

    ui->tEditSend->append("domain13 参数正在配置......");
    //连接各个配置模块和接受text框
    connect(domain13configWindow, &domain13::sendConfigText, this, &Dialog::recvConfigText);

}

void Dialog::on_btnDomain14_clicked()
{
    domain14 *domain14configWindow = new domain14(this);
    domain14configWindow->open();

    ui->tEditSend->append("domain14 参数正在配置......");
    //连接各个配置模块和接受text框
    connect(domain14configWindow, &domain14::sendConfigText, this, &Dialog::recvConfigText);

}

void Dialog::on_btnDomain15_clicked()
{
    domain15 *domain15configWindow = new domain15(this);
    domain15configWindow->open();

    ui->tEditSend->append("domain15 参数正在配置......");
    //连接各个配置模块和接受text框
    connect(domain15configWindow, &domain15::sendConfigText, this, &Dialog::recvConfigText);

}

void Dialog::on_EndConfigBtn_clicked()
{
    ui->tEditSend->append("结束配置(点击发送后生效)......");
    Dialog::SendData.resize(15);
    Dialog::SendData[0] = 0xff;
    for (int i = 1; i < 15; ++i) {
        Dialog::SendData[i] = 0x00;
    }
    qDebug() << "Dialog::SendData = " << Dialog::SendData;
}

//二进制Qstring类型转换为16进制QBytearray类型函数
quint8 BinToHex(QString strBin)
{
    quint8 ret = 0x00;
    if (strBin.length() != 8) {
        qDebug() << "传入函数BinToHex的参数不对！";
        return ret;
    }

    QString strH,strL;
    strH = strBin.mid(0,4);
    strL = strBin.mid(4,4);
    if(strH == "1111") {
        ret += 0xf0;
    }
    else if (strH  == "1110" ) {
        ret += 0xe0;
    }
    else if (strH  == "1101" ) {
        ret += 0xd0;
    }
    else if (strH  == "1100" ) {
        ret += 0xc0;
     }
    else if (strH  == "1011" ) {
        ret += 0xb0;
     }
    else if (strH  == "1010" ) {
        ret += 0xa0;
     }
    else if (strH  == "1001" ) {
        ret += 0x90;
     }
    else if (strH  == "1000" ) {
       ret += 0x80;
     }
    else if (strH  == "0111" ) {
      ret += 0x70;
     }
    else if (strH  == "0110" ) {
      ret += 0x60;
     }
    else if (strH  == "0101" ) {
      ret += 0x50;
     }
    else if (strH  == "0100" ) {
     ret += 0x40;
    }
    else if (strH  == "0011" ) {
     ret += 0x30;
     }
    else if (strH  == "0010" ) {
        ret += 0x20;
     }
    else if (strH  == "0001" ) {
        ret += 0x10;
     }
    else if (strH  == "0000" ) {
        ret += 0x00;
    }

    if(strL == "1111") {
        ret += 0x0f;
    }
    else if (strL  == "1110" ) {
        ret += 0x0e;
    }
    else if (strL  == "1101" ) {
        ret += 0x0d;
    }
    else if (strL  == "1100" ) {
        ret += 0x0c;
     }
    else if (strL  == "1011" ) {
        ret += 0x0b;
     }
    else if (strL  == "1010" ) {
        ret += 0x0a;
     }
    else if (strL  == "1001" ) {
        ret += 0x09;
     }
    else if (strL  == "1000" ) {
       ret += 0x08;
     }
    else if (strL  == "0111" ) {
      ret += 0x07;
     }
    else if (strL  == "0110" ) {
      ret += 0x06;
     }
    else if (strL  == "0101" ) {
      ret += 0x05;
     }
    else if (strL  == "0100" ) {
     ret += 0x04;
    }
    else if (strL  == "0011" ) {
     ret += 0x03;
     }
    else if (strL  == "0010" ) {
        ret += 0x02;
     }
    else if (strL  == "0001" ) {
        ret += 0x01;
     }
    else if (strL  == "0000" ) {
        ret += 0x00;
    }
qDebug()<<ret;
    return ret;
}












