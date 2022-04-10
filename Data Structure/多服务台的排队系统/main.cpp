#include <iostream>
#include <cstdlib>
#include <ctime>
#include "../链式队列/linkQueue.h"

using namespace std;

class simulator
{
private:
    int noOfServer; //服务台个数
    int arrivalLow; //到达间隔时间的下界
    int arrivalHigh; //到达间隔时间的上界
    int serviceTimeLow; //服务间隔时间的下界
    int serviceTimeHigh; //服务间隔时间的上界
    int customNum; //模拟的顾客数
    struct eventT
    {
        int time; //事件发生时间
        int type; //事件类型。0为到达，1为离开
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
    cout << "请输入柜台数："; cin >> noOfServer;
    cout << "请输入到达时间间隔的上下界（最小间隔时间 最大间隔时间）：";
    cin >> arrivalLow >> arrivalHigh;
    cout << "请输入服务时间的上下界（服务时间下界 服务时间上界）：";
    cin >> serviceTimeLow >> serviceTimeHigh;
    cout << "请输入模拟的顾客数：";
    cin >> customNum;
    srand(time(NULL));
}

int simulator::avgWaitTime()
{
    int serverBusy = 0; // 正在工作的服务台数
    int currentTime; // 记录模拟过程中的时间
    int totalWaitTime = 0; //模拟过程中所有顾客的等待时间的总和
    linkQueue<eventT> waitQueue; //顾客等待队列
    priorityQueue<eventT> eventQueue; //事件队列
    eventT currentEvent; //生成初始的事件队列
    int i;
    currentEvent.time = 0;
    currentEvent.type = 0;
    for(i=0; i<customNum; ++i)
    {
        currentEvent.time += arrivalLow + (arrivalHigh -arrivalLow +1) * rand() / (RAND_MAX + 1);
        eventQueue.enQueue(currentEvent);
    } //模拟过程
    while(!eventQueue.isEmpty())
    {
        currentEvent = eventQueue.deQueue();
        currentTime = currentEvent.time;
        switch(currentEvent.type)
        {
            case 0: //处理到达事件
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
            case 1: //处理离开事件
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
    cout << "平均等待时间：" << sim.avgWaitTime() << endl;
    return 0;
}
