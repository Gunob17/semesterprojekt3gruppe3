#ifndef LOGIN_H
#define LOGIN_H

#include <QtSql>
#include <QtSql/QSql>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtDebug>

class Login {

public:
    Login();
    void makeConnection();
    QSqlDatabase db;
};

#endif // LOGIN_H
