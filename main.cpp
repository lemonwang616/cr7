
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


int main()
{
	string str;
	cin>>str;
	int len=str.length();
	int i,j;
	int pointch=str.find('.');
	int ech=str.find('E');
	char negativech=str[str+1];
	int integernum=0;
	int decimalnum=0;
	int temp=0;
	cout<<pointch<<" "<<ech<<" "<<endl;
    return 0;  
}

