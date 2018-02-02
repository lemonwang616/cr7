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
bool GreaterSort(Info a,Info b)
{
    int i=0;
    if(a.total!=b.total)
    {
    return (a.total>b.total);
    }
    else
    {
        if(a.Morality!=b.Morality)
        
          return (a.Morality>b.Morality);
        else
            return (a.id<b.id);
    }
    
    //return (a.total>b.total);
}
void printvector(vector<Info> tempvector)
{
    sort(tempvector.begin(),tempvector.end(),GreaterSort);
    int size=tempvector.size();
    int i;
    for(i=0;i<size;i++)
    {
        printf("%s %d %d\n",tempvector[i].id.c_str(),tempvector[i].Morality,tempvector[i].Talent);
		//cout<<tempvector[i].id<<" "<<tempvector[i].Morality<<" "<<tempvector[i].Talent<<endl;
    }
    
    /*vector<Info>::iterator iter1;//=tempvector.begin();
    for(iter1=tempvector.begin();iter1!=tempvector.end();iter1++)
    {
        cout<<iter1[id]<<endl;
        
        
    }*/
}

int main()
{
    int N,L,H;
    cin>>N;//people number
    cin>>L;//the minimum adimission line
    cin>>H;//the excellent line
    
    vector<Info>GradeA;
    vector<Info>GradeB;
    vector<Info>GradeC;
    vector<Info>GradeD;
    int i,j;
    int count=0;//the num of reaching passing line
    Info temp;
    for(i=0;i<N;i++)
    {
        
        cin>>temp.id;
        cin>>temp.Morality;
        cin>>temp.Talent;
        temp.total=temp.Morality+temp.Talent;
        if((temp.Morality>=H)&&(temp.Talent>=H))
        {
            GradeA.push_back(temp);
            count++;
            continue;
        
        }
        if((temp.Morality>=H)&&(temp.Talent>=L))
        {
            GradeB.push_back(temp);
            count++;
            continue;
        
        }
        if((temp.Talent<H)&&(temp.Morality>=temp.Talent)&&(temp.Talent>=L))
        {
            GradeC.push_back(temp);
            count++;
            continue;
        }
        if((temp.Talent>=L)&&(temp.Morality>=L))
        {
            GradeD.push_back(temp);
            count++;
            continue;
        }
    }
    
    cout<<count<<endl;
    printvector(GradeA);
    printvector(GradeB);
    printvector(GradeC);
    printvector(GradeD);
    
    return 0;  
}

