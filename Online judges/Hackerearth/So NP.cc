#include<bits/stdc++.h>
using namespace std;

#define maxn 100002
int p[maxn], sz[maxn];

int find(int u){
	if(u == p[u]) return u;
	return p[u] = find (p[u]);
}

void merge(int u, int v){
	int pu = find(u);
	int pv = find(v);
	if(pu != pv){
		p[pu] = pv;
		sz[pv] += sz[pu];
	}else{
		sz[pu]++;
	}
}

set<int> v;

int main(){
	
	cin.sync_with_stdio(0), cin.tie(0);
	int n, m, k;
	cin>>n>>m>>k;
	
	for(int i = 0; i <= n; i++) p[i] = i;
	
	while(m--){
		int u, v;
		cin>>u>>v;
		merge(u, v);
	}
	
	for(int i = 1; i <= n; i++){
		v.insert(find(i));
	}
	
	if(v.size() > k) {
		cout<<-1<<endl;
		return 0;
	}
	
	int ans = 0;
	for(int x : v){
		ans += sz[x];
	}
	
	cout<<ans+(k-v.size())<<'\n';
	
}
