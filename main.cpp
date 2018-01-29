/*. 字符串中必须仅有P, A, T这三种字符，不可以包含其它字符；
2. 任意形如 xPATx 的字符串都可以获得“答案正确”，其中 x 或者是空字符串，或者是仅由字母 A 组成的字符串；
3. 如果 aPbTc 是正确的，那么 aPbATca 也是正确的，其中 a, b, c 均或者是空字符串，或者是仅由字母 A 组成的字符串。

现在就请你为PAT写一个自动裁判程序，判定哪些字符串是可以获得“答案正确”的。*/
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
    cout<<"答案正确";
else
	cout<<"答案错误";
	return 0;
}



