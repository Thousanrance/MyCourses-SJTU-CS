#ifndef WORKERFORTWOPOI_H
#define WORKERFORTWOPOI_H

#include <QObject>
#include "globalvar.h"
#include <QMap>
#include <QDate>

class Workerfortwopoi : public QObject
{
    Q_OBJECT
public:
    explicit Workerfortwopoi(QObject *parent = nullptr);

    void dowkfortwopoi();

signals:signals:

    void twopoiinfo(QMap<QDate, int> DAU1, QMap<QDate, int> DAU2);
    void wkfortwopoiover();

public:
    int poi1;
    int poi2;
    QDate sday;
    QDate eday;
};

#endif // WORKERFORTWOPOI_H
