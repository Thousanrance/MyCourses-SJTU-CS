#include <iostream>
#include <cstdlib>
#include <ctime>
#include "../链式队列/linkQueue.h"

using namespace std;

class simulator
{
    int arrivalLow; //到达时间间隔下界
    int arrivalHigh; //到达时间间隔上界
    int serviceTimeLow; //服务时间下限
    int serviceTimeHigh; //服务时间上限
    int customNum; //模拟的顾客数
public:
    simulator();
    double avgWaitTime()const;
};

simulator::simulator()
{
    cout<<"请输入到达时间间隔的上下界:";
    cin>>arrivalLow>>arrivalHigh;
    cout<<"请输入服务时间的上下界:";
    cin>>serviceTimeLow>>serviceTimeHigh;
    cout<<"请输入模拟的顾客数:";
    cin>>customNum;
    srand(time(NULL));
}

double simulator::avgWaitTime()const
{
    int currentTime=0; //当前时间
    int totalWaitTime=0; //总的等待时间
    int eventTime;
    linkQueue<int> customerQueue; //顾客到达事件队列
    int i;
    for(i=0;i<customNum;i++) //生成所有的到达事件
    {
        currentTime+=arrivalLow+(arrivalHigh-arrivalLow+1)*rand()/(RAND_MAX+1);
        customerQueue.enQueue(currentTime);
    }

    currentTime=0;
    while(!customerQueue.isEmpty())
    {
        eventTime=customerQueue.deQueue();
        if(eventTime<currentTime) //收集等待信息
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
    cout<<"平均等待时间："<<sim.avgWaitTime()<<endl;
    return 0;
}
