#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTcpServer> //链接套接字的类
#include <QTcpSocket>//通信套接字的类
namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    QTcpServer *tcpserver; //监听套接字
    QTcpSocket *tcpsocket; //通信套接字

private slots:
    void on_PuttonSend_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
