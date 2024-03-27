#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QSerialPort>
quint8 BinToHex(QString strBin);

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();
    bool getSerialPortConfig(void);
    static QString tag_ID;
    static QString setdata;
    static QByteArray SendData;

private slots:

    void on_btnOpen_clicked();

    void SerialPort_readyRead();

    void on_btnSend_clicked();

    void on_btnDomain6_clicked();

    void recvConfigText(QString ConfigInfo);

    void on_btnClearReceive_clicked();

    void on_btnClearSend_clicked();

    void on_btnDomain10_clicked();

    void on_btnDomain11_clicked();

    void on_btnDomain12_clicked();

    void on_btnDomain13_clicked();

    void on_btnDomain14_clicked();

    void on_EndConfigBtn_clicked();

    void on_btmDomain7_clicked();

    void on_btnDomain15_clicked();

    void on_btnDomain8_clicked();

    void on_btnDomain9_clicked();

    void on_clientsButton_clicked();

    void on_set_clicked();

private:
    Ui::Dialog *ui;

    QSerialPort mSerialPort;
    bool mIsOpen;
    QString mPortName;
    QString mBaudRate;
    QString mParity;
    QString mDataRate;
    QString mStopBits;
};

#endif // DIALOG_H
