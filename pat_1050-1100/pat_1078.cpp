// pat_1078
#if 0
#include <iostream>
#include <math.h>
using namespace std;
bool prime[20005];
int find_prime(int number)
{
	
	bool isprime = true;
	if(number%2 == 0)
	{
		isprime = false;
	}
	else
	{
		int halfnum = sqrt(number);
		int i;
		for(i = 3;i <= halfnum;i += 2)
		{
			if(number%i == 0)
			{
				isprime = false;
				break;
			}
		}
	}
	if(isprime)
		return number;
	else
	{
		return find_prime(++number);

	}
	/*
	int i,j;
	for(i=2;i<20005;++i)
	{
		if(i%2)
			prime[i]=true;
		else
		{
			prime[i]=false;
		}
	}
	for(i=3;i<=sqrt(20005);++i)
	{
		if(prime[i])
		{
		for(j=i+i;j<20005;j+=i)
			prime[j]=false;
		}
	}
	if(prime[number])
		return number;
	else
	{
		int k = number+1;
		while(!prime[k])
		{
			++k;
		}
		return k;
	}*/
}
bool isin[10005];
int numpostion[10005];
int main()
{
	int msize,n,num;
	cin>>msize>>n;
	if(msize<= 2)
		msize = 2;
	else
		msize = find_prime(msize);
	for(int ss = 0;ss<10005;++ss)
	{
		numpostion[ss] = -1;
	}
	
	bool isnai;
	for(int i = 0;i<n;i++)
	{
		isnai = false;
		cin>>num;
		int key = num%msize;
		if(isin[key])
		{
			for(int j=1;j<msize;j++)
			{
				int dd = j*j;
				key = (num+dd)%msize;
				if(!isin[key])
				{
					isin[key] = true;
					numpostion[i] = key;
					isnai = true;
					break;
				}
			}
		}
		else
		{
			isin[key] = true;
			numpostion[i] = key;
			isnai = true;
		}
		if(!isnai)
		{
			numpostion[i] = -1;
		}

	}
	if(n>0)
	{
	if(numpostion[0]<0)
	{
		cout<<"-";
	}
	else
		cout<<numpostion[0];
	}
	for(int k=1;k<n;++k)
	{
		if(numpostion[k]<0)
			cout<<" -";
		else
			cout<<" "<<numpostion[k];
	}
	cout<<endl;

	getchar();
	return 0;
}
#endif