//
//  main.cpp
//  0208
//
//  Created by lemon_wang on 18/2/8.
//  Copyright ? 2018ǯ lemon_wang. All rights reserved.
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
Tree tree[101];
void DFS(Tree ttre,int level)
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
}
struct Check_intable
{

  char id[20];
  char sign_in_time[10];
  char sign_out_time[10];
};
bool SmallerSort(Check_intable a,Check_intable b)
{
	if(strcmp(a.sign_in_time,b.sign_in_time)>0)
		return false;
	else
		return true;
	//return a.sign_in_time>b.sign_in_time;
}
bool GreaterSort(Check_intable a,Check_intable b)
{
	if(strcmp(a.sign_out_time,b.sign_out_time)<0)
		return false;
	else
		return true;
	//return a.sign_out_time>b.sign_out_time;
}
int main()
{
 int M;
 cin>>M;
 vector<Check_intable> vec;
 int i,j;
 Check_intable temptable;
 for(i=0;i<M;i++)
 {
 	scanf("%s %s %s",&temptable.id,&temptable.sign_in_time,&temptable.sign_out_time);
 //	cout<<i<<endl;
	//scanf("%s",&temptable.sign_in_time);
	//scanf("%s",&temptable.sign_out_time);
	vec.push_back(temptable);
 }
	sort(vec.begin(),vec.end(),SmallerSort);
	cout<<vec[0].id<<" ";
	//cout<<vec[0].id<<" "<<vec[0].sign_in_time<<endl;
	sort(vec.begin(),vec.end(),GreaterSort);
	//cout<<vec[0].id
	cout<<vec[0].id<<" "<<vec[0].sign_out_time<<endl;
    return 0;
}
