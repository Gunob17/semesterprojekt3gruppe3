#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
	void on_loadButton_clicked();

	void on_startButton_clicked();

	void on_Xinput_valueChanged();

	void on_throwButton_clicked();

	void on_verifyButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H


