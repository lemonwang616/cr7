/*. �ַ����б������P, A, T�������ַ��������԰��������ַ���
2. �������� xPATx ���ַ��������Ի�á�����ȷ�������� x �����ǿ��ַ����������ǽ�����ĸ A ��ɵ��ַ�����
3. ��� aPbTc ����ȷ�ģ���ô aPbATca Ҳ����ȷ�ģ����� a, b, c �������ǿ��ַ����������ǽ�����ĸ A ��ɵ��ַ�����

���ھ�����ΪPATдһ���Զ����г����ж���Щ�ַ����ǿ��Ի�á�����ȷ���ġ�*/
#include <iostream>
#include <cstring>
#include <regex>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
bool CheckFormat(string sstr)
{
	regex STD("^*APAT*b");
	bool bb=regex_match(sstr,STD);
	return bb;
}
string intconvertchar(int num)
{
	switch(num)
	{
		case 0:return "ling";
		case 1:return "yi";
		case 2:return "er";
		case 3:return "san";
		case 4:return "si";
		case 5:return "wu";
		case 6:return "liu";
		case 7:return "qi";
		case 8:return "ba";
		case 9:return "jiu";
		default:
			return "san";
	}
	
}
int main(int argc, char** argv) {
string str;
getline(cin,str);
bool flag=CheckFormat(str);
if(flag==true)
    cout<<"����ȷ";
else
	cout<<"�𰸴���";
	return 0;
}



