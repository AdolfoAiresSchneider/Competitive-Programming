#include <bits/stdc++.h>
using namespace std;

#define maxn 602
#define pb push_back
#define sz(x) (int)x.size()
#define endl '\n'

int n, vt[maxn][maxn], up[maxn][maxn], qtd, vis[361000];
vector<int> g[361000];

void init(int n){
  
  for(int i = 0; i <= qtd; i++) g[i].clear();
  memset(vt, -1, sizeof vt);
  memset(vis, 0, sizeof vis);
  memset(up, -1, sizeof up);
  qtd = 0;
  for(int i = 0; i < 2*n; i++){
    for(int j = 0; j < 2*n+1; j++){
      vt[i][j] = qtd++;
    }
  }
}

void add(int i1, int j1, int i2, int j2){
  int x = vt[i1][j1], y = vt[i2][j2];
  if(x == -1 || -1 == y) return;
  g[x].pb(y), g[y].pb(x);
}

void dfs(int u){
  vis[u] = 1;
  for(int v : g[u]){
    if(vis[v]) continue;
    dfs(v);
  }
}

int main(){
  //~ freopen("in", "r", stdin);
  cin.sync_with_stdio(0), cin.tie(0);
  string str;
 
  while(cin>>n){
    init(n);
    for(int i = 1; i <= 2*n-1; i++){
      cin>>str;
      for(int j = 0; j < sz(str); j++){
        if(i % 2) up[i][2*(j+1)-1] = (str[j] == 'V' ? 0 : 1);
        else up[i][2*(j+1)] = (str[j] == 'V' ? 0 : 1);
      }
    }
    
    // 0 = V, 1 = H
    for(int i = 0; i < 2*n; i++){
      for(int j = 0; j < 2*n+1; j++){
        if((i%2 && j%2) || (!(i%2) && !(j%2))){
          if(up[i+1][j+1] == -1){
            add(i, j, i+1, j), add(i, j, i, j+1);
          }else if(up[i+1][j+1] == 1){
             add(i, j, i, j+1);// Rigth down
           }
          else add(i, j, i+1, j); // Top left
        }else{
          if(up[i+1][j] != 1) add(i, j, i+1, j);
          if(up[i][j+1] != 0) add(i, j, i, j+1);
        }
      }
    }
    
    int cnt = 0;
    for(int i = 0; i < qtd; i++){
      if(vis[i]) continue;
      dfs(i), cnt++;
    }
    cout<<cnt-1<<endl;
  }
}
