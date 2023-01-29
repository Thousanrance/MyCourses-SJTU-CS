//�����Ĳ���
template <class KEY, class OTHER>
int seqSearch(SET<KEY, OTHER> data[], int size, const KEY &x)
{
    data[0].key = x;
    int i;
    for(i = size ; x != data[i].key; --i);
    return i;
}

//�����Ĳ���
//˳�����
template <class KEY, class OTHER>
int seqSearch(SET<KEY, OTHER> data[], int size, const KEY &x)
{
    data[0].key = x;
    int i;
    for(i = size ; x < data[i].key; --i); //Ĭ��������С��������
    if(x == data[i].key)
    {
        return i;
    }
    else
    {
        return 0;
    }
}

//���ֲ���
template <class KEY, class OTHER>
int binarySearch(SET<KEY, OTHER> data[], int size, const KEY &x)
{
    int low = 1, high = size, mid;
    while(low <= high )
    { //�����������
        mid = (low + high) / 2; //�����м�λ��
        if ( x == data[mid].key ) return mid;
        if ( x < data[mid].key) high = mid - 1;
        else low = mid + 1;
    }
    return 0;
}
