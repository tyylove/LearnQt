#include "widget.h"
#include "ui_widget.h"
#include <QPushButton>
#include <QLineEdit>
#include <QDebug>
#include <QString>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    QString name = "123456";
    QString password = "123456";
    connect(ui->pushButtonCancle,&QPushButton::clicked,this,&QWidget::close);
    connect(ui->pushButtonEnter,&QPushButton::clicked,[=](){
        if(name == ui->User->text() && password == ui->PassWorld->text())
        {
            qDebug() << "登录成功" << endl;
        }
        else
        {
            qDebug() << "登录失败" << endl;
        }
    });
}
Widget::~Widget()
{
    delete ui;
}
