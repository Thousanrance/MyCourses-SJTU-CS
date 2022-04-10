//一元多项式的加法

#include<iostream>
#include"linkList.h"

using namespace std;

struct Type
{
    int coef; // 系数
    int exp; // 幂指数
};
template <class elemType>
struct Node
{
    elemType data;
    Node* next;
};
template <class elemType>
class Polynomial
{
private:
    Node<elemType>* head;
    elemType stop_flag; // 用于判断多项式输入结束。
public:
    //从用户处获取结束标志并初始化多项式
    Polynomial(const elemType &stop);
    void getPoly(); //读入一个多项式
    void addPoly(const Polynomial &L1,const Polynomial &L2);//L1+L2
    void dispPloy();//显示一个多项式
    void clear();//释放多项式空间
    ~Polynomial()
    {
        clear();
        delete head;
    };
};

int main() //主函数
{
    Type stop_flag;
    getStop(stop_flag); //读入停止标志对
    Polynomial<Type> L1(stop_flag), L2(stop_flag), L3(stop_flag);
    L1.getPoly(); //读入第一个多项式
    L2.getPoly(); //读入第二个多项式
    L3.addPoly(L1,L2); //L1 = L2 +L3
    L3.dispPloy(); //显示多项式L3的内容
    return 0;
}
