/********************************************************************************
** Form generated from reading UI file 'domain7.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DOMAIN7_H
#define UI_DOMAIN7_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_domain7
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lEditpreamble;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *lEditid;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *lEdittype;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QLineEdit *lEditrate1;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QLineEdit *lEditrate2;
    QPushButton *btnConfirm7;

    void setupUi(QWidget *domain7)
    {
        if (domain7->objectName().isEmpty())
            domain7->setObjectName(QStringLiteral("domain7"));
        domain7->resize(404, 316);
        verticalLayout = new QVBoxLayout(domain7);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(domain7);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        lEditpreamble = new QLineEdit(domain7);
        lEditpreamble->setObjectName(QStringLiteral("lEditpreamble"));

        horizontalLayout->addWidget(lEditpreamble);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(domain7);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        lEditid = new QLineEdit(domain7);
        lEditid->setObjectName(QStringLiteral("lEditid"));

        horizontalLayout_2->addWidget(lEditid);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_3 = new QLabel(domain7);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_3->addWidget(label_3);

        lEdittype = new QLineEdit(domain7);
        lEdittype->setObjectName(QStringLiteral("lEdittype"));

        horizontalLayout_3->addWidget(lEdittype);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_4 = new QLabel(domain7);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_4->addWidget(label_4);

        lEditrate1 = new QLineEdit(domain7);
        lEditrate1->setObjectName(QStringLiteral("lEditrate1"));

        horizontalLayout_4->addWidget(lEditrate1);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_5 = new QLabel(domain7);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_5->addWidget(label_5);

        lEditrate2 = new QLineEdit(domain7);
        lEditrate2->setObjectName(QStringLiteral("lEditrate2"));

        horizontalLayout_5->addWidget(lEditrate2);


        verticalLayout->addLayout(horizontalLayout_5);

        btnConfirm7 = new QPushButton(domain7);
        btnConfirm7->setObjectName(QStringLiteral("btnConfirm7"));

        verticalLayout->addWidget(btnConfirm7);


        retranslateUi(domain7);

        QMetaObject::connectSlotsByName(domain7);
    } // setupUi

    void retranslateUi(QWidget *domain7)
    {
        domain7->setWindowTitle(QApplication::translate("domain7", "Form", 0));
        label->setText(QApplication::translate("domain7", "preamble: ", 0));
        label_2->setText(QApplication::translate("domain7", "id: ", 0));
        label_3->setText(QApplication::translate("domain7", "type: ", 0));
        label_4->setText(QApplication::translate("domain7", "rate1: ", 0));
        label_5->setText(QApplication::translate("domain7", "rate2: ", 0));
        btnConfirm7->setText(QApplication::translate("domain7", "\347\241\256\345\256\232", 0));
    } // retranslateUi

};

namespace Ui {
    class domain7: public Ui_domain7 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DOMAIN7_H
