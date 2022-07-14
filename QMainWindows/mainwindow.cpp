#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMenuBar>
#include <QToolBar>
#include <QPushButton>
#include <QStatusBar>
#include <QLabel>
#include <QDockWidget>
#include <QTextEdit>

//#include <QWidget>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //使用Qt的资源文件 ": +前缀名 + 文件名"
    ui->actionNew->setIcon(QIcon(":图标/Image/01/1.jpg"));
    resize(600,400);
    setWindowTitle("文本编辑器");
    //setFixedSize(600,400);

    //创建菜单栏 最多只有一个
    QMenuBar *bar = menuBar();

    //将菜单栏放到屏幕上
    setMenuBar(bar);

    //创建菜单
    QMenu *fileMenu = bar->addMenu("文件");
    QMenu *editMenu = bar->addMenu("编辑");
    QMenu *toolMenu = bar->addMenu("工具");
    QMenu *helpMenu = bar->addMenu("帮助");

    //创建菜单项
    fileMenu->addAction("新建");

    //添加分割线
    fileMenu->addSeparator();

    fileMenu->addAction("打开文件");
    fileMenu->addAction("打开文件夹");
    //添加分割线
    fileMenu->addSeparator();
    fileMenu->addAction("保存");
    fileMenu->addAction("另存为");

    editMenu->addAction("剪切");
    editMenu->addAction("复制");
    editMenu->addAction("粘贴");

    toolMenu->addAction("设置");
    toolMenu->addSeparator();
    toolMenu->addAction("环境");

    helpMenu->addAction("文档");


    //工具栏 可以有多个
    QToolBar * toolBar = new QToolBar(this);
    addToolBar(Qt::BottomToolBarArea,toolBar);

    //设置允许停靠的区域 以下示范为允许停靠上和下
    toolBar->setAllowedAreas(Qt::TopToolBarArea | Qt::BottomToolBarArea);

    QPushButton *btn1 = new QPushButton;
    btn1->setParent(this);
    btn1->setText("确定");
    toolBar->addWidget(btn1);

    QPushButton *btn2 = new QPushButton;
    btn2->setParent(this);
    btn2->setText("退出");
    move(500,0);
    toolBar->addWidget(btn2);
    connect(btn2,&QPushButton::clicked,this,&QPushButton::close);

    //状态栏 最多只有一个
     QStatusBar *sta = new QStatusBar;
     //设置到窗口中
     setStatusBar(sta);

     //放标签控件
     QLabel *label1 = new QLabel;
     label1->setParent(this);
     label1->setText("左侧提示");
     sta->addWidget(label1);

     QLabel *label2 = new QLabel;
     label2->setParent(this);
     label2->setText("右侧提示");
     sta->addPermanentWidget(label2);

     //铆接部件(浮动窗口) 可以有多个
     QDockWidget *dock = new QDockWidget("浮动",this);
     addDockWidget(Qt::BottomDockWidgetArea,dock);

     //设置中心部件
     QTextEdit *text = new QTextEdit(this);
     setCentralWidget(text);

}

MainWindow::~MainWindow()
{
    delete ui;
}
