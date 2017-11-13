#include "titlecurvewidget.h"
#include "ui_titlecurvewidget.h"

TitleCurveWidget::TitleCurveWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TitleCurveWidget)
{
    ui->setupUi(this);
}

TitleCurveWidget::~TitleCurveWidget()
{
    delete ui;
}

void TitleCurveWidget::appendValue(int value)
{
    ui->widget->appendValue(value);

}

void TitleCurveWidget::setTitle(QString strTitle)
{
    ui->label->setText(strTitle);

}

void TitleCurveWidget::setYMaxValue(int maxValue)
{
    ui->widget->setYMaxValue(maxValue);

}
