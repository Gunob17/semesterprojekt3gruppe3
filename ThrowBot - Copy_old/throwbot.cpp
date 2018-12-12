#include "throwbot.h"
#include "ui_throwbot.h"

ThrowBot::ThrowBot(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ThrowBot)
{
    ui->setupUi(this);
}

ThrowBot::~ThrowBot()
{
    delete ui;
}
