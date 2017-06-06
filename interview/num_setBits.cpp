#include <iostream>
using namespace std;

int main()
{
        int num;
        cout << "enter the number\n";
        cin >> num;
        int count = 0;

        while(num) {
                if(num&1) {
                        count++;
                }
                num = num >> 1;
        }

	/*
	subtract 1 from n toggles all the bits
	while(n) {
		n &= (n-1);
		count++;
	}

	*/
        cout<<"Number of bits set in the given number "<<num<<" is "<<count<<endl;
        return 0;
}
