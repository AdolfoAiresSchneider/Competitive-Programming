#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define maxn 100009
#define endl '\n'
#define pb push_back

vector<int> g[maxn];
ll deg[maxn], l[maxn], r[maxn], bit[maxn], cnt = 1, n, q;

void dfs(int u){
	l[u] = cnt;
	for(auto v : g[u]){
		cnt++;
		dfs(v);
	}
	r[u] = cnt;
}

void update(int idx, int x){
	for(; idx <= n; idx += (idx&-idx)){
		bit[idx] += x;
	}
}

ll query(int idx){
	ll sum = 0;
	for(; idx > 0; idx -= (idx&-idx)){
		sum += bit[idx];
	}
	return sum;
}

ll range(int l, int r){
	return query(r) - query(l-1);
}

int main(){
	
	cin.sync_with_stdio(0), cin.tie();
	//~ freopen("in", "r", stdin);
	cin>>n>>q;
	
	for(int i = 0;i < n-1; i++){
		int u, v;
		cin>>u>>v;
		
		g[u].pb(v);
		deg[v]++;
	}
	
	for(int i =1 ; i <= n; i++){
		if(deg[i] == 0) {
		    dfs(i);
		   // break;
		}
	}
	
	for(int i = 1; i <= n; i++){
		int x;
		cin>>x;
		update(l[i], x);
	}
	
	while(q--){
		int op, x, y;
		cin>>op;
		if(op == 2){
			cin>>x;
			cout<<range(l[x], r[x])<<endl;
		}else{
			cin>>x>>y;
			update(l[x], y-range(l[x], l[x]));
		}
	}
}

