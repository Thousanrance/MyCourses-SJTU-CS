/*
Problem Description
Use Gaussian Elimination to solve a linear system Ax = b.
The input is in the form of the augmented mat [A b].
A system of linear equations can have no solution, a unique solution or infinitely many solutions.
The output should be as follows:

if a system has no solution:
    print "No solution!"
elif a system has infinitely many solutions:
    print "No unique solution!"
else:
    print the result.

Examples
Given the linear system:
10x
1
​
 −x
2
​
 +2x
3
​
 +0x
4
​
 =6
−x
1
​
 +11x
2
​
 −x
3
​
 +3x
4
​
 =25
2x
1
​
 −x
2
​
 +10x
3
​
 −x
4
​
 =−11
0x
1
​
 +3x
2
​
 −x
3
​
 +8x
4
​
 =15

Input: 10 -1 2 0 6
       -1 11 -1 3 25
       2 -1 10 -1 -11
       0 3 -1 8 15
Output: 1.000 2.000 -1.000 1.000
Given that
x
1
​
 +x
2
​
 +x
3
​
 =4
2x
1
​
 +2x
2
​
 +x
3
​
 =6
x
1
​
 +x
2
​
 +2x
3
​
 =6

Input: 1 1 1 4
       2 2 1 6
       1 1 2 6
Output: No unique solution!
Given that
2x
1
​
 +3x
2
​
 =10
2x
1
​
 +3x
2
​
 =12

Input: 2 3 10
    2 3 12
Output: No solution!

Note
The input will not have invalid characters, such as non-numerical values, and the number of rows is equal to the number of variables.
The output retains three decimal places (rounded).
*/

#include <iostream>
#include <vector>
#include <sstream>
#include <iomanip>
#include <cmath>
using namespace std;

// Implement your Gaussian Elimination algorithm.
// You can add any standard library if needed.
//

int Gaussian(double** A,double* b,int n)
{
    //cout<<"here Gaussian"<<endl;

    int r = 0;//非零行数

	for (int i = 0; i < n; i++) //对每一列,把除了第r行之外的元素消为0
    {
		int cur = r; //从r行开始
		double max = fabs(A[r][i]);

		for (int j = r + 1; j < n; j++) //找这一列绝对值最大的元素
		{
			if (fabs(A[j][i]) > max)
			{
				cur = j; //最大元素所在行数
				max = fabs(A[j][i]);
			}
		}

		if (max < 1e-8) //若r以下全为0，则不需要处理，转到下一列，仍从r行开始处理
        {
            continue;
        }

        double tmp;
		for (int k = 0; k < n; k++) //交换最大元素所在行和第r行，最大元素转移到第r行了
		{
			double tmp = A[r][k];
			A[r][k] = A[cur][k];
			A[cur][k] = tmp;
		}
		tmp=b[r];
		b[r]=b[cur];
		b[cur]=tmp;

		for (int p = r+1; p < n; p++) //高斯消元
		{
			double temp = A[p][i] / A[r][i];
			for (int q = i; q < n; q++)
            {
                A[p][q] -= temp * A[r][q];
            }
            b[p]=b[p]-temp*b[r];
		}
		r++;
	}

	//r为非零行数
	//cout<<r<<endl;

	if(r < n)
	{
		for(int i = r; i < n; i++)//从非零行的下一行开始
        {
			if (fabs(b[i]) > 1e-8)
			{
			    return 1;
            }
        }
        return 2;
	}

    return 3;

}

// Test your implementation.
int main()
{
    // Input processing.
    string str;
    getline(cin, str); //读入第一行
    stringstream input(str);

    vector<double> elem;
    double a;

    while(input >> a)
    {
        elem.push_back(a);
    }

    int row;
    row=elem.size(); //获取列数

    for(int i=row-2;i>0;i--) //读入剩下几行
    {
        string str;
        getline(cin, str);
        stringstream input(str);

        double a;

        while(input >> a)
        {
            elem.push_back(a);
        }
    }

    int num;
    num=elem.size(); //所有元素个数

    int lin;
    lin=num/row; //行数

    //cout<<lin<<' '<<row<<endl;

    //创建动态数组
    double **Ab = new double* [lin];

    for(int i=0;i<lin;i++)
    {
        Ab[i]=new double [row];
    }

    //创建增广矩阵
    int m=0;
    for(int i=0;i<lin;i++)
    {
        for(int j=0;j<row;j++)
        {
            Ab[i][j] = elem[m++];
        }
    }

    /*
    for(int i=0;i<lin;i++)
    {
        for(int j=0;j<row;j++)
        {
            cout<<Ab[i][j]<<' ';
        }
        cout<<endl;
    }
    */

    //cout<<endl;

    //系数矩阵
    double **A = new double* [lin];
    for(int i=0;i<lin;i++)
    {
        A[i]=new double [lin];
    }
    for(int i=0;i<lin;i++)
    {
        for(int j=0;j<lin;j++)
        {
            A[i][j]=Ab[i][j];
        }
    }

    //b矩阵
    double *b = new double [lin];
    for(int i=0;i<lin;i++)
    {
        b[i]=Ab[i][lin];
    }

    // Solve the linear system and print the results.

    int n=lin;

    int flag = Gaussian(A,b,n);

/*
     for(int i=0;i<lin;i++)
    {
        for(int j=0;j<lin;j++)
        {
            cout<<A[i][j]<<' ';
        }
        cout<<endl;
    }

    cout<<endl;

    for(int i=0;i<lin;i++)
    {
        cout<<b[i]<<' ';
    }

    cout<<endl;
    cout<<endl;
*/

    if(flag==1)
    {
        cout<<"No solution!";
    }
    if(flag==2)
    {
        cout<<"No unique solution!";
    }
    if(flag==3)
    {
        double *res = new double [n];

        res[n-1]=b[n-1]/A[n-1][n-1];

        for(int i=n-2;i>=0;i--)
        {
            double sum=0;
            for(int j=i+1;j<n;j++)
            {
                sum += A[i][j]*res[j];
            }
            res[i]=(b[i]-sum)/A[i][i];
        }
        for(int i=0;i<n;i++)
        {
            cout<<setiosflags(ios::fixed)<<setprecision(3)<<res[i]<<' ';
        }
    }

    //system("pause");

    return 0;
}
