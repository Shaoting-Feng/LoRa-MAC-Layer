/********************************************************************************
** Form generated from reading UI file 'domain15.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DOMAIN15_H
#define UI_DOMAIN15_H

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

class Ui_domain15
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lEditPreamble;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *lEditID;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *lEditType;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QLineEdit *lEditMode;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QLineEdit *lEditDataLength;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_6;
    QLineEdit *lEditSymbolLen;
    QPushButton *btnConfirm15;

    void setupUi(QDialog *domain15)
    {
        if (domain15->objectName().isEmpty())
            domain15->setObjectName(QStringLiteral("domain15"));
        domain15->resize(416, 339);
        widget = new QWidget(domain15);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(20, 20, 391, 301));
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

        lEditID = new QLineEdit(widget);
        lEditID->setObjectName(QStringLiteral("lEditID"));

        horizontalLayout_2->addWidget(lEditID);


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

        lEditMode = new QLineEdit(widget);
        lEditMode->setObjectName(QStringLiteral("lEditMode"));

        horizontalLayout_4->addWidget(lEditMode);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_5 = new QLabel(widget);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_5->addWidget(label_5);

        lEditDataLength = new QLineEdit(widget);
        lEditDataLength->setObjectName(QStringLiteral("lEditDataLength"));

        horizontalLayout_5->addWidget(lEditDataLength);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_6 = new QLabel(widget);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_6->addWidget(label_6);

        lEditSymbolLen = new QLineEdit(widget);
        lEditSymbolLen->setObjectName(QStringLiteral("lEditSymbolLen"));

        horizontalLayout_6->addWidget(lEditSymbolLen);


        verticalLayout->addLayout(horizontalLayout_6);

        btnConfirm15 = new QPushButton(widget);
        btnConfirm15->setObjectName(QStringLiteral("btnConfirm15"));

        verticalLayout->addWidget(btnConfirm15);


        retranslateUi(domain15);

        QMetaObject::connectSlotsByName(domain15);
    } // setupUi

    void retranslateUi(QDialog *domain15)
    {
        domain15->setWindowTitle(QApplication::translate("domain15", "Dialog", 0));
        label->setText(QApplication::translate("domain15", "preamble: ", 0));
        label_2->setText(QApplication::translate("domain15", "id: ", 0));
        label_3->setText(QApplication::translate("domain15", "type: ", 0));
        label_4->setText(QApplication::translate("domain15", "mode: ", 0));
        label_5->setText(QApplication::translate("domain15", "data length: ", 0));
        label_6->setText(QApplication::translate("domain15", "symbol length: ", 0));
        btnConfirm15->setText(QApplication::translate("domain15", "\347\241\256\345\256\232", 0));
    } // retranslateUi

};

namespace Ui {
    class domain15: public Ui_domain15 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DOMAIN15_H
