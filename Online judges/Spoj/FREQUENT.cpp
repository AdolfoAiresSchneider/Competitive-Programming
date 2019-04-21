#include <bits/stdc++.h>
using namespace std;
 
#define maxn 100010
#define st first
#define nd second 
#define L (k << 1)
#define R (L + 1)
#define M ((l + r) >> 1)
 
typedef pair<int,int> ii;
typedef pair<int,ii> tri;
 
int n, q, u[maxn], st[4 * maxn];
tri v[maxn];
 
int build(int k = 1, int l = 1, int r = n){
	if(l == r) return st[k] = v[l].st;
	return st[k] = max(build(L, l, M), build(R, M+1, r));
}
 
int qry(int i, int j, int k = 1, int l = 1, int r = n){
	if(r < i || j < l) return 0;
	if(i <= l && r <= j) return st[k];
	return max(qry(i, j, L, l, M), qry(i, j, R, M+1, r));
}
 
int query(int i, int j){
	if(i > j) return 0;
	return qry(i, j);
}
 
int main(){
	//~ freopen("kin","r",stdin);
	cin.sync_with_stdio(0), cin.tie(0);
	while(cin >> n >> q && n){
		for(int i = 1; i <= n; ++i) cin >> u[i];
		for(int i = 1, j; i <= n; i = j){
			for(j = i + 1; j <= n && u[i] == u[j]; ++j){
			}
			tri t = tri(j - i, ii(i, j - 1));
			for(int k = i; k < j; ++k){
				v[k] = t;
			}
		}
		//~ cerr << "ok\n";
		build();
		while(q--){
			int i, j;
			cin >> i >> j;
			if(u[i] == u[j]){
				cout << j - i + 1 << '\n';
			}
			else{
				cout << max(max(v[i].nd.nd - i + 1, j - v[j].nd.st + 1), qry(v[i].nd.nd + 1, v[j].nd.st - 1)) << '\n';
			}
		}
		//~ cerr << '\n';
	}
	
	return 0;
}
