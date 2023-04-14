/********************************************************************************
** Form generated from reading UI file 'domain11.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DOMAIN11_H
#define UI_DOMAIN11_H

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

class Ui_domain11
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lEditPreamble;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *lEditId;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *lEditType;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QLineEdit *lEditSample;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QLineEdit *lEditSyncRate;
    QPushButton *btnConfirm11;

    void setupUi(QWidget *domain11)
    {
        if (domain11->objectName().isEmpty())
            domain11->setObjectName(QStringLiteral("domain11"));
        domain11->resize(453, 349);
        widget = new QWidget(domain11);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(10, 10, 431, 331));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        lEditPreamble = new QLineEdit(widget);
        lEditPreamble->setObjectName(QStringLiteral("lEditPreamble"));

        horizontalLayout->addWidget(lEditPreamble);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        lEditId = new QLineEdit(widget);
        lEditId->setObjectName(QStringLiteral("lEditId"));

        horizontalLayout_2->addWidget(lEditId);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_3 = new QLabel(widget);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_3->addWidget(label_3);

        lEditType = new QLineEdit(widget);
        lEditType->setObjectName(QStringLiteral("lEditType"));

        horizontalLayout_3->addWidget(lEditType);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_4 = new QLabel(widget);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_4->addWidget(label_4);

        lEditSample = new QLineEdit(widget);
        lEditSample->setObjectName(QStringLiteral("lEditSample"));

        horizontalLayout_4->addWidget(lEditSample);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_5 = new QLabel(widget);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_5->addWidget(label_5);

        lEditSyncRate = new QLineEdit(widget);
        lEditSyncRate->setObjectName(QStringLiteral("lEditSyncRate"));

        horizontalLayout_5->addWidget(lEditSyncRate);


        verticalLayout->addLayout(horizontalLayout_5);


        verticalLayout_2->addLayout(verticalLayout);

        btnConfirm11 = new QPushButton(widget);
        btnConfirm11->setObjectName(QStringLiteral("btnConfirm11"));

        verticalLayout_2->addWidget(btnConfirm11);


        retranslateUi(domain11);

        QMetaObject::connectSlotsByName(domain11);
    } // setupUi

    void retranslateUi(QWidget *domain11)
    {
        domain11->setWindowTitle(QApplication::translate("domain11", "Form", 0));
        label->setText(QApplication::translate("domain11", "preamble :", 0));
        lEditPreamble->setInputMask(QApplication::translate("domain11", "bbbbbbbbbbbbbbbbbbbbbbbb", 0));
        label_2->setText(QApplication::translate("domain11", "id :", 0));
        lEditId->setInputMask(QApplication::translate("domain11", "bbbbbbbbbbbbbbbb", 0));
        label_3->setText(QApplication::translate("domain11", "type :", 0));
        lEditType->setInputMask(QApplication::translate("domain11", "bbbb", 0));
        label_4->setText(QApplication::translate("domain11", "sample(MHz) : ", 0));
        lEditSample->setInputMask(QString());
        label_5->setText(QApplication::translate("domain11", "sync rate(MHz) : ", 0));
        lEditSyncRate->setInputMask(QString());
        btnConfirm11->setText(QApplication::translate("domain11", "\347\241\256\345\256\232", 0));
    } // retranslateUi

};

namespace Ui {
    class domain11: public Ui_domain11 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DOMAIN11_H
