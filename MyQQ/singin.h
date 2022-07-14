#ifndef SINGIN_H
#define SINGIN_H

#include <QWidget>

namespace Ui {
class Singin;
}

class Singin : public QWidget
{
    Q_OBJECT

public:
    explicit Singin(QWidget *parent = 0);
    ~Singin();

private:
    Ui::Singin *ui;
};

#endif // SINGIN_H
