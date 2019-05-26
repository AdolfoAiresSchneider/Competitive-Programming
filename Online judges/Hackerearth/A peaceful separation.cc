#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> ii;
#define pb push_back

#define maxn 100008
#define mod 1000000007
#define inf 1e18
#define endl '\n'
#define nd second
#define st first
#define all(x) x.begin(), x.end()

struct edge{
  int u, v, cost;
  bool operator < (const edge & other) const{
    return this-> cost < other.cost;
  }
  edge(int a, int b, int c) : u(a), v(b), cost(c){}
};

ii operator +(ii a, ii b){
  return {a.st + b.st, a.nd + b.nd};
}

ii operator -(ii a, ii b){
  return {a.st - b.st, a.nd - b.nd};
}

vector<ii> g[maxn], tree[maxn];
vector<edge> K[maxn];
stack<int> stk;
ii vert_cost[maxn], tot;
int vis[maxn], low[maxn], h[maxn], cnt = 1, comp = 1, mark[maxn], n, m, pai[maxn];

void scc(int u, int p, int d){
  h[u] = low[u] = d;
  vis[u] = 1, stk.push(u);
  for(ii ed : g[u]){
    int v = ed.st;
    if(v == p) continue;
    if(vis[v] == 0){
      scc(v, u, d+1);
      low[u] = min(low[u], low[v]);
    }else low[u] = min(low[u], h[v]);
  }
  if(h[u] == low[u]){
    while(1){
      ll v = stk.top(); stk.pop();
      mark[v] = comp;
      if(u == v) break;
    } comp++;
  }
}

int find(int u){
  if(u == pai[u]) return u;
  return pai[u] = find(pai[u]);
}

void init(){
  for(int i = 0; i <= n; i++)
    pai[i] = i;
}

ii mst(vector<edge> & arr){
  
  ii ans = {0,0};
  for(auto x : arr){
    ll pu = find(x.u), pv = find(x.v);
    if(pu == pv) continue; 
    pai[pu] = pv;
    ans.st += x.cost;
  }
  
  for(auto x : arr) pai[x.u] = x.u, pai[x.v] = x.v;
  reverse(all(arr));
  
  for(auto x : arr){
    ll pu = find(x.u), pv = find(x.v);
    if(pu == pv) continue; 
    pai[pu] = pv;
    ans.nd += x.cost;
  }
  return ans;
}

void compress(){
  init();
  for(int u = 1; u <= n; u++){
    for(ii x : g[u]){
      int v = x.st, cost = x.nd;
      if(mark[u] == mark[v]){
         K[mark[u]].pb({u,v, cost});
      }else{
        tree[mark[u]].pb({mark[v], cost});
        tot = tot + ii(cost,cost);
      }
    }
  }
  ll szz = 0;
  tot.st /= 2ll, tot.nd /= 2ll;
  for(int i = 1; i < comp; i++){
    sort(all(K[i]));
    vert_cost[i] = mst(K[i]);
    szz += K[i].size();
    tot = tot + vert_cost[i];
  }
}

ll ans = inf;
ii dfs(int u, int p){
  ii aux = ii(0,0);
  for(ii x : tree[u]){
    int v = x.st, cost = x.nd;
    if(v == p) continue;
    ii B = dfs(v, u);
    ii A = tot - B - ii(cost,cost);
    ans = min(ans, abs(A.st - B.nd));
    ans = min(ans, abs(A.nd - B.st));
    aux = aux + B + ii(cost, cost);
  }
  return aux + vert_cost[u];
}

int main(){
  
  //~ freopen("in", "r", stdin);
  cin.sync_with_stdio(0), cin.tie(0);
  
  cin>>n>>m;
  while(m--){
    int u, v, c;
    cin>>u>>v>>c;
    g[u].pb({v,c});
    g[v].pb({u,c});
  }
  scc(1, 1, 0); // find all BCC(biconected components)
  compress(); // compress the graph into a tree
  dfs(1,1); // calc the answer
  
  if(comp == 1 || ans == (ll)inf){
    ans = -1;
  }
  
  cout<<ans<<endl;
}
