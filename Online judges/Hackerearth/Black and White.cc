#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
typedef pair<int,ii> iii;

#define pb push_back
#define nd second
#define st first
#define maxn 1009
#define iii(a, b, c) iii(a, ii(b,c))

int isW[maxn], dist[maxn][maxn*3], n, m;
vector<ii> g[maxn];

int dkj(int s){
  priority_queue<iii, vector<iii>, greater<iii> > pq;
  pq.push(iii(0, isW[s] ? 1 : -1, s));
  memset(dist, 0x3f, sizeof dist);
  dist[s][isW[s] ? 1 : -1+1000] = 0;
  
  while(pq.size()){
    int u = pq.top().nd.nd;
    int d = pq.top().st;
    int diff = pq.top().nd.st; pq.pop();
    if(dist[u][diff+1000] < d) continue;
    
    for(ii x : g[u]){
      int v = x.st, cost = x.nd;
      int nc = diff + (isW[v] ? 1 : -1);
      if(dist[v][nc+1000] > d+cost){
        pq.push(iii(d+cost, nc, v));
        dist[v][nc+1000] = d+cost;
      }
    }
  }
  
  int d = 1e9;
  d = min(d, dist[n][-1+1000]);
  d = min(d, dist[n][0+1000]);
  d = min(d, dist[n][1+1000]);
  if(d == (int)1e9) d = -1;
  return d;
}

int main(){
  cin.sync_with_stdio(0), cin.tie(0);
  //~ freopen("in", "r", stdin);
  
  cin>>n>>m;
  
  while(m--){
    int u, v, c;
    cin>>u>>v>>c;
    g[u].pb({v, c});    
  }
  
  for(int i = 1; i <= n; i++){
    cin>>isW[i];
  }
  
  cout<<dkj(1)<<endl;
}
