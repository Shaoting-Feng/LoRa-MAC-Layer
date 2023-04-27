/********************************************************************************
** Form generated from reading UI file 'domain10.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DOMAIN10_H
#define UI_DOMAIN10_H

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

class Ui_domain10
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
    QLineEdit *lEditSyncPattern;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QLineEdit *lEditSyncMask;
    QPushButton *btnConfirm10;

    void setupUi(QWidget *domain10)
    {
        if (domain10->objectName().isEmpty())
            domain10->setObjectName(QStringLiteral("domain10"));
        domain10->resize(400, 360);
        widget = new QWidget(domain10);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(20, 20, 351, 301));
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

        lEditSyncPattern = new QLineEdit(widget);
        lEditSyncPattern->setObjectName(QStringLiteral("lEditSyncPattern"));

        horizontalLayout_4->addWidget(lEditSyncPattern);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_5 = new QLabel(widget);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_5->addWidget(label_5);

        lEditSyncMask = new QLineEdit(widget);
        lEditSyncMask->setObjectName(QStringLiteral("lEditSyncMask"));

        horizontalLayout_5->addWidget(lEditSyncMask);


        verticalLayout->addLayout(horizontalLayout_5);


        verticalLayout_2->addLayout(verticalLayout);

        btnConfirm10 = new QPushButton(widget);
        btnConfirm10->setObjectName(QStringLiteral("btnConfirm10"));

        verticalLayout_2->addWidget(btnConfirm10);


        retranslateUi(domain10);

        QMetaObject::connectSlotsByName(domain10);
    } // setupUi

    void retranslateUi(QWidget *domain10)
    {
        domain10->setWindowTitle(QApplication::translate("domain10", "Form", 0));
        label->setText(QApplication::translate("domain10", "preamble :", 0));
        lEditPreamble->setInputMask(QApplication::translate("domain10", "bbbbbbbbbbbbbbbbbbbbbbbb", 0));
        label_2->setText(QApplication::translate("domain10", "id :", 0));
        lEditId->setInputMask(QApplication::translate("domain10", "bbbbbbbbbbbbbbbb", 0));
        label_3->setText(QApplication::translate("domain10", "type :", 0));
        lEditType->setInputMask(QApplication::translate("domain10", "bbbb", 0));
        label_4->setText(QApplication::translate("domain10", "sync pattern : ", 0));
        lEditSyncPattern->setInputMask(QApplication::translate("domain10", "bbbbbbbbbbbbbbbb", 0));
        label_5->setText(QApplication::translate("domain10", "sync mask : ", 0));
        lEditSyncMask->setInputMask(QApplication::translate("domain10", "bbbbbbbbbbbbbbbb", 0));
        btnConfirm10->setText(QApplication::translate("domain10", "\347\241\256\345\256\232", 0));
    } // retranslateUi

};

namespace Ui {
    class domain10: public Ui_domain10 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DOMAIN10_H
