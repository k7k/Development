#include <iostream>

using namespace std;

void reverse(char *start, char* end)
{
	char tmp;
	while(start<end)
	{
		tmp = *start;
		*start++ = *end;
		*end-- = tmp;
	}
}

void reversePrint(char *str)
{

	char *tmp = str;
	char *begin = str;

	while(*tmp != '\0')
	{
		tmp++;
		if(*tmp == '\0')
		{
			reverse(begin, tmp-1);
		}
		else if(*tmp == ' ')
		{
			reverse(begin, tmp-1);
			begin = tmp+1;
		}
	}
	reverse(str,tmp-1);
}

int main()
{
	char s[100]="this is test prog";
	cout<<s<<endl;
	reversePrint(s);
	cout<<s<<endl;
	return 0;
}
