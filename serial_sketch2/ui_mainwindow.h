/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <titlecurvewidget.h>
#include "quadglwidget.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_4;
    QTextEdit *textEdit_history;
    QGroupBox *groupBox_9;
    quadGLWidget *quad;
    QGroupBox *groupBox_8;
    TitleCurveWidget *widget1;
    TitleCurveWidget *widget2;
    TitleCurveWidget *widget3;
    TitleCurveWidget *widget4;
    TitleCurveWidget *widget5;
    TitleCurveWidget *widget6;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *comboBox_portname;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QComboBox *comboBox_baudrate;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QComboBox *comboBox_databits;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QComboBox *comboBox_parity;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QComboBox *comboBox_stopbits;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_6;
    QComboBox *comboBox_flowcontrol;
    QPushButton *pushButton_openport;
    QPushButton *pushButton_closeport;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox_4;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_7;
    QLCDNumber *lcdNumber_acc_A;
    QSpacerItem *horizontalSpacer;
    QLabel *label_8;
    QLCDNumber *lcdNumber_sig_A;
    QGroupBox *groupBox_5;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_9;
    QLCDNumber *lcdNumber_acc_B;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_10;
    QLCDNumber *lcdNumber_sig_B;
    QGroupBox *groupBox_6;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_11;
    QLCDNumber *lcdNumber_acc_C;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_12;
    QLCDNumber *lcdNumber_sig_C;
    QSpacerItem *verticalSpacer;
    QGroupBox *groupBox_7;
    QHBoxLayout *horizontalLayout_10;
    QLineEdit *lineEdit_send;
    QPushButton *pushButton_senddata;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->setWindowModality(Qt::ApplicationModal);
        MainWindow->resize(1260, 962);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(710, 0, 531, 151));
        verticalLayout_4 = new QVBoxLayout(groupBox);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        textEdit_history = new QTextEdit(groupBox);
        textEdit_history->setObjectName(QStringLiteral("textEdit_history"));

        verticalLayout_4->addWidget(textEdit_history);

        groupBox_9 = new QGroupBox(centralWidget);
        groupBox_9->setObjectName(QStringLiteral("groupBox_9"));
        groupBox_9->setGeometry(QRect(10, 0, 681, 541));
        quad = new quadGLWidget(groupBox_9);
        quad->setObjectName(QStringLiteral("quad"));
        quad->setGeometry(QRect(-1, 19, 681, 521));
        quad->setCursor(QCursor(Qt::OpenHandCursor));
        groupBox_8 = new QGroupBox(centralWidget);
        groupBox_8->setObjectName(QStringLiteral("groupBox_8"));
        groupBox_8->setGeometry(QRect(10, 550, 1241, 371));
        widget1 = new TitleCurveWidget(groupBox_8);
        widget1->setObjectName(QStringLiteral("widget1"));
        widget1->setGeometry(QRect(10, 20, 401, 161));
        widget2 = new TitleCurveWidget(groupBox_8);
        widget2->setObjectName(QStringLiteral("widget2"));
        widget2->setGeometry(QRect(420, 20, 401, 161));
        widget3 = new TitleCurveWidget(groupBox_8);
        widget3->setObjectName(QStringLiteral("widget3"));
        widget3->setGeometry(QRect(830, 20, 401, 161));
        widget4 = new TitleCurveWidget(groupBox_8);
        widget4->setObjectName(QStringLiteral("widget4"));
        widget4->setGeometry(QRect(10, 190, 401, 161));
        widget5 = new TitleCurveWidget(groupBox_8);
        widget5->setObjectName(QStringLiteral("widget5"));
        widget5->setGeometry(QRect(420, 190, 401, 161));
        widget6 = new TitleCurveWidget(groupBox_8);
        widget6->setObjectName(QStringLiteral("widget6"));
        widget6->setGeometry(QRect(830, 190, 401, 161));
        groupBox_3 = new QGroupBox(centralWidget);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(710, 160, 200, 381));
        groupBox_3->setMinimumSize(QSize(200, 0));
        verticalLayout = new QVBoxLayout(groupBox_3);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(groupBox_3);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        comboBox_portname = new QComboBox(groupBox_3);
        comboBox_portname->setObjectName(QStringLiteral("comboBox_portname"));
        comboBox_portname->setMaximumSize(QSize(92, 16777215));
        comboBox_portname->setEditable(false);

        horizontalLayout->addWidget(comboBox_portname);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_4 = new QLabel(groupBox_3);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_4->addWidget(label_4);

        comboBox_baudrate = new QComboBox(groupBox_3);
        comboBox_baudrate->setObjectName(QStringLiteral("comboBox_baudrate"));
        comboBox_baudrate->setMaximumSize(QSize(92, 16777215));

        horizontalLayout_4->addWidget(comboBox_baudrate);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_3 = new QLabel(groupBox_3);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_3->addWidget(label_3);

        comboBox_databits = new QComboBox(groupBox_3);
        comboBox_databits->setObjectName(QStringLiteral("comboBox_databits"));
        comboBox_databits->setMaximumSize(QSize(92, 16777215));

        horizontalLayout_3->addWidget(comboBox_databits);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(groupBox_3);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        comboBox_parity = new QComboBox(groupBox_3);
        comboBox_parity->setObjectName(QStringLiteral("comboBox_parity"));
        comboBox_parity->setMaximumSize(QSize(92, 16777215));

        horizontalLayout_2->addWidget(comboBox_parity);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_5 = new QLabel(groupBox_3);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_5->addWidget(label_5);

        comboBox_stopbits = new QComboBox(groupBox_3);
        comboBox_stopbits->setObjectName(QStringLiteral("comboBox_stopbits"));
        comboBox_stopbits->setMaximumSize(QSize(92, 16777215));

        horizontalLayout_5->addWidget(comboBox_stopbits);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_6 = new QLabel(groupBox_3);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_6->addWidget(label_6);

        comboBox_flowcontrol = new QComboBox(groupBox_3);
        comboBox_flowcontrol->setObjectName(QStringLiteral("comboBox_flowcontrol"));
        comboBox_flowcontrol->setMaximumSize(QSize(92, 16777215));

        horizontalLayout_6->addWidget(comboBox_flowcontrol);


        verticalLayout->addLayout(horizontalLayout_6);

        pushButton_openport = new QPushButton(groupBox_3);
        pushButton_openport->setObjectName(QStringLiteral("pushButton_openport"));

        verticalLayout->addWidget(pushButton_openport);

        pushButton_closeport = new QPushButton(groupBox_3);
        pushButton_closeport->setObjectName(QStringLiteral("pushButton_closeport"));

        verticalLayout->addWidget(pushButton_closeport);

        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(930, 160, 308, 381));
        groupBox_2->setMaximumSize(QSize(350, 16777215));
        verticalLayout_2 = new QVBoxLayout(groupBox_2);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        groupBox_4 = new QGroupBox(groupBox_2);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        horizontalLayout_7 = new QHBoxLayout(groupBox_4);
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_7 = new QLabel(groupBox_4);
        label_7->setObjectName(QStringLiteral("label_7"));

        horizontalLayout_7->addWidget(label_7);

        lcdNumber_acc_A = new QLCDNumber(groupBox_4);
        lcdNumber_acc_A->setObjectName(QStringLiteral("lcdNumber_acc_A"));

        horizontalLayout_7->addWidget(lcdNumber_acc_A);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer);

        label_8 = new QLabel(groupBox_4);
        label_8->setObjectName(QStringLiteral("label_8"));

        horizontalLayout_7->addWidget(label_8);

        lcdNumber_sig_A = new QLCDNumber(groupBox_4);
        lcdNumber_sig_A->setObjectName(QStringLiteral("lcdNumber_sig_A"));

        horizontalLayout_7->addWidget(lcdNumber_sig_A);


        verticalLayout_2->addWidget(groupBox_4);

        groupBox_5 = new QGroupBox(groupBox_2);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        horizontalLayout_8 = new QHBoxLayout(groupBox_5);
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        label_9 = new QLabel(groupBox_5);
        label_9->setObjectName(QStringLiteral("label_9"));

        horizontalLayout_8->addWidget(label_9);

        lcdNumber_acc_B = new QLCDNumber(groupBox_5);
        lcdNumber_acc_B->setObjectName(QStringLiteral("lcdNumber_acc_B"));

        horizontalLayout_8->addWidget(lcdNumber_acc_B);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_2);

        label_10 = new QLabel(groupBox_5);
        label_10->setObjectName(QStringLiteral("label_10"));

        horizontalLayout_8->addWidget(label_10);

        lcdNumber_sig_B = new QLCDNumber(groupBox_5);
        lcdNumber_sig_B->setObjectName(QStringLiteral("lcdNumber_sig_B"));

        horizontalLayout_8->addWidget(lcdNumber_sig_B);


        verticalLayout_2->addWidget(groupBox_5);

        groupBox_6 = new QGroupBox(groupBox_2);
        groupBox_6->setObjectName(QStringLiteral("groupBox_6"));
        horizontalLayout_9 = new QHBoxLayout(groupBox_6);
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        label_11 = new QLabel(groupBox_6);
        label_11->setObjectName(QStringLiteral("label_11"));

        horizontalLayout_9->addWidget(label_11);

        lcdNumber_acc_C = new QLCDNumber(groupBox_6);
        lcdNumber_acc_C->setObjectName(QStringLiteral("lcdNumber_acc_C"));

        horizontalLayout_9->addWidget(lcdNumber_acc_C);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_3);

        label_12 = new QLabel(groupBox_6);
        label_12->setObjectName(QStringLiteral("label_12"));

        horizontalLayout_9->addWidget(label_12);

        lcdNumber_sig_C = new QLCDNumber(groupBox_6);
        lcdNumber_sig_C->setObjectName(QStringLiteral("lcdNumber_sig_C"));

        horizontalLayout_9->addWidget(lcdNumber_sig_C);


        verticalLayout_2->addWidget(groupBox_6);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        groupBox_7 = new QGroupBox(groupBox_2);
        groupBox_7->setObjectName(QStringLiteral("groupBox_7"));
        horizontalLayout_10 = new QHBoxLayout(groupBox_7);
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        lineEdit_send = new QLineEdit(groupBox_7);
        lineEdit_send->setObjectName(QStringLiteral("lineEdit_send"));

        horizontalLayout_10->addWidget(lineEdit_send);

        pushButton_senddata = new QPushButton(groupBox_7);
        pushButton_senddata->setObjectName(QStringLiteral("pushButton_senddata"));

        horizontalLayout_10->addWidget(pushButton_senddata);


        verticalLayout_2->addWidget(groupBox_7);

        MainWindow->setCentralWidget(centralWidget);
        groupBox_3->raise();
        groupBox_2->raise();
        groupBox->raise();
        groupBox_9->raise();
        groupBox_8->raise();
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        comboBox_portname->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\345\233\233\350\275\264\351\243\236\350\241\214\345\231\250\350\260\203\350\257\225\345\212\251\346\211\213", 0));
        groupBox->setTitle(QApplication::translate("MainWindow", "\345\216\206\345\217\262\346\266\210\346\201\257", 0));
        groupBox_9->setTitle(QApplication::translate("MainWindow", "\345\233\233\350\275\264\346\250\241\345\236\213-\344\270\211\347\273\264\346\230\276\347\244\272", 0));
        groupBox_8->setTitle(QApplication::translate("MainWindow", "\346\263\242\345\275\242\345\233\276", 0));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "\351\205\215\347\275\256", 0));
        label->setText(QApplication::translate("MainWindow", "\347\253\257\345\217\243\345\217\267", 0));
        label_4->setText(QApplication::translate("MainWindow", "\346\263\242\347\211\271\347\216\207", 0));
        label_3->setText(QApplication::translate("MainWindow", "\346\225\260\346\215\256\344\275\215", 0));
        label_2->setText(QApplication::translate("MainWindow", "\346\240\241\351\252\214\344\275\215", 0));
        label_5->setText(QApplication::translate("MainWindow", "\345\201\234\346\255\242\344\275\215", 0));
        label_6->setText(QApplication::translate("MainWindow", "\346\265\201\346\216\247\345\210\266", 0));
        pushButton_openport->setText(QApplication::translate("MainWindow", "\346\211\223\345\274\200", 0));
        pushButton_closeport->setText(QApplication::translate("MainWindow", "\345\205\263\351\227\255", 0));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "\345\217\202\346\225\260\350\257\273\345\217\226", 0));
        groupBox_4->setTitle(QApplication::translate("MainWindow", "A\347\273\204", 0));
        label_7->setText(QApplication::translate("MainWindow", "\345\212\240\351\200\237\345\272\246", 0));
        label_8->setText(QApplication::translate("MainWindow", "\350\247\222\345\212\240\351\200\237\345\272\246", 0));
        groupBox_5->setTitle(QApplication::translate("MainWindow", "B\347\273\204", 0));
        label_9->setText(QApplication::translate("MainWindow", "\345\212\240\351\200\237\345\272\246", 0));
        label_10->setText(QApplication::translate("MainWindow", "\350\247\222\345\212\240\351\200\237\345\272\246", 0));
        groupBox_6->setTitle(QApplication::translate("MainWindow", "C\347\273\204", 0));
        label_11->setText(QApplication::translate("MainWindow", "\345\212\240\351\200\237\345\272\246", 0));
        label_12->setText(QApplication::translate("MainWindow", "\350\247\222\345\212\240\351\200\237\345\272\246", 0));
        groupBox_7->setTitle(QApplication::translate("MainWindow", "\345\217\221\351\200\201", 0));
        pushButton_senddata->setText(QApplication::translate("MainWindow", "\345\217\221\351\200\201", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
