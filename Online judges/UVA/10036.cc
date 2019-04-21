#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int N,K;
ll dig[10001];
ll dp[10001][101];

int f(int i , int valor)
{
	if(i == N )
	{ 
		if(!(valor%K))return 1;
		return 0;
	}
	ll & r = dp[i][valor];
	if(r != -1) return r;
	return r = f(i+1,(valor + dig[i]%K + K)%K ) || f(i+1,(valor - dig[i]%K + K)%K);
}


int main()
{
	//~ freopen("in","r",stdin);
	//~ freopen("out","w",stdout);
	int casos;
	scanf("%d",&casos);
	while(casos--)
	{
		scanf("%d%d",&N,&K);
		for(int i = 0 ; i < N;i++) scanf("%lld",&dig[i]);
		memset(dp,-1,sizeof dp);
		if(f(0,0)) puts("Divisible");
		else puts("Not divisible");
	}
}
