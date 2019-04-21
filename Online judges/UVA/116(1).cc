#include <bits/stdc++.h>
using namespace std;

int linha, coluna;
int arr[11][101];
int dp[11][101];

int cima(int i){
	if(i == 0) return linha-1;
	return i-1;
}
int baixo(int i){
	if(i == linha-1) return 0;
	return i+1;
}

int f(int i, int j){
	
	if(j == coluna) return 0;
	if(j >= coluna ) return 1e9;
	if(dp[i][j] != -1 ) return dp[i][j];
	dp[i][j] = min( arr[i][j] + f(cima(i),j+1),min( arr[i][j] + f(baixo(i),j+1),arr[i][j] + f(i,j+1)));
	return dp[i][j];
}

void rec(int i, int j, int linha)
{
	if(j >= coluna ) return;
	cout<<linha<<' ';
	if( dp[i][j] == arr[i][j] + f(i,j+1) ) rec(i,j+1,i+1);
	else if( dp[i][j] == arr[i][j] + f(baixo(i),j+1) )rec(baixo(i),j+1,baixo(i)+1);
	else rec(cima(i),j+1,cima(i)+1);
}


int main()
{
	freopen("in","r",stdin);
	while(scanf("%d%d",&linha,&coluna)!=EOF)
	{
		for(int i = 0; i < linha;i++)
			for(int j = 0; j < coluna;j++)
				scanf("%d",&arr[i][j]);
		
		int resp = 1e9,aux,start = 0;
		memset(dp,-1,sizeof dp);
		
		for(int i = 0; i < linha ; i++){
			aux = f(i,0);
			if(aux < resp){
				resp = aux;	
				start = i;
			}
		}
		rec(start,0,start+1);
		cout<<endl<<resp<<endl;
	}	
}
