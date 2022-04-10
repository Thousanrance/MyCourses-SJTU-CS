#include<iostream>
#include<cmath>

using namespace std;

int main()
{
    int a,b,num=0;
    cin>>a>>b;
    
	int tmp,rank,m;
    
    for(int i=a;i<=b;i++)
    {
    	tmp=i;
    	rank=0;
    	
    	int n,fig=0;
    	
    	while(tmp!=0)
    	{
    		rank++;
    		tmp=tmp/10;
    		
			m=pow(10,rank-1);
			n=i/m%10;
			fig=fig+pow(n,3);
		}
		
		if(fig==i)
		{
			cout<<i<<' ';
			num++;
		}
	}
	
	if(num==0)
	{
		cout<<"no"; 
	}
	
    return 0;
}
