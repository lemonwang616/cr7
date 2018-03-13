//
//  main.cpp
//  0208
//
//  Created by lemon_wang on 18/2/8.
//  Copyright ? 2018钳 lemon_wang. All rights reserved.
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
#define INF 99999999
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
int n;//行数 
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
int maxSubItem(int *a,int low,int high)
{
    int s1,s2,s31,s32;
    int i,j;
    int sum;
    int mid=(low+high)/2;
    if(low==high)
    {
    	return a[low];
	}
	else
	{
		s1=maxSubItem(a,low,mid);
		s2=maxSubItem(a,mid+1,high);
		i=mid;
		s31=a[i];
		while((s31+a[i-1]>s31)&&(i>low))
		{
			s31=s31+a[i-1];
			i--;
		 } 
		j=mid+1;
		s32=a[j];
		while((s32+a[j+1]>s32)&&(j<high))
		{
			s32=s32+a[j+1];
			j++;
		}
		sum=s32+s31;
	}
	if(s1>sum)
	{
		sum=s1;
	}
	if(s2>sum)
	{
		sum=s2;
	}
	return sum;
}
int start,end;
int maxsub(int *a,int n)
{
	int temp=0;
	int maxn=-INF;
	int i;
	int k=0;//每次计算最大值时的头 
	//最后返回的头和尾 
	for(i=0;i<n;i++)
	{
		temp+=a[i];
		if(temp>maxn)
		{
			maxn=temp;
			start=k;
			end=i;		
		}
		if(temp<0)
		{
			temp=0;
			k=i+1;
		}
	}
	return maxn;
}
struct polynomial
{
	int expone;
	double coeffi;
};
int main()
{
	vector<polynomial>aa1;
	vector<polynomial>aa2;
	polynomial tempst;
//	vec<int,double>aa1;
//	vector<int,double>aa2;
	vector<polynomial>::iterator pp1;
	vector<polynomial>::iterator pp2;
	map<int,double>mp;
	map<int,double>::iterator it; 
	//double C[1000000]={0};//A*B's exponents
	//A*B 系数相乘 指数相加
	int a1,a2;
	int i,j,temp;
	double coeffi;
	int expone;
	cin>>a1;
	for(i=0;i<a1;i++)
	{
		scanf("%d %lf",&tempst.expone,&tempst.coeffi);
		aa1.push_back(tempst);
	}
	cin>>a2;
	for(i=0;i<a2;i++)
	{
		scanf("%d %lf",&tempst.expone,&tempst.coeffi);
		aa2.push_back(tempst);
	}
	for(i=0;i<a1;i++)
	{
		for(j=0;j<a2;j++)
		{
			expone=aa1[i].expone+aa2[j].expone;
			coeffi=aa1[i].coeffi*aa2[j].coeffi;
			if(coeffi==0)
			{
				continue;
			}
			it=mp.find(expone);
			if(it==mp.end())
			{
				mp.insert(std::make_pair(expone,coeffi));
			}
			else
			{
				double sumtemp=it->second+coeffi;
				if(sumtemp==0)
				{
					mp.erase(expone);
				}
				it->second=it->second+coeffi;
			}
		}
	}
	int count=mp.size();
	cout<<count;
	map<int,double>::reverse_iterator rit;
	for(rit=mp.rbegin();rit!=mp.rend();rit++)
	{
	
		printf(" %d %.1lf",rit->first,rit->second);
		//cout<<it->first<<" "<<it->second<<endl; 
	}
    return 0;
}
