/********************************************************************************
** Form generated from reading UI file 'index.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INDEX_H
#define UI_INDEX_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Index
{
public:
    QLabel *UserLogLab;
    QLabel *UserNameLab;
    QLineEdit *SelectLineEdit;
    QLabel *UserSignLab;
    QTabWidget *AllFriendTab;
    QWidget *CurrentChatTab;
    QWidget *FriendTab;
    QToolBox *FriendToolBox;
    QWidget *FriendItem;
    QListWidget *FriendList;
    QWidget *StrangerItem;

    void setupUi(QWidget *Index)
    {
        if (Index->objectName().isEmpty())
            Index->setObjectName(QStringLiteral("Index"));
        Index->setEnabled(true);
        Index->resize(280, 670);
        UserLogLab = new QLabel(Index);
        UserLogLab->setObjectName(QStringLiteral("UserLogLab"));
        UserLogLab->setGeometry(QRect(10, 10, 60, 60));
        UserLogLab->setFrameShape(QFrame::Box);
        UserLogLab->setTextFormat(Qt::AutoText);
        UserNameLab = new QLabel(Index);
        UserNameLab->setObjectName(QStringLiteral("UserNameLab"));
        UserNameLab->setEnabled(false);
        UserNameLab->setGeometry(QRect(79, 10, 54, 20));
        UserNameLab->setFrameShape(QFrame::Box);
        SelectLineEdit = new QLineEdit(Index);
        SelectLineEdit->setObjectName(QStringLiteral("SelectLineEdit"));
        SelectLineEdit->setGeometry(QRect(0, 80, 281, 28));
        SelectLineEdit->setFocusPolicy(Qt::NoFocus);
        UserSignLab = new QLabel(Index);
        UserSignLab->setObjectName(QStringLiteral("UserSignLab"));
        UserSignLab->setGeometry(QRect(79, 31, 191, 20));
        UserSignLab->setFrameShape(QFrame::Box);
        UserSignLab->setFrameShadow(QFrame::Plain);
        AllFriendTab = new QTabWidget(Index);
        AllFriendTab->setObjectName(QStringLiteral("AllFriendTab"));
        AllFriendTab->setEnabled(true);
        AllFriendTab->setGeometry(QRect(0, 110, 282, 521));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(AllFriendTab->sizePolicy().hasHeightForWidth());
        AllFriendTab->setSizePolicy(sizePolicy);
        AllFriendTab->setAutoFillBackground(false);
        AllFriendTab->setInputMethodHints(Qt::ImhNone);
        AllFriendTab->setTabPosition(QTabWidget::North);
        AllFriendTab->setTabShape(QTabWidget::Triangular);
        AllFriendTab->setIconSize(QSize(40, 40));
        AllFriendTab->setUsesScrollButtons(true);
        CurrentChatTab = new QWidget();
        CurrentChatTab->setObjectName(QStringLiteral("CurrentChatTab"));
        AllFriendTab->addTab(CurrentChatTab, QString());
        FriendTab = new QWidget();
        FriendTab->setObjectName(QStringLiteral("FriendTab"));
        FriendToolBox = new QToolBox(FriendTab);
        FriendToolBox->setObjectName(QStringLiteral("FriendToolBox"));
        FriendToolBox->setGeometry(QRect(-2, -1, 282, 500));
        FriendToolBox->setBaseSize(QSize(0, 0));
        FriendToolBox->setToolTipDuration(-1);
        FriendToolBox->setFrameShape(QFrame::NoFrame);
        FriendToolBox->setLineWidth(1);
        FriendItem = new QWidget();
        FriendItem->setObjectName(QStringLiteral("FriendItem"));
        FriendItem->setGeometry(QRect(0, 0, 282, 460));
        FriendList = new QListWidget(FriendItem);
        FriendList->setObjectName(QStringLiteral("FriendList"));
        FriendList->setGeometry(QRect(0, 0, 281, 461));
        FriendList->setFrameShape(QFrame::StyledPanel);
        FriendList->setAutoScroll(true);
        FriendList->setAutoScrollMargin(16);
        FriendToolBox->addItem(FriendItem, QStringLiteral("friend"));
        StrangerItem = new QWidget();
        StrangerItem->setObjectName(QStringLiteral("StrangerItem"));
        StrangerItem->setGeometry(QRect(0, 0, 282, 460));
        FriendToolBox->addItem(StrangerItem, QStringLiteral("stranger"));
        AllFriendTab->addTab(FriendTab, QString());

        retranslateUi(Index);

        AllFriendTab->setCurrentIndex(1);
        FriendToolBox->setCurrentIndex(0);
        FriendToolBox->layout()->setSpacing(0);


        QMetaObject::connectSlotsByName(Index);
    } // setupUi

    void retranslateUi(QWidget *Index)
    {
        Index->setWindowTitle(QApplication::translate("Index", "Form", 0));
        UserLogLab->setText(QString());
        UserNameLab->setText(QApplication::translate("Index", "username", 0));
        SelectLineEdit->setText(QApplication::translate("Index", "\346\220\234\347\264\242\345\245\275\345\217\213", 0));
        UserSignLab->setText(QApplication::translate("Index", "\344\270\252\346\200\247\347\255\276\345\220\215", 0));
        AllFriendTab->setTabText(AllFriendTab->indexOf(CurrentChatTab), QApplication::translate("Index", "\344\274\232\350\257\235", 0));
        FriendToolBox->setItemText(FriendToolBox->indexOf(FriendItem), QApplication::translate("Index", "friend", 0));
        FriendToolBox->setItemText(FriendToolBox->indexOf(StrangerItem), QApplication::translate("Index", "stranger", 0));
        AllFriendTab->setTabText(AllFriendTab->indexOf(FriendTab), QApplication::translate("Index", "\350\201\224\347\263\273\344\272\272", 0));
    } // retranslateUi

};

namespace Ui {
    class Index: public Ui_Index {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INDEX_H
