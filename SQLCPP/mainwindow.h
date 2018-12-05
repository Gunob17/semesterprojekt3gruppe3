#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_load_clicked();

    void on_pushButton_insert_clicked();

    void on_pushButton_delete_clicked();

    void on_pushButton_update_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
