#ifndef THROWBOT_H
#define THROWBOT_H

#include <QMainWindow>

namespace Ui {
class ThrowBot;
}

class ThrowBot : public QMainWindow
{
    Q_OBJECT

public:
    explicit ThrowBot(QWidget *parent = nullptr);
    ~ThrowBot();

private:
    Ui::ThrowBot *ui;
};

#endif // THROWBOT_H
