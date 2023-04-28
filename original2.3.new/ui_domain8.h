/********************************************************************************
** Form generated from reading UI file 'domain8.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DOMAIN8_H
#define UI_DOMAIN8_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_domain8
{
public:
    QWidget *widget;
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
    QLineEdit *lEditB2;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QLineEdit *lEditB1;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_6;
    QLineEdit *lEditB0;
    QPushButton *btnConfirm8;

    void setupUi(QDialog *domain8)
    {
        if (domain8->objectName().isEmpty())
            domain8->setObjectName(QStringLiteral("domain8"));
        domain8->resize(436, 353);
        widget = new QWidget(domain8);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(20, 10, 391, 321));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
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

        lEditB2 = new QLineEdit(widget);
        lEditB2->setObjectName(QStringLiteral("lEditB2"));

        horizontalLayout_4->addWidget(lEditB2);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_5 = new QLabel(widget);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_5->addWidget(label_5);

        lEditB1 = new QLineEdit(widget);
        lEditB1->setObjectName(QStringLiteral("lEditB1"));

        horizontalLayout_5->addWidget(lEditB1);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_6 = new QLabel(widget);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_6->addWidget(label_6);

        lEditB0 = new QLineEdit(widget);
        lEditB0->setObjectName(QStringLiteral("lEditB0"));

        horizontalLayout_6->addWidget(lEditB0);


        verticalLayout->addLayout(horizontalLayout_6);

        btnConfirm8 = new QPushButton(widget);
        btnConfirm8->setObjectName(QStringLiteral("btnConfirm8"));

        verticalLayout->addWidget(btnConfirm8);

        label->raise();
        lEditPreamble->raise();
        btnConfirm8->raise();
        lEditB2->raise();

        retranslateUi(domain8);

        QMetaObject::connectSlotsByName(domain8);
    } // setupUi

    void retranslateUi(QDialog *domain8)
    {
        domain8->setWindowTitle(QApplication::translate("domain8", "Dialog", 0));
        label->setText(QApplication::translate("domain8", "preamble: ", 0));
        label_2->setText(QApplication::translate("domain8", "id: ", 0));
        label_3->setText(QApplication::translate("domain8", "type: ", 0));
        label_4->setText(QApplication::translate("domain8", "B2: ", 0));
        label_5->setText(QApplication::translate("domain8", "B1: ", 0));
        label_6->setText(QApplication::translate("domain8", "B0: ", 0));
        btnConfirm8->setText(QApplication::translate("domain8", "\347\241\256\350\256\244", 0));
    } // retranslateUi

};

namespace Ui {
    class domain8: public Ui_domain8 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DOMAIN8_H
