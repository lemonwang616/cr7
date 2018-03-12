//
//  main.cpp
//  0208
//
//  Created by lemon_wang on 18/2/8.
//  Copyright ? 2018Ç¯ lemon_wang. All rights reserved.
//

#include <string>
#include <cstring> 
#include <iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include   <map>
#include <queue>
#include <math.h>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::map;
using std::queue;
#define PT 9999999
#define MAX 101
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

struct Tree{
    int node;
    int * child=NULL;
    int num=0;
};
int records[101]={0};

int D[MAX][MAX];
int n;//ÐÐÊý 
int maxsum[MAX][MAX];

/*void DFS(Tree ttre,int level)
{
	if(ttre.num==0)
	{
		records[level]++;
		return;
	}
	int i;
	for(i=0;i<ttre.num;i++)
	{
		DFS(tree[ttre.child[i]],level+1);
	}
}*/

int main()
{
 	int i,j;
 	cin>>n;
 	for(i=1;i<=n;i++)
 	{
 		for(j=1;j<=i;j++)
		 {
		 	cin>>D[i][j];
		 //	maxsum[i][j]=-1;
		 }	
	
	 }
	// cout<<"11"<<endl;
	 for(i=1;i<=n;i++)
	 	maxsum[n][i]=D[n][i];
	//cout<<"22"<<endl;
	for(i=n-1;i>=1;i--)
	{
		for(j=1;j<=i;j++)
		{
			maxsum[i][j]=std::max(maxsum[i+1][j],maxsum[i+1][j+1])+D[i][j];	
		}	
		for(j=1;j<=i;j++)
		{
			cout<<maxsum[i][j]<<" ";
		}
		cout<<endl;
	}
		
		cout<<maxsum[1][1]<<endl;
    return 0;
}
