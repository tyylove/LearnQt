#include "widget.h"
#include "ui_widget.h"
#include <QTimer>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    id1 = startTimer(1000);//参数 间隔 单位 毫秒
    id2 = startTimer(500);
    //启动定时器得第二种方法
    QTimer *timer = new QTimer(this);
    timer->start(250);
    connect(timer,&QTimer::timeout,[=](){
        static int num3 = 1;
        ui->label_3->setText(QString::number(num3++));
    });
    //设置按钮暂停
    connect(ui->pushButton,&QPushButton::clicked,[=](){
       timer->stop();
    });
    //设置按钮开始
    connect(ui->pushButton_2,&QPushButton::clicked,[=](){
        timer->start();
    });
}

Widget::~Widget()
{
    delete ui;
}
//重写定时器
void Widget::timerEvent(QTimerEvent *ev)
{
    if(id1 == ev->timerId())
    {
        static int num1 = 1;
        ui->label->setText(QString::number(num1++));
    }
    if(id2 == ev->timerId())
    {
        static int num2 = 1;
        ui->label_2->setText(QString::number(num2++));
    }
}
