#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5002; 
const int INF = 1e9; 
typedef long long ll;
typedef pair<int,int> ii;
typedef pair<ii,int> iii;

#define iii(a,b,c) iii(ii(a,b), c)
#define pb push_back
#define nd second
#define st first
 
struct edge {
	int a, b, cap, mf;
};
 
int n, s, t, dist[MAXN], ptr[MAXN], m;

vector<edge> e;
vector<int> g[MAXN];
 
void add_edge (int a, int b, int cap)
{
  g[a].push_back ((int) e.size());
  e.push_back ({ a, b, cap, 0 }); 
	g[b].push_back ((int) e.size());
  e.push_back ({ b, a, 0, 0 });
}
 
bool bfs()
{
  queue<int> q; q.push(s);
  memset (dist, -1, sizeof dist); 
  dist[s] = 0;
  
  while(q.size() && dist[t] == -1)
  {
    int v = q.front(); q.pop();
    for(auto id : g[v])
    {
      int to = e[id].b;
      if(dist[to] == -1 && e[id].mf < e[id].cap)
      {
        q.push(to);
        dist[to] = dist[v]+1;
      }
    }
  }
	return dist[t] != -1;
}
 
int dfs (int u, int mf) 
{
	if (!mf)  
    return 0;
	
  if (u == t)
    return mf;
  
	for (; ptr[u] < (int)g[u].size(); ++ptr[u])
  {
		int id = g[u][ptr[u]], to = e[id].b;
      
		if (dist[to] != dist[u] + 1)  
      continue;
      
		int garg = dfs (to, min (mf, e[id].cap - e[id].mf));
		
    if(garg) 
    {
			e[id].mf += garg;
			e[id^1].mf -= garg;
			return garg;
		}
	}
	return 0;
}

int dinic() // V^2*E
{
	int mf = 0;
	while(bfs())
  {   
		memset (ptr, 0, sizeof ptr);
		while (int garg = dfs (s, INF)){
			mf += garg;
    }
	}
	return mf;
}

vector<iii> v, v1, v2;
void init(int lim)
{
  e.clear();
  for(int i = 0; i <= n+m+15; i++)
      g[i].clear();
  
  for(auto t : v1){
    int a = t.st.st, b = t.st.nd, c = t.nd;
    add_edge(a, b, c);
  }
  for(auto t : v2){
    int a = t.st.st, b = t.st.nd, c = t.nd;
    add_edge(a, b, c);
  }
  for(auto t : v){
    int a = t.st.st, b = t.st.nd, c = t.nd;
    if(c <= lim) add_edge(a, b, INF);
  }
}

int p[MAXN], r[MAXN];

int main()
{
  //~ freopen("in", "r",stdin);
  
  int ed;
  scanf("%d%d%d", &n, &m, &ed);
  s = 0, t = n+m+4;
  int  tot = 0;
  
  for(int i = 1; i <= n; i++)
  {
    scanf("%d",&p[i]);
    v1.pb(iii(m+1+i, t, p[i]));
    tot += p[i];
  }
    
  for(int i = 1; i <= m; i++)
  {
    scanf("%dist",&r[i]);
    v2.pb(iii(s, i, r[i]));
  }
  
  while(ed--)
  {
    int a, b, c;
    scanf("%d%d%d",&b,&a,&c);
    v.pb(iii(a,b+1+m,c));
  }
  
  int l = 0, r = 1e9;
  while(l != r)
  {
    ll mid = (l+r)/2ll;
    init(mid);
    ll d = dinic();
    if(d != tot) l = mid+1;
    else r = mid;
  }
  
  printf("%d\n", (l >= INF ? -1 : l));
}
