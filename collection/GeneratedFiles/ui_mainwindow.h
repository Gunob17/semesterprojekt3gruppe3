/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
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
    QLabel *label3;
    QLabel *xLabel;
    QLabel *yLabel;
    QPushButton *throwButton;
    QSpinBox *Xinput;
    QSpinBox *Yinput;
    QLabel *label;
    QLabel *label1;
    QLabel *label2;
    QLabel *label7;
    QLabel *label6;
    QPushButton *verifyButton;
    QLabel *label4;
    QLabel *label5;
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
        startButton->setGeometry(QRect(460, 140, 441, 41));
        label3 = new QLabel(centralWidget);
        label3->setObjectName(QStringLiteral("label3"));
        label3->setGeometry(QRect(456, 220, 441, 31));
        QFont font;
        font.setPointSize(8);
        label3->setFont(font);
        label3->setAlignment(Qt::AlignCenter);
        xLabel = new QLabel(centralWidget);
        xLabel->setObjectName(QStringLiteral("xLabel"));
        xLabel->setGeometry(QRect(456, 260, 55, 16));
        xLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        yLabel = new QLabel(centralWidget);
        yLabel->setObjectName(QStringLiteral("yLabel"));
        yLabel->setGeometry(QRect(676, 260, 21, 16));
        yLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        throwButton = new QPushButton(centralWidget);
        throwButton->setObjectName(QStringLiteral("throwButton"));
        throwButton->setGeometry(QRect(460, 440, 441, 41));
        Xinput = new QSpinBox(centralWidget);
        Xinput->setObjectName(QStringLiteral("Xinput"));
        Xinput->setGeometry(QRect(516, 260, 151, 22));
        Xinput->setMinimum(-159);
        Xinput->setMaximum(836);
        Yinput = new QSpinBox(centralWidget);
        Yinput->setObjectName(QStringLiteral("Yinput"));
        Yinput->setGeometry(QRect(706, 260, 151, 22));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(460, 20, 441, 20));
        QFont font1;
        font1.setPointSize(12);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setUnderline(true);
        font1.setWeight(50);
        font1.setKerning(true);
        label->setFont(font1);
        label->setLocale(QLocale(QLocale::Danish, QLocale::Greenland));
        label->setFrameShadow(QFrame::Plain);
        label->setAlignment(Qt::AlignCenter);
        label1 = new QLabel(centralWidget);
        label1->setObjectName(QStringLiteral("label1"));
        label1->setGeometry(QRect(460, 90, 441, 21));
        label1->setFont(font);
        label1->setTextFormat(Qt::PlainText);
        label1->setAlignment(Qt::AlignCenter);
        label2 = new QLabel(centralWidget);
        label2->setObjectName(QStringLiteral("label2"));
        label2->setGeometry(QRect(460, 110, 441, 20));
        label2->setFont(font);
        label2->setAlignment(Qt::AlignCenter);
        label7 = new QLabel(centralWidget);
        label7->setObjectName(QStringLiteral("label7"));
        label7->setGeometry(QRect(460, 530, 441, 20));
        label7->setAlignment(Qt::AlignCenter);
        label6 = new QLabel(centralWidget);
        label6->setObjectName(QStringLiteral("label6"));
        label6->setGeometry(QRect(460, 410, 441, 20));
        label6->setAlignment(Qt::AlignCenter);
        verifyButton = new QPushButton(centralWidget);
        verifyButton->setObjectName(QStringLiteral("verifyButton"));
        verifyButton->setGeometry(QRect(460, 560, 441, 41));
        label4 = new QLabel(centralWidget);
        label4->setObjectName(QStringLiteral("label4"));
        label4->setGeometry(QRect(460, 310, 441, 20));
        label4->setAlignment(Qt::AlignCenter);
        label5 = new QLabel(centralWidget);
        label5->setObjectName(QStringLiteral("label5"));
        label5->setGeometry(QRect(460, 350, 441, 20));
        label5->setAlignment(Qt::AlignCenter);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 914, 21));
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
        label3->setText(QApplication::translate("MainWindow", "Please input coordinates for the desired destination:", nullptr));
        xLabel->setText(QApplication::translate("MainWindow", "x:", nullptr));
        yLabel->setText(QApplication::translate("MainWindow", "y:", nullptr));
        throwButton->setText(QApplication::translate("MainWindow", "Throw", nullptr));
        label->setText(QApplication::translate("MainWindow", "Welcome to the ThrowBot GUI!", nullptr));
        label1->setText(QApplication::translate("MainWindow", "Click the button below to open the camera, then press enter to capture.", nullptr));
        label2->setText(QApplication::translate("MainWindow", "The image will then be processed and the location of the object determined.", nullptr));
        label7->setText(QApplication::translate("MainWindow", "Click the button below to verify by taking a picture after the throw.", nullptr));
        label6->setText(QApplication::translate("MainWindow", "Click the button below to throw the object to the chosen coordinates.", nullptr));
        verifyButton->setText(QApplication::translate("MainWindow", "Verify Throw", nullptr));
        label4->setText(QApplication::translate("MainWindow", "X-axis has to be between: -159  and: 836", nullptr));
        label5->setText(QApplication::translate("MainWindow", "Y-axis has to be between: -538  and: -201 ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
