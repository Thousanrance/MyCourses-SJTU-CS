#include<iostream>
#include<cstdio>
#include<vector>
#include<iomanip>
#include<cmath>
#include<sstream>
using namespace std;

void printM(vector<vector<double>> matrix, int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		cout << endl;
		for (int j = 0; j < col; j++)
        {
			cout << matrix[i][j] << ' ';
        }
	}
}

int main()
{
	int row = 0, col = 0;
	double a;
	vector<vector<double>> matrix;
	vector<double>v;
	string str;
	getline(cin, str);
	stringstream Matrix(str);

	while (Matrix >> a)
	{
		v.push_back(a);
	}

	col = v.size();
	row = col - 1;

	matrix.resize(row);

	for (int i = 0; i < col; i++)
    {
        matrix[0].push_back(v[i]);
    }

	for (int i = 1; i < row; i++)
	{
		string mystr;
		getline(cin, mystr);
		stringstream Mystr(mystr);
		while (Mystr >> a)
        {
            matrix[i].push_back(a);
        }
	}

	int p = 0;

	for (int k = 0; k < row; k++) //��ÿһ��
    {
		int cur = p; //��p�п�ʼ
		double max = fabs(matrix[p][k]);

		for (int j = p + 1; j < row; j++) //����һ�о���ֵ����Ԫ��
		{
			if (fabs(matrix[j][k]) > max)
			{
				cur = j; //���Ԫ����������
				max = fabs(matrix[j][k]);
			}
		}

		if (max < 1e-8) //�����ֵΪ0��ת����һ��
        {
            continue;
        }

		for (int j = 0; j < col; ++j) //�������Ԫ�������к͵�p��
		{
			double tmp = matrix[p][j];
			matrix[p][j] = matrix[cur][j];
			matrix[cur][j] = tmp;
		}

		for (int i = p+1; i < row; ++i) //��p+1�п�ʼ��˹��Ԫ
		{
			double tmp = matrix[i][k] / matrix[p][k];
			for (int j = k + 1; j < col; j++)
            {
                matrix[i][j] -= tmp * matrix[p][j];
            }
		}
		p++;
	}

	p--;//pΪ��������

	if (p < row - 1)
	{
		for(int i = p + 1; i < row; ++i)
        {
			if (fabs(matrix[i][col - 1]) > 1e-8)
			{
			    cout << "No solution";
                return 0;
            }
			else
            {
                cout << "No unique solution";
                return 0;
            }
        }
	}

	double* X = new double[row] {};

	X[row - 1] = matrix[row - 1][col - 1] / matrix[row - 1][col - 2];

	for (int i = row-2; i >= 0; i--)
	{
		double temp = 0;
		for (int j = i + 1; j < row; j++)
		{
			temp += matrix[i][j] * X[j];
		}
		X[i] = (matrix[i][col - 1] - temp) / matrix[i][i];
	}

	for (int i = 0; i < row; i++)
	{
		cout <<fixed << setprecision(3) << X[i] << ' ';
	}

	return 0;
}
