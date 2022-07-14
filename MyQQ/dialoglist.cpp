#include "dialoglist.h"
#include "ui_dialoglist.h"
#include <QToolButton>
#include <QStringList>
#include <QVector>
#include <QMessageBox>
#include <QFont>
#include "widget.h"
#include "login.h"

DialogList::DialogList(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DialogList)
{
    ui->setupUi(this);

    //设置标题
    setWindowTitle("MyQQ");

    //设置图标
    setWindowIcon(QPixmap(":/images/0.jpg"));

    //网名列表
    QStringList nameList;
    nameList << "粤嵌科技" << "从此封心不再爱" << "一晴方知夏深( •︠ˍ•︡ )"
             << "浮世清欢" << "志在四方" << "🐕头军师"
             << "月关水三木" << "吃土豆长大的马铃薯" << "三嗜"
             << "优雅永不过时" << "杨洋🐏咩" << "平安是福";

    //头像列表
    QStringList iconnameList;
    iconnameList << "1" << "2" << "3" << "4" << "5"
                 << "6" << "7" << "8" << "9" << "10"
                 << "11" << "12";

    QVector<QToolButton *> vToolbtn;
    for(int i = 0;i<12;i++)
    {
    //设置头像
    QToolButton *btn = new QToolButton;

    //设置名字
    btn->setText(nameList[i]);

    //设置头像
    QString str = QString(":/images/%1.jpg").arg(iconnameList.at(i));
    btn->setIcon(QPixmap(str));

    //设置头像大小
    btn->setIconSize(QSize(90,90));

    //设置按钮的风格
    btn->setAutoRaise(true);

    //设置文字和图片一起显示
    btn->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

    //加到垂直布局中
    ui->vLayout->addWidget(btn);

    //用容器保存按钮,方便后续操作
    vToolbtn.push_back(btn);

    //添加标识，弹出一个窗口后不允许弹出第二个
    isShow.push_back(false);
    }
    //对按钮添加信号槽
    for(int i = 0;i<vToolbtn.size();i++)
    {
        connect(vToolbtn[i],&QToolButton::clicked,[=](){
            if(isShow[i])
            {
                QString str = QString("%1的窗口已经打开").arg(vToolbtn[i]->text());
                QMessageBox::warning(this,"警告",str);
                return;
            }
            isShow[i] = true;
            //弹出聊天对话框,并显示名字
            //参数1 顶层方式弹出(其它窗口对它没有影响) 参数2 窗口名字
            Widget *widget = new Widget(0,vToolbtn[i]->text());

            //设置窗口的标题
            widget->setWindowTitle(vToolbtn[i]->text());
            widget->setWindowIcon(vToolbtn[i]->icon());
            widget->show();
            connect(widget,&Widget::closeWidget,[=](){
                isShow[i] = false;
            });
        });
    }
}

DialogList::~DialogList()
{
    delete ui;
}
