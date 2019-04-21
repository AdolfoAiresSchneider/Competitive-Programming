#include <bits/stdc++.h>
using namespace std;
typedef long long ull;
// apenas colocar a dp na funçao e ignorar a soma!!!!!!!!!!!!!
ull dp[70][70];

ull f(int n, int back)
{
	if(n<=0) return  1;
	ull & r = dp[n][back];
	if(n==1) return  1;
	if(r != -1) return r ;
	r = 1;
	for(int i = 1 ; i <= back;i++)
		r += f(n-i,back);
	return r;
}

int main()
{
	ull a,b,caso = 1;
	memset(dp,-1,sizeof dp);
	while(scanf("%lld%lld",&a,&b) && a<61)
		printf("Case %llu: %llu\n",caso++,f(a,b));
}
