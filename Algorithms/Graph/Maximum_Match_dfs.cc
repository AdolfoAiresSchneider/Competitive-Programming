#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define maxn 10000


vi g[maxn];
int vis[maxn], match[maxn];

bool dfs(int u)
{
  if(vis[u]) 
    return false;
    
  vis[u] = true;
  
  for(auto v : g[u])
  {
    if(match[v] == -1 || dfs(match[v]))
    {
      match[v] = u;
      return true;
    }
  }
  return false;
}


int main()
{
  int ans = 0, n = maxn;
  
  for(int i = 1; i <= n; i++) 
  {
    memset(vis, 0, sizeof vis);
    ans += dfs(i);
  }
}
