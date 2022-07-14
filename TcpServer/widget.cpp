#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    //创建监听套接字   买手机
    tcpserver =new QTcpServer(this);
    //监听和绑定在一起 QHostAddress::Any所有的客户端都可以来链接
    tcpserver->listen(QHostAddress::Any,8888);
    setWindowTitle("服务器：8888");
    //tcpserver发出newConnection代表有客户端链接进来
    connect(tcpserver,&QTcpServer::newConnection,[=](){
      //别人来连接你 就同意 获取通信套接字
      tcpsocket=tcpserver->nextPendingConnection();
      //通过通信套接字去获取对方的IP和端口
   QString ip= tcpsocket->peerAddress().toString();
   qint16 port=tcpsocket->peerPort();
   QString str=QString("[ip=%1,port=%2]链接成功")
           .arg(ip).arg(port);
   ui->textEditRead->setText(str);
    //tcpsocket发出readyRead 代表客户端发送数据过来
   connect(tcpsocket,&QTcpSocket::readyRead,[=](){
       //读取对方发送过来的数据
   QByteArray  arr= tcpsocket->readAll();
   ui->textEditRead->append(arr);
   });
    });
}

Widget::~Widget()
{
    delete ui;
}
//当你点击send的按钮
void Widget::on_PuttonSend_clicked()
{
    if(tcpsocket==NULL) //没有客户端进行链接
    {
        return;
    }
    //先去获取我们写好的文本
  QString str=  ui->textEditWrite->toPlainText();
  //发送 write 参数是字节数组 str是QString类型  toUtf8()
  tcpsocket->write(str.toUtf8());
}
//关闭
void Widget::on_pushButton_2_clicked()
{
    if(tcpsocket==NULL) //没有客户端进行链接
    {
        return;
    }
    tcpsocket->disconnectFromHost();
    tcpsocket->close();
}
