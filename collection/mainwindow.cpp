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

    //Pointer, da man vil kun referere til en allerede oprettet connection, ikke oprette en ny!
    QSqlQuery* query = new QSqlQuery(conn.db);

    query->prepare("SELECT * FROM test123.koordinator;");

    query->exec();

    model->setQuery(*query);
    ui->tableView->setModel(model);
}

void MainWindow::on_startButton_clicked() {
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
    on_loadButton_clicked();
    QMessageBox::information(this, "Message", "The image was processed successfully!");
}

void MainWindow::on_throwButton_clicked() {
    point = cv::Point(ui->xInput->value(), ui->yInput->value());
    img.makePlacement(point.x, point.y);
    QMessageBox::information(this, "Message", "The object will now be thrown to the chosen destination");
    cv::destroyAllWindows();
}

void MainWindow::on_verifyButton_clicked() {
//    ImageProcessing finalImage;
    img = ImageProcessing(0);
    img.undistort();
    img.PanoramicDistortion();
    img.verifyThrow(point.x, point.y);
    QMessageBox::information(this, "Message", "The throw has been completed with these results");
    cv::destroyAllWindows();
}
