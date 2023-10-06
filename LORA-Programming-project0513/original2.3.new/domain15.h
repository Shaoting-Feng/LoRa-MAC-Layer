#ifndef DOMAIN15_H
#define DOMAIN15_H

#include <QDialog>

namespace Ui {
class domain15;
}

class domain15 : public QDialog
{
    Q_OBJECT

public:
    explicit domain15(QWidget *parent = 0);
    ~domain15();

signals:
    void sendConfigText(QString ConfigInfo);

private slots:
    void on_btnConfirm15_clicked();

private:
    Ui::domain15 *ui;
};

#endif // DOMAIN15_H
