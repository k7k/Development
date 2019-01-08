#include <iostream>

using namespace std;

/*
expected output:
4
* * * * * * *
  * * * * *
    * * *
      *
      *
    * * *
  * * * * *
* * * * * * *
*/
int main()
{
#if 0
	int r=0;
	cout<<"input count\n";
	cin>>r;

	/* half pyramid*/
	for(int i=0;i<r;++i){
		for(int j=0;j<(r-i);++j){
			cout<<"* ";
		}
		cout<<endl;
	}
#endif
	int m=0;
	int n=0;
	cin>>m;
	//printf("\033[5;32;40m"); /* the first parm: 5 tells it to blink... the second parm: 32 tells it green text... the third parm: 40 tells it black background */
	// inverted pyramid
	for(int i=m;i>0;--i){
		bool flag=true;
		for(int j=1;j<=(2*i-1);++j,flag=false){
			if(flag) {
				int c=m-i;
				while(c >0){
					cout <<"  ";
					c--;
				}
			}
			cout<<"* ";
		}
		cout<<endl;
	}

	// pyramid
	for(int i=1;i<=m;++i) {
		bool flag=true;
		for(int j=1;j<=(2*i-1);++j,flag=false) {
			if(flag){
				int c=m-i;
				while(c>0){
					cout<<"  ";
					c--;
				}
			}
			cout<<"* ";
		}
		cout<<endl;
	}

	//printf("\033[m"); /* stop blinking attribute from further text */
	return 0;
}
