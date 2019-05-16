#include<bits/stdc++.h>
using namespace std;

#define maxn 100009
#define pb push_back
#define st first
#define nd second

typedef long long ll;
typedef pair<int,int> ii;

int n, q, h[maxn];
vector<ii> g[maxn];
ii p[30][maxn];

void dfs_lca(int u, int d, int pai){
  h[u] = d;
  for(ii x : g[u]){
    int v = x.st, cost = x.nd;
    if(v == pai) continue;
    p[0][v] = ii(u, cost);
    dfs_lca(v, d+1, u);
  }
}

ii merge(ii a, ii b){
  return ii(b.st, max(a.nd, b.nd));
}

void process(){
  int lg = log2(n);
  for(int i = 1; i <= lg; i++){
    for(int u = 0; u < n; u++){
      ii x = p[i-1][u];
      ii y = p[i-1][x.st];
      p[i][u] = merge(x, y);
    }
  }
}

ii lca(int u, int v){
  
  if(h[v] < h[u]) swap(v, u);
    
  int diff = h[v] - h[u], mx = 0, lg = log2(h[  v]);
  
  for(int i = lg; i >= 0; i--){
    if((1<<i) & diff){
      mx = max(mx, p[i][v].nd);
      v = p[i][v].st;
    }
  }
  
  if(u == v) return ii(u, mx);
  
  for(int i = lg; i >= 0; i--){
    if(p[i][u].st != p[i][v].st){
      mx = max(mx, max(p[i][u].nd, p[i][v].nd));
      u = p[i][u].st, v = p[i][v].st;
    }
  }
  
  mx = max(mx, max(p[0][u].nd, p[0][v].nd));
  return ii(p[0][u].st, mx);
}

int main(){
  
  cin.sync_with_stdio(0), cin.tie(0);
  freopen("in", "r", stdin);
  cin>>n;
  
  ll sum = 0;
  for(int i = 0; i < n-1; i++){
    int u, v, c;
    cin>>u>>v>>c;
    u--, v--;
    g[u].pb({v,c}), g[v].pb({u,c});
    sum += c;
  }
  
  dfs_lca(0,0,0);
  process();
  
  int q;
  cin>>q;
  
  while(q--){
    int u, v, c;
    cin>>u>>v>>c;
    u--, v--;
    int mx = lca(u, v).nd;
    
    ll tree = sum - mx + c;
    if(tree < sum){
      cout<<"YES"<<endl;
      continue;
    }
    cout<<"NO"<<endl;
  }
  
}
