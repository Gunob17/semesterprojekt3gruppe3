#include "login.h"

#include <QtSql>
#include <QtSql/QSql>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtDebug>

Login::Login(){}

void Login::makeConnection(){

    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");

    db.setHostName("127.0.0.1");
    db.setPort(3306);
    db.setDatabaseName("test123");
    db.setUserName("root");
    db.setPassword("pass");

    if (!db.isValid()){
        qDebug() << "Error = " << db.lastError().text();
    }
}
