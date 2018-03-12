//
//  main.cpp
//  0208
//
//  Created by lemon_wang on 18/2/8.
//  Copyright ? 2018ǯ lemon_wang. All rights reserved.
//

#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include   <map>
#include <queue>
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
int main()
{
    int N,M;//the num of nodes   M the num of leafnodes
    cin>>N>>M;
    int i,j,k;
   // Tree tree[101];//vector
    //vector<Tree>
    for(i=1;i<=N;i++)
    {
        Tree temp;
        temp.node=i;
        tree[i]=temp;
    }
    //vector<Tree> trees;
    int node;
    int num;
    int temp;
    for(k=0;k<M;k++)
    {
        cin>>node>>num;
        tree[node].num=num;
        tree[node].child=new int[num];
        for(i=0;i<num;i++)
        {
            scanf("%d",&temp);
            tree[node].child[i]=temp;
        }
    }
    DFS(tree[1],1);
    temp=N-M;
    printf("%d",records[1]);
    num=records[1];
    for(i=2;num<temp;i++)
    {
    	printf(" %d",records[i]);
    	num=num+records[i];
	}
    /*queue<int> currentlevel;//  current level
        bool  firstflag=true;
    currentlevel.push(1);
    do{
        int count=0;//  record this level's non leaf node
        queue<int> nextlevel;//    next level
        while(currentlevel.empty()==0)
        {
            int cnode=currentlevel.front();
            currentlevel.pop();
            if(tree[cnode].num==0)
            {
                count++;
            }
            else{
                for(i=0;i<tree[cnode].num;i++)
                {
                    nextlevel.push(tree[cnode].child[i]);
                }
            }
        }
        if(firstflag==true)
        {
            printf("%d",count);
            firstflag=false;
        }
        else
        {
            printf(" %d",count);
        }
        currentlevel=nextlevel;
    }while(currentlevel.size()!=0);*/
    
    return 0;
}
