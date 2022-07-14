#include "widget.h"
#include "ui_widget.h"
#include <QPushButton>//按钮控件的头文件

Widget::Widget(QWidget *parent) :
    QWidget(parent)
{
    //按钮1
    QPushButton *btn1 = new QPushButton;

    btn1->setParent(this);//设置父亲

    btn1->setText("确定");//设置按钮上的文本信息

    resize(600,400);//重置窗口大小

    setWindowTitle("第一个窗口");//设置窗口标题

    setFixedSize(600,400);//固定窗口大小

    //按钮3
    cha = new Change;

    QPushButton *btn3 = new QPushButton;

    btn3->setParent(this);

    btn3->setText("切换");

    btn3->move(200,0);

    connect(btn3,&QPushButton::clicked,this,&Widget::Changewindow);

    connect(cha,&Change::Mysignals,this,&Widget::Delsignal);

    //按钮2
    QPushButton *btn2 = new QPushButton;

    btn2->setParent(this);

    btn2->setText("取消");

    btn2->move(400,0);

    /*
       信号和槽
       需求：点击按钮关闭窗口
       连接函数：connect
       connect(参数1，参数2，参数3，参数4)
       参数1：信号的发送者
       参数2：发送的信号(函数的地址)
       参数3：信号的接收者
       参数4：处理信号的槽函数(函数的地址)
       */

   connect(btn2,&QPushButton::clicked,this,&Widget::close);//点击取消关闭窗口
}

void Widget::Changewindow()
{
    this->hide();
    cha->show();
}

void Widget::Delsignal()
{
    cha->hide();
    this->show();
}
