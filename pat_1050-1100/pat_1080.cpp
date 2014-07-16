//pat_1080
#if 0
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int maxsnum = 40005;
const int maxcnum = 105;
const int maxk = 6;

struct Student{
	int ge;
	int gi;
	int gav;
	int num;
	int schoolChoice[maxk];
	//bool operator >(const Student& nexts) const;
	//bool operator <(const Student& nexts) const;
};
//bool Student::operator>(const Student& nexts) const
//{
//	if(gav != nexts.gav) return gav > nexts.gav;
//	else return ge >= nexts.ge;
//}

int schoolquota[maxcnum];
bool schoolfull[maxcnum];
vector<int> schoolch[maxcnum];
//vector<Student> studentList;
Student StudentList[maxsnum];
bool comp(Student a,Student b)
{
	if(a.gav != b.gav) return a.gav > b.gav;
	else return a.ge > b.ge;
}

int main()
{
	int n,m,k;
	cin>>n>>m>>k;
	int i,j;
	for(i = 0;i < m; ++ i)
	{
		int qnum;
		cin>>qnum;
		schoolquota[i] = qnum;
	}

	for(j = 0;j < n; ++ j)
	{
		int gen,gin;
		cin>>gen>>gin;
		StudentList[j].num = j;
		StudentList[j].ge = gen;
		StudentList[j].gi = gin;
		StudentList[j].gav = (gen + gin)/2;
		for(i = 0;i < k; ++ i)
		{
			int cs;
			cin>>cs;
			StudentList[j].schoolChoice[i] = cs;
		}
	}
	sort(StudentList,StudentList + n,comp);

	vector<Student>::iterator it;
	bool isin;
	for(i = 0;i < n; ++ i)
	{
		isin = false;
		for(j = 0;j < k; ++ j)
		{
			int schoice = StudentList[i].schoolChoice[j];
			if(!schoolfull[schoice])
			{
				schoolch[schoice].push_back(StudentList[i].num);
				--schoolquota[schoice];
				if(schoolquota[schoice] == 0)
				{
					schoolfull[schoice] = true;
				}
				break;
			}
			else
			{
				int ss = schoolch[schoice].size();
				int st = schoolch[schoice][ss-1];
				if(StudentList[i].gav == StudentList[i-1].gav && StudentList[i].ge == StudentList[i-1].ge && StudentList[i-1].num == st)
				{
					schoolch[schoice].push_back(StudentList[i].num);
					break;
				}
			}
		}
	}

	for(j = 0;j < m; ++ j)
	{
		int scnum = schoolch[j].size();
		if(scnum == 0)
			cout<<endl;
		else
		{
			// ¶ÔvÅÅÐò
			sort(schoolch[j].begin(),schoolch[j].end());
			for(i = 0;i < scnum; ++ i)
			{
				if(i != scnum-1)
				    cout<<schoolch[j][i]<<" ";
				else
					cout<<schoolch[j][i]<<endl;
			}
		}
	}

	getchar();
	return 0;
}
#endif
