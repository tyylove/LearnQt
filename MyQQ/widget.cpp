#include "widget.h"
#include "ui_widget.h"
#include <QPushButton>
#include <QMessageBox>
#include <QHostInfo>
#include <QDataStream>
#include <QDateTime>
#include <QFontComboBox>
#include <QColorDialog>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>


Widget::Widget(QWidget *parent,QString name) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    //初始化套接字
    udpSocket = new QUdpSocket(this);

    //用户名获取
    uName = name;

    //端口号
    this->port = 8888;

    //绑定端口号
    udpSocket->bind(port,QUdpSocket::ShareAddress | QUdpSocket::ReuseAddressHint);
 /* 采用ShareAddress绑定模式允许其它的服务连接到相同的地址和端口，特别是在多客户端
    监听同一个服务器端口时很有效，ReuseAddressHint表示重连服务器   */

    //发送新用户进入的消息
   sndMsg(UsrEnter);

   //点击发送按钮发送消息
   connect(ui->sendBtn,&QPushButton::clicked,[=](){
       sndMsg(Msg);
   });

   //采用TCP协议发送文件
   server = new TcpServer(this);
   connect(server,SIGNAL(sendFileName(QString)),this,SLOT(getFileName(QString)));
   connect(ui->msgTxtEdit,SIGNAL(currentCharFormatChanged(QTextCharFormat)),this,SLOT(currentFormatChanged(QTextCharFormat)));


   //监听群成员发送的数据
   connect(udpSocket,&QUdpSocket::readyRead,this,&Widget::ReceiveMessage);

   //点击退出按钮实现退出功能
   connect(ui->exitBtn,&QPushButton::clicked,this,&QWidget::close);

   /*************************附加功能*************************/

   //字体
   connect(ui->fontCbx,&QFontComboBox::currentFontChanged,[=](const QFont &font){
       ui->msgTxtEdit->setCurrentFont(font);
       ui->msgTxtEdit->setFocus();
   });

   //字号
   void(QComboBox::*cbxsignal)(const QString &text) = &QComboBox::currentIndexChanged;
   connect(ui->sizeCbx,cbxsignal,[=](const QString &text){
       ui->msgTxtEdit->setFontPointSize(text.toDouble());
       ui->msgTxtEdit->setFocus();
   });

   //加粗
   connect(ui->boldTBtn,&QToolButton::clicked,[=](bool isCheak){
       if(isCheak)
       {
            ui->msgTxtEdit->setFontWeight(QFont::Bold);
       }
       else
       {
           ui->msgTxtEdit->setFontWeight(QFont::Normal);
       }
   });

   //斜体
   connect(ui->italicTBtn,&QToolButton::clicked,[=](bool cheak){
       ui->msgTxtEdit->setFontItalic(cheak);
   });

   //下划线
   connect(ui->underlineTBtn,&QToolButton::clicked,[=](bool cheak){
       ui->msgTxtEdit->setFontUnderline(cheak);
   });

   connect(ui->colorTBtn,&QToolButton::clicked,[=](){
       QColor color = QColorDialog::getColor(Qt::red);
       ui->msgTxtEdit->setTextColor(color);
   });

   //清空聊天记录
   connect(ui->clearTBtn,&QToolButton::clicked,[=](){
       ui->msgBrowser->clear();
   });

   //保存记录
   connect(ui->saveTBtn,&QToolButton::clicked,[=](){
       if(ui->msgBrowser->document()->isEmpty())
       {
           QMessageBox::warning(this,"警告","无聊天记录");
           return;
       }
       else
       {
            QString path = QFileDialog::getSaveFileName(this,"保存记录","聊天记录","(*.txt)");
            if(path.isEmpty())
            {
                QMessageBox::warning(this,"警告","路径错误");
                return;
            }
           QFile file(path);
           file.open(QIODevice::WriteOnly | QIODevice::Text);
           QTextStream stream(&file);
           stream << ui->msgBrowser->toPlainText();
           file.close();
       }
   });
}


//发送消息
void Widget::sndMsg(MsgType type)
{
    //发送消息分为3中类型
    //发送的数据做分段处理 第一段 类型 第二段 用户名
    QByteArray array;
    QDataStream stream(&array,QIODevice::WriteOnly);
    stream << type << getUsr() ;//第一段内容添加到流中 第二段 用户名
    switch(type){
    case Msg:     //普通消息发送
        if(ui->msgTxtEdit->toPlainText() == "")
        {
            QMessageBox::warning(this,"警告","发送内容不能为空");
            return;
        }
        //第三段数据 具体的聊天内容
        stream << getMsg();
        break;
    case UsrEnter:  //新用户加入的消息
        break;
    case UsrLeft:    //用户离开消息
        break;
    default:
        break;
    }
    //书写报文 广播发送
    udpSocket->writeDatagram(array,QHostAddress::Broadcast,port);
}

//接收的消息
void Widget::ReceiveMessage()
{
    //拿到的数据报文
    //获取长度
    qint64 size = udpSocket->pendingDatagramSize();
    QByteArray array = QByteArray(size,0);
    udpSocket->readDatagram(array.data(),size);

    //解析数据
    //第一段 类型 第二段 用户名 第三段 内容
    QDataStream stream(&array,QIODevice::ReadOnly);

    int msgType;//读到的用户数据
    QString usrName;
    QString msg;

    //获取当前时间
    QString time = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
    stream >> msgType;
    switch(msgType){
    case Msg:   //普通聊天
        stream >> usrName >> msg;

        //追加聊天记录
        ui->msgBrowser->setTextColor(Qt::red);
        ui->msgBrowser->append("[" + usrName + "]" + time);
        ui->msgBrowser->append(msg);
        break;

    case UsrEnter:
        //更新显示在线人的昵称
        stream >> usrName;
        usrEnter(usrName);
    case UsrLeft:
        stream >> usrName;
        usrLeft(usrName,time);
        break;

    default:
        break;
    }
}

//获取聊天信息
QString Widget::getMsg()
{
    QString str = ui->msgTxtEdit->toHtml();//调用toHtml方法可修改字体颜色、大小、增加下划线
    //清空输入框
    ui->msgTxtEdit->clear();
    ui->msgTxtEdit->setFocus();//将焦点设置回输入框
    return str;
}

//新用户进入
void Widget::usrEnter(QString username)
{
    bool is_Empty = ui->usrTblWidget->findItems(username,Qt::MatchExactly).isEmpty();
    if(is_Empty)
    {
        QTableWidgetItem * usr = new QTableWidgetItem(username);
        //插入行
        ui->usrTblWidget->insertRow(0);
        ui->usrTblWidget->setItem(0,0,usr);

        //追加聊天记录
        ui->msgBrowser->setTextColor(Qt::blue);
        ui->msgBrowser->append(QString("%1 已上线").arg(username));

        //在线人数的更新
        ui->usrNumLbl->setText(QString("在线用户：%1人").arg(ui->usrTblWidget->rowCount()));

        //广播自身信息
        sndMsg(UsrEnter);
    }
}

//用户离开
void Widget::usrLeft(QString usrname, QString time)
{
    //更新右侧群成员列表
    bool is_Empty = ui->usrTblWidget->findItems(usrname,Qt::MatchExactly).isEmpty();
    if(!is_Empty)
    {
        int row = ui->usrTblWidget->findItems(usrname,Qt::MatchExactly).first()->row();
        ui->usrTblWidget->removeRow(row);

        //追加聊天记录
        ui->msgBrowser->setTextColor(Qt::gray);
        ui->msgBrowser->append(QString("%1于%2已下线").arg(usrname).arg(time));

        //在线人数的更新
        ui->usrNumLbl->setText(QString("在线用户：%1人").arg(ui->usrTblWidget->rowCount()));
    }
}

//获取群成员姓名
QString Widget::getUsr()
{
    return this->uName;
}

//关闭窗口
void Widget::closeEvent(QCloseEvent *e)
{
    emit this->closeWidget();
    sndMsg(UsrLeft);

    //断开套接字
    udpSocket->close();
    udpSocket->destroyed();

    QWidget::closeEvent(e);
}

Widget::~Widget()
{
    delete ui;
}

//发送文件
void Widget::on_sendFileBtn_clicked()
{
    if(ui->usrTblWidget->selectedItems().isEmpty())
    {
        QMessageBox::warning(0,"选择用户","请先从用户列表选择要传送的用户!",QMessageBox::Ok);
        return;
    }
    server->show();
    server->initServer();
}

