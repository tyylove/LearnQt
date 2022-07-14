/********************************************************************************
** Form generated from reading UI file 'chat.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHAT_H
#define UI_CHAT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFontComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Chat
{
public:
    QTextBrowser *messageBrower;
    QFontComboBox *fontComboBox;
    QComboBox *sizecComboBox;
    QToolButton *BoldToolBtn;
    QToolButton *ItalicToolBtn;
    QToolButton *ColorToolBtn;
    QToolButton *UnderToolBtn;
    QToolButton *ClearToolBtn;
    QToolButton *SendToolBtn;
    QToolButton *SaveToolBtn;
    QTextEdit *messageTextEdit;
    QPushButton *SendBtn;

    void setupUi(QWidget *Chat)
    {
        if (Chat->objectName().isEmpty())
            Chat->setObjectName(QStringLiteral("Chat"));
        Chat->resize(481, 563);
        messageBrower = new QTextBrowser(Chat);
        messageBrower->setObjectName(QStringLiteral("messageBrower"));
        messageBrower->setGeometry(QRect(0, 0, 481, 341));
        fontComboBox = new QFontComboBox(Chat);
        fontComboBox->setObjectName(QStringLiteral("fontComboBox"));
        fontComboBox->setGeometry(QRect(0, 340, 213, 31));
        sizecComboBox = new QComboBox(Chat);
        sizecComboBox->setObjectName(QStringLiteral("sizecComboBox"));
        sizecComboBox->setGeometry(QRect(210, 340, 41, 31));
        sizecComboBox->setFrame(true);
        BoldToolBtn = new QToolButton(Chat);
        BoldToolBtn->setObjectName(QStringLiteral("BoldToolBtn"));
        BoldToolBtn->setGeometry(QRect(252, 340, 32, 32));
        QIcon icon;
        icon.addFile(QStringLiteral(":/myImage/images/bold.png"), QSize(), QIcon::Normal, QIcon::Off);
        BoldToolBtn->setIcon(icon);
        BoldToolBtn->setIconSize(QSize(22, 22));
        BoldToolBtn->setCheckable(true);
        BoldToolBtn->setAutoRaise(true);
        ItalicToolBtn = new QToolButton(Chat);
        ItalicToolBtn->setObjectName(QStringLiteral("ItalicToolBtn"));
        ItalicToolBtn->setGeometry(QRect(285, 340, 32, 32));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/myImage/images/italic.png"), QSize(), QIcon::Normal, QIcon::Off);
        ItalicToolBtn->setIcon(icon1);
        ItalicToolBtn->setIconSize(QSize(22, 22));
        ItalicToolBtn->setCheckable(true);
        ItalicToolBtn->setAutoRaise(true);
        ColorToolBtn = new QToolButton(Chat);
        ColorToolBtn->setObjectName(QStringLiteral("ColorToolBtn"));
        ColorToolBtn->setGeometry(QRect(350, 340, 32, 32));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/myImage/images/color.png"), QSize(), QIcon::Normal, QIcon::Off);
        ColorToolBtn->setIcon(icon2);
        ColorToolBtn->setIconSize(QSize(22, 22));
        ColorToolBtn->setAutoRaise(true);
        UnderToolBtn = new QToolButton(Chat);
        UnderToolBtn->setObjectName(QStringLiteral("UnderToolBtn"));
        UnderToolBtn->setGeometry(QRect(318, 340, 31, 32));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/myImage/images/under.png"), QSize(), QIcon::Normal, QIcon::Off);
        UnderToolBtn->setIcon(icon3);
        UnderToolBtn->setIconSize(QSize(22, 22));
        UnderToolBtn->setCheckable(true);
        UnderToolBtn->setAutoRaise(true);
        ClearToolBtn = new QToolButton(Chat);
        ClearToolBtn->setObjectName(QStringLiteral("ClearToolBtn"));
        ClearToolBtn->setGeometry(QRect(448, 340, 32, 32));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/myImage/images/clear.png"), QSize(), QIcon::Normal, QIcon::Off);
        ClearToolBtn->setIcon(icon4);
        ClearToolBtn->setIconSize(QSize(22, 22));
        ClearToolBtn->setAutoRaise(true);
        SendToolBtn = new QToolButton(Chat);
        SendToolBtn->setObjectName(QStringLiteral("SendToolBtn"));
        SendToolBtn->setGeometry(QRect(416, 340, 31, 32));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/myImage/images/send.png"), QSize(), QIcon::Normal, QIcon::Off);
        SendToolBtn->setIcon(icon5);
        SendToolBtn->setIconSize(QSize(22, 22));
        SendToolBtn->setAutoRaise(true);
        SaveToolBtn = new QToolButton(Chat);
        SaveToolBtn->setObjectName(QStringLiteral("SaveToolBtn"));
        SaveToolBtn->setGeometry(QRect(383, 340, 32, 32));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/myImage/images/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        SaveToolBtn->setIcon(icon6);
        SaveToolBtn->setIconSize(QSize(22, 22));
        SaveToolBtn->setAutoRaise(true);
        messageTextEdit = new QTextEdit(Chat);
        messageTextEdit->setObjectName(QStringLiteral("messageTextEdit"));
        messageTextEdit->setGeometry(QRect(0, 370, 481, 151));
        SendBtn = new QPushButton(Chat);
        SendBtn->setObjectName(QStringLiteral("SendBtn"));
        SendBtn->setGeometry(QRect(427, 525, 51, 31));

        retranslateUi(Chat);

        QMetaObject::connectSlotsByName(Chat);
    } // setupUi

    void retranslateUi(QWidget *Chat)
    {
        Chat->setWindowTitle(QApplication::translate("Chat", "Form", 0));
        sizecComboBox->clear();
        sizecComboBox->insertItems(0, QStringList()
         << QApplication::translate("Chat", "9", 0)
         << QApplication::translate("Chat", "10", 0)
         << QApplication::translate("Chat", "11", 0)
         << QApplication::translate("Chat", "12", 0)
         << QApplication::translate("Chat", "13", 0)
         << QApplication::translate("Chat", "14", 0)
         << QApplication::translate("Chat", "15", 0)
         << QApplication::translate("Chat", "16", 0)
         << QApplication::translate("Chat", "17", 0)
         << QApplication::translate("Chat", "18", 0)
         << QApplication::translate("Chat", "19", 0)
         << QApplication::translate("Chat", "20", 0)
         << QApplication::translate("Chat", "22", 0)
         << QApplication::translate("Chat", "24", 0)
         << QApplication::translate("Chat", "26", 0)
         << QApplication::translate("Chat", "28", 0)
         << QApplication::translate("Chat", "30", 0)
         << QApplication::translate("Chat", "32", 0)
         << QApplication::translate("Chat", "34", 0)
         << QApplication::translate("Chat", "36", 0)
        );
        sizecComboBox->setCurrentText(QApplication::translate("Chat", "9", 0));
        BoldToolBtn->setText(QApplication::translate("Chat", "...", 0));
        ItalicToolBtn->setText(QApplication::translate("Chat", "...", 0));
        ColorToolBtn->setText(QApplication::translate("Chat", "...", 0));
        UnderToolBtn->setText(QApplication::translate("Chat", "...", 0));
        ClearToolBtn->setText(QApplication::translate("Chat", "...", 0));
        SendToolBtn->setText(QApplication::translate("Chat", "...", 0));
        SaveToolBtn->setText(QApplication::translate("Chat", "...", 0));
        SendBtn->setText(QApplication::translate("Chat", "\345\217\221\351\200\201", 0));
    } // retranslateUi

};

namespace Ui {
    class Chat: public Ui_Chat {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHAT_H
