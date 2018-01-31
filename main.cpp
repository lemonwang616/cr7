/*
输入样例：
3 4 -5 2 6 1 -2 0
输出样例：
12 3 -10 1 6 0
*/
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main()
{
	vector<int> vec;
	char ch;
	int temp;
	while(cin>>temp)
	{
		vec.push_back(temp);
		ch=getchar();
		if(ch=='\n')
			break;
		if(ch==' ')
			continue;
	}
	int length=vec.size();
	int i,j;
	vector<int> Deriva;
	for(i=0;i<length/2;i++)
	{
		if(vec[2*i+1]==0)
		{
			//cout<<"i="<<2*i+1<<endl;
			continue;
		}
		int temp1=vec[2*i]*vec[2*i+1];
		Deriva.push_back(temp1);
		int temp2=vec[2*i+1]-1;
		Deriva.push_back(temp2);		
	}
	int len=Deriva.size();
	for(i=0;i<len-1;i++)
		cout<<Deriva[i]<<" ";
	cout<<Deriva[len-1];
	return 0;	
}

