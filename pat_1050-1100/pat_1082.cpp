// pat_1082
#if 0
#include <iostream>
#include <string>

using namespace std;

int main()
{
	string st[10] = {"Fu","","Shi","Bai","Qian","Wan","Shi","Bai","Qian","Yi"};
	string st2[10] = {"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
	string sting_in;
	cin>>sting_in;

	char num;
	int length = sting_in.length();
	int l = length;
	int zeronum = 0;
	for(int i = 0;i < length; ++ i)
	{
		if( i == 0 )
		{
			if(sting_in[i] == '-')
				cout<<"Fu";
			else
			{
				int n = sting_in[i] - '0';
				int j = length - i;
				if(j!=1)
					cout<<st2[n]<<" "<<st[j];
				else
					cout<<st2[n];//<<endl;
			}
		}
		else
		{
			int j = length - i;
			int n = sting_in[i] - '0';
			if(n > 0)
			{
				if(zeronum > 0)
					cout<<" ling";
				zeronum = 0;
				if(j!=1)
					cout<<" "<<st2[n]<<" "<<st[j];
				else
					cout<<" "<<st2[n];//<<endl;
			}
			else if(n == 0)
			{
			    zeronum ++;
				if(zeronum > 0)
				{
					//zeronum ++;
					if(j == 5)
						cout<<" Wan";
				}
			}
		}
	    
	}

	getchar();
	return 0;
}
#endif