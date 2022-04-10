/*
	This is the program to calculate the radius of the circle.
*/

#include<iostream>
#include<cmath>

using namespace std;

int main(/*int argc,char*argv[]*/)
{
	double area;
	
	cout<<"Please input the area of a circle:";
	cin>>area;
	
	double r;
	
	r=sqrt(area/M_PI);//Calculate the radius
	
	cout<<endl<<"The radius is:"<<r<<endl;
	
	return 0;
}
