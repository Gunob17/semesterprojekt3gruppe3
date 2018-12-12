/// by Simon Askholm and Frederik Hansen
#include "login.h"

#include <QtSql>
#include <QtSql/QSql>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtDebug>

Login::Login() {}

void Login::makeConnection() {
	QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");

	db.setHostName("localhost");
	db.setPort(3306);
	db.setDatabaseName("test123");
	db.setUserName("root");
	db.setPassword("pass");
	if (db.open()) {
		qDebug() << "Opened!";
	}
	else if (!db.isValid()) {
		qDebug() << "Error = " << db.lastError().text();
	}
}