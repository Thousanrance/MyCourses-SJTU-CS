#ifndef WORKERFORTWOUSERS_H
#define WORKERFORTWOUSERS_H

#include <QObject>
#include "globalvar.h"
#include <QVector>
#include <QPoint>

class Workerfortwousers : public QObject
{
    Q_OBJECT
public:
    explicit Workerfortwousers(QObject *parent = nullptr);

    void dowkftwousrs();

signals:
    void twousrsinfo(QVector<QPoint> popular1, QVector<QPoint> popular2);
    void wkftwousrsover();

public:
    int user1;
    int user2;
    QDateTime stime;
    QDateTime etime;

};

#endif // WORKERFORTWOUSERS_H
