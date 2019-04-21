#include <bits/stdc++.h>
using namespace std;

int linhas, coluna;
short int arr[11][101];
short int dp[11][101];

inline int cima(int i){
	if(i == 0) return linhas-1;
	return i-1;
}
inline int baixo(int i){
	if(i == linhas-1) return 0;
	return i+1;
}

int f(int i, int j){
	if(j == coluna) return 0;
	if(j >= coluna ) return 1e9;
	short int & r = dp[i][j],& aux =  arr[i][j];
	if(r != -1 ) return r;
	return r = min( aux + f(cima(i),j+1),min( aux + f(baixo(i),j+1),aux + f(i,j+1)));	
}

void rec(int i, int j, int linha)
{
	if(j >= coluna) return;
	printf("%d",linha); if(j<coluna-1) printf(" "); 
	short int & r = dp[i][j],& aux =  arr[i][j];
	if(i == linhas-1 && r == aux + f(baixo(i),j+1) ) rec(baixo(i),j+1,baixo(i)+1);
	else if(i > 0 && r == aux + f(cima(i),j+1)) rec(cima(i),j+1,cima(i)+1);
	else if( r == aux + f(i,j+1) ) rec(i,j+1,i+1);
	else if( r == aux + f(baixo(i),j+1) )rec(baixo(i),j+1,baixo(i)+1);
	else rec(cima(i),j+1,cima(i)+1);
}


int main()
{
	//freopen("in","r",stdin);
	//freopen("out","w",stdout);
	
	register int i,j,aux,resp,start;
	while(scanf("%d%d",&linhas,&coluna)!=EOF)
	{
		for(i = 0; i < linhas;i++){
			for( j = 0; j < coluna;++j){
				scanf("%hd",&arr[i][j]);
				dp[i][j] = -1;
			}
		}
		
		resp = 1e9,start = 0;
		for(i = 0; i < linhas ;++i){
			aux = f(i,0);
			if(aux < resp){
				resp = aux;	
				start = i;
			}
		}
		
		rec(start,0,start+1);
		printf("\n%d\n",resp);
	}	
}
