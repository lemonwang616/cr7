
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
	int order;//表示链表的排序 其中0表示乱序 所有的都没有排序 
};
bool compare(ChainStruct a,ChainStruct b)
{
	return a.order<b.order;
}
int main()
{
	string initaladdress;
	int N;//正整数个数 
	int K;//反转个数
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
		if(count==N)
			break;
	}
	int temnum=0;
	int len=vec.size();
	
	if(K==1)
	{
	
    }
		
	else
	{
	int inversetime=N/K;//反转次数  N 正整数个数  K反转个数 
	int remaintime=N%K;//剩余的个数
	//cout<<inversetime<<endl;
	//cout<<remaintime<<endl; 
	for(i=0;i<inversetime;i++)
	{
		//cout<<"the "<<i<<" time"<<endl;
		temnum=i*K+K+1;
		vec[i*K].order=temnum-vec[i*K].order;
		vec[i*K+K-1].order=temnum-vec[i*K+K-1].order;
		vec[i*K+K-1].nextaddre=vec[i*K+K-2].address;
		for(j=i*K+1;j<i*K+K-1;j++)
		{
			vec[j].order=temnum-vec[j].order;
			vec[j].nextaddre=vec[j-1].address;
    	}	
    	if(remaintime==0)
    	{
    		vec[i*K].nextaddre="-1";
		}
		else
			{
				if(i==inversetime-1)
				{
					vec[i*K].nextaddre=vec[inversetime*K].address;
				}
				else
				{
					vec[i*K].nextaddre=vec[i*K+2*K-1].address;
				}
			}
	} 
	sort(vec.begin(),vec.end(),compare);
	
	}
	
	for(i=0;i<N;i++)
	{
		printf("%s %d %s\n",vec[i].address.c_str(),vec[i].num,vec[i].nextaddre.c_str());
	//cout<<vec[i].address<<" "<<vec[i].num<<" "<<vec[i].nextaddre<<" "<<vec[i].order<<endl;
	}	
    return 0;  
}

