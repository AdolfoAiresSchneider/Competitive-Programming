#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N,S;
ll dp[66][66][2];

ll f(int i, int l, int last)
{
	if(l == 0 &&  i == N) return 1;
	if(i > N || l < 0)   return 0;
	ll & r = dp[i][l][last];
	if(r != -1) return r;
	if(last) return r = f( i+1 , l - 1 , 1) + f(i+1 , l , 0 );
	return r = f(i+1,l,1) + f(i+1,l,0);
}


int main()
{
	//~ freopen("in","r",stdin);
	//~ freopen("out","w",stdout);
	while(scanf("%lld%lld",&N,&S) == 2 && (N>0||S>0))
	{
		memset(dp,-1,sizeof dp);
		cout<<f(0,S,1)<<endl;
	}
}
