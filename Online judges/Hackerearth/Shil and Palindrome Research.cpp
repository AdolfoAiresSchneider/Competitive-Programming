#include <bits/stdc++.h>
using namespace std;

#define maxn 200009
#define endl '\n'
#define sz(x) (int)s.size()

int n, q, bit[26][maxn];
string s;

void update(int l, int idx, int x){
	for(; idx <= n; idx += (idx&-idx)){
		bit[l][idx] += x;
	}
}

int query(int l, int idx){
	int sum = 0;
	for(; idx > 0 ; idx -= (idx&-idx)){
		sum += bit[l][idx];
	}
	return sum;
}

int range(int l, int i, int j){
	return query(l, j) - query(l, i-1);
}

void build(){
	for(int i = 1; i <= sz(s); i++){
		int l = s[i-1]-'a';
		update(l, i, 1);
	}
}

bool f(int l, int r){
	int par = 0, imp = 0;
	for(int i = 0; i < 26; i++){
		int qtd = range(i, l, r);
		if(qtd%2) imp++;
		else par++;
	}
	
	return imp <= 1;
}

int main(){
	
	//~ freopen("in", "r", stdin);
	cin.sync_with_stdio(0), cin.tie(0);
	cin>>n>>q>>s;
	
	build();
	
	while(q--){
		int op, l;
		cin>>op>>l;
		if(op == 1){
			char c;
			cin>>c;
			update(s[l-1]-'a', l, -1);
			s[l-1] = c;
			update(c-'a', l, 1);
		}
		else{
			int r;
			cin>>r;
			if(f(l,r)) cout<<"yes"<<endl;
			else cout<<"no"<<endl;
		}
	}
}

