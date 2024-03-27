#ifndef DOMAIN7_H
#define DOMAIN7_H

#include <QDialog>

namespace Ui {
class domain7;
}

class domain7 : public QDialog
{
    Q_OBJECT

public:
    explicit domain7(QDialog *parent = 0);
    ~domain7();

signals:
    void sendConfigText(QString ConfigInfo);

private slots:
    void on_btnConfirm7_clicked();


private:
    Ui::domain7 *ui;
};

#endif // DOMAIN7_H
