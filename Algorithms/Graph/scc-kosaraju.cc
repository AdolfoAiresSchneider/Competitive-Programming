#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define maxn 100000

vi g[maxn], rg[maxn], q;
int vis[maxn], id_scc[maxn];

void dfs(int u, vector<int> * g, bool cnt)
{
  vis[u] = 1;
  for(auto v : g[u])
  {
    if(vis[v])
      continue;
    dfs(v, g, cnt);
  }
  if(cnt == 0) q.push_back(u);
  else id_scc[u] = cnt;
}

int main()
{
  int n, m;
  cin>>n>>m;
  
  while(m--)
  {
    int a, b;
    cin>>a>>b;
    
    g[a].push_back(b);
    rg[b].push_back(a);
  }
  // roda o dfs na ordem dada
  for(int u = 0; u < n; u++)
    if(!vis[u]) dfs(u, g, 0);
  
  int cnt = 1;
  
  memset(vis, 0, sizeof vis);
  // roda o dfs na ordem reversa
  for(int i = n-1; i >= 0; i--)
    if(vis[i]) dfs(i, rg, cnt++);
}
