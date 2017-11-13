#ifndef MAINWINDOW_H
#define MAINWINDOW_H

//在windows下
#define WIN

#include <QMainWindow>

#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QTimer>
#include <QIODevice>
#include <QPainter>
#include <QPen>
#include <QFile>
#include <QTime>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    QSerialPort* port;
    QTimer time;
    QIODevice* reader;
    QFile* data;
    //分为A、B、C组的加速度和角加速度
    int acc_A, sig_A, acc_B, sig_B, acc_C, sig_C;

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_openport_clicked();

    void on_pushButton_closeport_clicked();
    void readdata();

    void on_pushButton_senddata_clicked();


    void slot_timeout();


private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
