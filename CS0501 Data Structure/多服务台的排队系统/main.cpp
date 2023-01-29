#include <iostream>
#include <cstdlib>
#include <ctime>
#include "../��ʽ����/linkQueue.h"

using namespace std;

class simulator
{
private:
    int noOfServer; //����̨����
    int arrivalLow; //������ʱ����½�
    int arrivalHigh; //������ʱ����Ͻ�
    int serviceTimeLow; //������ʱ����½�
    int serviceTimeHigh; //������ʱ����Ͻ�
    int customNum; //ģ��Ĺ˿���
    struct eventT
    {
        int time; //�¼�����ʱ��
        int type; //�¼����͡�0Ϊ���1Ϊ�뿪
        bool operator<(const eventT &e)const
        {
            return time < e.time;
        }
    };
public:
    simulator();
    int avgWaitTime();
};

simulator::simulator()
{
    cout << "�������̨����"; cin >> noOfServer;
    cout << "�����뵽��ʱ���������½磨��С���ʱ�� �����ʱ�䣩��";
    cin >> arrivalLow >> arrivalHigh;
    cout << "���������ʱ������½磨����ʱ���½� ����ʱ���Ͻ磩��";
    cin >> serviceTimeLow >> serviceTimeHigh;
    cout << "������ģ��Ĺ˿�����";
    cin >> customNum;
    srand(time(NULL));
}

int simulator::avgWaitTime()
{
    int serverBusy = 0; // ���ڹ����ķ���̨��
    int currentTime; // ��¼ģ������е�ʱ��
    int totalWaitTime = 0; //ģ����������й˿͵ĵȴ�ʱ����ܺ�
    linkQueue<eventT> waitQueue; //�˿͵ȴ�����
    priorityQueue<eventT> eventQueue; //�¼�����
    eventT currentEvent; //���ɳ�ʼ���¼�����
    int i;
    currentEvent.time = 0;
    currentEvent.type = 0;
    for(i=0; i<customNum; ++i)
    {
        currentEvent.time += arrivalLow + (arrivalHigh -arrivalLow +1) * rand() / (RAND_MAX + 1);
        eventQueue.enQueue(currentEvent);
    } //ģ�����
    while(!eventQueue.isEmpty())
    {
        currentEvent = eventQueue.deQueue();
        currentTime = currentEvent.time;
        switch(currentEvent.type)
        {
            case 0: //�������¼�
                    if(serverBusy != noOfServer)
                    {
                        ++serverBusy;
                        currentEvent.time += serviceTimeLow + (serviceTimeHigh - serviceTimeLow +1) * rand() / (RAND_MAX + 1);
                        currentEvent.type = 1;
                        eventQueue.enQueue(currentEvent);
                    }
                    else
                    {
                        waitQueue.enQueue(currentEvent);
                    }
                    break;
            case 1: //�����뿪�¼�
                    if(!waitQueue.isEmpty())
                    {
                        currentEvent = waitQueue.deQueue();
                        totalWaitTime += currentTime - currentEvent.time;
                        currentEvent.time = currentTime + serviceTimeLow + (serviceTimeHigh - serviceTimeLow +1) * rand() / (RAND_MAX + 1);
                        currentEvent.type = 1;
                        eventQueue.enQueue(currentEvent);
                    }
                    else
                    {
                        --serverBusy;
                    }
        }
    }
    return totalWaitTime / customNum;
}

int main()
{
    simulator sim;
    cout << "ƽ���ȴ�ʱ�䣺" << sim.avgWaitTime() << endl;
    return 0;
}
