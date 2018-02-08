#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include<map>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::map;
struct ChainStruct
{
	int  address;
	int num;
	int nextaddre;
	//int order;
};


int main()
{
	int  initaladdress;
    int N;//正整数个数 
    int K;//反转个数
	scanf("%d",&initaladdress);
	scanf("%d",&N);
	scanf("%d",&K);
	map<int,ChainStruct>mymap;
	ChainStruct tempstruct;
  int i,j;
  for(i=0;i<N;i++)
  {
  	scanf("%d",&tempstruct.address);
  	scanf("%d",&tempstruct.num);
  	scanf("%d",&tempstruct.nextaddre);
    mymap.insert(std::make_pair(tempstruct.address,tempstruct));
  }
  	map<int,ChainStruct>::iterator it;
  	/*for(it=mymap.begin();it!=mymap.end();it++)
  	{
  		cout<<it->first<<" "<<it->second.address<<" "<<it->second.num<<" "<<it->second.nextaddre<<endl;
	  }*/
  	vector<ChainStruct> vec;
  	int temp=initaladdress;
  	int count=0;
  	if(temp==-1)
  	{
  		printf("-1\n");
  		return 0;
	}
	
	while(temp!=-1)
	{
	 it=mymap.find(temp);
	 if(it==mymap.end())
	 	break;
    	++count;
     temp=it->second.nextaddre;  
     tempstruct=it->second;
     vec.push_back(tempstruct);
     if(count==N)
      	break;
	}
  	N=count;
  	vector<ChainStruct> endvec;
	int inversetime=N/K;//反转次数  N 正整数个数  K反转个数 
	int remaintime=N%K;//剩余的个数
	for(i=0;i<inversetime;i++)
	{
		for(j=i*K+K-1;j>=i*K;j--)
		{
			endvec.push_back(vec[j]);
		}
	}
	for(i=inversetime*K;i<N;i++)
	{
		endvec.push_back(vec[i]);
	}
    endvec[N-1].nextaddre=-1;
	for(i=0;i<N-1;i++)
  {
  	endvec[i].nextaddre=endvec[i+1].address;
    printf("%05d %d %05d\n",endvec[i].address,endvec[i].num,endvec[i].nextaddre);
  //cout<<vec[i].address<<" "<<vec[i].num<<" "<<vec[i].nextaddre<<" "<<vec[i].order<<endl;
  }  	
  	printf("%05d %d %d\n",endvec[N-1].address,endvec[N-1].num,-1);
	return 0;
}
