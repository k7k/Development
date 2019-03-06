#include <iostream>
#include <unordered_map>
using namespace std;

struct Trie{
    bool isWordEnd;
    unordered_map<char, Trie*> mp;
};

Trie* getNode()
{
    Trie *tmp = new Trie;
    tmp->isWordEnd = false;
    return tmp;
}

void insert(Trie*& root, string str)
{
    if(root == NULL)
        root = getNode();

    Trie *tmp = root;
    char c;
    for(int i=0;i<str.length();++i)
    {
        c = str[i];

        if(tmp->mp.find(c) == tmp->mp.end())
            tmp->mp[c] = getNode();

        tmp = tmp->mp[c];
    }
    tmp->isWordEnd = true;
}

bool search(Trie *root, string query)
{
        if(root == NULL)
                return false;

        Trie *tmp = root;
        for(int i=0; i<query.length();++i)
        {
                if(tmp->mp.find(query[i]) == tmp->mp.end())
                        return false;

                tmp = tmp->mp[query[i]];
        }
        return (tmp && tmp->isWordEnd);
}

bool isLastNode(Trie *root)
{
        if(root->mp.empty())
                return true;

        return false;
}

void autoSuggest(Trie *root, string q)
{
        if(root == NULL)
                return;

        if(root->isWordEnd)
        {
                cout<<q<<endl;
        }

        if(isLastNode(root)) 
            return;
        
         
        for(auto it = root->mp.begin(); it != root->mp.end();++it)
        {
                        q.push_back(it->first);
                        autoSuggest(it->second,q);
                        q.pop_back();
        }
}

int printAutoSuggest(Trie *root, string query)
{
        if(root == NULL)
                return 0 ;

        Trie *tmp = root;
        for(int i=0; i<query.length();++i)
        {
                if(!tmp)
                    break;

                if(!tmp->mp.empty())
                {
						if(tmp->mp.find(query[i]) != tmp->mp.end())
                        	tmp = tmp->mp[query[i]];
						else return 0;
                }
				else if(i != query.length())
					return 0;
        }

        bool iswordfound = (tmp->isWordEnd == true);
        bool isLast = isLastNode(tmp);

        if(isLast && iswordfound)
        {
                cout<<query<<endl;
                return -1;
        }

        if(!isLast)
        {
                string str = query;
                autoSuggest(tmp,query);
                return 1;
        }
        return 0;
}

int main() {

        Trie *root = getNode();

        insert(root, "hello");
        insert(root, "hell");
        insert(root, "hellow");
        insert(root, "hel");
        insert(root, "help");
        insert(root, "helper");
        insert(root, "helping");
        insert(root, "dog");
        insert(root, "cat");
        insert(root, "a");

        //if(search(root,"dg"))
        if(search(root,"help"))
                cout<<"search found\n";
        else cout<<"Search not found\n";

        //int ret = printAutoSuggest(root, "dg");
        //int ret = printAutoSuggest(root, "hellowdg");
        int ret = printAutoSuggest(root, "hel");
        if(ret == 1)
                cout<<"found string with prefix\n";
        else if(ret == -1)
            cout<<"No string with prefix\n";
        else if(ret == 0)
            cout<<"NO matching string found\n";

        return 0;
}




