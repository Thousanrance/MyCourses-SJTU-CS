#ifndef RECORD_H
#define RECORD_H

#include <QDateTime>

class Record
{
public:
    Record(){};
    Record(int id, int poi, QDateTime t, double x, double y);

public:
    int user_id;
    int location_id;
    QDateTime time;
    double latitude;
    double longitude;
};

#endif // RECORD_H
