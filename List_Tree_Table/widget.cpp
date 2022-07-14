#include "widget.h"
#include "ui_widget.h"
#include <QListWidget>
#include <QTreeWidget>
#include <QString>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    QListWidgetItem *item1 = new QListWidgetItem("床前明月光");
    QListWidgetItem *item2 = new QListWidgetItem("疑是地上霜");
    QListWidgetItem *item3 = new QListWidgetItem("举头望明月");
    QListWidgetItem *item4 = new QListWidgetItem("低头思故乡");
    ui->listWidget->addItem(item1);
    ui->listWidget->addItem(item2);
    ui->listWidget->addItem(item3);
    ui->listWidget->addItem(item4);
    item1->setTextAlignment(0x0004);
    item2->setTextAlignment(Qt::AlignHCenter);
    item3->setTextAlignment(0x0004);
    item4->setTextAlignment(Qt::AlignHCenter);
    QStringList list;
    list<<"床前明月光"<<"疑是地上霜"<<"举头望明月"<<"低头思故乡";
    ui->listWidget->addItems(list);
    //设置水平头
    ui->treeWidget->setHeaderLabels(QStringList()<<"英雄"<<"英雄简介");

    QTreeWidgetItem *tree1 = new QTreeWidgetItem(QStringList()<<"力量");
    QTreeWidgetItem *tree2 = new QTreeWidgetItem(QStringList()<<"敏捷");
    QTreeWidgetItem *tree3 = new QTreeWidgetItem(QStringList()<<"智力");
    //加载顶层节点
    ui->treeWidget->addTopLevelItem(tree1);
    ui->treeWidget->addTopLevelItem(tree2);
    ui->treeWidget->addTopLevelItem(tree3);

    //追加子节点
    QTreeWidgetItem *child1 = new QTreeWidgetItem(QStringList()<<"猪悟能");
    QTreeWidgetItem *child2 = new QTreeWidgetItem(QStringList()<<"孙行者");
    QTreeWidgetItem *child3 = new QTreeWidgetItem(QStringList()<<"沙悟净");
    tree1->addChild(child1);
    tree2->addChild(child2);
    tree3->addChild(child3);


    ui->tableWidget->setColumnCount(3);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList()<<"姓名"<<"性别"<<"年龄");
    ui->tableWidget->setRowCount(5);
    QStringList name;
    name<<"妲己"<<"亚瑟"<<"赵云"<<"关羽"<<"唐僧";
    QStringList sex;
    sex<<"女"<<"男"<<"男"<<"男"<<"女";
    QStringList age;
    age<<"18"<<"28"<<"38"<<"48"<<"35";
    for(int i = 0;i<5;i++)
    {
        int count = 0;
        ui->tableWidget->setItem(i,count++,new QTableWidgetItem(name[i]));
        ui->tableWidget->setItem(i,count++,new QTableWidgetItem(sex[i]));
        ui->tableWidget->setItem(i,count++,new QTableWidgetItem(age[i]));
    }
}

Widget::~Widget()
{
    delete ui;
}
