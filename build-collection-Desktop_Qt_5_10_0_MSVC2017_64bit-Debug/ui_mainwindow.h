/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QTableView *tableView;
    QPushButton *loadButton;
    QPushButton *startButton;
    QLabel *inputPrompt;
    QLabel *xLabel;
    QLabel *yLabel;
    QPushButton *throwButton;
    QSpinBox *xInput;
    QSpinBox *yInput;
    QLabel *welcome;
    QLabel *label;
    QLabel *label_2;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(914, 708);
        MainWindow->setStyleSheet(QLatin1String("QMainWindow {\n"
"	background-color: rgb(171, 208, 255);\n"
"	border: 1px solid gray;\n"
"	color: 000000;\n"
"}"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        tableView = new QTableView(centralWidget);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(11, 11, 441, 591));
        loadButton = new QPushButton(centralWidget);
        loadButton->setObjectName(QStringLiteral("loadButton"));
        loadButton->setGeometry(QRect(10, 610, 441, 28));
        startButton = new QPushButton(centralWidget);
        startButton->setObjectName(QStringLiteral("startButton"));
        startButton->setGeometry(QRect(460, 230, 441, 41));
        inputPrompt = new QLabel(centralWidget);
        inputPrompt->setObjectName(QStringLiteral("inputPrompt"));
        inputPrompt->setGeometry(QRect(460, 420, 441, 31));
        QFont font;
        font.setPointSize(8);
        inputPrompt->setFont(font);
        inputPrompt->setAlignment(Qt::AlignCenter);
        xLabel = new QLabel(centralWidget);
        xLabel->setObjectName(QStringLiteral("xLabel"));
        xLabel->setGeometry(QRect(460, 460, 55, 16));
        xLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        yLabel = new QLabel(centralWidget);
        yLabel->setObjectName(QStringLiteral("yLabel"));
        yLabel->setGeometry(QRect(680, 460, 21, 16));
        yLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        throwButton = new QPushButton(centralWidget);
        throwButton->setObjectName(QStringLiteral("throwButton"));
        throwButton->setGeometry(QRect(460, 500, 441, 41));
        xInput = new QSpinBox(centralWidget);
        xInput->setObjectName(QStringLiteral("xInput"));
        xInput->setGeometry(QRect(520, 460, 151, 22));
        yInput = new QSpinBox(centralWidget);
        yInput->setObjectName(QStringLiteral("yInput"));
        yInput->setGeometry(QRect(710, 460, 151, 22));
        welcome = new QLabel(centralWidget);
        welcome->setObjectName(QStringLiteral("welcome"));
        welcome->setGeometry(QRect(460, 20, 441, 20));
        QFont font1;
        font1.setPointSize(12);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setUnderline(true);
        font1.setWeight(50);
        font1.setKerning(true);
        welcome->setFont(font1);
        welcome->setLocale(QLocale(QLocale::Danish, QLocale::Greenland));
        welcome->setFrameShadow(QFrame::Plain);
        welcome->setAlignment(Qt::AlignCenter);
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(460, 180, 441, 21));
        label->setFont(font);
        label->setTextFormat(Qt::PlainText);
        label->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(460, 200, 441, 20));
        label_2->setFont(font);
        label_2->setAlignment(Qt::AlignCenter);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 914, 26));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "ThrowBot GUI", nullptr));
        loadButton->setText(QApplication::translate("MainWindow", "Load Table", nullptr));
        startButton->setText(QApplication::translate("MainWindow", "Start New Test", nullptr));
        inputPrompt->setText(QApplication::translate("MainWindow", "Please input coordinates for the desired destination:", nullptr));
        xLabel->setText(QApplication::translate("MainWindow", "x:", nullptr));
        yLabel->setText(QApplication::translate("MainWindow", "y:", nullptr));
        throwButton->setText(QApplication::translate("MainWindow", "Throw", nullptr));
        welcome->setText(QApplication::translate("MainWindow", "Welcome to the ThrowBot GUI!", nullptr));
        label->setText(QApplication::translate("MainWindow", "Click the button below to open the camera, then press enter to capture.", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "The image will then be processed and the location of the object determined.", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
