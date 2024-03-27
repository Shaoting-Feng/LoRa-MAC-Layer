#ifndef DOMAIN9_H
#define DOMAIN9_H

#include <QDialog>

namespace Ui {
class domain9;
}

class domain9 : public QDialog
{
    Q_OBJECT

public:
    explicit domain9(QWidget *parent = 0);
    ~domain9();
signals:
    void sendConfigText(QString ConfigInfo);

private slots:
    void on_btnConfirm9_clicked();

private:
    Ui::domain9 *ui;
};

#endif // DOMAIN9_H
