#ifndef CLIENT_H
#define CLIENT_H

#include <QWidget>
#include <QTcpSocket> //客户端就可以直接使用通信套接字进行通信
namespace Ui {
class Client;
}

class Client : public QWidget
{
    Q_OBJECT

public:
    explicit Client(QWidget *parent = 0);
    ~Client();
    QTcpSocket *clisocket;
private slots:
    void on_pushConnect_clicked();

    void on_pushSend_clicked();

    void on_pushClose_clicked();

private:
    Ui::Client *ui;
};

#endif // CLIENT_H
