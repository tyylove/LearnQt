#ifndef SMALLWIGET_H
#define SMALLWIGET_H

#include <QWidget>

namespace Ui {
class SmallWiget;
}

class SmallWiget : public QWidget
{
    Q_OBJECT

public:
    explicit SmallWiget(QWidget *parent = 0);
    ~SmallWiget();
    //设置值
    void SetNum(int num);
    //获取值
    int GetNum();

private:
    Ui::SmallWiget *ui;
};

#endif // SMALLWIGET_H
