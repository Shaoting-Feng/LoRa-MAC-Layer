/********************************************************************************
** Form generated from reading UI file 'set.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SET_H
#define UI_SET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_set
{
public:
    QPushButton *ifbroadcast_y;
    QPushButton *ifbroadcast_n;
    QLabel *label;
    QLabel *label_2;
    QPushButton *if_setsleepmode_y;
    QPushButton *if_setsleepmode_n;
    QPushButton *sure_button;
    QLabel *label_3;
    QLabel *label_4;

    void setupUi(QWidget *set)
    {
        if (set->objectName().isEmpty())
            set->setObjectName(QStringLiteral("set"));
        set->resize(554, 219);
        ifbroadcast_y = new QPushButton(set);
        ifbroadcast_y->setObjectName(QStringLiteral("ifbroadcast_y"));
        ifbroadcast_y->setGeometry(QRect(200, 40, 93, 28));
        ifbroadcast_y->setCheckable(true);
        ifbroadcast_y->setChecked(false);
        ifbroadcast_y->setAutoExclusive(false);
        ifbroadcast_n = new QPushButton(set);
        ifbroadcast_n->setObjectName(QStringLiteral("ifbroadcast_n"));
        ifbroadcast_n->setGeometry(QRect(370, 40, 93, 28));
        ifbroadcast_n->setCheckable(true);
        ifbroadcast_n->setChecked(true);
        ifbroadcast_n->setAutoExclusive(false);
        label = new QLabel(set);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(40, 40, 101, 16));
        label_2 = new QLabel(set);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(40, 110, 101, 16));
        if_setsleepmode_y = new QPushButton(set);
        if_setsleepmode_y->setObjectName(QStringLiteral("if_setsleepmode_y"));
        if_setsleepmode_y->setGeometry(QRect(200, 110, 93, 28));
        if_setsleepmode_y->setCheckable(true);
        if_setsleepmode_y->setChecked(false);
        if_setsleepmode_y->setAutoExclusive(false);
        if_setsleepmode_n = new QPushButton(set);
        if_setsleepmode_n->setObjectName(QStringLiteral("if_setsleepmode_n"));
        if_setsleepmode_n->setGeometry(QRect(370, 110, 93, 28));
        if_setsleepmode_n->setCheckable(true);
        if_setsleepmode_n->setChecked(true);
        if_setsleepmode_n->setAutoExclusive(false);
        sure_button = new QPushButton(set);
        sure_button->setObjectName(QStringLiteral("sure_button"));
        sure_button->setGeometry(QRect(440, 170, 93, 28));
        label_3 = new QLabel(set);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(40, 60, 101, 16));
        label_4 = new QLabel(set);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(40, 130, 101, 16));

        retranslateUi(set);

        QMetaObject::connectSlotsByName(set);
    } // setupUi

    void retranslateUi(QWidget *set)
    {
        set->setWindowTitle(QApplication::translate("set", "Form", 0));
        ifbroadcast_y->setText(QApplication::translate("set", "\346\230\257", 0));
        ifbroadcast_n->setText(QApplication::translate("set", "\345\220\246", 0));
        label->setText(QApplication::translate("set", "\346\230\257\345\220\246\345\274\200\345\220\257\345\271\277\346\222\255", 0));
        label_2->setText(QApplication::translate("set", "\346\230\257\345\220\246\350\256\276\347\275\256\344\274\221\347\234\240", 0));
        if_setsleepmode_y->setText(QApplication::translate("set", "\346\230\257", 0));
        if_setsleepmode_n->setText(QApplication::translate("set", "\345\220\246", 0));
        sure_button->setText(QApplication::translate("set", "\347\241\256\345\256\232", 0));
        label_3->setText(QApplication::translate("set", " (\351\273\230\350\256\244\344\270\272\345\220\246)", 0));
        label_4->setText(QApplication::translate("set", " (\351\273\230\350\256\244\344\270\272\345\220\246)", 0));
    } // retranslateUi

};

namespace Ui {
    class set: public Ui_set {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SET_H
