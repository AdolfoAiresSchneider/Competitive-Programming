#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;


vector<ii> coins;

int dp[400][400][100];

int f(int s1, int s2, int i, int total)
{
	if((s1*s1 +s2*s2)  ==  total ) return 0;
	if((s1*s1 +s2*s2) >total || i >= (int)coins.size() )  return 1e9;
	int & r = dp[s1][s2][i];
	if(r != -1) return r;
	r = 1e9;
	r = min(f(s1 +coins[i].first , s2 + coins[i].second , i , total) + 1, f (s1,s2,i+1,total));
	return r;
}

int main()
{
	//~ freopen("in","r",stdin);
	int casos,M,S,a,b;
	scanf("%d",&casos);
	
	while(casos--)
	{
		coins.clear();
		scanf("%d%d",&M,&S);
		while(M--)
		{
			scanf("%d%d",&a,&b);
			coins.push_back(ii(a,b));
		}
		memset(dp, -1, sizeof dp);
		int resp = f(0,0,0,S*S);
		if(resp < 1e9) printf("%d\n",resp);
		else printf("not possible\n");
	}
}
