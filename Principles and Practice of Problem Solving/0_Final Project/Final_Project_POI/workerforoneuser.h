#ifndef WORKERFORONEUSER_H
#define WORKERFORONEUSER_H

#include <QObject>
#include "globalvar.h"
#include <QVector>
#include <QPoint>


class Workerforoneuser : public QObject
{
    Q_OBJECT
public:
    explicit Workerforoneuser(QObject *parent = nullptr);

    void dowkfoneusr();

signals:
    void oneusrinfo(QVector<QPoint> popular);
    void wkfoneusrover();

public:
    int oneuser;
    QDateTime stime;
    QDateTime etime;

};

#endif // WORKERFORONEUSER_H
