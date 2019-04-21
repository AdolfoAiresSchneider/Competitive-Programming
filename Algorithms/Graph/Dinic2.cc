#include<bits/stdc++.h>
using namespace std;


#define pb push_back
typedef long long ll;
// V^2*E
struct dinic_mf {

  struct edge {
    int a, b, cap, flow;
    edge(int a,int b,int cap,int flow):a(a),b(b),cap(cap),flow(flow){}
  };

  int INF = 1500000001 ;

  int n , source , sink ,d[20001] ,ptr[20001] ,q[20001*10];

  vector <edge> e;
  vector <int> g[20001];

  void add_edge ( int a, int b, int cap ) {
    edge e1 = edge(a,b,cap,0);
    edge e2 = edge(b,a,0,0);
    g[a].push_back(e.size()), e.push_back(e1);
    g[b].push_back(e.size()), e.push_back(e2);
  }

  bool bfs () {
    int qh = 0 , qt = 0; // qt é o final da fila, qh e o inicio
    q [qt++] = source;
    memset( d, -1 , sizeof d );
    d[source] = 0 ;
    while ( qh < qt  && d[sink] == -1 ) {

      int v = q[qh++];

      for(int i = 0 ; i < (int)g[v].size() ; ++i ) {

          int id = g [v][i] ;
          int to = e [id].b ;

          if (d[to] == -1 && (e[id].flow < e[id].cap )){
            q[qt++] = to;
            d[to] = d [ v ] + 1 ;
          }

      }
    }
    return d[sink] != - 1 ;
  }


  int dfs ( int u, int garg ) {
    if (!garg)  return 0 ;
    if (u == sink)  return garg;

    for ( ; ptr[u] < (int) g[u].size() ; ++ptr[u] ) {
      int id = g [u][ptr[u]] , to = e[id].b;

      if ( d[to] != d[u] + 1 ) continue;

      if (int f = dfs(to, min(garg, e[id].cap - e[id].flow ))){
        e[id].flow += f ;
        e[id^1].flow -= f;
        return f;
      }
    }
    return 0;
  }

  ll dinic(){
    ll mf = 0 ;

    while( bfs () ){
      memset(ptr,0,sizeof ptr ) ;
      while (int f = dfs(source,INF) ) mf += f ;
    }
    return mf ;
  }

  dinic_mf( int n, int source, int sink) : n(n),source(source),sink(sink) {}
};


int main() {
  freopen("in","r",stdin);
  // cin.sync_with_stdio(0),cin.tie(0);
  int n,m;
  cin>>n>>m;

  dinic_mf D(n+2,1,n);
  for(int i = 0 ; i < m ; ++i){
    int a,b,cap;
    cin>>a>>b>>cap;
    D.add_edge(a,b,cap);
  }

  cout << D.dinic() << endl;

  for(int i = 0 ; i < (int)D.e.size() ; i+=2){
    cout << D.e[i].flow << '\n';
  } cout << '\n';

  return 0;
}


