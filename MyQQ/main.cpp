#include "widget.h"
#include <QApplication>
#include "dialoglist.h"
#include "login.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //Widget w;
    //DialogList list;
    //list.show();
    //w.show();
    Login l;
    l.show();
    return a.exec();
}
