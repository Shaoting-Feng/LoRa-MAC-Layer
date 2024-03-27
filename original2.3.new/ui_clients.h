/********************************************************************************
** Form generated from reading UI file 'clients.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIENTS_H
#define UI_CLIENTS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_clients
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QPushButton *pushButton;
    QPushButton *pushButton2;
    QLineEdit *ObjectNum;
    QMenuBar *menubar;

    void setupUi(QWidget *clients)
    {
        if (clients->objectName().isEmpty())
            clients->setObjectName(QStringLiteral("clients"));
        clients->resize(641, 378);
        centralwidget = new QWidget(clients);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        centralwidget->setGeometry(QRect(10, 10, 630, 301));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(100, 90, 141, 41));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(330, 170, 151, 51));
        pushButton2 = new QPushButton(centralwidget);
        pushButton2->setObjectName(QStringLiteral("pushButton2"));
        pushButton2->setGeometry(QRect(130, 170, 151, 51));
        ObjectNum = new QLineEdit(centralwidget);
        ObjectNum->setObjectName(QStringLiteral("ObjectNum"));
        ObjectNum->setGeometry(QRect(250, 100, 290, 21));
        menubar = new QMenuBar(clients);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 641, 26));

        retranslateUi(clients);

        QMetaObject::connectSlotsByName(clients);
    } // setupUi

    void retranslateUi(QWidget *clients)
    {
        clients->setWindowTitle(QApplication::translate("clients", "MainWindow", 0));
        label->setText(QApplication::translate("clients", "\350\257\267\350\276\223\345\205\245\345\257\271\350\261\241\347\274\226\345\217\267\357\274\232", 0));
        pushButton->setText(QApplication::translate("clients", "\347\241\256\345\256\232", 0));
        pushButton2->setText(QApplication::translate("clients", "\346\270\205\347\251\272", 0));
        ObjectNum->setInputMask(QApplication::translate("clients", "bbbb", 0));
    } // retranslateUi

};

namespace Ui {
    class clients: public Ui_clients {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENTS_H
