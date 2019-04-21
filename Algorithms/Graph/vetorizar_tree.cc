#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define maxn 100000

vi g[maxn];

vi euler;
int l[maxn], r[maxn], cnt= 0;
// Vetorização de arvore !!
void dfs(int u, int pai)
{
  l[u] = cnt;
  euler.push_back(u);
  
  for(auto v : g[u])
  {
    if(v == pai)
      continue;
      
    cnt++;
    dfs(v, u);
  }
  
  euler.push_back(u); // depende do que vc quer
  r[u] = cnt;
}

int main()
{
}
