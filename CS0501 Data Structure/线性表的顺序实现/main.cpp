//�Ӽ����������ɸ��ַ�������˳�����һ��˳����У�ɾ����һ���ڵ㲢�������뵽���Ա���м�λ��

#include <iostream>
#include "seqList.h"

using namespace std;

int main()
{
    seqList<char> chlist(21);
    //����һ��SeqList��Ķ�������ElemType����Ϊchar���ռ��СΪ21�������±�Ϊ0������Ԫ���⣬�����Է�20����㡣
    char ctemp;
    int i, n, result;
    // ����һ���������������� Enter ��Ϊ������־��
    cout << "number of the elements:"<<endl;
    cin >> n;
    cin.get(ctemp); // �� Enter ������
    cout <<"input the elements:\n"<<endl;
    // ���ַ�������뵽��chlist�У������β��뵽��β��
    for(i=0; i<=n-1; i++)
    {
        cin.get(ctemp);
        chlist.insertt(i, ctemp);
    }
    ctemp = chlist.visit(0); //����׽��.
    chlist.removee(0);
    chlist.insertt(chlist.length()/2, ctemp);
    // ��ɾ�����׽����뵽�м䡣
    cout <<"output the elements:\n"<<endl;
    for(i=0; i<chlist.length(); i++)
    cout.put(chlist.visit(i));
    // ��ȡ��i������ֵ�������
    cout <<'\n';
    return 0;
}
