#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;

#define maxn 250
#define inf 63
#define pb push_back

vector<int> g[maxn];

int n, e, k;
int cap[maxn][maxn], cost[maxn][maxn];
int pai[maxn], dist[maxn];


void add(int from,int to, int a, int b)
{
	g[from].pb(to), g[to].pb(from);
	cap[from][to] = a, cap[to][from] = 0;
	cost[from][to]= b, cost[to][from]=-b;
}

int dkj(int source, int sink)
{
	memset(dist,inf,sizeof dist);
	priority_queue<ii ,vector<ii>, greater<ii> > pq; 
	pq.push(ii(0,source));
	dist[source] = 0;
	
	while(pq.size())
	{
		int u = pq.top().second;
		int d = pq.top().first; pq.pop();
		
		if(u == sink) 
			return dist[u];
		
		if(d > dist[u])
			continue;
		
		for(auto v : g[u])
		{			
			int w = cost[u][v];
		
			if(cap[u][v] >= 1 && dist[u] + w < dist[v])
			{
				dist[v]= dist[u] + w;
				pai[v] = u;
				pq.push(ii(dist[v],v));
			}
		}
	}
	return -1;
}

ii minCost(int source, int sink) // O(V*E^2). 
{
	int mf = 0;
	int flowCost = 0;
	
	while(dkj(source, sink) != -1)
	{	
		int u, garg = inf , v = sink;
		while(v != source)
		{
			u = pai[v];
			garg = min(garg , cap[u][v]);
			v = u;
		}
		
		v = sink;
		while(v != source)
		{
			u = pai[v];
			cap[u][v] -= garg;
			cap[v][u] += garg;
			v = u;	
		}
		
		// flow*(cost do caminho)
		flowCost += garg * dist[sink];
		mf += garg;
	}
	
	return ii(flowCost, mf);
}

int main() 
{
	//~ freopen("in","r",stdin);
	int casos, source, sink;
	cin>>casos;
	
	while(casos--)
	{
		cin>>n>>e>>k;
		
		for(int i = 0; i < 3*n ; i++)
			g[i].clear();
			
		memset(cap,0,sizeof cap);
		memset(cost,0,sizeof cost);
			
		source = 0;
		sink = n*2 + 1;
		
		for(int i = 1; i <= e; i++)
		{
			int u, v, cost;
			cin>>u>>v>>cost;
			add(u+1, v+1+n, 1, cost);
		}
		
		for(int i = 1; i <= n; i++)
		{
			add(source, i, k, 0);
			add(i+n, sink, k, 0);
		}
				
		ii ans = minCost(source, sink);
		
		if(ans.second != n*k) cout<<-1<<endl;
		else cout<<ans.first<<'\n';
	}
}
