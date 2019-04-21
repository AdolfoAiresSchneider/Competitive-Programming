#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;

#define maxn 10009 
#define st first
#define nd second
#define pb push_back

vector<int> g[maxn];
int n, s;
vector<ii> ed;

ii dfs(int u, int d, int pai){
  ii ans(d, u);
  for(int v :g[u]){
    if(v == pai) continue;
    ans = max(ans, dfs(v, d+1, u));
  }
  return ans;
}

void init(){
  ed.clear();
  for(int i = 0; i <= n; i++){
    g[i].clear();
  }
}

int main(){
  
  cin.sync_with_stdio(0), cin.tie(0);
  //~ freopen("in", "r", stdin);
  
  int t;
  cin>>t;
  
  while(t--){
    init();
    cin>>n>>s;
    for(int i = 0; i < n-1; i++){
      int u, v;
      cin>>u>>v;
      g[u].pb(v), g[v].pb(u);
      ed.pb({u, v});
    }
    
    int cnt = 0;
    ii node = dfs(1, 0, -1);
    int diameter = dfs(node.nd, 0, -1).st;
    
    for(ii x : ed){
      int l = dfs(x.st, 0, x.nd).st;
      int r = dfs(x.nd, 0, x.st).st;
      if(l+r+1 == diameter) cnt++;
    }
    if(cnt == n-1) cout<<(int)ceil((double)s/(n-1))<<endl;
    else cout<<0<<endl;
  }
}
