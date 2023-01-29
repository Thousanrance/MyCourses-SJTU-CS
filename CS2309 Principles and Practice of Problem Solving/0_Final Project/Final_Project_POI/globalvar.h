#ifndef GLOBALVAR_H
#define GLOBALVAR_H

//#include <QSqlDatabase>
#include <QDateTime>
#include "record.h"
#include <QHash>
#include <QVector>
#include <QPoint>

//global Database
//extern QSqlDatabase interest;
extern QHash<int, Record> interest;

//因为LoadWorker类需要使用这些数据
extern int v_recfrom;
extern int v_recto;
extern int v_userfrom;
extern int v_userto;
extern bool poiorgps; //poi的筛选方式
extern int v_poifrom;
extern int v_poito;
extern double v_xfrom;
extern double v_xto;
extern double v_yfrom;
extern double v_yto;
extern QDateTime v_timefrom;
extern QDateTime v_timeto;




//快排
extern int divide(QVector<QPoint> &a, int low, int high);

extern void quickSort(QVector<QPoint> &a, int low, int high);

extern void quickSort(QVector<QPoint> &a, int size);


#endif // GLOBALVAR_H
