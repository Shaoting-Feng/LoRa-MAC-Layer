#ifndef DOMAIN13_H
#define DOMAIN13_H

#include <QDialog>

namespace Ui {
class domain13;
}

class domain13 : public QDialog
{
    Q_OBJECT

public:
    explicit domain13(QDialog *parent = 0);
    ~domain13();

signals:
    void sendConfigText(QString ConfigInfo);

private slots:
    void on_btnConfirm13_clicked();

private:
    Ui::domain13 *ui;
};

#endif // DOMAIN13_H
