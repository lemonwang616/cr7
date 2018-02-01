/*
德 Morality  才 Talent 
N 考生总数   L录取最低分数线  H 优先录取线 
第一类  德才全尽  德 才 全大于H   按德才总分高到低排序
第二类   德胜才    德>=H  才<H  按德才总分高到低排序
第三类   德才均低于H  德>=才  按总分排序
第四类  德、才达到最低线L  按总分排序 
*/
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

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

struct Info
{
	string id;
	int Morality;
	int Talent;
	int total;
};

int main()
{
	int N,L,H;
	cin>>N;//people number
	cin>>H;//the minimum adimission line
	cin>>H;//the excellent line
	Info Infom[N];
	int i,j;
	for(i=0;i<N;i++)
	{
		cin>>Infom[i].id;
		cin>>Infom[i].Morality;
		cin>>Infom[i].Talent;
		Infom[i].total=Infom[i].Morality+Infom[i].Talent;
	}
	return 0;	
}

