#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDialog>
#include <QDebug>
#include <QMessageBox>
#include <QColorDialog>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //点击新建按钮，弹出一个对话框
    connect(ui->actionNew,&QAction::triggered,[=](){
       //对话框 模态对话框 非模态对话框
      //模态对话框(不可以对其他窗口进行操作) 非模态对话框(可以对其他窗口进行操作)

        //创建模态对话框
          //QDialog *dig = new QDialog(this);
          //dig->resize(200,100);
          //dig->exec();
         // qDebug() << "模态对话框弹出了" << endl;


        //非模态对话框
        /*
        QDialog *dig2 = new QDialog(this);
        dig2->resize(200,100);
        dig2->show();
        dig2->setAttribute(Qt::WA_DeleteOnClose);//防止测试次数过多导致内存泄露，在关闭对话框就释放
        qDebug() << "非模态对话框弹出了" << endl;
        */

        //消息对话框
        //错误对话框
        //QMessageBox::critical(this,"critical","错误");

        //信息对话框
        //QMessageBox::information(this,"information","信息");

        //提问对话框
        //参数1 父对象 参数2 标题 参数3 提示内容 参数4 按键类型 参数5 回车键关联的按键
        if(QMessageBox::Save == QMessageBox::question(this,"question","信息",QMessageBox::Save|QMessageBox::Cancel,QMessageBox::Cancel))
        {
           qDebug() << "选择的是保存" << endl;
        }
        else
        {
           qDebug() << "选择的是取消" << endl;
        }
    });
    connect(ui->actionCopy,&QAction::triggered,[=](){
    QColor color = QColorDialog::getColor(QColor(255,250,124));
    qDebug() << "红色：" << color.red() << "绿色：" << color.green() << "蓝色：" << color.blue() << endl;
    });

    connect(ui->actionOpen,&QAction::triggered,[=](){
    //文件对话框
    //参数1 父对象 参数2 标题 参数3 默认打开路径 参数4 过滤文件格式
    QString file;
    file = QFileDialog::getOpenFileName(this,"打开文件","D:/嵌入式实训","(*.doc)");
    qDebug() << file;
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}
