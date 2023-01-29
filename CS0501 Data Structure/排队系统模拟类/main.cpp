#include <iostream>
#include <cstdlib>
#include <ctime>
#include "../��ʽ����/linkQueue.h"

using namespace std;

class simulator
{
    int arrivalLow; //����ʱ�����½�
    int arrivalHigh; //����ʱ�����Ͻ�
    int serviceTimeLow; //����ʱ������
    int serviceTimeHigh; //����ʱ������
    int customNum; //ģ��Ĺ˿���
public:
    simulator();
    double avgWaitTime()const;
};

simulator::simulator()
{
    cout<<"�����뵽��ʱ���������½�:";
    cin>>arrivalLow>>arrivalHigh;
    cout<<"���������ʱ������½�:";
    cin>>serviceTimeLow>>serviceTimeHigh;
    cout<<"������ģ��Ĺ˿���:";
    cin>>customNum;
    srand(time(NULL));
}

double simulator::avgWaitTime()const
{
    int currentTime=0; //��ǰʱ��
    int totalWaitTime=0; //�ܵĵȴ�ʱ��
    int eventTime;
    linkQueue<int> customerQueue; //�˿͵����¼�����
    int i;
    for(i=0;i<customNum;i++) //�������еĵ����¼�
    {
        currentTime+=arrivalLow+(arrivalHigh-arrivalLow+1)*rand()/(RAND_MAX+1);
        customerQueue.enQueue(currentTime);
    }

    currentTime=0;
    while(!customerQueue.isEmpty())
    {
        eventTime=customerQueue.deQueue();
        if(eventTime<currentTime) //�ռ��ȴ���Ϣ
        {
            totalWaitTime+=currentTime-eventTime;
        }
        else
        {
            currentTime=eventTime;
        }
        currentTime+=serviceTimeLow+(serviceTimeHigh-serviceTimeLow+1)*rand()/(RAND_MAX+1);
    }
    return totalWaitTime*1.0/customNum;
}

int main()
{
    simulator sim;
    cout<<"ƽ���ȴ�ʱ�䣺"<<sim.avgWaitTime()<<endl;
    return 0;
}
