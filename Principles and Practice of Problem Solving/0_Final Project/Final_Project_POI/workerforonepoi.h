#ifndef WORKERFORONEPOI_H
#define WORKERFORONEPOI_H

#include <QObject>
#include "globalvar.h"
#include <QMap>
#include <QDate>

class Workerforonepoi : public QObject
{
    Q_OBJECT
public:
    explicit Workerforonepoi(QObject *parent = nullptr);

    void dowkforonepoi();

signals:

    void onepoiinfo(QMap<QDate, int> DAU);
    void wkforonepoiover();

public:
    int onepoi;
    QDate sday;
    QDate eday;

};

#endif // WORKERFORONEPOI_H
