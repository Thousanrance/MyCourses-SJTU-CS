#include "record.h"

Record::Record(int id, int poi, QDateTime t, double x, double y)
{
    user_id = id;
    location_id = poi;
    time = t;
    longitude = x;
    latitude = y;
}
