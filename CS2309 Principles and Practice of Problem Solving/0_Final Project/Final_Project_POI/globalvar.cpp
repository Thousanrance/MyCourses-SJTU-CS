#include "globalvar.h"


//global
//QSqlDatabase interest = QSqlDatabase::addDatabase("QSQLITE");
QHash<int, Record> interest;

//因为LoadWorker类需要使用
int v_recfrom;
int v_recto;
int v_userfrom;
int v_userto;
bool poiorgps = true;
int v_poifrom;
int v_poito;
double v_xfrom;
double v_xto;
double v_yfrom;
double v_yto;
QDateTime v_timefrom;
QDateTime v_timeto;


//快排:降序
int divide(QVector<QPoint> &a, int low, int high) //划分函数
{
    QPoint  k = a[low];
    do
    {
        while(low < high && a[high].y() <= k.y())
        {
            --high;
        }
        if(low < high)
        {
            a[low] = a[high];
            ++low;
        }
        while(low < high && a[low].y() >= k.y())
        {
            ++low;
        }
        if(low < high)
        {
            a[high] = a[low];
            --high;
        }
    }while(low != high);
    a[low] = k;
    return low;
}

void quickSort(QVector<QPoint> &a, int low, int high)
{
    int mid;
    if(low >= high)
    {
        return;
    }
    mid = divide(a, low, high);
    quickSort(a, low, mid-1); //排序左一半
    quickSort(a, mid+1, high); //排序右一半
}

void quickSort(QVector<QPoint> &a, int size) //包裹函数
{
    quickSort(a, 0, size-1);
}
