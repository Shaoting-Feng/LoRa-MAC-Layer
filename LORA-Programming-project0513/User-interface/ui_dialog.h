/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_6;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *cBoxSerialPort;
    QSpacerItem *verticalSpacer_3;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_2;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout;
    QPushButton *btnDomain6;
    QPushButton *btmDomain7;
    QPushButton *btnDomain8;
    QPushButton *btnDomain9;
    QPushButton *btnDomain10;
    QPushButton *btnDomain11;
    QPushButton *btnDomain12;
    QPushButton *btnDomain13;
    QPushButton *btnDomain14;
    QPushButton *btnDomain15;
    QSpacerItem *verticalSpacer_2;
    QVBoxLayout *verticalLayout_2;
    QPushButton *btnOpen;
    QSpacerItem *verticalSpacer;
    QPushButton *btnSend;
    QSpacerItem *verticalSpacer_5;
    QPushButton *btnClearReceive;
    QSpacerItem *verticalSpacer_6;
    QPushButton *btnClearSend;
    QSpacerItem *horizontalSpacer_3;
    QVBoxLayout *verticalLayout_5;
    QTextEdit *tEditReceived;
    QSpacerItem *verticalSpacer_7;
    QPushButton *EndConfigBtn;
    QSpacerItem *verticalSpacer_4;
    QTextEdit *tEditSend;
    QSpacerItem *horizontalSpacer_4;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QStringLiteral("Dialog"));
        Dialog->resize(583, 552);
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        Dialog->setFont(font);
        Dialog->setAutoFillBackground(false);
        Dialog->setSizeGripEnabled(false);
        horizontalLayout_3 = new QHBoxLayout(Dialog);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer = new QSpacerItem(28, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(Dialog);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        cBoxSerialPort = new QComboBox(Dialog);
        cBoxSerialPort->setObjectName(QStringLiteral("cBoxSerialPort"));
        cBoxSerialPort->setMinimumSize(QSize(80, 25));

        horizontalLayout->addWidget(cBoxSerialPort);


        verticalLayout_3->addLayout(horizontalLayout);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        label_2 = new QLabel(Dialog);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout_4->addWidget(label_2);

        scrollArea = new QScrollArea(Dialog);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, -34, 125, 322));
        verticalLayout = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        btnDomain6 = new QPushButton(scrollAreaWidgetContents);
        btnDomain6->setObjectName(QStringLiteral("btnDomain6"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(btnDomain6->sizePolicy().hasHeightForWidth());
        btnDomain6->setSizePolicy(sizePolicy);
        btnDomain6->setIconSize(QSize(12, 12));

        verticalLayout->addWidget(btnDomain6);

        btmDomain7 = new QPushButton(scrollAreaWidgetContents);
        btmDomain7->setObjectName(QStringLiteral("btmDomain7"));
        sizePolicy.setHeightForWidth(btmDomain7->sizePolicy().hasHeightForWidth());
        btmDomain7->setSizePolicy(sizePolicy);
        btmDomain7->setIconSize(QSize(12, 12));

        verticalLayout->addWidget(btmDomain7);

        btnDomain8 = new QPushButton(scrollAreaWidgetContents);
        btnDomain8->setObjectName(QStringLiteral("btnDomain8"));
        sizePolicy.setHeightForWidth(btnDomain8->sizePolicy().hasHeightForWidth());
        btnDomain8->setSizePolicy(sizePolicy);
        btnDomain8->setIconSize(QSize(12, 12));

        verticalLayout->addWidget(btnDomain8);

        btnDomain9 = new QPushButton(scrollAreaWidgetContents);
        btnDomain9->setObjectName(QStringLiteral("btnDomain9"));
        sizePolicy.setHeightForWidth(btnDomain9->sizePolicy().hasHeightForWidth());
        btnDomain9->setSizePolicy(sizePolicy);
        btnDomain9->setIconSize(QSize(12, 12));

        verticalLayout->addWidget(btnDomain9);

        btnDomain10 = new QPushButton(scrollAreaWidgetContents);
        btnDomain10->setObjectName(QStringLiteral("btnDomain10"));
        sizePolicy.setHeightForWidth(btnDomain10->sizePolicy().hasHeightForWidth());
        btnDomain10->setSizePolicy(sizePolicy);
        btnDomain10->setIconSize(QSize(12, 12));

        verticalLayout->addWidget(btnDomain10);

        btnDomain11 = new QPushButton(scrollAreaWidgetContents);
        btnDomain11->setObjectName(QStringLiteral("btnDomain11"));
        sizePolicy.setHeightForWidth(btnDomain11->sizePolicy().hasHeightForWidth());
        btnDomain11->setSizePolicy(sizePolicy);
        btnDomain11->setIconSize(QSize(12, 12));

        verticalLayout->addWidget(btnDomain11);

        btnDomain12 = new QPushButton(scrollAreaWidgetContents);
        btnDomain12->setObjectName(QStringLiteral("btnDomain12"));
        sizePolicy.setHeightForWidth(btnDomain12->sizePolicy().hasHeightForWidth());
        btnDomain12->setSizePolicy(sizePolicy);
        btnDomain12->setIconSize(QSize(12, 12));

        verticalLayout->addWidget(btnDomain12);

        btnDomain13 = new QPushButton(scrollAreaWidgetContents);
        btnDomain13->setObjectName(QStringLiteral("btnDomain13"));
        sizePolicy.setHeightForWidth(btnDomain13->sizePolicy().hasHeightForWidth());
        btnDomain13->setSizePolicy(sizePolicy);
        btnDomain13->setIconSize(QSize(12, 12));

        verticalLayout->addWidget(btnDomain13);

        btnDomain14 = new QPushButton(scrollAreaWidgetContents);
        btnDomain14->setObjectName(QStringLiteral("btnDomain14"));
        sizePolicy.setHeightForWidth(btnDomain14->sizePolicy().hasHeightForWidth());
        btnDomain14->setSizePolicy(sizePolicy);
        btnDomain14->setIconSize(QSize(12, 12));

        verticalLayout->addWidget(btnDomain14);

        btnDomain15 = new QPushButton(scrollAreaWidgetContents);
        btnDomain15->setObjectName(QStringLiteral("btnDomain15"));
        sizePolicy.setHeightForWidth(btnDomain15->sizePolicy().hasHeightForWidth());
        btnDomain15->setSizePolicy(sizePolicy);
        btnDomain15->setIconSize(QSize(12, 12));

        verticalLayout->addWidget(btnDomain15);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout_4->addWidget(scrollArea);


        verticalLayout_3->addLayout(verticalLayout_4);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_2);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        btnOpen = new QPushButton(Dialog);
        btnOpen->setObjectName(QStringLiteral("btnOpen"));
        btnOpen->setMinimumSize(QSize(80, 30));

        verticalLayout_2->addWidget(btnOpen);

        verticalSpacer = new QSpacerItem(117, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        btnSend = new QPushButton(Dialog);
        btnSend->setObjectName(QStringLiteral("btnSend"));
        btnSend->setMinimumSize(QSize(80, 30));

        verticalLayout_2->addWidget(btnSend);


        verticalLayout_3->addLayout(verticalLayout_2);


        verticalLayout_6->addLayout(verticalLayout_3);

        verticalSpacer_5 = new QSpacerItem(20, 13, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_6->addItem(verticalSpacer_5);

        btnClearReceive = new QPushButton(Dialog);
        btnClearReceive->setObjectName(QStringLiteral("btnClearReceive"));

        verticalLayout_6->addWidget(btnClearReceive);

        verticalSpacer_6 = new QSpacerItem(20, 13, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_6->addItem(verticalSpacer_6);

        btnClearSend = new QPushButton(Dialog);
        btnClearSend->setObjectName(QStringLiteral("btnClearSend"));

        verticalLayout_6->addWidget(btnClearSend);


        horizontalLayout_2->addLayout(verticalLayout_6);

        horizontalSpacer_3 = new QSpacerItem(17, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        tEditReceived = new QTextEdit(Dialog);
        tEditReceived->setObjectName(QStringLiteral("tEditReceived"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(3);
        sizePolicy1.setVerticalStretch(4);
        sizePolicy1.setHeightForWidth(tEditReceived->sizePolicy().hasHeightForWidth());
        tEditReceived->setSizePolicy(sizePolicy1);
        tEditReceived->setMinimumSize(QSize(359, 0));

        verticalLayout_5->addWidget(tEditReceived);

        verticalSpacer_7 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer_7);

        EndConfigBtn = new QPushButton(Dialog);
        EndConfigBtn->setObjectName(QStringLiteral("EndConfigBtn"));
        EndConfigBtn->setMouseTracking(false);

        verticalLayout_5->addWidget(EndConfigBtn);

        verticalSpacer_4 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_5->addItem(verticalSpacer_4);

        tEditSend = new QTextEdit(Dialog);
        tEditSend->setObjectName(QStringLiteral("tEditSend"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(3);
        sizePolicy2.setVerticalStretch(1);
        sizePolicy2.setHeightForWidth(tEditSend->sizePolicy().hasHeightForWidth());
        tEditSend->setSizePolicy(sizePolicy2);
        tEditSend->setMinimumSize(QSize(359, 0));

        verticalLayout_5->addWidget(tEditSend);


        horizontalLayout_2->addLayout(verticalLayout_5);


        horizontalLayout_3->addLayout(horizontalLayout_2);

        horizontalSpacer_4 = new QSpacerItem(28, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);


        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "SD_PHY", 0));
        label->setText(QApplication::translate("Dialog", "\347\253\257\345\217\243\345\217\267\357\274\232", 0));
        label_2->setText(QApplication::translate("Dialog", "\350\257\267\351\200\211\346\213\251\346\202\250\351\234\200\350\246\201\351\205\215\347\275\256\347\232\204\345\217\202\346\225\260\357\274\232", 0));
        btnDomain6->setText(QApplication::translate("Dialog", "domain6", 0));
        btmDomain7->setText(QApplication::translate("Dialog", "domain7", 0));
        btnDomain8->setText(QApplication::translate("Dialog", "domain8", 0));
        btnDomain9->setText(QApplication::translate("Dialog", "domain9", 0));
        btnDomain10->setText(QApplication::translate("Dialog", "domain10", 0));
        btnDomain11->setText(QApplication::translate("Dialog", "domain11", 0));
        btnDomain12->setText(QApplication::translate("Dialog", "domain12", 0));
        btnDomain13->setText(QApplication::translate("Dialog", "domain13", 0));
        btnDomain14->setText(QApplication::translate("Dialog", "domain14", 0));
        btnDomain15->setText(QApplication::translate("Dialog", "domain15", 0));
        btnOpen->setText(QApplication::translate("Dialog", "\346\211\223\345\274\200", 0));
        btnSend->setText(QApplication::translate("Dialog", "\345\217\221\351\200\201", 0));
        btnClearReceive->setText(QApplication::translate("Dialog", "\346\270\205\347\251\272\346\216\245\346\224\266\347\252\227\345\217\243", 0));
        btnClearSend->setText(QApplication::translate("Dialog", "\346\270\205\347\251\272\345\217\221\351\200\201\347\252\227\345\217\243", 0));
        EndConfigBtn->setText(QApplication::translate("Dialog", "\347\273\223\346\235\237\351\205\215\347\275\256", 0));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
