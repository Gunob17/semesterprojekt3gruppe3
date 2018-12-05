#include "mainwindow.h"
#include "conection.h"

#include <QApplication>

#include <QtSql>
#include <QtSql/QSql>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>

#include <QtDebug>
#include <QString>
#include <iostream>



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);



    MainWindow w;
    w.show();

    return a.exec();
}
