/*
Newton Interpolation
The main function takes as input two sequences of numbers and one single number.
The first sequence represents [x1,x2,¡­,xi] of some points, and the second sequence represents [y1,y2,¡­,yi].
You need to find the Newton interpolating polynomial to pass through the points.
The single number is the xn of an additional point to be interpolated.

First, implement your Newton Interpolation algorithm based on [x1,x2,¡­,xi] and [y1,y2,¡­,yi].
Then, use it to compute the value yn at xn.

Example:

Input: 0.0 0.1 0.2 0.3 0.4 0.5
       1.0 0.995 0.98 0.955 0.921 0.878
       0.7
Output: 0.748

Note:
The output retains three decimal places (rounded)!.

[x1,x2,¡­,xi] and [y1,y2,¡­,yi] are distinct and of equal length.

Theof points are increased monotonically and have the equal interval, i.e. xk=x0+kh,h¡Ê{1,2,¡­}.

*/
#include <iostream>
#include <vector>
#include <sstream>
#include <iomanip>
#include <cmath>

using namespace std;

// You can add additional standard libraries if necessary.
// Implement the Newton interpolation!
class Newton
{
public:
    Newton(vector<double> x, vector<double> y,int l): X(x),Y(y),len(l) {}

    double newton_interpolation(double xn)
    {
        double yn;

        double h=X[1]-X[0];

        double *dt=getDividedDifferenceTable();

        yn=Y[0];

        double mult;
        double k_;

        for(int k=1;k<len;k++)
        {
            mult=1;
            k_=1;
            for(int i=0;i<k;i++)
            {
                mult*=xn-X[i];
                k_*=i+1;
            }
            yn+=dt[k]/(k_*pow(h,k))*mult;
        }

        return yn;
    }

    double *getDividedDifferenceTable()
    {
        double* dt=new double[len];
        for(int i=0;i<len;i++)
        {
            dt[i]=Y[i];
        }
        double tmp1;
        double tmp2;
        for(int k=0;k<len-1;k++)
        {
            tmp1=dt[k];
            tmp2=dt[k+1];
            for(int j=k+1;j<len;j++)
            {
                dt[j]=tmp2-tmp1;
                tmp1=tmp2;
                tmp2=dt[j+1];
            }
        }

        /*cout<<"²î·Ö±íÎª£º"<<endl;
        for(int i=0;i<len;i++)
        {
            cout<<dt[i]<<' ';
        }
        cout<<endl;*/

        return dt;
    }

private:
    vector<double> X,Y;
    int len;
};


// Test your implementation.
int main()
{
    //  Input preprocessing.
    string str;
    getline(cin, str);
    stringstream xstr(str);
    getline(cin, str);
    stringstream ystr(str);

    // X and Y are two vectors of equal length to be traversed.
    vector<double> X, Y;
    double a;
    while (xstr >> a)
    {
        X.push_back(a);
    }
    while (ystr >> a)
    {
        Y.push_back(a);
    }
    // interp_x is the point to be interpolated.
    double interp_x;
    cin >> interp_x;

    // Do Newton interpolation for interp_x using X and Y, and print your results
    // Note: The result retains three decimal places (rounded)!
    int len=X.size();

    Newton N(X,Y,len);

    cout<<setiosflags(ios::fixed)<<setprecision(3)<<N.newton_interpolation(interp_x);

    // End
    return 0;
}

