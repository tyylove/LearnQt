#include "widget.h"
#include "ui_widget.h"
#include <QPushButton>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    //创建一个老师对象
    this->zt = new Teacher;

    //创建一个学生对象
    this->st = new Student;

    void (Teacher::*teachersignal)(QString) = &Teacher::hungry;
    void (Student::*studentslot)(QString) = &Student::treat;

    connect(zt,teachersignal,st,studentslot);
    //ClassIsOver();

    QPushButton *btn1 = new QPushButton;
    btn1->setParent(this);
    btn1->setText("下课");
    resize(600,400);
    setFixedSize(600,400);
    connect(btn1,&QPushButton::clicked,this,&Widget::ClassIsOver);

    QPushButton *btn2 = new QPushButton;
    btn2->setParent(this);
    btn2->setText("退出");
    btn2->move(500,0);
    connect(btn2,&QPushButton::clicked,this,&Widget::close);

    //disconnect(zt,teachersignal,st,studentslot); 断开信号1的连接
    //disconnect(btn2,&QPushButton::clicked,this,&Widget::close); 断开信号2的连接

}

void Widget::ClassIsOver()
{
    emit zt->hungry();
    emit zt->hungry("宫保鸡丁");//emit关键字，表示发送信号
}

Widget::~Widget()
{
    delete ui;
}
