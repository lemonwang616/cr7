
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include<map>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::map;

bool isPrime(int num)
{
    if(num==0||num==1)
    {
        return false;
    }
    int i;
    for(i=2;i*i<=num;i++)
    {
        if(num%i==0)
            return false;
    }
    return true;
}

struct ChainStruct
{
	string address;
	int num;
	string nextaddre;
	int order;//��ʾ��������� ����0��ʾ���� ���еĶ�û������ 
};
int main()
{
	string initaladdress;
	int N;//���������� 
	int K;//��ת����
	cin>>initaladdress;
	cin>>N;
	cin>>K; 
	map<string,ChainStruct>mymap;
	ChainStruct tempstruct;
	tempstruct.order=0;
	int i,j;
	for(i=0;i<N;i++)
	{
		cin>>tempstruct.address;
		cin>>tempstruct.num;
		cin>>tempstruct.nextaddre;
		mymap.insert(std::make_pair(tempstruct.address,tempstruct));
	}
	map<string,ChainStruct>::iterator it;
	vector<ChainStruct> vec;
	string temp=initaladdress;
	int count=0;
	while(temp!="-1")
	{
		it=mymap.find(temp);
		it->second.order=++count;
		temp=it->second.nextaddre;	
		tempstruct=it->second;
		vec.push_back(tempstruct);
	}
	int 
	
	/*it=mymap.begin();
	while(it!=mymap.end())
	{
		cout<<it->first<<" "<<(it->second).num<<" "<<(it->second).nextaddre<<" "<<it->second.order<<endl;
		it++;
	}*/
    return 0;  
}

