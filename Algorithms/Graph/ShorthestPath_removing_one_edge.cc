#include <bits/stdc++.h>
using namespace std;

#define maxn 100009
#define pb push_back
#define nd second
#define st first
#define inf 0x3f3f3f3f
#define endl '\n'

typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef long long ll;

vii G[maxn];
int d1[maxn], d2[maxn];
int n, m, s, t;
// Find the shorthest path removing just one edge!!
void djk(int s, int t, int * dist)
{
  priority_queue<ii, vector<ii>, greater<ii> > pq;
  dist[s] = 0; pq.push(ii(0, s));
  while(!pq.empty())
  {
    int u = pq.top().nd;
    int d = pq.top().st; pq.pop();
    
    if(d > dist[u])
      continue;
    
    for(auto v : G[u])
    {
      if(d + v.nd < dist[v.st])
      {
       dist[v.st] = d + v.nd;
       pq.push(ii(d + v.nd, v.st));
      }
    }
  }
}

int h[maxn], b[maxn], vis[maxn];
bool is_path[maxn];
bool cut_edge(int u, int p, int lim, int d)
{
  h[u] = b[u] = d;
  vis[u] = 1;
  
  if(u == t)
    is_path[u] = true;
  
  for(auto v : G[u])
  {
    if(v.st == p || (d1[u] + v.nd + d2[v.st] > lim && d1[v.st] + v.nd + d2[u] > lim))
      continue;
      
      if(vis[v.st] == 0)
      {
        if(cut_edge(v.st, u, lim, d+1))
          return true;
          
        b[u] = min(b[u], b[v.st]);
        
        if(b[v.st] > h[u] && is_path[v.st])
          return true;
        
        is_path[u] |= is_path[v.st];
             
        continue;
      }
      
      b[u] = min(b[u], h[v.st]);
  }
  return false;
}

int main()
{
  //~ freopen("in", "r", stdin);
  scanf("%d%d%d%d",&n, &m, &s, &t);
  
  int a, b, c;
  while(m--)
  {
    scanf("%d%d%d",&a,&b,&c);
    G[a].pb(ii(b,c));
    G[b].pb(ii(a,c));
  }
  
  memset(d1, inf, sizeof d1);
  memset(d2, inf, sizeof d2);
  
  djk(s, t, d1);
  djk(t, s, d2);
  
  ll l = 0, r = inf;
  while(l < r)
  {
    ll mid = (l+r)/2;
    
    memset(vis,0,sizeof vis), memset(is_path, 0, sizeof is_path);
    
    if(cut_edge(s, -1, d1[t] + mid, 0)) l = mid+1;
    else r = mid;
  }
  
  printf("%lld\n",l >= inf ? -1 : l+d1[t]);
}
