#include <bits/stdc++.h>
using namespace std;


vector<int> notas[80];
int N,T,P;

int dp[80][80];

int mochila(int prova, int disp, int k)
{
	if(disp == 0 && k == N) return 1;
	if(disp < 0 || prova >= N) return 0;
	if(dp[prova][disp] != -1) return dp[prova][disp];
	dp[prova][disp] = 0;
	for(int i = 0; i < (int)notas[prova].size();i++){
		if(notas[prova][i] <= disp) dp[prova][disp] += mochila(prova+1,disp-notas[prova][i],k+1);	
	}
	return dp[prova][disp];
 }

int main ()
{
	//freopen("in","r",stdin);
	int casos;
	scanf("%d",&casos);
	while(casos--)
	{
		scanf("%d%d%d",&N,&T,&P);
		
		for(int i = 0; i < N;i++)
		{
			for(int j = P; j <= (T - P * (N - 1));j++)
			{
				notas[i].push_back(j); 
			}
		}	
		memset(dp,-1,sizeof dp);
		cout<<mochila(0,T,0)<<endl;	
		for(int i = 0; i < N;i++) notas[i].clear(); // limpar
	}
}
