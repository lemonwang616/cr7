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
long long chartoint(string str,long long radix)
{
	long long num=0;
	int i,j;
	int len=str.length();
	int temp;
	//cout<<len<<"  23 "<<radix<<endl;
	for(i=0;i<len;i++)
	{
		//cout<<str[i]<<" ";
		if(str[i]>='0'&&str[i]<='9')
	  {
		temp=str[i]-'0';
	  }
	  	else 
	  {
		if(str[i]>='a'&&str[i]<='z')
		{
			temp=str[i]-'a'+10;
		}
	  }	
	  	//printf("%d ",tem)
	  	num=num*radix+temp;
	//	cout<<temp<<" ";
	}
	//cout<<endl;
	if(num<0)//判断是否溢出 
	{
		num=-1;
	}
	return num;
}
int thebigestnum(string str)
{
	int len=str.length();
	int i,max=0,temp;
	for(i=0;i<len;i++)
	
	{
	    if(str[i]>='0'&&str[i]<='9')
	  {
		temp=str[i]-'0';
	  }
	  	else 
	  {
		if(str[i]>='a'&&str[i]<='z')
		{
			temp=str[i]-'a'+10;
		}
	  }	
	  if(temp>max)
	  {
		max=temp;
	  }	
	}
	max=max+1;
//	cout<<max<<"zudazhi"<<endl;
	return max;
}

int main()
{
	string N1,N2;
	//char N1[11];
	//char N2[11];
	int len1,len2;
	int *I1;
	int *I2;
	int i,j,k;
	int tag,radix;
	long long knowradix,askedradix;
	long long knowsum,askedsum;
	string askedstr;
	cin>>N1;
	cin>>N2;
	cin>>tag;
	cin>>radix;
	if(tag==1)
	{
		knowsum=chartoint(N1,radix);
		knowradix=radix;
		askedstr=N2;
	//	cout<<tag<<endl;
	}
	else
	{
		knowsum=chartoint(N2,radix);
		knowradix=radix;
		askedstr=N1;
	}
//	cout<<askedstr<<" "<<knowsum<<endl; 
	long long upperbond,lowerbond;// upperbond 上界 
	
	upperbond=knowsum+1;
	lowerbond=thebigestnum(askedstr);
	if(upperbond<lowerbond)
	{
		printf("Impossible\n");
		return 0;
	}
//	printf("%lld %lld\n",upperbond,lowerbond);
	//printf("%lld %lld",upperbond,lowerbond);
	//二分法 先判断利用利用下界计算，若大于则输出impossible
	long long tempsum=chartoint(askedstr,lowerbond);
	//cout<<tempsum<<endl;
	if(tempsum==knowsum)
	
	{
		printf("%lld",lowerbond);
		return 0;
	}
	if(tempsum>knowsum)
	{
		printf("Impossible\n");
		return 0;
	}
	long long mid;
	int flag=0;
	while(lowerbond<=upperbond)
	{
		mid=(upperbond+lowerbond)/2;
		tempsum=chartoint(askedstr,mid);
		if(tempsum==-1||tempsum>knowsum)
    {
      upperbond=mid-1;
    }
    else if(tempsum<knowsum)
    {
      lowerbond=mid+1;
    }
    else if(tempsum==knowsum)
    {
      cout<<mid;
      return 0;
    }
		
		/*if(tempsum==knowsum)
		{
			cout<<mid;
			return 0;
		}
		else
		{
			if(tempsum==-1||tempsum>knowsum)
			{
				upperbond=mid-1;
					
			}
			else
			{
				lowerbond=mid+1;
				
			}
		}*/
	}
		printf("Impossible\n");
	
	//printf("%s %s %d %d\n",N1.c_str(),N2.c_str(),tag,radix);
	
    return 0;
}
