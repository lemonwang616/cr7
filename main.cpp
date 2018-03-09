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
typedef struct rescueteam
{
	int count;
	int resnum;
}resut;
int main()
{
	
	int N,M,C1,C2;
	cin>>N>>M>>C1>>C2;
	int res[N];
	int shortime[N];//记录C1到每个点的最短路径的次数 

	int flag[N]={0};
	int resu[N][N];//存储救援队的个数 
	int i,j,k;
	for(i=0;i<N;i++)
		scanf("%d",&res[i]);
	int rode[N][N];
	for(i=0;i<N;i++)
		for(j=0;j<N;j++)
		{
			rode[i][j]=INF;
			resu[i][j]=0;
		}
	int start,end,temp;
	for(i=0;i<M;i++)
	{
		scanf("%d %d %d",&start,&end,&temp);
		rode[start][end]=temp;
		rode[end][start]=temp;
		resu[start][end]=res[start]+res[end];
		resu[end][start]=res[start]+res[end];
		if(start==C1)
		{
			shortime[end]=1;
		}
	}


	flag[C1]=1;
	int minlen;
	int node;//record current min node
	
	for(k=0;k<N-1;k++)
	{
		minlen=INF;
		for(i=0;i<N;i++)
		{
			if(flag[i]==0&&(rode[C1][i]<minlen))
			{
					minlen=rode[C1][i];
					node=i;
			}
		}
		flag[node]=1;
		//cout<<node<<endl; 
		for(i=0;i<N;i++)
		{
			if(flag[i]==0&&((rode[C1][node]+rode[node][i])<=rode[C1][i]))
			{
				
				if((rode[C1][node]+rode[node][i])<rode[C1][i])
				{
					shortime[i]=shortime[node];	
					resu[C1][i]=resu[C1][node]+res[i];
				}
				else  if((rode[C1][node]+rode[node][i])==rode[C1][i])
				{
					shortime[i]=shortime[i]+shortime[node];
					if((resu[C1][node]+res[i])>resu[C1][i])
					{
						resu[C1][i]=resu[C1][node]+res[i];
					}
				}
				rode[C1][i]=rode[C1][node]+rode[node][i];
				
			}
			//每次更新路径时，存入最大救援数量和最短距离 
		}
	
	}
//	cout<<rode[C1][C2]<<" "<<shortime[C2]<<" "<<resu[C1][C2];
	cout<<shortime[C2]<<" "<<resu[C1][C2];
	return 0;
}


