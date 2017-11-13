#include "curvewidget.h"

CurveWidget::CurveWidget(QWidget *parent) : QWidget(parent)
{
    listValues.clear();
    yMaxValue = 25;
}


//实现绘制
void CurveWidget::paintEvent(QPaintEvent *)
{
    double width = this->width();
    double height = this->height();
    double dx = width/2000;
    double dy = height/yMaxValue;
    //qDebug()<<width()<<":"<<height();
    QPainter painter(this);
    painter.save();
    painter.setWindow(QRect(0,height,width,-height));
    //painter.setViewport(0,0,this->width(), 25);
    QTransform transform;
    transform.translate(20, 1);
    painter.setTransform(transform);

    painter.setPen(QPen(Qt::red));
    //painter.drawLine(0,0,100,100);
    int counts = listValues.count();
    for(int i=0;i<counts-1;i++)
    {
        painter.drawLine(dx*i,listValues[i]*dy,dx*(i+1),listValues[i+1]*dy);
    }

    painter.setPen(QPen(Qt::black));
    painter.drawLine(0,0,0,height);
    painter.drawLine(0,height,-5,height-5);
    painter.drawLine(0,height,5,height-5);

    painter.drawLine(0,0,width,0);

    for(int i=0;i<5;i++)
    {
        painter.drawLine(0,i*5*dy,-5,i*5*dy);
        //painter.drawText(-10,i*5*dy+10,QString("%1").arg(i*5));
    }


    painter.restore();

    for(int i=0;i<5;i++)
    {
        painter.drawText(0,height-i*5*dy,QString("%1").arg(i*5));

    }
    //painter.drawLine(0,0,50,50);

    /*
    painter.drawRect(0,0,width,height);

    painter.setPen(QPen(Qt::red));

    QTransform transform;
    transform.translate(width, height);
    transform.rotate(180);

    painter.setTransform(transform);

    painter.drawLine(0,0,50,-50);

    double dx = width/2000;

    int counts = listValues.count();
    for(int i=0;i<counts-1;i++)
    {
        painter.drawLine(dx*i,listValues[i],dx*(i+1),listValues[i+1]);
    }

    */

    /*
    painter.setViewport(0,0,this->width(), this->height());
    painter.setWindow(QRect(-1000,-25,1001,26));
    drawCurves(painter);
    */

}

void CurveWidget::appendValue(int value)
{

    listValues.prepend(value);
    if(listValues.count()>2000)
    {
        listValues.removeLast();
    }

    update();
}

void CurveWidget::setYMaxValue(int maxValue)
{
    yMaxValue = maxValue;
    update();
}

