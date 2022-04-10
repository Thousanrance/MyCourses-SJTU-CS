#include<iostream>
#include<cmath>
using namespace std;

class Matrix
{
    private:
        int lin;
        int col;
        int** mat;
    public:
        void Initialization(int l,int c);
        void Transpose();
        int Determinant(int l);
};

void Matrix::Initialization(int l,int c)
{
    lin=l;
    col=c;
    mat=new int*[lin];
    for(int k=0;k<lin;k++)
    {
        mat[k]=new int[col];
    }
    for(int i=0;i<l;i++)
    {
        for(int j=0;j<c;j++)
        {
            cin>>mat[i][j];
        }
    }
}

void Matrix::Transpose()
{
    for(int j=0;j<col;j++)
    {
        for(int i=0;i<lin;i++)
        {
            cout<<mat[i][j]<<(i+1==lin?"\n":" ");
        }
    }
}

int Matrix::Determinant(int l)
{



    //chongxie
}

int complement(int** mat,int n,int i,int j)
{
    if(n==2)
    {
        return pow(-1,i+j)*(mat[0][0]*mat[1][1]-mat[0][1]*mat[1][0]);
    }
    else
    {
        n--;
        int** cmpl;
        cmpl=new int* [n];
        for(int k=0;k<n;k++)
        {
            cmpl[k]=new int [n];
        }
        for(int )

    }


}

int main()
{
    int l,c;
    Matrix A;
    cin>>l>>c;
    A.Initialization(l,c);
    A.Transpose();
    /*if(l==c)
    {
        cout<<A.Determinant(l);
    }
    else
    {
        cout<<'@';
    }*/
    return 0;
}
