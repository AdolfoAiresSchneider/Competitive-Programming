#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define pb push_back
#define st first
#define nd second 
#define inf 0x3f3f3f3f
#define maxn 100001
#define maxLog 21
#define endl '\n'

vii g[maxn];
int l[maxn], p[maxn][maxLog], w[maxn][maxLog], n , k, q;
ii poke[maxn];


void dfs(int u, int pai)
{
  l[u] = l[pai] + 1;
  p[u][0] = pai;
  
  for(auto v : g[u])
  {
    if(v.st == pai)
      continue;
      
    w[v.st][0] = v.nd;
    dfs(v.st, u);
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
      w[u][i] = max(w[u][i-1], w[x][i-1]);
    }
  }
}

// Calcula o lca e a maior aresta no caminho entre U e V.
ii lca(int u, int v)
{
  if(l[u] < l[v])
    swap(u, v);
  
  int dif = l[u] - l[v], cost = -1, lg = log2(l[u]);
  
  for(int i = lg; i >= 0; i--)
  {
    if(!((1 << i) & dif)) 
      continue;
    cost = max(cost,  w[u][i]);
    u = p[u][i];
  }
  
  if(u == v) 
    return ii(u, cost);
    
  for(int i = lg; i >= 0; i--)
  {
    if(p[u][i] == p[v][i])
      continue;
    cost = max(cost, max(w[u][i], w[v][i]));
    u = p[u][i], v = p[v][i];
  }
  return ii(p[u][0], max(cost, max(w[u][0], w[v][0])));  
}

void init_lca()
{
  memset(w, -1, sizeof w);
  l[1] = 0;
  memset(p, 0, sizeof p);
}

int dist(int u, int v)
{
  int anc = lca(u ,v).st;
  return l[u] + l[v] - 2*l[anc];
}

// It is possible to sum a value in all edges/vertices between two vertices,
// using this 
/*    
 *    val[b] += c;
      val[a] += c;
      val[lca(a, b)] -= c;
      if (lca(a, b))
        val[pr[lca(a, b)][0]] -= c;
        
*/// After that do a dfs to calculate the sum and you will have the value of each v!!

int main()
{
  
}
