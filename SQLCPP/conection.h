#ifndef CONECTION_H
#define CONECTION_H

#include <QtSql>
#include <QtSql/QSql>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>

#include <QtDebug>
#include <QString>
#include <iostream>


class conection
{
public:
    conection();

    void makeConection();
};

#endif // CONECTION_H
