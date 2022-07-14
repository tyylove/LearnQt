#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "change.h"
#include <QPushButton>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    Change *cha;

public slots:
    void Changewindow();
    void Delsignal();
};

#endif // WIDGET_H
