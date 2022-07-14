#include "widget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();//显示窗口
    return a.exec();//阻塞窗口消失
}
