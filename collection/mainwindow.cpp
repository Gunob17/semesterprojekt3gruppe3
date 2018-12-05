#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "login.h"
#include "imageprocessing.h"
#include <QtSql>
#include <QtSql/QSql>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtDebug>
#include <QString>

Login conn;
ImageProcessing img;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow){
    ui->setupUi(this);
    conn.makeConection();
    on_pushButton_load_clicked();
	
}

MainWindow::~MainWindow(){

    delete ui;
}

void MainWindow::on_pushButton_load_clicked(){

    QSqlQueryModel * model = new  QSqlQueryModel();

    //Pointer, da man vil kun referere til en allerede oprettet connection, ikke oprette en ny!
    QSqlQuery* query = new QSqlQuery(conn.db);

    query->prepare("SELECT * FROM test123.koordinator;");

	query->exec();

    model->setQuery(*query);
    ui->tableView->setModel(model);
}

void MainWindow::on_pushButton_insert_clicked(){

   /* if (ui->nameInput->text().isEmpty() || ui->ssnInput->text().isEmpty()) {}
    else {
            QString name;
            QString SSN;

            name = ui->nameInput->text();
            SSN  = ui->ssnInput->text();

            QString toSQL = "insert into person values (NULL, "+ SSN +", '"+ name +"')";

            QSqlQuery* query = new QSqlQuery(conn.db);

            query->prepare(toSQL);
            query->exec();

            ui->nameInput->clear();
            ui->ssnInput->clear();
            ui->IDInput->clear();
     */       on_pushButton_load_clicked();
    }



void MainWindow::on_pushButton_delete_clicked(){
	/*
    if (ui->IDInput->text().isEmpty()) {}
    else {
        QString ID;

        ID = ui->IDInput->text();

        QString toSQL = "Delete FROM person WHERE ID =" + ID;

        QSqlQuery* query = new QSqlQuery(conn.db);

        query->prepare(toSQL);
        query->exec();

        ui->nameInput->clear();
        ui->ssnInput->clear();
        ui->IDInput->clear();
		*/
        on_pushButton_load_clicked();
    }


void MainWindow::on_pushButton_update_clicked(){
/*
    QString name;
    QString SSN;
    QString ID;

    if (ui->nameInput->text().isEmpty()) {}
    else {
        ID = ui->IDInput->text();
        name = ui->nameInput->text();
        QString toSQL = "UPDATE person SET aName = '" + name + "' WHERE ID = " + ID +"";
        QSqlQuery* query = new QSqlQuery(conn.db);

        query->prepare(toSQL);
        query->exec();
        on_pushButton_load_clicked();
    }

    if (ui->ssnInput->text().isEmpty()) {}
    else {
        ID = ui->IDInput->text();
        SSN = ui->ssnInput->text();
        QString toSQL2 = "UPDATE person SET ssn = '" + SSN + "' WHERE ID = " + ID +"";
        QSqlQuery* query2 = new QSqlQuery(conn.db);

        query2->prepare(toSQL2);
        query2->exec();*/
        on_pushButton_load_clicked();
    /*}

    ui->nameInput->clear();
    ui->ssnInput->clear();
    ui->IDInput->clear();
	*/
}
void MainWindow::on_test_clicked() {
	img = ImageProcessing(0);
	img.undistort();
	img.PanoramicDistortion();
	img.findTemplate();
	img.findCenter();
	cv::destroyAllWindows();
	cv::Point2i center = img.getCenter();
	QString x = QString::number(center.x - 300);
	QString y = QString::number(center.y - 900);
	QString toSQL = "insert into koordinator values (NULL," + x + ", " + y + ",NULL,NULL)";
	QSqlQuery* query = new QSqlQuery(conn.db);
	query->prepare(toSQL);
	query->exec();
	on_pushButton_load_clicked();
}

