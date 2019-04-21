#include <bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define nd second
#define st first
#define maxn 100009
#define endl '\n'
#define inf 1e9
 
typedef vector<int> vi;
typedef pair<int,int> ii;
 
vi g[maxn], tree[maxn];
int sub_tree[maxn], n, is_centroid[maxn], m;
 
void dfs(int u, int p, int & tot){
  sub_tree[u] = 1;
  tot++;
  for(auto v : g[u]){
    if(v == p || is_centroid[v]) continue;
    dfs(v, u, tot);
    sub_tree[u] += sub_tree[v]; 
  }
}

int centroid(int u, int tot, int p){ 
  for(auto v : g[u]){
    if(is_centroid[v] || v == p) continue;
    if(sub_tree[v] > tot/2){
      return centroid(v, tot, u);
    }
  }
  return u;
}

int centroid_tree(int u){
  int tot = 0;
  dfs(u, u, tot);
  int root = centroid(u, tot, u);
  is_centroid[root] = 1;
  
  for(auto v : g[root]){
    if(is_centroid[v]) continue;
    int sub_root = centroid_tree(v);
    tree[root].pb(sub_root);
    tree[sub_root].pb(root);
  }
  g[root].clear();
  return root;
}
 
int p[maxn];
void dfs2(int u, int pai, int d){
  p[u] = pai;
  for(auto v : tree[u]){
    if(v == pai) continue;
    dfs2(v, u, d+1);
  }
}
 
int h[maxn],p2[maxn][30];
void dfs_lca(int u, int pai, int d){
  h[u] = d, p2[u][0] = pai;
  for(auto v : g[u]){
    if(v == pai) continue;
    dfs_lca(v, u, d+1);
  }
}
 
void process(){
  int lg = log2(n);
  for(int i = 1; i <= lg; i++){
    for(int u = 1; u <= n; u++){
      int x = p2[u][i-1];
      p2[u][i] = p2[x][i-1];
    }
  }
}
 
int lca(int u, int v)
{
  if(h[v] > h[u]) swap(u, v);
  int diff = h[u] - h[v];
  for(int i = log2(n); i >= 0; i--){
    if((1<<i) & diff)
      u = p2[u][i];
  }
  
  
  if(u == v) return u;
  
  for(int i = log2(n); i >= 0; i--){
    if(p2[u][i] != p2[v][i])
      u = p2[u][i], v = p2[v][i];
  }
  
  return p2[u][0];
}
 
int dist(int u, int v){
  return h[u] + h[v] - 2*h[lca(u,v)];
}

set<ii> ans[maxn];
int color[maxn];
 
int query(int u){
  if(color[u] == 0) return 0;
  int aux = inf, x = u;
  while(1){
    int cur = inf;
    if(ans[x].size()) cur = (*ans[x].begin()).st;
    aux = min(aux, dist(u,x)+cur);
    if(x == p[x]) break;
    x = p[x];
  }
  return aux;
}
 
int cnt = 0;
void upd1(int u){
  cnt ++;
  color[u] ^= 1;
  int x = u;
  while(1){
    ans[x].insert(ii(dist(u, x), u));
    //~ cout<<" >f> "<<u<<' '<<x<<' '<<dist(u, x)<<' '<<ans[x].size()<<endl;
    if(x == p[x]) break;
    x = p[x];
  }
  //~ cout<<" @@@ "<<query(3)<<endl;
  
  //~ cout<<endl;
}
 
void upd2(int u){
  cnt--;
  color[u] ^= 1;
  int x = u;
  while(1){
    ans[x].erase(ii(dist(u, x), u));
    //~ cout<<" >s> "<<u<<' '<<x<<' '<<dist(u, x)<<endl;
    if(x == p[x]) break;
    x = p[x];
    
  }
  //~ cout<<endl;
}
 
 
int main()
{
  //~ freopen("in","r", stdin);
   
  cin.sync_with_stdio(0), cin.tie(0);
  cin>>n;
  for(int i = 0; i < n-1; i++){
    int u, v;
    cin>>u>>v;
    g[u].pb(v), g[v].pb(u);
  }
  
  dfs_lca(1,1,0);
  process();
  int root = centroid_tree(1);
  dfs2(root, root, 0);
  
  for(int i = 0; i <= n; i++)
    color[i] = 1;
    
  cin>>m;
  while(m--){
    int t, u;
    cin>>t>>u;
    if(t == 0){
      if(color[u] == 1) upd1(u);
      else upd2(u);
    }
    else{
      if(cnt) cout<<query(u)<<endl;
      else cout<<-1<<endl;
    }
  }
}
