#include "loadworker.h"
#include "globalvar.h"
#include <record.h>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QFile>
#include <QString>
#include <QTextStream>
#include <QDateTime>

LoadWorker::LoadWorker(QObject *parent, QFile * file) : QObject(parent)
{
    csvfile = file;
}

void LoadWorker::doloadwork()
{
    csvfile->open(QIODevice::ReadOnly);
    QStringList eachline;
    eachline.clear();

    QTextStream in(csvfile);

    //记录遍历行数
    int r = 0;
    int percent = 0;
    //需要处理的五个数据
    int user;
    int poi;
    QDateTime t;
//    int t_t; //时间戳，存进数据库
    double x;
    double y;
    //开始过滤
//    QSqlQuery query;
//    query.exec("DELETE FROM POI");
    while(!in.atEnd())
    {
        QString fileLine = in.readLine();
        r++;
        //根据行数过滤
        if(r < v_recfrom)
        {
            continue;
        }
        eachline = fileLine.split(",", QString::SkipEmptyParts);
        //根据用户过滤
        user = eachline[0].toInt();
        if(user < v_userfrom)
        {
            continue;
        }
        if(user > v_userto)
        {
            emit loadprogress(100);
            break;
        }
        //根据poi过滤
        if(poiorgps)
        {
            poi = eachline[1].toInt();
            if(poi < v_poifrom || poi > v_poito)
            {
                continue;
            }
            x = eachline[4].toDouble();
            y = eachline[3].toDouble();
        }
        else
        {
            x = eachline[4].toDouble();
            if(x < v_xfrom || x > v_xto)
            {
                continue;
            }
            y = eachline[3].toDouble();
            if(y < v_yfrom || y > v_yto)
            {
                continue;
            }
            poi = eachline[1].toInt();
        }
        //根据时间过滤
        t = QDateTime::fromString(eachline[2],"yyyy-MM-ddThh:mm:ssZ");
        qDebug() << t ;
        if(t < v_timefrom || t > v_timeto)
        {
            continue;
        }
//        t_t = t.toTime_t();

        //数据库无法跨线程使用，我能力有限没办法解决这个问题，所以只能换方案
//        query.prepare("INSERT INTO POI(user_id, location_id, time, latitude, longitute) VALUES (:vuser, :vpoi, :vt, :vy, :vx)");
//        query.bindValue(":vuser", user);
//        query.bindValue(":vpoi", poi);
//        query.bindValue(":vt", t_t);
//        query.bindValue(":vy", y);
//        query.bindValue(":vx", x);

//        query.exec();

        //qDebug() << user << poi << t << y << x ;

        Record rec(user, poi, t, x, y);

        interest.insert(r, rec);

        qDebug() << r ;
        percent = (r - v_recfrom + 1)*100/(v_recto - v_recfrom + 1);
        qDebug() << percent ;
        emit loadprogress(percent);
        //进度达到100后结束循环
        if(percent == 100)
        {
            break;
        }
    }

    //query.exec();

//    Record i;
//    foreach(i, interest)
//    {
//        qDebug() << i.time ;
//    }

    emit loadprogress(100);
    csvfile->close();
    emit loadover();
}
