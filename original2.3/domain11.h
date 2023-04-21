#ifndef DOMAIN11_H
#define DOMAIN11_H

#include <QDialog>

namespace Ui {
class domain11;
}

class domain11 : public QDialog
{
    Q_OBJECT

public:
    explicit domain11(QDialog *parent = 0);
    ~domain11();

signals:
    void sendConfigText(QString ConfigInfo);

private slots:
    void on_btnConfirm11_clicked();

private:
    Ui::domain11 *ui;
};

#endif // DOMAIN11_H
