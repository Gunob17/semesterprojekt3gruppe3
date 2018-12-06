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
	//static void onMouse(int event, int x, int y, int, void *);
    
	void on_pushButton_load_clicked();

    //void on_pushButton_insert_clicked();

    //void on_pushButton_delete_clicked();

    //void on_pushButton_update_clicked();

	void on_test_clicked();

	void on_pushButton_find_clicked();

	void on_Xinput_valueChanged(int arg1);

	//void on_Yinput_valueChanged(int arg1);


private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H


