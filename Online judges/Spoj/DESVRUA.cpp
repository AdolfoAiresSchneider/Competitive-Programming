#include <bits/stdc++.h>
using namespace std;
 
#define maxn 1004
#define pb push_back
 
vector<int> g[maxn], rg[maxn], bg[maxn];
int vis[maxn], d[maxn], h[maxn], g3[maxn][maxn];
 
void init(int n)
{
  for(int i = 0; i <= n; i++)
    g[i].clear(), rg[i].clear(), bg[i].clear();
 
  memset(vis, 0, sizeof vis);
  memset(h, 0, sizeof h);
  memset(d, 0, sizeof d);
  memset(g3, 0, sizeof g3);
}
 
int dfs(int u, vector<int> * G)
{
  int sum = vis[u] = 1;
  for(auto v : G[u])
  {
    if(vis[v]) continue;
    sum += dfs(v, G);
  }
  return sum;
}
 
bool isScc(int n)
{
  int a = dfs(1, g);
  memset(vis, 0, sizeof vis);
  int b = dfs(1,rg);
 
  return a == n && b == n;
}
 
int cnt = 0;
void bridge(int u, int pai)
{
  d[u] = h[u] = h[pai]+1;
  vis[u] = 1;
 
  for(auto v : bg[u])
  {
    if(vis[v] == 0)
    {
      bridge(v, u);
 
      d[u] = min(d[u], d[v]);
 
      if(d[v] > h[u])
        if(g3[u][v] != 2)
          cnt++;
 
      continue;
    }
 
    if(v != pai)
      d[u] = min(d[u], h[v]);
  }
 
  vis[u] = 2;
}
 
bool isConexo(int n)
{
  memset(vis, 0, sizeof vis);
  return dfs(1, bg) == n;
}
 
bool hasBridge(int n)
{
  memset(vis, 0, sizeof vis);
 
  cnt = 0;
 
  for(int i = 1 ; i <= n ; i++)
    if(vis[i] == 0)
      bridge(i,i);
 
  return cnt;
}
 
 
int main()
{
  // freopen("in", "r" ,stdin);
  int n, m;
 
  while(cin>>n>>m)
  {
    init(n);
    for(int i = 0; i < m; i++)
    {
      int a, b, c;
      cin>>a>>b>>c;
 
 
      if(i == 0)
        continue;
 
      g3[a][b] = c;
 
      g[a].pb(b);
      rg[b].pb(a);
 
 
      bg[a].pb(b);
      bg[b].pb(a);
 
      if(c == 2)
      {
        g[b].pb(a);
        rg[a].pb(b);
      }
    }
 
    if(isScc(n))
    {
      cout<<'-'<<endl;
      continue;
    }
 
    if(!isConexo(n))
    {
      cout<<'*'<<endl;
      continue;
    }
 
    if(hasBridge(n))
    {
      cout<<2<<endl;
      continue;
    }
 
    cout<<1<<endl;
  }
}
