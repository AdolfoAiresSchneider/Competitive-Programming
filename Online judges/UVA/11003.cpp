#include <bits/stdc++.h>
using namespace std;

int pesos[1001];
int loads[1001];
int N;
int dp[5000][5000];




int mochila(int caixa, int disp)
{
	if(caixa >= N) return 0;
	if(disp == 0) return 0;
	if(dp[caixa][disp]!=-1) return dp[caixa][disp];
		
	if(pesos[caixa] <= disp)
		dp[caixa][disp] = max( 1 + mochila(caixa+1,min(disp - pesos[caixa] ,loads[caixa])) , mochila(caixa+1,disp));
	else dp[caixa][disp] = mochila(caixa+1,disp);
	
	return dp[caixa][disp];
	
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out","w",stdout);
	
	int caixas,peso,load;
	while(scanf("%d",&caixas)&&caixas)
	{
		N = caixas;
		for(int i = 0; i < caixas;i++)
		{
			scanf("%d%d",&peso,&load);
			pesos[i]= peso;
			loads[i] = load;
		}
		
		memset(dp,-1,sizeof dp);
		int resp  = 1;
		for(int i = 0; i<caixas; i++)
		{
			resp = max(resp,mochila(i+1	,loads[i])+1);
		}
		cout<<resp<<endl;
	}	
}
