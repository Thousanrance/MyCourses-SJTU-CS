#ifndef FORONEPOI_H
#define FORONEPOI_H

#include <QWidget>
#include <QDate>

namespace Ui {
class ForOnePOI;
}

class ForOnePOI : public QWidget
{
    Q_OBJECT

public:
    explicit ForOnePOI(QWidget *parent = nullptr);
    ~ForOnePOI();

    int onepoi;
    QDate sday;
    QDate eday;

private:
    Ui::ForOnePOI *ui;
};

#endif // FORONEPOI_H
