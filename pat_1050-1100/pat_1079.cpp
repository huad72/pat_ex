// pat_1079
#if 0 
#include <iostream>
#include <vector>
using namespace std;
const int maxnum = 100005;

struct Tree{
	vector<int> son_point;
};

Tree rtree[maxnum];
int tree[maxnum];
int node[maxnum];
bool isin[maxnum];
double p,r;
double final_price;
void search_tree(int length,double price,int nowpoint)
{
	int sonnum = rtree[nowpoint].son_point.size();
	if(sonnum == 0)
	{
		final_price += price*node[nowpoint];
	}
	else
	{
		double newprice = price + price*r/100;
		for(int i = 0;i < sonnum; ++ i)
		{
			int nownode = rtree[nowpoint].son_point[i];
			if(isin[nownode])
			{
				final_price += newprice*node[nownode];
				//cout<<price<<" "<<nownode<<" "<<length<<" "<<node[nownode]<<endl;
			}
			else
			{
				search_tree(length+1,newprice,nownode);
			}
		}
	}
}
int main()
{
	for(int i = 0;i < maxnum; ++ i)
	{
		tree[i] = -1;
		isin[i] = false;
	}
	int m_num;
	cin>>m_num>>p>>r;
	final_price = 0;
	int ki,id;
	for(int j = 0;j < m_num; ++ j)
	{
		cin>>ki;
		if(ki == 0)
		{
			cin>>id;
			node[j] = id;
			isin[j] = true;
		}
		else
		{
			for(int m = 0;m < ki; ++ m)
			{
				cin>>id;
				tree[id] = j;
				rtree[j].son_point.push_back(id);
			}
		}

	}

	vector<int> rootnum;
	for(int n = 0;n < m_num; ++ n)
	{
		if(tree[n] < 0)
			rootnum.push_back(n);
	}
	vector<int>::iterator it;
	for(it = rootnum.begin();it != rootnum.end(); ++it)
	{
		int root = *it;
		search_tree(1,p,root);
	}

	printf("%.1f",final_price);

	getchar();
	return 0;
}
#endif;