#include <iostream>

using namespace std;

template <class elemType>
class stackk
{
public:
    virtual bool isEmpty()const = 0;
    virtual elemType top()const = 0;
    virtual void push(const elemType &x) = 0;
    virtual elemType pop() = 0;
    virtual ~stackk(){}
};

class outOfBound{};

template <class elemType>
class linkStack: public stackk<elemType>
{
private:
    struct node
    {
        elemType data;
        node *next;
        node(const elemType &x, node *N = NULL)
        {
        	data = x;
            next = N;
        }
        node():next(NULL){} //头结点专属，可以不要
        ~node(){}
	};
	node *Top; //T为什么要大写：避免与函数同名
public:
    linkStack();
    ~linkStack();
    bool isEmpty()const;
    elemType top()const;
    elemType pop();
    void push(const elemType &x);
};

template <class elemType>
linkStack<elemType>::linkStack()
{
    Top = NULL;
}

template <class elemType>
linkStack<elemType>::~linkStack() //释放每个结点
{
    node *tmp;
    while(Top!=NULL)
    {
    	//兄弟协同法
        tmp = Top;
        Top = Top->next;
    	delete tmp;
    }
}

template <class elemType>
bool linkStack<elemType>::isEmpty()const
{
    return Top == NULL;
}

template <class elemType>
elemType linkStack<elemType>::pop()
{
    if(Top==NULL)
    {
        throw outOfBound();
    }
    node *tmp = Top;
    elemType x = Top->data;
    Top = Top->next;
    delete tmp;
    return x;
}

template <class elemType>
elemType linkStack<elemType>::top()const
{
    if(Top==NULL)
    {
        throw outOfBound();
    }
    return Top->data;
}

template <class elemType>
void linkStack<elemType>::push(const elemType &x)
{
    Top = new node(x, Top);
}


int main()
{
    linkStack<int> Min;
    linkStack<int> Max;

    int days;
    scanf("%d",&days);

    int price,earnt=0,earne=0;
    int lowest=0;
    scanf("%d",&price);
    Min.push(price);
    Max.push(lowest);

    for(int i=1;i<days;i++)
    {
        int price;
        scanf("%d",&price);
        if(price<Min.top())
        {
            Min.push(price);
            Max.push(lowest);
            earnt=Max.top()-Min.top();
        }
        if(price>Max.top())
        {
            Max.push(price);
            earnt=Max.top()-Min.top();
        }
        if(earnt>earne)
        {
            earne=earnt;
        }
    }
    printf("%d",earne);
    return 0;

}
