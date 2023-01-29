#ifndef FORTWOUSERS_H
#define FORTWOUSERS_H

#include <QWidget>
#include <QDateTime>

namespace Ui {
class ForTwoUsers;
}

class ForTwoUsers : public QWidget
{
    Q_OBJECT

public:
    explicit ForTwoUsers(QWidget *parent = nullptr);
    ~ForTwoUsers();

    int user1;
    int user2;
    QDateTime starttime;
    QDateTime endtime;

private:
    Ui::ForTwoUsers *ui;
};

#endif // FORTWOUSERS_H
