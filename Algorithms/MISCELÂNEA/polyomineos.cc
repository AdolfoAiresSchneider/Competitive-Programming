#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;

#define maxn 60
#define st first
#define nd second

typedef unsigned long long ull;


int g[maxn][maxn];
int mx[] = {0, 1, 0, -1};
int my[] = {1, 0, -1, 0}, n, m;

vector< set<ii> > polyominoes;
set< ull > dp;

ii operator - (ii a, ii b)
{
  return ii(a.st - b.st, a.nd - b.nd);
}

ull id(set<ii> & p)
{
  ull hash = 0;
  for(auto v : p) 
    hash = hash*31ull + 39ull*v.st + v.nd;
  return hash;
}


// Gerar todos os polyomineos de tamanho m
void f(set<ii> p)
{   
  ii aux = * p.begin();
  
  set<ii> p2;
  
  if(aux.first < 0 || aux.second < 0)
  {  
    for(auto u : p) 
      p2.insert(u-aux);
  }
  else p2 = p;
      
  p = p2;
      
  if(dp.find(id(p)) != dp.end())
    return;
  
  dp.insert(id(p));
  
  if((int)p.size() == m)
  {
    polyominoes.push_back(p);
    return;
  }
  
  set<ii> new_p = p;
  
  for(auto v : p)
  {
    for(int i = 0; i < 4; i++)
    {
      int nx = v.st + mx[i], ny = v.nd + my[i];
      
      if(new_p.find(ii(nx , ny)) != new_p.end())
        continue;
        
      new_p.insert(ii(nx, ny));
      f(new_p);
      new_p.erase(ii(nx, ny));
    }
  }
}

int f2(set<ii> & v , int i, int j)
{
  int sum = 0;
  for(auto t : v)
  {
    if(t.st + i < 0 || t.st + i >= n || t.nd+j < 0 || t.nd+j >= n)
      return -1;
    sum += g[t.st + i][t.nd + j];
  }
  
  return sum;
}

int main()
{
  //~ freopen("in", "r", stdin);
  cin>>n>>m;
  
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
      cin>>g[i][j];
  
  f({ii(0,0)});
  
  int ans = -1e9;
  for(auto & v : polyominoes)
  {
    for(int i = 0; i < n; i++){
      for(int j = 0; j < n; j++){
        ans = max(ans, f2(v, i, j));
      }
    }
  }
  cout<<ans<<endl;
}
