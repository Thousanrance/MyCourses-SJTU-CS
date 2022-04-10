#include <iostream>
#include "linkStack.h"

using namespace std;

int calcPost(char *sufStr) //计算后缀式
{
    int op1, op2, op;
    int tmp, i;
    linkStack<int> s;
    i=0;
    while(sufStr[i]!='\0')
    {
        if((sufStr[i]>='0')&&(sufStr[i]<='9')) //数字转为整数后进栈
        {
            tmp = sufStr[i] - '0';
            s.push(tmp);
        }
        else
        {
            //栈顶整数出栈
            op2 = s.top();
            s.pop();
            op1 = s.top();
            s.pop();
            switch (sufStr[i])
            {
                case '*' : op = op1*op2; break; //如果是运算符为'*',则做*运算
                case '/' : op = op1/op2; break;
                case '+' : op = op1+op2; break;
                case '-' : op = op1-op2; break;
            };
            s.push(op); //每一步计算结果进栈
        }
        i++;
    }
    op = s.top();
    s.pop(); //计算结果出栈
    return op;
}

void inToSufForm(char *inStr, char *sufStr)//中缀式转为后缀式
{
    linkStack<char> s; //用字符栈
    int i,j;
    char topCh,hash='#';
    s.push(hash); //铺垫一个底垫
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
                case '(' : s.push(inStr[i]); break; //优先级最高，直接入栈
                case ')' : //弹栈，弹出元素进入后缀式，直到弹出一个左括号
                           topCh = s.pop();
                           while(topCh!='(')
                           {
                               sufStr[j++] = topCh;
                               topCh = s.pop();
                           } //')'字符不入栈
                           break;
                case '*' :
                case '/' :
                            topCh = s.top();
                            while((topCh=='*')||(topCh=='/')) //*、/为左结合，后来者优先级低
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
                            while((topCh!='(')&&(topCh!='#')) //只有左括号和底垫优先级比+、-低
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
    //将栈中还没有弹出的操作符弹空
    topCh = s.top();
    while(topCh!='#')
    {
        sufStr[j++] = topCh;
        s.pop();
        topCh = s.top();
    }
    sufStr[j]='\0'; //后缀字符串加结束符'\0'
}

int main()
{
    return 0;
}
