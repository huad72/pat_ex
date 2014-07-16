// pat_1074
#if 0
#include <iostream>
using namespace std;

const int maxnum = 100005;

struct Node{
	int address;
	int nextaddress;
	int preaddress;
	int num;
	bool isinlsit;
};

Node nodelist[maxnum];
int thefnode[maxnum];

int main()
{
	int fnode,n,k;
	cin>>fnode>>n>>k;
	int i,j;
	int lastnode;
	for(i = 0;i < n; ++ i)
	{
		int address,num,nextadd;
		cin>>address>>num>>nextadd;

		nodelist[address].address = address;
		nodelist[address].num = num;
		nodelist[address].nextaddress = nextadd;
		if( nextadd != -1)
		{
			nodelist[nextadd].preaddress = address;
			nodelist[nextadd].isinlsit = true;
		}
		else
		{
			lastnode = address;
		}
	}
	int nn = 0;
	int testnode = fnode;
	while(testnode != -1)
	{
		nn++;
		testnode = nodelist[testnode].nextaddress;
	}

	//cout<<endl;
	int nownum = fnode;

	if(k!=0)
	{
	int turntime = nn/k;
	int remainnum = nn%k;
	
	for(i = 0;i < turntime; ++i)
	{
	    int nextadd;
		for(j = 0;j < k - 1; ++ j)
		{
			nextadd = nodelist[nownum].nextaddress;
			nownum = nextadd;
		}
		thefnode[i] = nownum;
		nownum = nodelist[nownum].nextaddress;
	}
	thefnode[turntime] = nownum;
	for(i = 0;i < turntime; ++i)
	{	
		int turnnowadd = thefnode[i];
		//if(i != 0)
		//	lastfnode = nodelist[thefnode[i]].nextaddress;
		//else
		//	lastfnode = fnode;
		for(j = 0;j < k; ++ j)
		{
			printf("%05d %d ",nodelist[turnnowadd].address,nodelist[turnnowadd].num);
			if(j != k-1)//turnnowadd != lastfnode)
				printf("%05d\n",nodelist[turnnowadd].preaddress);
			else
			{
				if(thefnode[i+1] == -1)
					printf("%d\n",thefnode[i+1]);
				else
					printf("%05d\n",thefnode[i+1]);
			}
			turnnowadd = nodelist[turnnowadd].preaddress;
		}
		
	}
	}
	while(nownum != -1)
	{
		printf("%05d %d ",nodelist[nownum].address,nodelist[nownum].num,nodelist[nownum].nextaddress);
		if(nodelist[nownum].nextaddress == -1)
			printf("%d\n",nodelist[nownum].nextaddress);
		else
			printf("%05d\n",nodelist[nownum].nextaddress);
		nownum = nodelist[nownum].nextaddress;
	}

	getchar();
	return 0;
}
#endif