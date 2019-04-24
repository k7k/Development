#include <iostream>
#include <string>
#include <map>
#include <stack>
using namespace std;

//check braces are proper {([]{})}

int validateExpr(string str)
{
	// valid expr length always be even
	map<char,char> mp;
	mp['{'] = '}';
	mp['['] = ']';
	mp['('] = ')';

	int len = strlen(str.c_str());

	stack<char> st;
	char ch;
	map<char,char>::iterator it;
	for(int i=0;i<len;++i)
	{
		if(str[i] == '{' || str[i] == '[' || str[i] == '(')
		{
			st.push(str[i]);
		}
		else {
			if(st.empty())
			{
				cout<<"mismatch in parentheses in expr " <<str<<endl;
				return 1;
			}
			ch = st.top();
			st.pop();
			it = mp.find(ch);
			if(it != mp.end())
			{
				if(it->second != str[i])
				{
					cout<<"mismatch in parentheses in expr " <<str<<endl;
					return 1;
				}
			}
			
		}
	}
	if(st.empty())
		cout<<"matching parentheses in expr "<<str<<endl;
	else 
		cout<<"mismatch in parentheses in expr " <<str<<endl;
	return 0;
}

int main()
{
	
	string str1 = "{([]{})}"; //valid
	string str2 = "[()]{}{[()()]()}"; //valid
	string str3 = "{(})"; //invalid
	string str4 = "{()(}"; //invalid
	string str5 = "[()]{}{[()(]))()}"; //invalid
	validateExpr(str1);
	validateExpr(str2);
	validateExpr(str3);
	validateExpr(str4);
	validateExpr(str5);
	return 0;
}
