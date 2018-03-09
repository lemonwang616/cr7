//
//  main.cpp
//  0208
//
//  Created by lemon_wang on 18/2/8.
//  Copyright ? 2018年 lemon_wang. All rights reserved.
//

#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <map>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::map;
#define INF 9999999
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
bool iicompare(int a,int b)
{
	return a<b;
}

int main()
{
	int N,M;//N the number of nodes     M the number of non-leaf node
	cin>>N>>M;
	if(N==1)
	{
		cout<<"1";
		return 0;
	}
	int K;
	int nodecount[N+1]={0};//每个节点的子节点数 
	int sencount[N+1]={0};//每一层无孩子的个数
	int levelcount[N+1]={0};//每个节点的层数; 
	levelcount[1]=1;
	//vector<int> vec[N+1];
	int i,j,k;
	int ID;
	int temp;
	int count=1;//record the number of seniority level
	for(i=0;i<N;i++)
	{
		scanf("%d %d",&ID,&K);
		nodecount[ID]=K;
		for(j=0;j<K;j++)
		{
			scanf("%d",&temp);
		//	vec[ID].push_back(temp);
			levelcount[temp]=levelcount[ID]+1;
		}
		if(count<(levelcount[ID]+1))
		{
			count=levelcount[ID]+1;
		}
	}
	for(i=1;i<=N;i++)
	{
		if(nodecount[i]==0)
		{
			sencount[levelcount[i]]=sencount[levelcount[i]]+1;
		}
	}
/*	if(count==1)
	{
		cout<<sencount[i];
	}
	else
	{*/
		for(i=1;i<count;i++)
			cout<<sencount[i]<<" ";
		cout<<sencount[count];
//	}
	
	return 0;
	
}


