#include "change.h"

Change::Change(QWidget *parent) : QWidget(parent)
{
   QPushButton *btn4 = new QPushButton ;
   btn4->setParent(this);
   btn4->setText("返回");
   setWindowTitle("MyWindow");
   resize(600,400);
   setFixedSize(600,400);
   connect(btn4,&QPushButton::clicked,this,&Change::Changesignals);
}

void Change::Changesignals()
{
    //发出一个信号
    emit Mysignals();
}

