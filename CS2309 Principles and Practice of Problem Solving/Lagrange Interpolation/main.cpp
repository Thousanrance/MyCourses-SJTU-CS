/*
Lagrange Interpolation
The main function takes as input two sequences of numbers and one single number. The first sequence represents
[x1,x2,бн,xi] of some points, and the second sequence represents [y1,y2,бн,yi].
You need to find the Lagrange interpolating polynomial to pass through the points.
The single number is the xn of an additional point to be interpolated.

First, implement your Lagrange Interpolation algorithm based on [x1,x2,бн,xi] and [y1,y2,бн,yi].
Then, use it to compute the value yn at xn.

Example:

Input: 0.0 0.1 0.2 0.3 0.4 0.5
       1.0 0.995 0.98 0.955 0.921 0.878
       0.7
Output: 0.748

Note:

1.The output retains three decimal places (rounded)!.

2.[x1,x2,бн,xi] and [y1,y2,бн,yi] are distinct and of equal length.
*/

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
        double P;

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
    cin >> interp_x;

    // Do Lagrange interpolation for interp_x using X and Y, and print your results
    // Note: The result retains three decimal places (rounded)!
    Lagrange Pn(X,Y);

    int len=X.size();

    cout<<setiosflags(ios::fixed)<<setprecision(3)<<Pn.lagrange_interpolation(len,interp_x);

    // End
    return 0;
}
