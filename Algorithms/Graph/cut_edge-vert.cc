#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define maxn 100000

vi g[maxn];
int h[maxn], b[maxn], vis[maxn];

void bridge(int u, int pai, int root)
{
  h[u] = b[u] = h[pai] + 1;
  vis[u] = 1;
  
  for(auto v : g[u])
  {
    if(vis[v] == 0)
    {
      bridge(v, u, root);
      b[u] = min(b[u], b[v]);
      
      // Bridge
      if(b[v] > h[u]) {}
      
      // Articulation vertice
      if(b[v] >= h[u] && (v != root || g[u].size() > 1)) {}
        
      continue;
    }
    
    if(v != pai)
      b[u] = min(h[v], b[u]);  
  }
  vis[u] = 2;
}

int main()
{
  
}
