#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    //获取当前值
    connect(ui->btn_get,&QPushButton::clicked,[=](){
       qDebug()<<ui->widget->GetNum();
    });

    //设置到一半
    connect(ui->btn_set,&QPushButton::clicked,[=](){
       ui->widget->SetNum(50);
    });
}

Widget::~Widget()
{
    delete ui;
}
