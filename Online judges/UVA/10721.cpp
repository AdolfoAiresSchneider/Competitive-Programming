#include <bits/stdc++.h>
using namespace std;
int N,K,M;

long long dp[51][51][51];

long long int f(int i,int k, int m, int last)
{
	if(i < 0 || k < 0 || m > M) return 0;
	if(i == 0 && k == 0 && m <= M ) return 1;
	if(dp[i][k][m] != -1) return dp[i][k][m];
	if(last == 1 || last == 0){	
		if(last == 0) dp[i][k][m] = f(i-1,k,m+1,0) + f(i-1,k-1,1,1);
		else dp[i][k][m] = f(i-1,k,m+1,1) + f(i-1,k-1,1,0);
	}
	else dp[i][k][m] = f(i-1,k-1,1,0);
	return dp[i][k][m];
}

int main()
{
	int i,j,k;
	while(scanf("%d%d%d",&N,&K,&M))
	{
		for(i = 0; i <= N;i++) for(j = 0; j <= K;j++)  for(k = 0; k <= M;k++) dp[i][j][k] = -1; 
		cout<<f(N,K,1,-1)<<endl;
	}
}
