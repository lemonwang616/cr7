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
void  simplification(long long a,long long b)//分数化成最简形式
{
   // int s[4];//s[0] 符号  k a/b  s[1] k  s[2] a s[3] b
    if(b==0)
    {
        printf("Inf");
        return ;
    }
    int np=0;//存储正负号  0为整数  1为负数
    long long k;
    if(a<0)
    {
        np=1;
        a=-a;
        k=-1;
    }
    long long gcd=GCD(a,b);
    a=a/gcd;
    b=b/gcd;
    if(a/b==0&&a!=0)//数值小于1 且分数值不为0
    {
       if(np==1)
       {
           printf("(-%lld/%lld)",a,b);
       }
        else
        {
            printf("%lld/%lld",a,b);
        }
        
        return;
    }
    else
    {
        
        k=a/b;
        a=a%b;
        if(a==0&&np==0)//若用a来判断则b为1时，
        {
        printf("%lld",k);
            return ;
        }
        if(a==0&&np==1)
        {
            printf("(-%lld)",k);
            return ;
        }
        if(np==0)
        {
            printf("%lld %lld/%lld",k,a,b);
            return ;
        }
        else
        {
            printf("(-%lld %lld/%lld)",k,a,b);
        }
        
    }
    //return s;
}
void charactercompute(char c,long long a1,long long b1,long long a2,long long b2)
{
    simplification(a1,b1);
    printf(" %c ",c);
    simplification(a2,b2);
    printf(" = ");
    long long gcd=GCD(a1, b1);
    a1=a1/gcd;
    b1=b1/gcd;
    gcd=GCD(a2,b2);
    a2=a2/gcd;
    b2=b2/gcd;
    long long a3,b3;
    switch(c)
    {
    case '+':
            a3=a1*b2+a2*b1;
            b3=b1*b2;
            
            break;
    case '-':
            a3=a1*b2-a2*b1;
            b3=b1*b2;
            break;
    case '*':
            a3=a1*a2;
            b3=b1*b2;
            break;
    case '/':
            a3=a1*b2;
            b3=a2*b1;
            if(b3<0)
            {
                a3=-a3;
                b3=-b3;
            }
            break;
    default:
            break;
    }
    simplification(a3,b3);
    cout<<endl;
    return ;
}
int main()
{
    freopen("a.txt","r",stdin);
    int a1,a2,a5,a6;
    long long a3;
    long long a4;
    a1=12%-8;
    a2=12/8;
    a5=12%-3;
    a6=12/-3;
    cout<<a1<<" "<<a2<<endl;
    cout<<a5<<" "<<a6<<endl;
    long long gcd1=GCD(12,-8);
    long long gcd2=GCD(12,-3);
    cout<<gcd1<<endl;
    cout<<gcd2<<endl;
   /* long long a1,b1,a2,b2;
    scanf("%lld/%lld%lld/%lld",&a1,&b1,&a2,&b2);
    charactercompute('+',a1,b1,a2,b2);
    charactercompute('-', a1, b1, a2, b2);
    charactercompute('*', a1, b1, a2, b2);
    charactercompute('/', a1, b1, a2, b2);*/
    return 0;
}