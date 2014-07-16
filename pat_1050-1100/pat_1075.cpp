// pat_1075
#if 0
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int maxnum = 10005;

struct Pat{
	int id;
	int score[6];
	int totalScore;
	int rank;
	int perfectnum;
	bool isvist;
};

bool camp(const Pat &a,const Pat &b)
{
	if(a.isvist != b.isvist) 
		return a.isvist > b.isvist;
	else 
	{
		if(a.totalScore != b.totalScore)
			return a.totalScore > b.totalScore;
		else
		{
			if(a.perfectnum != b.perfectnum)
				return a.perfectnum > b.perfectnum;
			else
				return a.id < b.id;
		}
	}
}
Pat user[maxnum];
int fullscore[6];

int main()
{
	int n,k,m;
	cin>>n>>k>>m;

	int i,j;

	for( i = 0;i < maxnum; ++i)
	{
		user[i].id = 0;
		user[i].totalScore = 0;
		user[i].rank = 0;
		user[i].isvist = false;
		user[i].perfectnum = 0;
		for( j = 0;j < 6; ++ j)
			user[i].score[j] = -1;
	}

	for(i = 1;i <= k; ++ i)
	{
		cin>>fullscore[i];
	}

	for(i = 0;i < m; ++ i)
	{
		int id,proid,score;
		cin>>id>>proid>>score;
		user[id].id = id;
		if( score > user[id].score[proid])
		{
			user[id].isvist = true;
			int prescore = user[id].score[proid];
			if(prescore > 0)
				user[id].totalScore += (score - prescore);
			else
				user[id].totalScore += score;
			user[id].score[proid] = score;
			if(score == fullscore[proid])
			{
				user[id].perfectnum ++;
			}
		}
		else if(score == user[id].score[proid])
		{
			if(score == -1)
				user[id].score[proid] = 0;
			if(score == 0)
			{
				user[id].isvist = true;
			}
		}
	}

	sort(user,user + maxnum,camp);

	int nowrank = 1;
	int samrank = 1;
	for(i = 0;i < n; ++i)
	{
		if(!user[i].isvist)
			continue; // break;
		if(i > 0)
		{
			if(user[i].totalScore == user[i-1].totalScore)
			{
				 ++ samrank;
				//printf("%d %05d ",nowrank,user[i].id);
			}
			else
			{
				nowrank += samrank;
				samrank = 1;
			}	
		}
		printf("%d %05d %d",nowrank,user[i].id,user[i].totalScore);
		for(j = 1;j <= k; ++ j)
		{
			if(user[i].score[j] < 0)
				printf(" -");
			else
				printf(" %d",user[i].score[j]);
		}
		printf("\n");
	}

	getchar();
	return 0;
}
#endif