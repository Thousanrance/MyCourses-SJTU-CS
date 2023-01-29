#include <iostream>
#include "../��ʽ����/linkQueue.h"

using namespace std;

bool putBuffer(linkQueue<int> *buffer,int size,int in);
void checkBuffer(linkQueue<int> *buffer,int size,int &last);

void arrange(int in[],int n,int k)
{
    linkQueue<int> *buffer=new linkQueue<int> [k]; //��ʾk��������
    int last=0; //���������һ�ڳ���ı��
    for(int i=0;i<n;i++) //���δ�������ϵĳ���
    {
        if(!putBuffer(buffer,k,in[i])) //�޿��õĻ�����
        {
            return;
        }
        checkBuffer(buffer,k,last);
    }
}

bool putBuffer(linkQueue<int> *buffer,int size,int in)
{
    int avail=-1,max=0; //availΪ����ʵĻ�����кţ�maxΪ�ö���βԪ�صı�š�
    for(int j=0;j<size;j++) //Ѱ�Һ��ʵĶ���
    {
        if(buffer[j].isEmpty()) //�ҵ��ն��У�����
        {
            if(avail==-1)
            {
                avail=j;
            }
            else if(buffer[j].getTail()<in&&buffer[j].getTail()>max)
            {
                avail=j;
                max=buffer[j].getTail();
            }
        }
    }
    if(avail!=-1) //������ʵĻ������
    {
        buffer[avail].enQueue(in);
        cout<<in<<"���뻺����"<<avail<<endl;
        return true;
    }
    else
    {
        cout<<"�޿��з���"<<endl;
        return false;
    }
}

void checkBuffer(linkQueue<int> *buffer,int size,int &last)
{
    int j;
    int flag=true; //��Ԫ�س���
    while(flag) //����������ж��У�������Ԫ�س���
    {
        flag=false;
        for(j=0;j<size;j++) //������ж���
        {
            if(!buffer[j].isEmpty()&&buffer[j].getHead()==last+1)
            {
                cout<<"��"<<buffer[j].deQueue()<<"�ӻ�����"<<j<<"�Ƶ�����"<<endl;
                last++;
                flag=true;
                break;
            }
        }
    }
}

int main()
{
    return 0;
}
