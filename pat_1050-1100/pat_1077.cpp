// pat 1077
#if 0
#include <iostream>
#include <string>
using namespace std;
int main()
{
	string cin_string;
	int num;
	int result_length = 0;
	string result_string;
	cin>>num;
	getline(cin,cin_string);
	int same_num = 0;
	for(int i = 0;i<num;++i)
	{
		getline(cin,cin_string);
		same_num = 0;
		if(i==0)
		{
			result_length = cin_string.length();
			result_string = cin_string;
		}
		else
		{

			int now_length = cin_string.length();
			int s = now_length-1;
			for(int j = result_length-1;j>=0&&s>=0;--j,--s)
			{
				if(result_string[j] != cin_string[s])
				{
					if(same_num == 0)
					{
						result_length = 0;
						result_string = "nai";
					}
					else
					{
						result_length = same_num;
						result_string = result_string.substr(j+1,same_num);
						//cout<<"sub string = "<<result_string<<endl;
					}
					break;
				}
				else
				{
					same_num++;
				}
			}
			if(same_num == 0)
				break;
			else
			{
				if(s < 0)
				{
					result_string = cin_string;
				}
			}
		}

	}
	cout<<result_string<<endl;
	
	getchar();

	return 0;
}
#endif