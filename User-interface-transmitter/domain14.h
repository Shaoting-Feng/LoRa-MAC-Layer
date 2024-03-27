#ifndef DOMAIN14_H
#define DOMAIN14_H

#include <QDialog>

namespace Ui {
class domain14;
}

class domain14 : public QDialog
{
    Q_OBJECT

public:
    explicit domain14(QDialog *parent = 0);
    ~domain14();

signals:
    void sendConfigText(QString ConfigInfo);

private slots:
    void on_btnConfirm14_clicked();

private:
    Ui::domain14 *ui;
};

#endif // DOMAIN14_H
