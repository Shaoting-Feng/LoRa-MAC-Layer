/********************************************************************************
** Form generated from reading UI file 'domain12.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DOMAIN12_H
#define UI_DOMAIN12_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_domain12
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lEditPreamble;
    QSpacerItem *verticalSpacer_3;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *lEditId;
    QSpacerItem *verticalSpacer_2;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *lEditType;
    QSpacerItem *verticalSpacer;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QLineEdit *lEditSymbol2;
    QSpacerItem *verticalSpacer_4;
    QPushButton *btnConfirm12;

    void setupUi(QWidget *domain12)
    {
        if (domain12->objectName().isEmpty())
            domain12->setObjectName(QStringLiteral("domain12"));
        domain12->resize(400, 300);
        layoutWidget = new QWidget(domain12);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 10, 351, 281));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        widget = new QWidget(layoutWidget);
        widget->setObjectName(QStringLiteral("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        lEditPreamble = new QLineEdit(widget);
        lEditPreamble->setObjectName(QStringLiteral("lEditPreamble"));

        horizontalLayout->addWidget(lEditPreamble);


        verticalLayout->addWidget(widget);

        verticalSpacer_3 = new QSpacerItem(20, 17, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);

        widget_2 = new QWidget(layoutWidget);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        horizontalLayout_2 = new QHBoxLayout(widget_2);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(widget_2);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        lEditId = new QLineEdit(widget_2);
        lEditId->setObjectName(QStringLiteral("lEditId"));

        horizontalLayout_2->addWidget(lEditId);


        verticalLayout->addWidget(widget_2);

        verticalSpacer_2 = new QSpacerItem(20, 17, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        widget_3 = new QWidget(layoutWidget);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        horizontalLayout_3 = new QHBoxLayout(widget_3);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_3 = new QLabel(widget_3);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_3->addWidget(label_3);

        lEditType = new QLineEdit(widget_3);
        lEditType->setObjectName(QStringLiteral("lEditType"));

        horizontalLayout_3->addWidget(lEditType);


        verticalLayout->addWidget(widget_3);

        verticalSpacer = new QSpacerItem(20, 17, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        widget_4 = new QWidget(layoutWidget);
        widget_4->setObjectName(QStringLiteral("widget_4"));
        horizontalLayout_4 = new QHBoxLayout(widget_4);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_4 = new QLabel(widget_4);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_4->addWidget(label_4);

        lEditSymbol2 = new QLineEdit(widget_4);
        lEditSymbol2->setObjectName(QStringLiteral("lEditSymbol2"));

        horizontalLayout_4->addWidget(lEditSymbol2);


        verticalLayout->addWidget(widget_4);


        verticalLayout_2->addLayout(verticalLayout);

        verticalSpacer_4 = new QSpacerItem(20, 17, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_4);

        btnConfirm12 = new QPushButton(layoutWidget);
        btnConfirm12->setObjectName(QStringLiteral("btnConfirm12"));

        verticalLayout_2->addWidget(btnConfirm12);


        retranslateUi(domain12);

        QMetaObject::connectSlotsByName(domain12);
    } // setupUi

    void retranslateUi(QWidget *domain12)
    {
        domain12->setWindowTitle(QApplication::translate("domain12", "Form", 0));
        label->setText(QApplication::translate("domain12", "preamble:", 0));
        lEditPreamble->setInputMask(QApplication::translate("domain12", "bbbbbbbbbbbbbbbbbbbbbbbb", 0));
        lEditPreamble->setPlaceholderText(QApplication::translate("domain12", "101010101010101010101010", 0));
        label_2->setText(QApplication::translate("domain12", "id:", 0));
        lEditId->setInputMask(QApplication::translate("domain12", "bbbbbbbbbbbbbbbb", 0));
        lEditId->setPlaceholderText(QApplication::translate("domain12", "0000000000000001", 0));
        label_3->setText(QApplication::translate("domain12", "type:", 0));
        lEditType->setInputMask(QApplication::translate("domain12", "bbbb", 0));
        lEditType->setPlaceholderText(QApplication::translate("domain12", "0110", 0));
        label_4->setText(QApplication::translate("domain12", "symbol2 :", 0));
        lEditSymbol2->setInputMask(QString());
        lEditSymbol2->setPlaceholderText(QApplication::translate("domain12", "1", 0));
        btnConfirm12->setText(QApplication::translate("domain12", "\347\241\256\345\256\232", 0));
    } // retranslateUi

};

namespace Ui {
    class domain12: public Ui_domain12 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DOMAIN12_H
