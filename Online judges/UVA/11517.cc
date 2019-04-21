#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;

int N;

ii operator + (ii a, ii b)
{
	return ii(a.first + b.first, a.second + b.second);
}


int moedas[100];
ii dp[10001][101];


ii f( int i , int disp )
{
	if(disp <= 0) return ii(0,0);
	if(i >= N) return ii(1e9,1e9);
	ii & r = dp[disp][i];
	if(r != ii(-1,-1)) return r;
	return r = min( f(i+1 , disp - moedas[i]) + ii(moedas[i] , 1) , f(i+1 , disp) );
}

int main()
{
	//~ freopen("in","r",stdin);	
	//~ freopen("out","w",stdout);	
	
	int casos;
	scanf("%d",&casos);
	int preco;
	while(casos--)
	{
		scanf("%d%d",&preco,&N);
		for(int i = 0 ; i < N;i++)
			scanf("%d",&moedas[i]);
		memset(dp,-1, sizeof dp);
		ii resp = f(0,preco);
		printf("%d %d\n",resp.first , resp.second);
	}
	
}
