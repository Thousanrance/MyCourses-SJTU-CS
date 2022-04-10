/*
Prime Palindrome
Given an integer n, return the smallest prime palindrome greater than or equal to n.

An integer is prime if it has exactly two divisors: 1 and itself. Note that 1 is not a prime number.

For example, 2, 3, 5, 7, 11, and 13 are all primes.
An integer is a palindrome if it reads the same from left to right as it does from right to left.

For example, 101 and 12321 are palindromes.
The test cases are generated so that 1 <= n <= 10^8, the answer always exists and is in the range [2, 2*10^8].

Example 1
Input: n = 6
Output: 7
Example 2
Input: n = 8
Output: 11
Example 3
Input: n = 13
Output: 101
*/
#include <iostream>
#include <cmath>
#include <math.h>

using namespace std;

class Solution
{
public:
    int primePalindrome(int n)
	{
        if(n<=11)
		{
			switch(n)
			{
				case 1:
				case 2:return 2;break;
				case 3:return 3;break;
				case 4:
				case 5:return 5;break;
				case 6:
				case 7:return 7;break;
				default:return 11;break;
			}
		}

		int modulus=n%6;
		switch(modulus)
		{
			case 0:n++;
			case 1:modulus=1;break;
			case 2:n++;
			case 3:n++;
			case 4:n++;
			case 5:modulus=5;break;
		}

		int* bits=new int[10];
		while(1)
		{
			int length=getNumLength(n,bits);
			if((length%2)==0)
			{
				n=(int)pow(10,length)+1;
				modulus=5;
				continue;
			}

			if(isPalindrome(length,bits)&&isPrime(n))
			{
				return n;
			}

			if(modulus==1)
			{
				n+=4;
				modulus=5;
			}
			else
			{
				n+=2;
				modulus==1;
			}
		}
    }

	int getNumLength(int n,int bits[])
	{
		int length=0;
		while(n>0)
		{
			bits[length++]=n%10;
			n/=10;
		}
		return length;
	}

	bool isPrime(int n)
	{
		int s=(int)sqrt(n);
		for(int i=3;i<=s;i+=2)
		{
			if(n%i==0)
			{
				return false;
			}
		}
		return true;
	}

	bool isPalindrome(int len,int bits[])
	{
		for(int i=0;i<len/2;i++)
		{
			if(bits[i]!=bits[len-i-1])
			{
				return false;
			}
		}
		return true;
	}

	int nthUglyNumber(int n)
	{
		return primePalindrome(n);
	}

};

int main()
{
	Solution s;
	int n;
	cin >> n;
	cout << s.nthUglyNumber(n) << endl;
	return 0;
}
