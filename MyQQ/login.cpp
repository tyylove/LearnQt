#include "login.h"
#include "ui_login.h"
#include <QMessageBox>
#include "dialoglist.h"
#include "singin.h"

Login::Login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    setWindowTitle("QQ");
    setWindowIcon(QPixmap(":/images/0.jpg"));
    connect(ui->Register,&QPushButton::clicked,[=](){
        Singin *sing = new Singin;
        sing->show();
    });
    QString name = "123456";
    QString password = "admine";
    connect(ui->loginBtn,&QPushButton::clicked,[=](){
        if(name == ui->Username->text() && password == ui->Password->text())
        {
            DialogList *dia = new DialogList(0);
            dia->show();
            this->close();
        }
        else
        {
            QMessageBox::warning(this,"警告","账号或密码错误");
        }
    });

}

Login::~Login()
{
    delete ui;
}
