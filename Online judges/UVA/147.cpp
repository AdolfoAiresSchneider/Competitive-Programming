#include<bits/stdc++.h>
using namespace std;

int moedas[]={10000,5000,2000,1000,500,200,100,50,20,10,5};



long long int dp[12][30001];

long long int CC(int i, int disp)
{
	if(disp == 0) return 1;
	if( i >= 11 || disp < 0) return 0;
	if(dp[i][disp] != -1 ) return dp[i][disp];
	dp[i][disp] = CC(i+1,disp) + CC(i,disp-moedas[i]);
	return dp[i][disp];
}

int main()
{	
	//freopen("in]","r",stdin);
	int v1,v2;
	memset(dp,-1,sizeof dp);	
	while(1)
	{
		scanf("%d.%d",&v1,&v2);
		if(!v1 && !v2) break;
		if(v2<10)printf("%3d.0%d%17lld\n",v1,v2,CC(0,v1*100+v2) );
		else printf("%3d.%d%17lld\n",v1,v2,CC(0,v1*100+v2) );
	}
}
