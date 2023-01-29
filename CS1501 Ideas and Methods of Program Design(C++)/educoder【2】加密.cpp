#include<iostream>

using namespace std;

int main()
{
	int n,m;
	cin>>n>>m;
	
	int n_tho=(n/1000+7)%10;
	int n_hun=((n/100)%10+7)%10;
	int n_ten=((n/10)%10+7)%10;
	int n_one=(n%10+7)%10;

	int n_code=n_ten*1000+n_one*100+n_tho*10+n_hun;
			
	int m_tho1=m/1000;
	int m_hun1=(m/100)%10;
	int m_ten1=(m/10)%10;
	int m_one1=m%10;
	
	int m_tho,m_hun,m_ten,m_one;
		
	if(m_tho1<7)
	{
		m_tho=m_tho1+3;
	}
	else
	{
		m_tho=m_tho1-7;
	}
	
	if(m_hun1<7)
	{
		m_hun=m_hun1+3;
	}
	else
	{
		m_hun=m_hun1-7;
	}
	
	if(m_ten1<7)
	{
		m_ten=m_ten1+3;
	}
	else
	{
		m_ten=m_ten1-7;
	}
	
	if(m_one1<7)
	{
		m_one=m_one1+3;
	}
	else
	{
		m_one=m_one1-7;
	}
	
	int m_key=m_ten*1000+m_one*100+m_tho*10+m_hun;
		
	cout<<n_code<<" "<<m_key;
	
	return 0;
	
	
 } 
