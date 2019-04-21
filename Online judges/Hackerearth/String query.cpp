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

void build(){
	for(int i = 1; i <= sz(s); i++){
		int l = s[i-1]-'a';
		update(l, i, 1);
	}
}

int main(){
	
	cin.sync_with_stdio(0), cin.tie(0);
	cin>>s>>q;
	n = sz(s);
	
	build();
	
	while(q--){
		int k; char l;
		cin>>k>>l;
		int i = 1, j = n;
		while(i < j){
			int mid = (i+j)/2;
			if(query(l-'a', mid) >= k) j = mid;
			else i = mid+1;
		}
		update(l - 'a', i, -1);
		s[i-1] = '#';
	}
	
	for(char c : s){
		if(c == '#') continue;
		cout<<c;
	}
	cout<<endl;
}

