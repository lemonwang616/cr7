/*
�� Morality  �� Talent 
N ��������   L¼ȡ��ͷ�����  H ����¼ȡ�� 
��һ��  �²�ȫ��  �� �� ȫ����H   ���²��ָܷߵ�������
�ڶ���   ��ʤ��    ��>=H  ��<H  ���²��ָܷߵ�������
������   �²ž�����H  ��>=��  ���ܷ�����
������  �¡��Ŵﵽ�����L  ���ܷ����� 
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

