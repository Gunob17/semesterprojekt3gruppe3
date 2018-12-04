/********************************************************************************
** Form generated from reading UI file 'throwbot.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_THROWBOT_H
#define UI_THROWBOT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ThrowBot
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ThrowBot)
    {
        if (ThrowBot->objectName().isEmpty())
            ThrowBot->setObjectName(QStringLiteral("ThrowBot"));
        ThrowBot->resize(400, 300);
        menuBar = new QMenuBar(ThrowBot);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        ThrowBot->setMenuBar(menuBar);
        mainToolBar = new QToolBar(ThrowBot);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        ThrowBot->addToolBar(mainToolBar);
        centralWidget = new QWidget(ThrowBot);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        ThrowBot->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(ThrowBot);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        ThrowBot->setStatusBar(statusBar);

        retranslateUi(ThrowBot);

        QMetaObject::connectSlotsByName(ThrowBot);
    } // setupUi

    void retranslateUi(QMainWindow *ThrowBot)
    {
        ThrowBot->setWindowTitle(QApplication::translate("ThrowBot", "ThrowBot", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ThrowBot: public Ui_ThrowBot {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_THROWBOT_H
