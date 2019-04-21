#include<bits/stdc++.h>
using namespace std;

#define maxn 100009
#define st first
#define nd second
#define pb push_back

typedef pair<int,int> ii;

int n, q, p[maxn][30], h[maxn];
vector<int> g[maxn];

void dfs_lca(int u, int pai, int d)
{
  h[u] = d, p[u][0] = pai;
  for(auto v : g[u])
  {
    if(v == pai)
      continue;
    dfs_lca(v, u, d+1);
  }
}

void process()
{
  int lg = log2(n);
  for(int i = 1; i <= lg; i++) 
  {
    for(int u = 1; u <= n; u++)
    {
      int x = p[u][i-1];
      p[u][i] = p[x][i-1];
    }
  }
}

int lca(int u, int v)
{
  if(h[u] < h[v])
    swap(u, v);
  
  int dif = h[u] - h[v], lg = log2(h[u]);
  
  for(int i = lg; i >= 0; i--)
    if((1<<i) & dif)
      u = p[u][i];
  
  if(u == v)
    return u;
  
  for(int i = lg; i >= 0; i--)
    if(p[u][i] != p[v][i])
      u = p[u][i], v = p[v][i];
  
  return p[u][0];
}

int dist(int u, int v)
{
  return h[u] + h[v] - 2*h[lca(u,v)];
}

int inPath(int u, int v, int x)
{
  return lca(u, x) == u && lca(x,v) == x;
}

bool intersect(int u, int v, int x, int y)
{
  if(h[u] > h[v]) swap(u, v);
  if(h[x] > h[y]) swap(x, y);
  
  int anc = lca(v, y);
  return inPath(u,v,anc) && inPath(x,y, anc);
}

vector<ii> t;
int query(int u, int v, int x, int y)
{    
  int anc1 = lca(u,v);
  int anc2 = lca(x,y);
  
  if(!(intersect(u,anc1, x, anc2) || intersect(u, anc1, y, anc2) || 
    intersect(v, anc1, x, anc2) || intersect(v, anc1, y, anc2)))
      return 0;
  
  t.clear();
  int a1 = lca(u,x); t.pb(ii(h[a1], a1));
  int a2 = lca(u,y); t.pb(ii(h[a2], a2));
  int a3 = lca(v,x); t.pb(ii(h[a3], a3));
  int a4 = lca(v,y); t.pb(ii(h[a4], a4));
  
  sort(t.rbegin(), t.rend());
  return dist(t[0].nd, t[1].nd)+1;
}

int main()
{
  //~ freopen("in", "r", stdin);
  //~ freopen("out", "w", stdout);
  
  scanf("%d%d",&n,&q);
  
  for(int i = 0; i < n-1; i++)  
  {
    int a, b;
    scanf("%d%d",&a,&b);
    g[a].pb(b),g[b].pb(a);
  }
  
  dfs_lca(1,1,0);
  process();
  
  while(q--)
  {
    int a, b, c, d;
    scanf("%d%d%d%d",&a,&b,&c,&d);
    printf("%d\n", query(a, b, c, d));
  }
}
