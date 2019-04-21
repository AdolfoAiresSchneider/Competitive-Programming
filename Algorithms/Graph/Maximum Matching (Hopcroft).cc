#include<bits/stdc++.h>
using namespace std;

#define maxn 100001
#define NIL 0
#define INF (1<<28)

vector< int > G[maxn];
int n, m, match[maxn], dist[maxn];

// n: number of nodes on left side, nodes are numbered 1 to n
// m: number of nodes on right side, nodes are numbered n+1 to n+m
// G = NIL[0] ∪ G1[G[1---n]] ∪ G2[G[n+1---n+m]]

bool bfs() 
{
    queue< int > Q;
    
    for(int i = 1; i <= n; i++) 
    {
      if(match[i] == 0) 
        dist[i] = 0, Q.push(i);
      else dist[i] = INF;
    }
    
    dist[0] = INF;
    while(!Q.empty())
    {
      int u = Q.front(); Q.pop();
      
      if(u != 0){
        for(auto v: G[u])
          if(dist[match[v]]==INF)
            dist[match[v]] = dist[u] + 1, Q.push(match[v]);
      }
      
    }
    return (dist[NIL]!=INF);
}

bool dfs(int u) 
{
  if(u == 0)
    return true;
  
  for(auto v : G[u])
  {
    if(dist[match[v]] == dist[u]+1)
    {
      if(dfs(match[v]))
      {
        match[v] = u, match[u] = v;
        return true;
      }
    }
  }
  dist[u] = INF;
  return false;
}

int hopcroft_karp()// sqrt(V)*E
{
    memset(match, 0, sizeof match);
    int matching = 0;
    while(bfs())
    {
      for(int i = 1; i <= n; i++)
        if(match[i] == 0 && dfs(i))
            matching++;
    }
    return matching;
}

int main()
{
}
  
