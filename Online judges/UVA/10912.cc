#include <bits/stdc++.h>
using namespace std;

int L,S;
int valor[26];
long int dp[28][28][400];

long long int f(int n, int i , int disp)
{
	if(i == 26 && n == L && disp == 0) return 1;
	if(i > 26 || n < 0 || disp < 0) return 0;
	if(dp[i][n][disp] != -1) return dp[i][n][disp];
	dp[i][n][disp] = f(n+1,i+1,disp - valor[i]) + f(n,i+1,disp);
	return dp[i][n][disp];
}

int main()
{
	//freopen("in","r",stdin);
	int casos = 1;
	for(int i = 0; i < 27;i++) valor[i] = i+1;
	while(scanf("%d%d",&L,&S) && (L||S))
	{
		memset(dp,-1,sizeof dp);
		printf("Case %d: %lld\n",casos++,f(0,0,S));
	}	
}
