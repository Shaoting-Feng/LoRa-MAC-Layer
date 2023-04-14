#ifndef DOMAIN6_H
#define DOMAIN6_H

#include <QDialog>

namespace Ui {
class domain6;
}

class domain6 : public QDialog
{
    Q_OBJECT

public:
    explicit domain6(QDialog *parent = 0);
    ~domain6();

private slots:
//    void on_pushButton_clicked();

    void on_btnConfirm6_clicked();

signals:
    void sendConfigText(QString ConfigInfo);

private:
    Ui::domain6 *ui;
};

#endif // DOMAIN6_H
