#ifndef CLIENTS_H
#define CLIENTS_H

#include <QDialog>
namespace Ui {
class clients;
}

class clients : public QDialog
{
    Q_OBJECT

public:
    explicit clients(QDialog *parent = 0);
    ~clients();
private slots:
    void on_pushButton_clicked();
    void on_pushButton2_clicked();
signals:
    void sendConfigText(QString ConfigInfo);

private:
    Ui::clients *ui;

};

#endif // CLIENTS_H
