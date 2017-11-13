/********************************************************************************
** Form generated from reading UI file 'titlecurvewidget.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TITLECURVEWIDGET_H
#define UI_TITLECURVEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <curvewidget.h>

QT_BEGIN_NAMESPACE

class Ui_TitleCurveWidget
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QSpacerItem *horizontalSpacer_2;
    CurveWidget *widget;

    void setupUi(QWidget *TitleCurveWidget)
    {
        if (TitleCurveWidget->objectName().isEmpty())
            TitleCurveWidget->setObjectName(QStringLiteral("TitleCurveWidget"));
        TitleCurveWidget->resize(400, 300);
        verticalLayout = new QVBoxLayout(TitleCurveWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label = new QLabel(TitleCurveWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);

        widget = new CurveWidget(TitleCurveWidget);
        widget->setObjectName(QStringLiteral("widget"));

        verticalLayout->addWidget(widget);


        retranslateUi(TitleCurveWidget);

        QMetaObject::connectSlotsByName(TitleCurveWidget);
    } // setupUi

    void retranslateUi(QWidget *TitleCurveWidget)
    {
        TitleCurveWidget->setWindowTitle(QApplication::translate("TitleCurveWidget", "Form", 0));
        label->setText(QApplication::translate("TitleCurveWidget", "TextLabel", 0));
    } // retranslateUi

};

namespace Ui {
    class TitleCurveWidget: public Ui_TitleCurveWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TITLECURVEWIDGET_H
