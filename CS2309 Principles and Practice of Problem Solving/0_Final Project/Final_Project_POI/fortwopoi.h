#ifndef FORTWOPOI_H
#define FORTWOPOI_H

#include <QWidget>
#include <QDate>

namespace Ui {
class ForTwoPOI;
}

class ForTwoPOI : public QWidget
{
    Q_OBJECT

public:
    explicit ForTwoPOI(QWidget *parent = nullptr);
    ~ForTwoPOI();

    int poi1;
    int poi2;
    QDate sday;
    QDate eday;

private:
    Ui::ForTwoPOI *ui;
};

#endif // FORTWOPOI_H
