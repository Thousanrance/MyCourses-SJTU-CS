//无序表的查找
template <class KEY, class OTHER>
int seqSearch(SET<KEY, OTHER> data[], int size, const KEY &x)
{
    data[0].key = x;
    int i;
    for(i = size ; x != data[i].key; --i);
    return i;
}

//有序表的查找
//顺序查找
template <class KEY, class OTHER>
int seqSearch(SET<KEY, OTHER> data[], int size, const KEY &x)
{
    data[0].key = x;
    int i;
    for(i = size ; x < data[i].key; --i); //默认数据由小到大有序
    if(x == data[i].key)
    {
        return i;
    }
    else
    {
        return 0;
    }
}

//二分查找
template <class KEY, class OTHER>
int binarySearch(SET<KEY, OTHER> data[], int size, const KEY &x)
{
    int low = 1, high = size, mid;
    while(low <= high )
    { //查找区间存在
        mid = (low + high) / 2; //计算中间位置
        if ( x == data[mid].key ) return mid;
        if ( x < data[mid].key) high = mid - 1;
        else low = mid + 1;
    }
    return 0;
}
