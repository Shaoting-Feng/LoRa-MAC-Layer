#ifndef DOMAIN10_H
#define DOMAIN10_H

#include <QDialog>

namespace Ui {
class domain10;
}

class domain10 : public QDialog
{
    Q_OBJECT

public:
    explicit domain10(QDialog *parent = 0);
    ~domain10();
private slots:



    void on_btnConfirm10_clicked();

signals:
    void sendConfigText(QString ConfigInfo);

private:
    Ui::domain10 *ui;
};

#endif // DOMAIN10_H
