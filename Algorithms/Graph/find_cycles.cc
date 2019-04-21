#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define maxn 100000

vi g[maxn];
int pai[maxn], vis[maxn];

void find_cycle(int u)
{
  vis[u] = 1;
  for(auto v : g[u])
  {
    if(v == pai[v]) // para grafos bidirecionais
      continue;
      
    if(vis[u] == 0)  
    {
      pai[v] = u;
      find_cycle(v);
      continue;
    }
    
    if(vis[v] == 1)
    {
      int x = u;
      
      while(x != v)
      {
        cout<<x<<'-'; // imprimir o ciclo
        x = pai[x];
      }
      cout<<v<<endl;
    }
  }

  vis[u] = 2; // apenas para grafos direcionados
}

int main()
{
  
}
