#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QUdpSocket>
#include "tcpclient.h"
#include "tcpserver.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT
    enum MsgType{Msg,UsrEnter,UsrLeft};
public:
    explicit Widget(QWidget *parent,QString name);
    ~Widget();
public:
    void sndMsg(MsgType type);//广播UDP消息
    void usrEnter(QString username);//处理新用户加入
    void usrLeft(QString usrname,QString time);//处理用户离开
    QString getUsr();//获取用户名
    QString getMsg();//获取聊天信息
    void closeEvent(QCloseEvent *);//关闭事件

private:
    Ui::Widget *ui;
    QUdpSocket *udpSocket;//UDP套接字
    qint16 port;//端口号
    QString uName;//用户名
    TcpServer *server;
    void ReceiveMessage();//接收UDP消息
signals:
    //关闭窗口发送一个关闭的信号
    void closeWidget();

private slots:
    void on_sendFileBtn_clicked();//发送文件
};

#endif // WIDGET_H
