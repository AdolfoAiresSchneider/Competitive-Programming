#include <bits/stdc++.h>
using namespace std;
long long int c=1;

long long valores[300];
long long int n,q,MOD;
long long dp[201][201][201];

long long mod(long long number, int mod)
{
    return number % mod;
}


long long int mochila(  int m , int resto , int j )
{
	if( m == 0 && resto == 0) return 1;
	if( j == n || m == 0 ) return 0;
	if(dp[m][resto][j] != -1) return dp[m][resto][j];
	dp[m][resto][j] = mochila( m-1 , mod(resto + mod(valores[j],MOD),MOD) , j+1) + mochila(m,resto,j+1);
	return dp[m][resto][j];
}

int main()
{
	long long int d;
	while(scanf("%lld%lld",&n,&q) && (n||q))
	{
		for( int i = 0; i < n ; i++ )	
			scanf("%lld",&valores[i]);
			
		printf("SET %lld:\n",c++);
		
		for(int i = 1;i <= q; i++)
		{
			memset(dp,-1,sizeof dp);
			scanf("%lld%lld",&MOD,&d);
			long long resp = mochila(d,0,0);
			printf("QUERY %d: %lld\n",i,resp);	
		}
	}
}
