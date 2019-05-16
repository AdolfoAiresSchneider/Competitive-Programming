#include <bits/stdc++.h>
using namespace std;

#define maxn 200009
#define pb push_back

unordered_map<string, int> dic;
vector<int> g[maxn];
int vis[maxn], ans;

int get_id(string & str){
  if(dic.count(str)) return dic[str];
  return dic[str] = dic.size();
}

void dfs(int u){
  vis[u] = 1;
  for(int v : g[u]){
    if(vis[v] == 2) continue;
    if(vis[v] == 0) dfs(v);
    else ans++;
  }
  vis[u] = 2;
}

int main(){
  //~ freopen("in", "r", stdin);
  cin.sync_with_stdio(0), cin.tie(0);
  string u, v;
  
  while(cin>>u>>v){
    g[get_id(u)].pb(get_id(v));
  }
  
  int n = dic.size();
  for(int i = 0; i < n; i++){
    if(!vis[i]) dfs(i);
  }
  
  cout<<ans<<endl;
}
