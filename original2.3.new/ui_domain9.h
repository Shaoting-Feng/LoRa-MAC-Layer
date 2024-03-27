/********************************************************************************
** Form generated from reading UI file 'domain9.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DOMAIN9_H
#define UI_DOMAIN9_H

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

class Ui_domain9
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
    QLineEdit *lEditA2;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QLineEdit *lEditA1;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_6;
    QLineEdit *lEditA0;
    QPushButton *btnConfirm9;

    void setupUi(QDialog *domain9)
    {
        if (domain9->objectName().isEmpty())
            domain9->setObjectName(QStringLiteral("domain9"));
        domain9->resize(541, 442);
        widget = new QWidget(domain9);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(40, 20, 441, 391));
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

        lEditA2 = new QLineEdit(widget);
        lEditA2->setObjectName(QStringLiteral("lEditA2"));

        horizontalLayout_4->addWidget(lEditA2);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_5 = new QLabel(widget);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_5->addWidget(label_5);

        lEditA1 = new QLineEdit(widget);
        lEditA1->setObjectName(QStringLiteral("lEditA1"));

        horizontalLayout_5->addWidget(lEditA1);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_6 = new QLabel(widget);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_6->addWidget(label_6);

        lEditA0 = new QLineEdit(widget);
        lEditA0->setObjectName(QStringLiteral("lEditA0"));

        horizontalLayout_6->addWidget(lEditA0);


        verticalLayout->addLayout(horizontalLayout_6);

        btnConfirm9 = new QPushButton(widget);
        btnConfirm9->setObjectName(QStringLiteral("btnConfirm9"));

        verticalLayout->addWidget(btnConfirm9);


        retranslateUi(domain9);

        QMetaObject::connectSlotsByName(domain9);
    } // setupUi

    void retranslateUi(QDialog *domain9)
    {
        domain9->setWindowTitle(QApplication::translate("domain9", "Dialog", 0));
        label->setText(QApplication::translate("domain9", "preamble: ", 0));
        label_2->setText(QApplication::translate("domain9", "id : ", 0));
        label_3->setText(QApplication::translate("domain9", "type: ", 0));
        label_4->setText(QApplication::translate("domain9", "A2 : ", 0));
        label_5->setText(QApplication::translate("domain9", "A1 : ", 0));
        label_6->setText(QApplication::translate("domain9", "A0 : ", 0));
        btnConfirm9->setText(QApplication::translate("domain9", "\347\241\256\345\256\232", 0));
    } // retranslateUi

};

namespace Ui {
    class domain9: public Ui_domain9 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DOMAIN9_H
