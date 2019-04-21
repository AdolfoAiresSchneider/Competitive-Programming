#include <bits/stdc++.h>
using namespace std;
 
typedef pair<int,int> ii;
#define maxn 600
#define inf 1e9
 
 
int g[maxn][maxn];
 
int dist[maxn];
int m,n;
 
int dkj(int source, int sink)
{
	
	for(int i = 0; i <= n+10; i++)
		dist[i] = inf;
		
	priority_queue<ii ,vector<ii>, greater<ii> > pq;
	pq.push(ii(0,source));
	dist[source] = 0;
	
	while(!pq.empty())
	{
		ii atual  = pq.top(); pq.pop();
		
		int u = atual.second;
		int d = atual.first;
		
		for(int i = 0; i <= n ; i++)
		{
			
			if( i == u) continue;
			int v = g[u][i];
			
			if(d + v < dist[i])
			{
				dist[i] = d + v;
				pq.push(ii(dist[i],i));
			}
		}
	}
	return dist[sink];
}
 
int main()
{
	//~ freopen("in","r",stdin);
	
	while(scanf("%d%d",&n,&m) == 2 && (m || n) )
	{
		for(int i = 0; i <= n;i++)
			for(int j = 0; j <= n;j++)
				g[i][j] = inf;
			
		while(m--)
		{
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			g[a][b] = c;
			if(g[b][a] != inf ) g[a][b] = g[b][a] = 0;
		}
		
		int k;
		cin>>k;
		
		while(k--)
		{
			int a,b;
			scanf("%d%d",&a,&b);
			int d = dkj(a,b);
			
			if(d == (int) inf) printf("Nao e possivel entregar a carta\n");
			else printf("%d\n",d);
		}
		printf("\n");
	}
}
