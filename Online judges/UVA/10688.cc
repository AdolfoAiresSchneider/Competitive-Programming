#include <bits/stdc++.h>
using namespace std;

int N,K;
int valores[600];
int dp[500][500];

int f(int i, int j)
{
	if(i >= j) return 0;
	if(dp[i][j] != -1) return dp[i][j];
	dp[i][j] = 1e9;
	for(int a = i; a <= j;a++)	dp[i][j] = min( dp[i][j] , (K+a)*(j-i+1) + f(a+1,j) + f(i,a-1));
	return dp[i][j];
}

int main()
{
	int casos,u = 1;
	scanf("%d",&casos);	
	while(casos--)
	{
		scanf("%d%d",&N,&K);
		memset(dp, -1 ,sizeof dp);
		cout<<"Case "<<u++<<": "<<f(1,N)<<endl;
	}
}
