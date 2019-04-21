#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
#define maxn 10009 
#define st first
#define nd second
#define pb push_back

vector<ii> g[maxn];
int p[maxn];

int main(){
  //~ freopen("in", "r", stdin);
  int n, m, k;
  cin>>n>>m>>k;
  for(int i = 1; i <= n; i++){
    cin>>p[i];
  }
  
  while(m--){
    int u, v;
    cin>>u>>v;
    g[u].pb({p[v], v});
    g[v].pb({p[u], u});
  }
  
  for(int i = 1; i <= n; i++){
    sort(g[i].rbegin(), g[i].rend());
    if((int)g[i].size() < k) cout<<-1<<endl;
    else  cout<<g[i][k-1].nd<<endl;
  }
  
  
}

