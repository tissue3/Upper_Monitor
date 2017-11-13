#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    port = new QSerialPort;
    setWindowIcon(QIcon(":/plats.ico"));

    //遍历有效的串口信息，并添加到组合框中
    foreach(const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
    {
         QSerialPort serial;
         serial.setPort(info);
         if(serial.open(QIODevice::ReadWrite))
         {
             qDebug() << "Name : " << info.portName();
             qDebug() << "Description : " << info.description();
             qDebug() << "Manufacturer: " << info.manufacturer();
             qDebug() << "Serial Number: " << info.serialNumber();
             qDebug() << "System Location: " << info.systemLocation();
             ui->comboBox_portname->addItem(info.portName());
             serial.close();
         }
    }

    //添加串口信息
    ui->comboBox_baudrate->addItem("1200",QSerialPort::Baud1200);
    ui->comboBox_baudrate->addItem("2400",QSerialPort::Baud2400);
    ui->comboBox_baudrate->addItem("4800",QSerialPort::Baud4800);
    ui->comboBox_baudrate->addItem("9600",QSerialPort::Baud9600);
    ui->comboBox_baudrate->addItem("19200",QSerialPort::Baud19200);
    ui->comboBox_baudrate->addItem("38400",QSerialPort::Baud38400);
    ui->comboBox_baudrate->addItem("57600",QSerialPort::Baud57600);
    ui->comboBox_baudrate->addItem("115200",QSerialPort::Baud115200);

    ui->comboBox_databits->addItem("5",QSerialPort::Data5);
    ui->comboBox_databits->addItem("6",QSerialPort::Data6);
    ui->comboBox_databits->addItem("7",QSerialPort::Data7);
    ui->comboBox_databits->addItem("8",QSerialPort::Data8);

    ui->comboBox_stopbits->addItem("One",QSerialPort::OneStop);
    ui->comboBox_stopbits->addItem("OnePointFive",QSerialPort::OneAndHalfStop);
    ui->comboBox_stopbits->addItem("Two",QSerialPort::TwoStop);

    ui->comboBox_parity->addItem("PAR_NONE",QSerialPort::NoParity);
    ui->comboBox_parity->addItem("PAR_ODD",QSerialPort::OddParity);
    ui->comboBox_parity->addItem("PAR_EVEN",QSerialPort::EvenParity);
    ui->comboBox_parity->addItem("PAR_SPACE",QSerialPort::SpaceParity);


    ui->comboBox_flowcontrol->addItem("NoFlowControl",QSerialPort::NoFlowControl);
    //ui->comboBox_flowcontrol->addItem("FlowControl",QSerialPort::FlowControl);

    //设置读串口数据的方式，windows下事件驱动，linux下定时器扫描
#ifdef WIN
    connect(port, SIGNAL(readyRead()), this, SLOT(readdata()));
#else
    time->setInterval(100);
    connect(time, SIGNAL(timeout()), this, SLOT(readdata()));
#endif
    //设定路径
    data = new QFile("output.txt");

    connect(&time,SIGNAL(timeout()),
            this,SLOT(slot_timeout()));
    time.setSingleShot(false);
    time.start(100);
}

void MainWindow::readdata()
{
    QByteArray str;
    //读取串口
    str = port->readAll();
    QString temp = str;
    int start = 0;

    while(temp.mid(start,4) != "A4A4")
    {
        start = start + 2;
        if (temp.length() == start) {return;}
    }

    start = start + 4;

    if(temp.mid(24+start,4) != "A5A5")
        return;

    qDebug() << "Received:" << str;

    str = "-->  " + str;

    ui->textEdit_history->append(str);

    //从十六进制转换为十进制
    bool ok;
    //在start基础上加
    acc_A = temp.mid(start,4).toInt(&ok,16);
    sig_A = temp.mid(4+start,4).toInt(&ok,16);
    acc_B = temp.mid(8+start,4).toInt(&ok,16);
    sig_B = temp.mid(12+start,4).toInt(&ok,16);
    acc_C = temp.mid(16+start,4).toInt(&ok,16);
    sig_C = temp.mid(20+start,4).toInt(&ok,16);

    //按格式写入文件
    QTextStream out(data);
    out << "\t" << acc_A  << "\t" << sig_A << "\t" << acc_B  << "\t" << sig_B << "\t" << acc_C << "\t" << sig_C << "\n";

    //显示
    ui->lcdNumber_acc_A->display(acc_A);
    ui->lcdNumber_sig_A->display(sig_A);
    ui->lcdNumber_acc_B->display(acc_B);
    ui->lcdNumber_sig_B->display(sig_B);
    ui->lcdNumber_acc_C->display(acc_C);
    ui->lcdNumber_sig_C->display(sig_C);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_openport_clicked()
{
    if (! port) return;
    if (port->isOpen())
        port->close();
    //设置串口信息 端口号
    port->setPortName(ui->comboBox_portname->currentText());

    //波特率
    int portparam = (ui->comboBox_baudrate->itemData(ui->comboBox_baudrate->currentIndex())).toInt();
    port->setBaudRate((QSerialPort::BaudRate)portparam);
    //停止位
    portparam = (ui->comboBox_stopbits->itemData(ui->comboBox_stopbits->currentIndex())).toInt();
    port->setStopBits((QSerialPort::StopBits)portparam);
    //数据位
    portparam = (ui->comboBox_databits->itemData(ui->comboBox_databits->currentIndex())).toInt();
    port->setDataBits((QSerialPort::DataBits)portparam);
    //校验位
    portparam = (ui->comboBox_parity->itemData(ui->comboBox_parity->currentIndex())).toInt();
    port->setParity((QSerialPort::Parity)portparam);
    //流控制位
    portparam = (ui->comboBox_flowcontrol->itemData(ui->comboBox_flowcontrol->currentIndex())).toInt();
    port->setFlowControl(QSerialPort::NoFlowControl);

    //以读写方式打开
    port->open(QIODevice::ReadWrite);

    port->clearError();
    port->clear();

    ui->pushButton_closeport->setEnabled(true);
    ui->pushButton_openport->setEnabled(false);

    ui->comboBox_portname->setEnabled(false);
    ui->comboBox_baudrate->setEnabled(false);
    ui->comboBox_parity->setEnabled(false);
    ui->comboBox_stopbits->setEnabled(false);
    ui->comboBox_databits->setEnabled(false);
    ui->comboBox_flowcontrol->setEnabled(false);

    //以只写和文本方式打开
    if(!data->open(QFile::WriteOnly | QFile::Text | QFile::Append))
    {
        return;
    }

    //写入提示信息
    QTextStream out(data);
    out << "\n/***********************************************************/" << "\n";
    out << "\tsystem is starting at " << QTime::currentTime().toString() << "\n";
    out << "/***********************************************************/" << "\n\n";

    out << "\tacc_A\tang_A\tacc_B\tang_B\tacc_C\tang_C\n";
}

void MainWindow::on_pushButton_closeport_clicked()
{
    if (! port) return;
    //关闭串口
    port->close();
    //textBr_mess->append("Port close");
    ui->pushButton_closeport->setEnabled(false);
    ui->pushButton_openport->setEnabled(true);

    ui->comboBox_portname->setEnabled(true);
    ui->comboBox_baudrate->setEnabled(true);
    ui->comboBox_parity->setEnabled(true);
    ui->comboBox_stopbits->setEnabled(true);
    ui->comboBox_databits->setEnabled(true);
    ui->comboBox_flowcontrol->setEnabled(true);

    if(data->isOpen())
    {
        data->close();
    }
}

void MainWindow::on_pushButton_senddata_clicked()
{
    QString str;
    str = ui->lineEdit_send->text();
    //串口发送数据
    port->write(str.toLatin1());
    qDebug() << "Send:" << str;

    str = "<--  " + str;

    ui->textEdit_history->append(str);

}

void MainWindow::slot_timeout()
{
    ui->widget1->appendValue(acc_A);
    ui->widget1->setTitle("acc_A");
    ui->widget1->setYMaxValue(10000);

    ui->widget2->appendValue(sig_A);
    ui->widget2->setTitle("sig_A");
    ui->widget2->setYMaxValue(10000);

    ui->widget3->appendValue(acc_B);
    ui->widget3->setTitle("acc_B");
    ui->widget3->setYMaxValue(10000);

    ui->widget4->appendValue(sig_B);
    ui->widget4->setTitle("sig_B");
    ui->widget4->setYMaxValue(10000);

    ui->widget5->appendValue(acc_C);
    ui->widget5->setTitle("acc_C");
    ui->widget5->setYMaxValue(10000);

    ui->widget6->appendValue(qrand()%25);
    ui->widget6->setTitle("sig_C");
    ui->widget6->setYMaxValue(10000);

}
