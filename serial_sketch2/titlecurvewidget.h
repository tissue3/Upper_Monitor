#ifndef TITLECURVEWIDGET_H
#define TITLECURVEWIDGET_H

#include <QWidget>

namespace Ui {
class TitleCurveWidget;
}

class TitleCurveWidget : public QWidget
{
    Q_OBJECT

public:
    explicit TitleCurveWidget(QWidget *parent = 0);
    ~TitleCurveWidget();

private:
    Ui::TitleCurveWidget *ui;

public slots:
    void appendValue(int value);
    void setTitle(QString strTitle);
    void setYMaxValue(int maxValue);
};

#endif // TITLECURVEWIDGET_H
