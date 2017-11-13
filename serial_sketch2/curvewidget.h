#ifndef CURVEWIDGET_H
#define CURVEWIDGET_H

#include <QWidget>
#include <QtCore>
#include <QtGui>
#include <QtWidgets>


class CurveWidget : public QWidget
{
    Q_OBJECT
public:
    explicit CurveWidget(QWidget *parent = 0);

    //实现绘制
    void paintEvent(QPaintEvent *);
signals:

public slots:
    void appendValue(int value);

    void setYMaxValue(int maxValue);
private:
    QList<double> listValues;

    int yMaxValue;
};

#endif // CURVEWIDGET_H
