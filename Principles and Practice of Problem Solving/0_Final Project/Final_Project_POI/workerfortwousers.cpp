#include "workerfortwousers.h"
#include <QDebug>
#include <QHash>
#include <QPoint>
#include <QVector>
#include <QMetaType>

Workerfortwousers::Workerfortwousers(QObject *parent) : QObject(parent)
{
    qRegisterMetaType<QVector<QPoint>>("QVector<QPoint>");
}

void Workerfortwousers::dowkftwousrs()
{
    QHash<int, int> counter1;
    QHash<int, int> counter2;

    QHash<int, Record>::const_iterator i;

    //先插入符合条件的记录的poi
    qDebug() << "here!" ;
    qDebug() << interest.size();
    for(i = interest.constBegin(); i != interest.constEnd(); ++i)
    {
        qDebug() << i.value().time ;
        qDebug() << stime;
        if(i.value().time >= stime && i.value().time <= etime)
        {
            if(i.value().user_id == user1)
            {
                counter1.insert(i.value().location_id, 0);
                //qDebug() << counter.size();
            }
            if(i.value().user_id == user2)
            {
                counter2.insert(i.value().location_id, 0);
                //qDebug() << counter.size();
            }
        }

    }

    //再计数
    for(i = interest.constBegin(); i != interest.constEnd(); ++i)
    {
        if(i.value().time >= stime && i.value().time <= etime)
        {
            if(i.value().user_id == user1)
            {
                counter1[i.value().location_id] = counter1[i.value().location_id] + 1;
            }
            if(i.value().user_id == user2)
            {
                counter2[i.value().location_id] = counter2[i.value().location_id] + 1;
            }
        }

    }

    //取出最大的十个
    QVector<QPoint> info1;
    QVector<QPoint> info2;

    int num1ofpoi = counter1.size();
    int num2ofpoi = counter2.size();

    QHash<int, int>::const_iterator j;

    if(num1ofpoi <= 10) //如果少于10个就直接取出排序
    {
        for(j = counter1.constBegin(); j != counter1.constEnd(); ++j)
        {
            QPoint tmp(j.key(), j.value());
            info1.push_back(tmp);
        }
        quickSort(info1, num1ofpoi);
    }
    else //多于10个就维护一个基于快排的堆
    {
        int k = 0;
        for(j = counter1.constBegin(); j != counter1.constEnd(); ++j)
        {
            QPoint tmp(j.key(), j.value());
            if(k < 10)
            {
                info1.push_back(tmp);
                k++;
            }
            else
            {
                quickSort(info1, 10);
                if(j.value() > info1[9].y())
                {
                    info1[9].setX(j.key());
                    info1[9].setY(j.value());
                }
            }
        }
    }

    if(num2ofpoi <= 10) //如果少于10个就直接取出排序
    {
        for(j = counter2.constBegin(); j != counter2.constEnd(); ++j)
        {
            QPoint tmp(j.key(), j.value());
            info2.push_back(tmp);
        }
        quickSort(info2, num2ofpoi);
    }
    else //多于10个就维护一个基于快排的堆
    {
        int k = 0;
        for(j = counter2.constBegin(); j != counter2.constEnd(); ++j)
        {
            QPoint tmp(j.key(), j.value());
            if(k < 10)
            {
                info2.push_back(tmp);
                k++;
            }
            else
            {
                quickSort(info2, 10);
                if(j.value() > info2[9].y()) //替换掉最小的
                {
                    info2[9].setX(j.key());
                    info2[9].setY(j.value());
                }
            }
        }
    }

    emit twousrsinfo(info1, info2);

    emit wkftwousrsover();
}
