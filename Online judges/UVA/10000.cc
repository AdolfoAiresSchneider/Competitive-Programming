#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
// Apenas maior dinstancia em um dag e imprimir o destino com id minimo
int N,start,a,b;
vector<int> grafo[101];
int dp[101];
int v[101];


int f(int u)
{
	int & r = dp[u];
	if(r != -1)  return r;
	
	if(grafo[u].size() == 0) // não posso ir para nenhum !
	{
		v[u] = u;
		return 0;
	}
	
	for(int i = 0 ; i < (int)grafo[u].size() ; i++)
	{
		if(r == f(grafo[u][i]) + 1) v[u] = min(v[u],v[grafo[u][i]]); // se tiver o mesmo tamango pega o meno id de vetice!
		else
		{
			if(r < f(grafo[u][i]) + 1)
			{
				r = f(grafo[u][i]) + 1;
				v[u] = v[grafo[u][i]]; // segunda dp com vertices, vai trazendo os vertices
			}
		}
	}
	return r;
}

int main()
{	
	int caso = 1;
	while(scanf("%d",&N) && N)	
	{
		for(int i = 0 ; i <= N;i++) grafo[i].clear();
		scanf("%d",&start);
		
		while(scanf("%d%d",&a,&b) && ( a || b ) )
			grafo[a].push_back(b);
		
		memset(dp,-1,sizeof dp);
		memset(v,-1,sizeof v);		
		
		int resp = f(start);
		printf("Case %d: The longest path from %d has length %d, finishing at %d.\n\n",caso++,start,resp,v[start]);
	}
}
