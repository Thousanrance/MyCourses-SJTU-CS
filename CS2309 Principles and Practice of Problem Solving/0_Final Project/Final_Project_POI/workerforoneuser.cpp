#include "workerforoneuser.h"
#include <QDebug>
#include <QHash>
#include <QPoint>
#include <QVector>
#include <QMetaType>



Workerforoneuser::Workerforoneuser(QObject *parent) : QObject(parent)
{
    qRegisterMetaType<QVector<QPoint>>("QVector<QPoint>");
}

void Workerforoneuser::dowkfoneusr()
{
    QHash<int, int> counter;

    QHash<int, Record>::const_iterator i;

    //先插入符合条件的记录的poi
    qDebug() << "here!" ;
    qDebug() << interest.size();
    for(i = interest.constBegin(); i != interest.constEnd(); ++i)
    {
        qDebug() << i.value().time ;
        qDebug() << stime;
        if(i.value().user_id == oneuser && i.value().time >= stime && i.value().time <= etime)
        {
            counter.insert(i.value().location_id, 0);
            qDebug() << counter.size();
        }
    }

    //再计数
    for(i = interest.constBegin(); i != interest.constEnd(); ++i)
    {
        if(i.value().user_id == oneuser && i.value().time >= stime && i.value().time <= etime)
        {
            counter[i.value().location_id] = counter[i.value().location_id] + 1;
        }
    }

    //取出最大的十个
    QVector<QPoint> info;

    int numofpoi = counter.size();

    QHash<int, int>::const_iterator j;

    if(numofpoi <= 10) //如果少于10个就直接取出排序
    {
        for(j = counter.constBegin(); j != counter.constEnd(); ++j)
        {
            QPoint tmp(j.key(), j.value());
            info.push_back(tmp);
        }
        quickSort(info, numofpoi);
    }
    else //多于10个就维护一个基于快排的堆
    {
        int k = 0;
        for(j = counter.constBegin(); j != counter.constEnd(); ++j)
        {
            QPoint tmp(j.key(), j.value());
            if(k < 10)
            {
                info.push_back(tmp);
                k++;
            }
            else
            {
                quickSort(info, 10);
                if(j.value() > info[9].y())
                {
                    info[9].setX(j.key());
                    info[9].setY(j.value());
                }
            }
        }
    }

    emit oneusrinfo(info);

    emit wkfoneusrover();
}
