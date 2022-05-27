# include <math.h>
# include <stdio.h>
# include <iostream>
# include <algorithm>

using namespace std;

const int MAX_N = 100000 + 5;

int n, arr[MAX_N];

void qsort(int *arr, int l, int r)
{
    /*
    Arguments:
        - arr: the array;
        - l: left-end point of the unsorted array;
        - r: right-end point of the unsorted array.
    */
    // TODO: implement the given QuickSort algorithm here.
}

void QuickSort(int n, int *arr)
{
    // TODO: implement the "shuffle" trick mentioned in the question here.
    
    // Call the recursive QuickSort procedure.
    qsort(arr, 1, n);
}

int main()
{
    ios :: sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // Input
    cin >> n;
    for (int i = 1; i <= n; ++ i) cin >> arr[i];

    // QuickSort
    QuickSort(n, arr);

    // Output
    for (int i = 1; i <= n; ++ i) cout << arr[i] << ' ';
    cout << endl;
    return 0;
}