#include <bits/stdc++.h>
using namespace std;
long long int N,K,qtd = 188;

int primos[1001];
long long int dp[300][20][1120];

void geraPrimos()
{
	int k = 0,totalDivisores,i,j;
	  for(i = 0; i <= 1130; i++) {
        totalDivisores = 0;
        for(j = 1; j <= i; j++) {
            if(i % j == 0) {
                totalDivisores++;
            }
        }
        if(totalDivisores == 2) {
			primos[k++] = i;
        }
    }
}

long long mochila(int primo, int k, int sum)
{
	if(sum == 0 && k == 0) return 1;
	
	if( primo == qtd || k == 0 || sum < 0) return 0;
	
	if(dp[primo][k][sum] != -1) return dp[primo][k][sum];
	
	dp[primo][k][sum] = mochila(primo+1,k-1,sum-primos[primo]) + mochila(primo+1,k,sum);
	
	return dp[primo][k][sum];
	
}

int main()
{
	geraPrimos();
	while(scanf("%lld%lld",&N,&K) && (N||K))
	{	
		memset(dp,-1,sizeof dp);
		cout<<mochila(0,K,N)<<endl;
	}
}
