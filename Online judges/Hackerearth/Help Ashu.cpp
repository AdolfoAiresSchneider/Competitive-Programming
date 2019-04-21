#include <bits/stdc++.h>
using namespace std;
 
#define maxn 100009
#define endl '\n'
 
int n, q, bit[maxn];
 
void update(int idx, int x){
	for(; idx <= n; idx += (idx&-idx)){
		bit[idx] += x;
	}
}
 
int query(int idx){
	int sum = 0;
	for(; idx > 0 ; idx -= (idx&-idx)){
		sum += bit[idx];
	}
	return sum;
}
 
int range(int i, int j){
	return query(j) - query(i-1);
}
 
int main(){
	
	//~ freopen("in", "r", stdin);
	cin.sync_with_stdio(0), cin.tie(0);
	cin>>n;
	for(int i = 1 ; i <= n; i++){
		int x;
		cin>>x;
		update(i, x%2);
	}
	
	cin>>q;
	while(q--){
		int op, x, y;
		cin>>op>>x>>y;
		if(!op){
			update(x, y%2 - range(x,x));
		}else if(op == 1){
			cout<<(y-x+1)-range(x, y)<<endl;
		}else{
			cout<<range(x, y)<<endl;
		}
	}
}
