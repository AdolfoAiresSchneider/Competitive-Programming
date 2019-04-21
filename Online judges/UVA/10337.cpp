#include <bits/stdc++.h>
using namespace std;

int X,C;
int mat[50][1009];
int dp[50][1009];

// uma abordagem para achar um caminho minimo em um DAG usando DP é fazer o destino ser
// ou algo do tipo. kkk

int f(int alt, int j)
{
	if(alt == 0 && j == C ) return 0; // cheguei onde quero, elemento neutro para minimo
	if(alt > 9 || alt < 0 || j >= C || j < 0) return 1e9; // casos nao desejados, retorna infinito, não vai afetar a função min
	if(dp[alt][j] != -1) return dp[alt][j];	// base da dp
	dp[alt][j] = min(20 + f(alt-1,j+1), min( 30 + f(alt,j+1) , 60 + f(alt+1,j+1))); // calcula o minimo fuel possivel
	return	dp[alt][j] - mat[alt][j]; // retira o custo do vento
}

int main(){
	//freopen("in","r",stdin);
	int casos;
	scanf("%d",&casos);
	while(casos--)
	{
		scanf("%d",&X);
		C = X/100;
		for(int i = 9; i >=0; i--) // leitura invertida das colunas
			for(int j = 0; j <C;j++){
				scanf("%d",&mat[i][j]);
				dp[i][j] = -1;
			}
		cout<<f(0,0)<<endl;
		puts("");
	} 
}
