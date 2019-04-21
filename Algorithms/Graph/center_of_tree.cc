#include <bits/stdc++.h>
using namespace std;

#define maxn 100002
#define inf 0x3f3f3f3f
typedef pair<int,int> ii;
typedef vector<int> vi;

vi g[maxn];
int deg[maxn], l[maxn];

vector<int> tree_center(int n)
{
  vi c;
  queue<int> q;
  int maxlevel = -inf;
  
  for(int i = 1; i <= n; i++)
    if(!deg[i]) q.push(i);
  
  while(!q.empty())
  {
    int u = q.front(); q.pop();
    maxlevel = max(maxlevel, l[u]);
    for(auto v : g[u])
      if(--deg[v] == 1)
        q.push(v),l[v] = l[u]+1;
  }
  
  for(int i = 1; i <= n ; i++)
    if(l[i] == maxlevel)
      c.push_back(i);
      
  return c;
}


int main()
{
  
}
