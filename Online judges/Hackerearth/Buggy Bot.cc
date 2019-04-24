#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define maxn 1000009
int n, m, k, U[maxn], V[maxn], pos[maxn], end_at[maxn];

set<int> ans;
vector<int> g[maxn], aux[maxn];

int main() {
   //~ freopen("in", "r", stdin);
   
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0, a, b; i < m; i++) {
		scanf("%d%d", &a, &b);
		g[a].pb(b);
	}
  
	for (int i = 0; i < k; i++) {
		scanf("%d%d", U+i, V+i);
	}
  
	pos[0] = 1;
	int cp = 1;
	for (int i = 0; i < k; i++) {
		if (cp == U[i]) cp = V[i];
		pos[i+1] = cp;
	}
  
	for (int i = 1; i <= n; i++) {
		end_at[i] = i;
	}
  
	ans.insert(pos[k]);
	for (int i = k-1; i >= -1; i--) {
		int cur = pos[i+1];
		for (int j : g[cur]) {
			ans.insert(end_at[j]);
      aux[j].pb(cur);
		}
    g[cur].clear();
    
		if (i >= 0){
      end_at[U[i]] = end_at[V[i]];
      for(int x : aux[U[i]]){
        // se alguma dessas arestas leva à esse vertice , cuja a resposta já está calculada!!
        g[x].pb(U[i]);
      }
    }
    aux[U[i]].clear();
	}
	
  printf("%d\n", (int)ans.size());
  for(int x : ans){
		printf("%d ", x);
	}
}
