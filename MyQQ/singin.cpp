#include "singin.h"
#include "ui_singin.h"
#include <QPixmap>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QFileDialog>

Singin::Singin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Singin)
{
    ui->setupUi(this);
    setWindowTitle("注册账号");
    setWindowIcon(QPixmap(":/images/0.jpg"));
    connect(ui->registerBtn,&QPushButton::clicked,[=](){
        QString namedata = ui->Username->text();
        QString passworddata = ui->Password->text();
        if(namedata.isEmpty())
        {
            QMessageBox::warning(this,"警告","路径错误");
            return;
        }
        else
        {
            QString path = QFileDialog::getSaveFileName(this,"账号密码","数据记录","(*.txt)");
            QFile file(path);
            file.open(QIODevice::WriteOnly | QIODevice::Text);
            QTextStream stream(&file);
            stream << "Username:" << namedata << endl;
            stream <<"Password:" << passworddata << endl;
            QMessageBox::information(this,"注册","注册成功");
            file.close();
        }
        this->close();
    });
    connect(ui->cancleBtn,&QPushButton::clicked,[=](){
        QMessageBox::warning (this,"注册","注册失败");
        this->close();
    });
}

Singin::~Singin()
{
    delete ui;
}
