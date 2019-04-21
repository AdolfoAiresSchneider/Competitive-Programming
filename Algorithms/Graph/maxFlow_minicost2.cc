#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;

#define maxn 10000
#define inf 0x3f3f3f3f
#define endl '\n'

int p[maxn], dist[maxn];
vector<int> g[2 * maxn + 4];
int n, m;


struct ed
{
	int cost, cap, to, from;
	ed(){}
	ed(int a,int b, int c, int d) :
    cost(a) , cap(b), to(c) ,from(d){}
};

vector<ed> edges;

ii operator + (ii a, ii b){
	return ii(a.first + b.first , a.second + b.second );
}

void add(int from, int to, int cost, int cap)
{
	edges.push_back(ed(cost, cap, to, from));
	edges.push_back(ed(-cost, 0, from, to));
	
	g[from].push_back(edges.size()-2);	
	g[to].push_back((edges.size()-1));	
}

bool djk(int s , int t)
{
  priority_queue<ii, vector<ii>, greater<ii> > pq;
  memset(dist, inf, sizeof dist), memset(p, -1, sizeof p);
  dist[s] = 0; pq.push(ii(0,s));
	
	while(pq.size())
	{
		int u = pq.top().second;
		int d = pq.top().first; pq.pop();
    
    if(u == t)
      return 1;
      
    if(d > dist[u]) 
      continue;
	    
    for(auto x : g[u])
		{
			ed v = edges[x];
			
      if(dist[v.to] > d + v.cost && v.cap > 0)
      {
				dist[v.to] = d + v.cost;
				p[v.to] = x;
				pq.push(ii(dist[v.to], v.to));
			}
		}
	}
	return 0;
}

ii max_flow_minCost(int s, int t)
{
	ii ans = ii(0,0);
	while(djk(s,t))
	{
		int garg = inf;
		
		int x = p[t];
		while(x != -1)
    {
			ed v = edges[x];
			garg = min(garg , v.cap);
			x = p[v.from];
		}
    
		x = p[t];
		while(x != -1)
    {	
			ed &  v1 = edges[x], &  v2 = edges[x^1];
			v1.cap -= garg, v2.cap += garg;
			x = p[v1.from];
		}
		ans =  ans + ii(garg, dist[t]);
	}
  
	return ans;
}

void init(int N)
{
  for(int i = 0; i <= N; i++)
    g[i].clear();
  edges.clear();
}

// Min cost of two paths from S to T
int main()
{
	//~ freopen("in","r",stdin);
  cin.sync_with_stdio(0), cin.tie(0);
	
	while(cin>>n>>m)
	{
    init(2*n+55);
    
    // Splitando os vertices, só podemos usar um vertice uma vez.
    // Vertice i  = 2*i(in) - (2*i+1)(out)
    
		for(int i = 1; i <= n;i++)
			add(2*i , 2*i+1 ,0, 1);
    
		while(m--)
    {
      int a, b, c;	
			cin>>a>>b>>c;
			int u = 2*a+1, v = 2*b;
			add(u, v, c, 1);
		}
    
		add(2*n , 2*n+2 , 0 , 2); // Limitando o fluxo de saida para 2, ou seja dois caminhos
		cout<<max_flow_minCost(2 + 1 , 2*n+2).second<<endl;
	}
}
