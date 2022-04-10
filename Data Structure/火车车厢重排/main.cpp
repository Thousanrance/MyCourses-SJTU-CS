#include <iostream>
#include "../链式队列/linkQueue.h"

using namespace std;

bool putBuffer(linkQueue<int> *buffer,int size,int in);
void checkBuffer(linkQueue<int> *buffer,int size,int &last);

void arrange(int in[],int n,int k)
{
    linkQueue<int> *buffer=new linkQueue<int> [k]; //表示k条缓冲轨道
    int last=0; //出轨上最后一节车厢的编号
    for(int i=0;i<n;i++) //依次处理入轨上的车厢
    {
        if(!putBuffer(buffer,k,in[i])) //无可用的缓冲轨道
        {
            return;
        }
        checkBuffer(buffer,k,last);
    }
}

bool putBuffer(linkQueue<int> *buffer,int size,int in)
{
    int avail=-1,max=0; //avail为最合适的缓冲队列号，max为该队列尾元素的编号。
    for(int j=0;j<size;j++) //寻找合适的队列
    {
        if(buffer[j].isEmpty()) //找到空队列，备用
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
    if(avail!=-1) //进入合适的缓冲队列
    {
        buffer[avail].enQueue(in);
        cout<<in<<"移入缓冲区"<<avail<<endl;
        return true;
    }
    else
    {
        cout<<"无可行方案"<<endl;
        return false;
    }
}

void checkBuffer(linkQueue<int> *buffer,int size,int &last)
{
    int j;
    int flag=true; //有元素出队
    while(flag) //反复检查所有队列，将合适元素出队
    {
        flag=false;
        for(j=0;j<size;j++) //检查所有队列
        {
            if(!buffer[j].isEmpty()&&buffer[j].getHead()==last+1)
            {
                cout<<"将"<<buffer[j].deQueue()<<"从缓冲区"<<j<<"移到出轨"<<endl;
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
