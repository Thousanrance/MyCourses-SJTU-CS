#include "workerfortwopoi.h"
#include <QDebug>
#include <QHash>
#include <QMetaType>

Workerfortwopoi::Workerfortwopoi(QObject *parent) : QObject(parent)
{
    qRegisterMetaType<QMap<QDate, int>>("QMap<QDate, int>");
}

void Workerfortwopoi::dowkfortwopoi()
{
    //准备计数器
    QMap<QDate, int> counter1;
    QMap<QDate, int> counter2;

    QDate d(sday);

    while(d != eday)
    {
        counter1.insert(d, 0);
        counter2.insert(d, 0);
        d = d.addDays(1);
    }

    QHash<int, Record>::const_iterator i;

    //计数
    for(i = interest.constBegin(); i != interest.constEnd(); ++i)
    {
        if(i.value().time.date() >= sday && i.value().time.date() < eday)
        {
            if(i.value().location_id == poi1)
            {
                counter1[i.value().time.date()] = counter1[i.value().time.date()] + 1;
            }
            if(i.value().location_id == poi2)
            {
                counter2[i.value().time.date()] = counter2[i.value().time.date()] + 1;
            }

        }
    }

    emit twopoiinfo(counter1, counter2);

    emit wkfortwopoiover();

}
