#ifndef DOMAIN8_H
#define DOMAIN8_H

#include <QDialog>

namespace Ui {
class domain8;
}

class domain8 : public QDialog
{
    Q_OBJECT

public:
    explicit domain8(QWidget *parent = 0);
    ~domain8();

signals:
    void sendConfigText(QString ConfigInfo);

private slots:
    void on_btnConfirm8_clicked();

private:
    Ui::domain8 *ui;
};

#endif // DOMAIN8_H
