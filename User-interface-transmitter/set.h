#ifndef SET_H
#define SET_H

#include <QDialog>
namespace Ui {
class set;
}

class set : public QDialog
{
    Q_OBJECT

public:
    explicit set(QWidget *parent = 0);
    ~set();
private slots:
    void on_sure_button_clicked();
signals:
    void sendConfigText(QString ConfigInfo);

private:
    Ui::set *ui;
};

#endif // SET_H
