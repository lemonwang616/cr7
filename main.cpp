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
int main()
{
 	int N;
 	cin>>N;
 	int a[N];
 	int sum=0;
 	int i;
 	int flag=0;//whether or no less than 0
 	for(i=0;i<N;i++)
 	{
 		scanf("%d",&a[i]);
 		if(a[i]>=0)
 		{
 			flag=1;
		 }
	 }
	 if(flag==0)
	 {
	 	cout<<0<<" "<<a[0]<<" "<<a[N-1];
	 	return 0;
	 }
	 sum=maxsub(a,N);
	 //sum=maxSubItem(a,0,N-1);
	 cout<<sum<<" "<<a[start]<<" "<<a[end];
    return 0;
}
