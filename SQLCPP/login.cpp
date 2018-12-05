#include "login.h"

#include <QtSql>
#include <QtSql/QSql>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtDebug>

Login::Login(){}

void Login::makeConection(){

    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");

    db.setHostName("localhost");
    db.setPort(3306);
    db.setDatabaseName("test");
    db.setUserName("root");
    db.setPassword("1234");

    if(db.open()){
        //qDebug() << "Opended!";
        //db.close();
    }
    else if (! db.isValid()){
        qDebug() << "Error = " << db.lastError().text();
    }
}
