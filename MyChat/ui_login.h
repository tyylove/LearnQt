/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Login
{
public:
    QLabel *label;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QPushButton *LoginBtn;
    QPushButton *ExitBtn;

    void setupUi(QWidget *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName(QStringLiteral("Login"));
        Login->resize(400, 300);
        label = new QLabel(Login);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(87, 75, 61, 21));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\271\274\345\234\206"));
        font.setPointSize(11);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label_2 = new QLabel(Login);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(88, 111, 61, 21));
        label_2->setFont(font);
        lineEdit = new QLineEdit(Login);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(154, 77, 161, 20));
        lineEdit_2 = new QLineEdit(Login);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(154, 113, 161, 20));
        lineEdit_2->setEchoMode(QLineEdit::Password);
        LoginBtn = new QPushButton(Login);
        LoginBtn->setObjectName(QStringLiteral("LoginBtn"));
        LoginBtn->setGeometry(QRect(99, 184, 71, 31));
        LoginBtn->setFont(font);
        ExitBtn = new QPushButton(Login);
        ExitBtn->setObjectName(QStringLiteral("ExitBtn"));
        ExitBtn->setGeometry(QRect(229, 184, 71, 31));
        ExitBtn->setFont(font);

        retranslateUi(Login);
        QObject::connect(ExitBtn, SIGNAL(clicked()), Login, SLOT(close()));

        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QWidget *Login)
    {
        Login->setWindowTitle(QApplication::translate("Login", "Form", 0));
        label->setText(QApplication::translate("Login", "\347\224\250\346\210\267\345\220\215\357\274\232", 0));
        label_2->setText(QApplication::translate("Login", "\345\257\206  \347\240\201\357\274\232", 0));
        LoginBtn->setText(QApplication::translate("Login", "\347\231\273\345\275\225", 0));
        ExitBtn->setText(QApplication::translate("Login", "\351\200\200\345\207\272", 0));
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
