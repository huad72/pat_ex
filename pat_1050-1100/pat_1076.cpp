// pat_1076
#if 0
#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>
using namespace std;

const int maxnum = 1005;

struct WeiboUser{
	int id;
	vector<int> follows;
};

WeiboUser user[maxnum];

bool isvist[maxnum];
bool isinv[maxnum];
int lenum[10];
int weibonum;

void search_map(int level,int id,const int maxlevel)
{
	queue<int> idque;
	idque.push(id);
	lenum[0] = 1;
	isvist[id] = true;
	while (level < maxlevel&&!idque.empty())
	{
		id = idque.front();
		idque.pop();
		--lenum[level];
		int lnum = 0;
		vector<int>::iterator it;
		for(it = user[id].follows.begin(); it != user[id].follows.end(); ++ it)
		{
			int nextid = *it;
			if(!isvist[nextid])
			{
				isvist[nextid] = true;
				idque.push(nextid);
				++ lnum;
				++ weibonum;
			}	
		}
		lenum[level+1] += lnum;
		if(lenum[level] == 0)
			++ level;
	}
}

int main()
{
	int n,l;
	cin>>n>>l;
	int i,j;
	for(i = 1;i <= n; ++ i)
	{
		user[i].id = i;
		int fnum;
		cin>>fnum;
		for(j = 0;j < fnum; ++ j)
		{
			int id;
			cin>>id;
			user[id].follows.push_back(i);
		}
	}



	int k;
	cin>>k;
	for(i = 0;i < k; ++ i)
	{
		int qnum;
		cin>>qnum;
		weibonum = 0;
		memset(isvist,0,sizeof(bool)*maxnum);
		search_map(0,qnum,l);
		cout<<weibonum<<endl;

	}
	getchar();
	return 0;
}
#endif