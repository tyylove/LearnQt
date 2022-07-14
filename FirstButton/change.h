#ifndef CHANGE_H
#define CHANGE_H

#include <QWidget>
#include <QPushButton>

class Change : public QWidget
{
    Q_OBJECT
public:
    explicit Change(QWidget *parent = 0);

signals:
    Mysignals();

public slots:
    void Changesignals();
};

#endif // CHANGE_H
