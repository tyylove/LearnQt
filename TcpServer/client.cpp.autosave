#include "client.h"
#include "ui_client.h"
#include <QHostAddress>
Client::Client(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Client)
{
    ui->setupUi(this);
    clisocket = new QTcpSocket(this);
    //服务器会给客户端发送信息
    connect(clisocket,&QTcpSocket::readyRead,[=](){
     QByteArray arr=clisocket->readAll();
     ui->textEditRead->append(arr);
    });
}

Client::~Client()
{
    delete ui;
}
//链接服务器
void Client::on_pushConnect_clicked()
{
    //获取行编辑输入的ip和端口
    QString ip=ui->lineEditIp->text();
    qint16 port =ui->lineEditPort->text().toInt();
    //和服务器进行链接
    clisocket->connectToHost(QHostAddress(ip),port);
}
//发送数据
void Client::on_pushSend_clicked()
{
    if(clisocket==NULL) //没有客户端进行链接
    {
        return;
    }
    //先去获取我们写好的文本
  QString str=  ui->textEditWrite->toPlainText();
  //发送 write 参数是字节数组 str是QString类型  toUtf8()
  clisocket->write(str.toUtf8());
}
//关闭
void Client::on_pushClose_clicked()
{
    if(clisocket==NULL) //没有客户端进行链接
    {
        return;
    }
    clisocket->disconnectFromHost();
    clisocket->close();
}
