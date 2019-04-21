#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll c = 1;
ll p[300];
ll dp[201][40][40];

int main()
{
	//~ freopen("in","r",stdin);
	
	ll n,q,m,D;
	while(scanf("%lld%lld",&n,&q) && (n||q))
	{
		for( int i = 0; i < n ; i++ )
			cin>>p[i]; 
			
		printf("SET %lld:\n",c++);
		
		for(int w = 1 ; w <= q; w++)
		{
			cin>>D>>m;
			
			memset(dp ,0 ,sizeof dp);
			dp[0][0][0] = 1; // 0 % D = 0
			
			for(int i = 1; i <= n ; i++)
			{
				for(int j = 0; j <= m; j++)
				{
					for(int k = 0; k < D ; k++)
					{	
						ll rest = ((p[i-1] + k ) % D+D)%D;
						if(j > 0) dp[i][j][k] += dp[i-1][j-1][rest];
						dp[i][j][k] += dp[i-1][j][k]; 
					}
				}
			}
			
			printf("QUERY %d: %lld\n",w,dp[n][m][0]);	
		}
	}
}
