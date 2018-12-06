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
void MainWindow::on_pushButton_find_clicked() {
	//if (ui->Xinput->text().isEmpty() || ui->Yinput->text().isEmpty()) {}
	
		int x_spin;
		int y_spin;

		x_spin = ui->Xinput->value();
		y_spin = ui->Yinput->value();
	img = ImageProcessing("C:/Users/gusta/Desktop/images/robcalc01.jpg");
	//img.undistort();
	img.PanoramicDistortion();
	img.makePlacement(x_spin,y_spin);

	cv::destroyAllWindows();
	cv::Point2i center = img.getCenter();
	QString x = QString::number(center.x - 300);
	QString y = QString::number(center.y - 900);
	//QString toSQL = "insert into koordinator values (NULL," + x + ", " + y + ",NULL,NULL)";
	//QSqlQuery* query = new QSqlQuery(conn.db);
	//query->prepare(toSQL);
	//query->exec();

	on_pushButton_load_clicked();
}
void MainWindow::on_Xinput_valueChanged(int arg1) {
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
		ui->label->setText("y axis has to be between: " + QString::number(0.9815498*(x_spin)+(-1130.576)) + " and: " + QString::number(-1.030369*x_spin + 551.3884));
		ui->Yinput->setRange(0.9815498*(x_spin)+(-1130.576), -1.030369*x_spin + 551.3884);
	}
	else if (y_spin > 12.4321*x_spin + (-4497.037)) {
		ui->label->setText("y axis has to be between: " + QString::number(-1.030905*x_spin + -538.9139) + " and: " + QString::number(0.9775281*x_spin + -201.573));
		ui->Yinput->setRange(-1.030905*x_spin + -538.9139, 0.9775281*x_spin + -201.573);
	}
	//ui->Yinput->setRange(0.9815498*x_spin + (-525.0406), 0.9775281*x_spin + 405.1685);
	
}

/*void MainWindow::on_Yinput_valueChanged(int arg1) {
	int x_spin;
	int y_spin;

	x_spin = ui->Xinput->value();
	y_spin = ui->Yinput->value();
	ui->Xinput->setRange( (y_spin - 1760.499) / -1.030369,(y_spin - 670.3576) / -1.030905);
	//Qlabel* label
	ui->label2->setText("x axis has to be between: " + QString::number((y_spin - 1760.499) / -1.030369) + " and: " + QString::number((y_spin - 670.3576) / -1.030905));
}*/