#include <iostream>
#include "linkStack.h"

using namespace std;

int calcPost(char *sufStr) //�����׺ʽ
{
    int op1, op2, op;
    int tmp, i;
    linkStack<int> s;
    i=0;
    while(sufStr[i]!='\0')
    {
        if((sufStr[i]>='0')&&(sufStr[i]<='9')) //����תΪ�������ջ
        {
            tmp = sufStr[i] - '0';
            s.push(tmp);
        }
        else
        {
            //ջ��������ջ
            op2 = s.top();
            s.pop();
            op1 = s.top();
            s.pop();
            switch (sufStr[i])
            {
                case '*' : op = op1*op2; break; //����������Ϊ'*',����*����
                case '/' : op = op1/op2; break;
                case '+' : op = op1+op2; break;
                case '-' : op = op1-op2; break;
            };
            s.push(op); //ÿһ����������ջ
        }
        i++;
    }
    op = s.top();
    s.pop(); //��������ջ
    return op;
}

void inToSufForm(char *inStr, char *sufStr)//��׺ʽתΪ��׺ʽ
{
    linkStack<char> s; //���ַ�ջ
    int i,j;
    char topCh,hash='#';
    s.push(hash); //�̵�һ���׵�
    i=0;
    j=0;
    while (inStr[i]!='\0')
    {
        if((inStr[i]>='0')&&(inStr[i]<='9'))
        {
            sufStr[j++]=inStr[i++];
        }
        else
        {
            switch (inStr[i])
            {
                case '(' : s.push(inStr[i]); break; //���ȼ���ߣ�ֱ����ջ
                case ')' : //��ջ������Ԫ�ؽ����׺ʽ��ֱ������һ��������
                           topCh = s.pop();
                           while(topCh!='(')
                           {
                               sufStr[j++] = topCh;
                               topCh = s.pop();
                           } //')'�ַ�����ջ
                           break;
                case '*' :
                case '/' :
                            topCh = s.top();
                            while((topCh=='*')||(topCh=='/')) //*��/Ϊ���ϣ����������ȼ���
                            {
                                s.pop();
                                sufStr[j++] = topCh;
                                topCh = s.top();
                            }
                            s.push(inStr[i]);
                            break;
                case '+' :
                case '-' :
                            topCh = s.top();
                            while((topCh!='(')&&(topCh!='#')) //ֻ�������ź͵׵����ȼ���+��-��
                            {
                                s.pop();
                                sufStr[j++] = topCh;
                                topCh = s.top();
                            }
                            s.push(inStr[i]);
                            break;
            }
            i++;
        }
    }
    //��ջ�л�û�е����Ĳ���������
    topCh = s.top();
    while(topCh!='#')
    {
        sufStr[j++] = topCh;
        s.pop();
        topCh = s.top();
    }
    sufStr[j]='\0'; //��׺�ַ����ӽ�����'\0'
}

int main()
{
    return 0;
}
