#include <iostream>

using namespace std;

class Rational
{
    private:
    int num;
    int den;
    public:
    Rational()
    {

    }
    Rational(int n,int d)
    {
        num=n;
        den=d;
    }
    void display()
    {
        printf("%d",num);
        printf("/");
        printf("%d\n",den);
    }
    bool operator>(const Rational &r1) const;
};

bool Rational::operator>(const Rational &r1) const
{
    return num * r1.den > den * r1.num;
}

bool abs(int p,int q)
{
    int lit=(p>q)?q:p;
    for(int i=2;i<=lit;i++)
    {
        if(p%i==0&&q%i==0)
        {
            return false;
        }
    }
    return true;
}

void quick_sort(Rational s[], int l, int r)
{
    if(l < r)
    {
        int i = l, j = r;
        Rational x = s[l];
        while(i < j)
        {
            while(i < j && s[j] > x) // 从右向左找第一个小于x的数
            {
                j--;
            }
            if(i < j)
            {
                s[i++] = s[j];
            }
            while(i < j && x > s[i]) // 从左向右找第一个大于等于x的数
            {
                 i++;
            }
            if(i < j)
            {
                s[j--] = s[i];
            }
        }
        s[i] = x;
        quick_sort(s, l, i - 1); // 递归调用
        quick_sort(s, i + 1, r);
    }
}

int main()
{
    int n,k;
    scanf("%d",&n);
    scanf("%d",&k);
    Rational *res;
    res=new Rational [k+1];
    int current=0;
    for(int q=n;q>1;q--)
    {
        for(int p=q-1;p>=1;p--)
        {
            if(abs(p,q))
            {
                Rational x(p,q);
                if(current<k)
                {
                    res[++current]=x;
                }
                else if(current==k)
                {
                    quick_sort(res,1,k);
                    if(x>res[1])
                    {
                        res[1]=x;
                        quick_sort(res,1,k);
                        current++;
                    }
                }
                else
                {
                   if(x>res[1])
                    {
                        res[1]=x;
                        quick_sort(res,1,k);
                    }
                }
            }
        }
    }
    Rational ans=res[1];
    ans.display();
    return 0;
}
