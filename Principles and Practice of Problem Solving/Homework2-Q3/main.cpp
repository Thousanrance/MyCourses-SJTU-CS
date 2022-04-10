
#include <iostream>
#include <vector>
#include <sstream>
#include <iomanip>
using namespace std;


// You can add additional standard libraries if necessary.
// Implement the Lagrange interpolation!
class Lagrange
{
public:
    Lagrange(vector<double> x, vector<double> y): X(x), Y(y){}

    double lagrange_interpolation(int len,double xn)
    {
        double yn=0;
        double P=0;

        for(int k=0;k<len;k++)
        {
            P=Y[k];
            for(int j=0;j<len;j++)
            {
                if(j!=k)
                {
                    P*=(xn-X[j])/(X[k]-X[j]);
                }
            }
            yn += P;
        }

        return yn;
    }

private:
    vector<double> X, Y;
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

    // Do Lagrange interpolation for interp_x using X and Y, and print your results
    // Note: The result retains three decimal places (rounded)!
    Lagrange Pn(X,Y);

    int len=X.size();

    double i;
    for(i=-5;i<=5;i+=0.1)
    {
        interp_x=i;
        cout<<setiosflags(ios::fixed)<<setprecision(3)<<Pn.lagrange_interpolation(len,interp_x)<<endl;
    }

    // End
    return 0;
}






/*
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

    // Do Newton interpolation for interp_x using X and Y, and print your results
    // Note: The result retains three decimal places (rounded)!
    int len=X.size();

    Newton N(X,Y,len);

    double i;
    for(i=-5;i<=5;i+=0.1)
    {
        interp_x=i;
        cout<<setiosflags(ios::fixed)<<setprecision(3)<<N.newton_interpolation(interp_x)<<endl;
    }

    // End
    return 0;
}
*/
