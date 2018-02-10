//
//  main.cpp
//  0208
//
//  Created by lemon_wang on 18/2/8.
//  Copyright ? 2018Äê lemon_wang. All rights reserved.
//

#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include   <map>
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
bool iicompare(int a,int b)
{
	return a<b;
}
int main()
{
	int N;
	scanf("%d",&N);
	int p;
	int i,j,k;
	scanf("%d",&p);
	int aa[N];
	//vector<int> aa;
	int temp;
	for(i=0;i<N;i++)
	{
	//	scanf("%d",&temp);
		cin>>aa[i];
		//aa.push_back(temp);
	}
	std::sort(aa,aa+N);
	//sort(aa.begin(),aa.end(),iicompare);
	int count=0;
	i=N-1;
	int flag=0;
	while(i>=0)
	{
		k=i;
		flag=0;
		for(j=0;j<=k;j++)
		{
			if(aa[j]*p>=aa[i])
			{
				temp=i-j+1;
				if(temp>count)
					count=temp;
				flag=1;
				k=j;
				break;
			}
		}
		i--;
		if(flag==1&&i<=count)
		{
			break;
			
		}
	}
	cout<<count;
	return 0;
}


