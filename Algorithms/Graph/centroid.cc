#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define nd second
#define st first
#define maxn 100004
#define endl '\n'
#define inf 1e9

typedef vector<int> vi;
//

/*
 * Depth at most log2(n)
 * A path u-v can be cut into u-z-v where z is the lca of (u,v) in the centroid_tree
 * */

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

int main()
{
  //~ freopen("in","r", stdin);
   
  cin.sync_with_stdio(0), cin.tie(0);
	cin>>n>>m;
  for(int i = 0; i < n-1; i++){
    int u, v;
    cin>>u>>v;
    g[u].pb(v), g[v].pb(u);
  }
  int root = centroid_tree(1);
}
