#include <iostream>
#include <string>
using namespace std;
#define R 3
#define C 5
   
/* checking 8 neighbours of (x,y)

	(-1,1)	(0,1)	(1,1)
	(-1,0)	(x,y)	(1,0)
	(-1,-1)	(0,-1)	(1,-1)
*/

char buf1[10] = {'\0'};
char buf2[10] = {'\0'};
 
int rowIn[] = {-1,-1,-1,0,0,1,1,1};
int colIn[] = {-1,0,1,-1,1,-1,0,1};

bool isValid(int r, int c, int prevR, int prevC)
{
	return ( (r>= 0 && r<R) && (c>=0 && c<C) &&
		(!(r == prevR && c == prevC)));
}

void DFS(char mat[][C], int r, int c, int prevR, int prevC, string path, int index, char* word, int len)
{
	if(index>len || mat[r][c] != word[index])
		return;

	snprintf(buf1, sizeof(buf1)-1, "%d", r);
	snprintf(buf2, sizeof(buf2)-1, "%d", c);
	path += " " + string(1,mat[r][c]) + "("+ buf1 +" , "+ buf2 +")";

	if(index == len)
	{
		cout<<"path: "<<path<<endl;
		return;
	}

	for(int i=0;i<8;++i)
	{
		if(isValid(r+rowIn[i], c+colIn[i], r, c))
			DFS(mat, r+rowIn[i], c+colIn[i], r, c, path, index+1, word, len);
	}
}

void searchWord(char mat[][C], char* word, int len)
{
	for(int i=0;i<R;++i)
	{
		for(int j=0;j<C;++j)
		{
			if(mat[i][j] == word[0])
				DFS(mat, i, j, -1, -1, "", 0, word, len);
		}
	}
}

int main()
{
	char mat1[R][C] ={ 
						{'B', 'N', 'E', 'Y' ,'S'},
						{'H', 'E', 'D', 'E' ,'S'},
						{'S', 'G', 'N', 'D' ,'E'}
					};

	char mat[R][C] ={ 
						{'B', 'N', 'E', 'S' ,'S'},
						{'H', 'E', 'D', 'E' ,'S'},
						{'S', 'G', 'N', 'D' ,'E'}
					};

	char word[]="DES";
	searchWord(mat, word, strlen(word)-1);
	return 0;
}
