#include "workerforonepoi.h"
#include <QDebug>
#include <QHash>
#include <QMetaType>

Workerforonepoi::Workerforonepoi(QObject *parent) : QObject(parent)
{
    qRegisterMetaType<QMap<QDate, int>>("QMap<QDate, int>");
}

void Workerforonepoi::dowkforonepoi()
{
    //准备计数器
    QMap<QDate, int> counter;

    QDate d(sday);

    while(d != eday)
    {
        counter.insert(d, 0);
        d = d.addDays(1);
    }

    QHash<int, Record>::const_iterator i;

    //计数
    for(i = interest.constBegin(); i != interest.constEnd(); ++i)
    {
        if(i.value().location_id == onepoi && i.value().time.date() >= sday && i.value().time.date() <= eday)
        {
            counter[i.value().time.date()] = counter[i.value().time.date()] + 1;
        }
    }

    emit onepoiinfo(counter);

    emit wkforonepoiover();

}
