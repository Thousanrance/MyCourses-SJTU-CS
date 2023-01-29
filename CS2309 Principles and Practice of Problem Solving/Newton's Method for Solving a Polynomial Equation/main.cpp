/*
Problem Description
Use Newton's method to solve a polynomial equation. The equation can be represented as a
n
​
 x
n
 +a
n−1
​
 x
n−1
 +...+a
0
​
 =0

The input contains two lines. The first line contains an integer n. The second line contains n+1 floating point numbers a
0
​
 ,...,a
n
​
 .

Examples
When you test your answer with the given examples, the root you get may be slightly different from the examples because of the precision or multiple roots of the equation. All available answers will be accepted! When you debug your program, you can run it on your PC.

The equation x
2
 +x−1=0
Input: 2
       -1.0 1.0 1.0
Your Answer: 0.618034
The equation x
3
 +3x
2
 +3x+1=0
Input: 3
       1.0 3.0 3.0 1.0
Your Answer: -1.000000
Note
Recommend to use double to store the values in your program.
Don't round your answer! Our test program will substitute your answer back into the given equation and check if the result is near 0.
For Newton's method, use the following configuration:
Maximum iterations: 10
5

x
0
​
 =0
Stopping criterion: ∣x
k
​
 −x
k−1
​
 ∣<10
−6

The iteration of the given equation will be convergent with the configuration mentioned in 3 (Other initial value may not!).
n≤20
*/


#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

/* This is the class you need to implement. *DO NOT* output anything in your code.
   We will get your answer as below:
    Newton solution(n, a);
    double answer = solution.solve();

   Feel free to add any members in the class.*/

int iteration=0;

class Newton
{
    int n;
    vector<double> a;
    vector<double> b;
public:
    Newton(int _n, vector<double> _a)
    {
        n=_n;
        //cout<<n<<endl;
        a=_a;
        //cout<<a[2]<<endl;

        double tmp;
        for(int i=1;i<=n;i++)
        {
            tmp=a[i]*i;
            b.push_back(tmp);
            //cout<<tmp<<' ';
        }
        //cout<<b[1]<<endl;
        //cout<<endl;
    }

    double solve()
    {
        // Fill in code here!
        //cout<<"here3"<<endl;
        if(a[0]==0)
        {
            return 0.0;
        }
        return g(0.0);
    }

    double f(double x)
    {
        //cout<<"here5"<<endl;
        double res=0;
        for(int i=0;i<=n;i++)
        {
            res+=a[i]*pow(x,i);
        }
        //cout<<"fx0="<<res<<endl;
        return res;
    }

    double df(double x)
    {
        //cout<<"here6"<<endl;
        double res=0;
        for(int i=0;i<n;i++)
        {
            res+=b[i]*pow(x,i);
        }
        //cout<<"dfx0="<<res<<endl;
        return res;
    }

    double g(double xk)
    {
        iteration++;
        if(iteration>pow(10,5))
        {
            return xk;
        }
        //cout<<"here4"<<endl;
        double xk1=xk-f(xk)/df(xk);
        cout<<"x1="<<xk1<<endl;
        if(fabs(xk1-xk)<pow(10,-6))
        {
            return xk1;
        }
        else
        {
            //cout<<"here7"<<endl;
            //system("pause");
            return g(xk1);
        }
    }
};

int main()
{
    int n;
    cin>>n;

    vector<double> a;

    for(int i=0;i<=n;i++)
    {
        double num;
        cin>>num;
        a.push_back(num);
    }

    Newton solution(n,a);
    //cout<<"here1"<<endl;
    double answer = solution.solve();
    //cout<<"here2"<<endl;
    double check=solution.f(answer);
    cout<<setiosflags(ios::fixed)<<setprecision(6)<<check;

    return 0;
}
