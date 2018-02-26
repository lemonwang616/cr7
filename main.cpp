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
long long GCD(long long a,long long b)
{
    long long m=a%b;
    while(m)
    {
        a=b;
        b=m;
        m=a%b;
    }
  //  if(b<0)
        //b=-b;
    return b;
}
bool isequal(int * conver,int * temp,int N)
{
    bool flag=true;
    int i;
    for(i=0;i<N;i++)
    {
        if(conver[i]!=temp[i])
        {
            flag=false;
            break;
        }
    }
    return flag;
}
    
bool InsertionSort(int * origin,int * conver,int N)
{
    int count=0;
    bool flag=false;
    //cout<<"INsertion  "<<N<<endl;
    int i,j,k;
    int temp;
    for(i=1;i<N;i++)
    {
        //cout<<i<<endl;
        for(j=0;j<i;j++)
        {
            if(origin[i]<origin[j])
            {
                temp=origin[i];
                k=i;
                while(k!=j)
                {
                    //cout<<k<<" "<<j<<endl;
                    origin[k]=origin[k-1];
                    k--;
                    //cout<<k<<" "<<origin[k]<<k+1<<origin[k+1]<<endl;
                    
                }
                origin[j]=temp;
            }
        }
        flag=isequal(conver,origin,N);
        if(count==1)
        {
            cout<<"Insertion Sort"<<endl;
            for(i=0;i<N-1;i++)
                printf("%d ",origin[i]);
           printf("%d",origin[N-1]);
            return flag;
        }
        if(flag==true)
        {
            count++;
        }
        
    }
    return flag;
}
void merge(int * array,int low,int mid,int high) // [low,mid)  [mid,high)
{
    int temp[high-low];
    int i=low;
    int j=mid;
    int k=0;
    while(i<mid&&j<high)
    {
        if(array[i]<=array[j])
        {
            temp[k++]=array[i++];
        }
        else
        {
            temp[k++]=array[j++];
        }
    
    }
    while(i<mid)
    {
        temp[k++]=array[i++];
    }
    while(j<high)
    {
        temp[k++]=array[j++];
    }
    for(i=low,k=0;i<high;i++,k++)
    {
        array[i]=temp[k];
    }
}

bool MergeSort(int * origin,int * conver,int N)
{
    bool flag=false;
    int count=0;
    int i,j,k;
    for(i=1;i<N;i=i*2)
    {
        for(j=0;j<N;j=j+2*i)
        {
            if(j+2*i<=N)
            {
                merge(origin,j,j+i,j+2*i);
                //cout<<"merge(j,j+i,j+2*i)"<<endl;
            }
            else
            {
                if(j+i<=N)
                {
                    merge(origin,j,j+i,N);
                    //cout<<"merge(j,j+i,N)"<<endl;
                
                }
            }
        }
        flag=isequal(conver,origin,N);
        if(count==1)
         {
         cout<<"Merge Sort"<<endl;
         for(i=0;i<N-1;i++)
         printf("%d ",origin[i]);
         printf("%d",origin[N-1]);
         return flag;
         
         }
        if(flag==true)
        {
            count++;
        }
       
    
        
    }
    
    return flag;

}
void mergeSort(int * origin,int * conver,int N)
{
    //bool flag=false;
    //int count=0;
    int i,j,k;
    for(i=1;i<N;i=i*2)
    {
        for(j=0;j<N;j=j+2*i)
        {
            if(j+2*i<=N)
            {
                merge(origin,j,j+i,j+2*i);
                //cout<<"merge(j,j+i,j+2*i)"<<endl;
            }
            else
            {
                //if(j+i<=N)
                //{
                    merge(origin,j,j+i,N);
                    //cout<<"merge(j,j+i,N)"<<endl;
                    
                //}
            }
        }
     
        for(k=0;k<N;k++)
            printf(" %d",origin[k]);
        printf("\n");
        
        
    }
    
   
    
}
void compare(int * origin,int * conver,int N)
{
    bool flag=false;
    int temp[N];
    int i;
    for(i=0;i<N;i++)
    {
        temp[i]=origin[i];
    }
    flag=InsertionSort(origin,conver,N);
    if(flag==true)
        return;
    else
    {
    MergeSort(temp,conver,N);
        //cout<<"213"<<endl;
        return;
    }
}
int main()
{
    //freopen("a.txt","r",stdin);
    int N;
    cin>>N;
    int origin[N];
    int conver[N];
   /* int InsertArray[N];
   int MergeArray[N];*/
    int i,j,k;
   for(i=0;i<N;i++)
        scanf("%d",&origin[i]);
    for(i=0;i<N;i++)
        scanf("%d",&conver[i]);
    /* for(i=0;i<N;i++)
        printf("%d",origin[i]);
    printf("\n");
    for(i=0;i<N;i++)
        printf("%d",conver[i]);
    printf("\n");*/
    mergeSort(origin,conver,N);
    //compare(origin,conver,N);
  // MergeSort(origin,conver,N);
   
   //InsertionSort(origin,conver,N);
    return 0;
}