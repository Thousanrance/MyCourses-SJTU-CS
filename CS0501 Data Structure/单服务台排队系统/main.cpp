/*
ʵ��һ��������̨�Ŷ�ϵͳ���˿͵ĵ���ʱ���Ϊÿ���˿ͷ����ʱ�䲻ȷ����
�����ȵ��ȷ����ԭ��ÿ���˿͵���ϵͳʱ��Ҫ�Ŷӵȴ���ǰһλ�˿ͷ�����ϣ�
Ҫ�����ÿ���˿͵�ƽ���ȴ�ʱ�䡣

Input Format
�� 1 �У�һ������ n, ��ʾ���� n ���˿ͣ�

�� 2 �� n + 1 �У�ÿ��һ������ t ��һ������ s������ t ��ʾ�˿͵ĵ���ʱ�̣�s ��ʾ�˿ͷ��������ʱ��

Output Format
���һ������������ʾ���й˿��ڶ����е�ƽ���ȴ�ʱ��

*/

#include <cstdio>

int main()
{
    int num;
    scanf("%d",&num);
    int current=0;
    double wait=0;
    int event;

    for(int i=0;i<num;i++)
    {
        int a,s;
        scanf("%d",&a);
        scanf("%d",&s);

        event=a;
        if(event<current)
        {
            wait+=current-event;
        }
        else
        {
            current=event;
        }
        current+=s;
    }
    printf("%.2lf",wait/num);

    return 0;
}
