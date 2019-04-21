#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
int n,m,t;

ii operator + (ii a, ii b)
{
	return ii(a.first + b.first, a.second + b.second);
}
ii dp[10002];

ii mochila(int disp)
{
	if(disp <= 0) return ii(0,0);
	if(dp[disp] != ii(-1,-1))  return dp[disp];
	dp[disp] = ii(0,0);
	if(m <= disp)  dp[disp] = max(ii(m,1) + mochila(disp-m),dp[disp]);
	if(n <= disp) dp[disp] = max(dp[disp],ii(n,1) + mochila(disp-n));
	return dp[disp];
}

int main()
{
	//freopen("in","r",stdin);
	//freopen("out","w",stdout);
	register int i;
	ii resp;
	
	while(cin>>n>>m>>t)
	{
		for(i = 0;i<t+1;++i) dp[i] = ii(-1,-1);
		resp = mochila(t);
		if(t - resp.first > 0) cout<<resp.second<<' '<<t-resp.first<<endl;
		else cout<<resp.second<<endl;
	}
}
