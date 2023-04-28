#ifndef DOMAIN12_H
#define DOMAIN12_H

#include <QDialog>

namespace Ui {
class domain12;
}

class domain12 : public QDialog
{
    Q_OBJECT

public:
    explicit domain12(QDialog *parent = 0);
    ~domain12();

signals:
    void sendConfigText(QString ConfigInfo);

private slots:
    void on_btnConfirm12_clicked();

private:
    Ui::domain12 *ui;
};

#endif // DOMAIN12_H
