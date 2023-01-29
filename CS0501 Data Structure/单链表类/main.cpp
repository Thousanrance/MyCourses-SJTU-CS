//һԪ����ʽ�ļӷ�

#include<iostream>
#include"linkList.h"

using namespace std;

struct Type
{
    int coef; // ϵ��
    int exp; // ��ָ��
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
    elemType stop_flag; // �����ж϶���ʽ���������
public:
    //���û�����ȡ������־����ʼ������ʽ
    Polynomial(const elemType &stop);
    void getPoly(); //����һ������ʽ
    void addPoly(const Polynomial &L1,const Polynomial &L2);//L1+L2
    void dispPloy();//��ʾһ������ʽ
    void clear();//�ͷŶ���ʽ�ռ�
    ~Polynomial()
    {
        clear();
        delete head;
    };
};

int main() //������
{
    Type stop_flag;
    getStop(stop_flag); //����ֹͣ��־��
    Polynomial<Type> L1(stop_flag), L2(stop_flag), L3(stop_flag);
    L1.getPoly(); //�����һ������ʽ
    L2.getPoly(); //����ڶ�������ʽ
    L3.addPoly(L1,L2); //L1 = L2 +L3
    L3.dispPloy(); //��ʾ����ʽL3������
    return 0;
}
