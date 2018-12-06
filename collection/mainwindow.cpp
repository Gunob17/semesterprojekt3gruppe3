#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "login.h"
#include "imageprocessing.h"

#include <cmath>
#include <QtSql>
#include <QtSql/QSql>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtDebug>
#include <QString>
#include <QMessageBox>

Login conn;
ImageProcessing img;
cv::Point point;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow){
    ui->setupUi(this);
    conn.makeConection();
	on_loadButton_clicked();
	
}

MainWindow::~MainWindow(){

    delete ui;
}

void MainWindow::on_loadButton_clicked() {

    QSqlQueryModel * model = new  QSqlQueryModel();

    //Pointer, da man kun vil referere til en allerede oprettet connection, ikke oprette en ny!
    QSqlQuery* query = new QSqlQuery(conn.db);

    query->prepare("SELECT * FROM test123.koordinator;");

	query->exec();

    model->setQuery(*query);
    ui->tableView->setModel(model);
}


void MainWindow::on_startButton_clicked() {
	img = ImageProcessing(1);
	
	img.undistort();
	img.PanoramicDistortion();
	img.findTemplate();
	img.findCenter();
	
	cv::destroyAllWindows();
	cv::Point2i center = img.getCenter();
	QString x = QString::number(center.x - 300);
	QString y = QString::number(center.y - 900);
	QString toSQL = "insert into koordinator values (NULL," + x + ", " + y + ",NULL,NULL,NULL,NULL)";
	
	QSqlQuery* query = new QSqlQuery(conn.db);
	query->prepare(toSQL);
	query->exec();
	on_loadButton_clicked();
	QMessageBox::information(this, "Message", "The image was processed successfully!");
}

void MainWindow::on_Xinput_valueChanged() {
	int x_spin;
	int y_spin;

	x_spin = ui->Xinput->value();
	y_spin = ui->Yinput->value();
	/*if (y_spin <= 0.9815498*(x_spin) + (-1130.576)) {
		ui->Yinput->setValue(0.9815498*x_spin + (-1130.576));
		//ui->label->setText("y axis has to be between: " + QString::number(0.9815498*(x_spin)+(-1130.576)) + " and: " + QString::number(-1.030369*x_spin + 551.3884));
	}
	else if (y_spin <= -1.030905*x_spin + -538.9139) {
		ui->Yinput->setValue(-1.030905*x_spin + -538.9139);
		//ui->label->setText("y axis has to be between: " + QString::number(0.9815498*(x_spin)+(-1130.576)) + " and: " + QString::number(-1.030369*x_spin + 551.3884));
	}
	if (y_spin >= -1.030369*x_spin + 551.3884) {
		ui->Yinput->setValue(-1.030369*x_spin + 551.3884);
		//ui->label->setText("y axis has to be between: " + QString::number(0.9815498*(x_spin)+(-1130.576)) + " and: " + QString::number(-1.030369*x_spin + 551.3884));
	}
	else if (y_spin >= 0.9775281*x_spin  + -201.573) {
		ui->Yinput->setValue(0.9775281*x_spin + -201.573);
		//ui->label->setText("y axis has to be between: " + QString::number(0.9815498*(x_spin)+(-1130.576)) + " and: " + QString::number(-1.030369*x_spin + 551.3884));
	}
	*/
	if (y_spin <= 12.4321*x_spin + (-4497.037)) {
		ui->label5->setText("Y-axis has to be between: " + QString::number(0.9815498*(x_spin)+(-1130.576)) + " and: " + QString::number(-1.030369*x_spin + 551.3884));
		ui->Yinput->setRange(0.9815498*(x_spin)+(-1130.576), -1.030369*x_spin + 551.3884);
	}
	else if (y_spin > 12.4321*x_spin + (-4497.037)) {
		ui->label5->setText("Y-axis has to be between: " + QString::number(-1.030905*x_spin + -538.9139) + " and: " + QString::number(0.9775281*x_spin + -201.573));
		ui->Yinput->setRange(-1.030905*x_spin + -538.9139, 0.9775281*x_spin + -201.573);
	}
	
	
}
void MainWindow::on_throwButton_clicked() {
	point = cv::Point(ui->Xinput->value(), ui->Yinput->value());
	img = ImageProcessing("./images/robcalc02.jpg");
	img.PanoramicDistortion();
	img.makePlacement(point.x, point.y);
	QMessageBox::information(this, "Message", "The object will now be thrown to the chosen destination");
	cv::destroyAllWindows();
	QSqlQueryModel * model = new  QSqlQueryModel();
	QSqlQuery* query = new QSqlQuery(conn.db);

	query->prepare("SELECT * FROM test123.koordinator;");

	query->exec();
	model->setQuery(*query);

	int place = model->rowCount();
	
	QSqlQuery* query2 = new QSqlQuery(conn.db);
	QString toSQL = "UPDATE `test123`.`koordinator` SET `throwx` = "+ QString::number(point.x)+", `throwy` = "+ QString::number(point.y) +" WHERE (`testnr` = "+ QString::number(place) +");";
	query2->prepare(toSQL);

	query2->exec();
	on_loadButton_clicked();
}
void MainWindow::on_verifyButton_clicked() {
	//    ImageProcessing finalImage;
	img = ImageProcessing(1);
	img.undistort();
	img.PanoramicDistortion();
	img.verifyThrow(point.x, point.y);
	QMessageBox::information(this, "Message", "The throw has been completed with these results");
	cv::destroyAllWindows();
	
	cv::Point2i center = img.getCenter();
	QString x = QString::number(center.x - 300);
	QString y = QString::number(center.y - 900);
	int lenth = std::sqrt(std::pow(point.x - (center.x - 300), 2) + std::pow(point.y - (center.y - 900), 2));
	ui->label_2->setText("there is " + QString::number(lenth) + " mm between target and object");
	QSqlQueryModel * model = new  QSqlQueryModel();
	QSqlQuery* query = new QSqlQuery(conn.db);

	query->prepare("SELECT * FROM test123.koordinator;");

	query->exec();

	model->setQuery(*query);

	int place = model->rowCount();

	QSqlQuery* query2 = new QSqlQuery(conn.db);
	QString toSQL = "UPDATE `test123`.`koordinator` SET `landx` = " +x+", `landy` = " +y+" WHERE(`testnr` = "+ QString::number(place)+");";
	query2->prepare(toSQL);

	query2->exec();
	on_loadButton_clicked();
	
}

