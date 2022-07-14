#include "smallwiget.h"
#include "ui_smallwiget.h"

SmallWiget::SmallWiget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SmallWiget)
{
    ui->setupUi(this);
    //QSpinBox移动 QSlider跟着移动
    void(QSpinBox:: * func)(int) = &QSpinBox::valueChanged;
    connect(ui->spinBox,func,ui->horizontalSlider,&QSlider::setValue);
    connect(ui->horizontalSlider,&QSlider::valueChanged,ui->spinBox,&QSpinBox::setValue);
}

SmallWiget::~SmallWiget()
{
    delete ui;
}
void SmallWiget::SetNum(int num)
{
    ui->spinBox->setValue(num);
}

int SmallWiget::GetNum()
{
    return ui->spinBox->value();
}
