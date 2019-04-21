#include <bits/stdc++.h>
using namespace std;

int pesos[1009];
int precos[1009];
int qtdProdutos;
int dp[1009][1009];

int mochila(int disp, int produto)
{
	if(produto >= qtdProdutos)	return 0;
	
	if(disp <= 0 ) return 0;
	
	if(dp[disp][produto] != -1) return dp[disp][produto];
	
	dp[disp][produto] = 0;
	
	if(pesos[produto]<=disp) dp[disp][produto] = max(precos[produto] + mochila(disp-pesos[produto],produto+1),mochila(disp,produto+1));	
	else dp[disp][produto] = mochila(disp,produto+1);
	return dp[disp][produto];
}

int main()
{
	int casos,produtos,pessoas;
	scanf("%d",&casos);	
	while(casos--)
	{
		scanf("%d",&produtos);
		qtdProdutos = produtos;
		int a,b;
		for(int i = 0; i < produtos;i++)
		{
			scanf("%d%d",&a,&b);
			precos[i] = a;
			pesos[i] = b;
		}
		scanf("%d",&pessoas);
		int Soma = 0,pesoAux;
		while(pessoas--)
		{
			scanf("%d",&pesoAux);
			memset(dp,-1,sizeof dp);
			Soma += mochila(pesoAux,0);	
		}
		cout<<Soma<<endl;
	}
}
