#include <bits/stdc++.h>
using namespace std;

long long int N,M;
long long int valores[1001];
long long int dp[1000][1000];

long long f(int n, int m)
{
	if( m <= 0 ) return 1;
	if(n == N) return 0;
	if(dp[n][m] != -1 ) return dp[n][m];
	dp[n][m] = (valores[n] * f(n+1, m-1 ) + f(n+1,m) )%M;
	return dp[n][m]%M;
}

int main()
{
	//freopen("in","r",stdin);
	//freopen("out","w",stdout);
	while(scanf("%lld%lld",&N,&M) && (N||M))
	{
		for(int i = 0; i < N ; i++) scanf("%lld",&valores[i]);
		memset(dp,-1,sizeof dp);
		long long resp = 0;
		for(int i = 1; i <= N; i++)
		{
			resp = max(f(0,i),resp);
		}
		cout<<resp<<endl;
	}
}
