#include "widget.h"
#include "ui_widget.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QFile>
#include <QTextCodec>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{

    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    QString filePath=QFileDialog::getOpenFileName(this,
    "选择文件","D:/嵌入式实训","(*.doc)");
    if(filePath.isEmpty())
    {
        QMessageBox::warning(this,"waring","打开文件失败");
        return;
    }
    else
    {
        ui->lineEdit->setText(filePath);
    }
    //创建文件对象 指明是打开的那个文件
    QFile file(filePath);
    //打开文件  只读的方式
    file.open(QIODevice::ReadOnly);
    //readAll() 读取所有数据返回值是QByteArray
   QByteArray arr=file.readAll();
   ui->textEdit->setText(arr);

    file.close();
    //QIODevice::WriteOnly 就会把之前给你覆盖掉
    //QIODevice::Append 追加 就是在尾部加入我们写的东西
    file.open(QIODevice::Append);
    file.write("你好重庆交通大学");
file.close();
}

