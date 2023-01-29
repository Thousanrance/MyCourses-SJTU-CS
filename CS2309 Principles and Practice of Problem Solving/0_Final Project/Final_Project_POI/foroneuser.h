#ifndef FORONEUSER_H
#define FORONEUSER_H

#include <QWidget>
#include <QDateTime>


namespace Ui {
class ForOneUser;
}

class ForOneUser : public QWidget
{
    Q_OBJECT

public:
    explicit ForOneUser(QWidget *parent = nullptr);
    ~ForOneUser();

    int oneuser;
    QDateTime starttime;
    QDateTime endtime;

private:
    Ui::ForOneUser *ui;
};

#endif // FORONEUSER_H
