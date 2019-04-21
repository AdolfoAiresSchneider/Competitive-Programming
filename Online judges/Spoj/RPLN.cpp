#include <bits/stdc++.h>
using namespace std;
 
#define INF INT_MAX
 
int st[100090*4];
int vet[100900];
 
void build(int root, int l, int r){
	if(l == r){
		st[root] = vet[l];
		return ;
	}
	int noL = 2*root,noR = 2*root+1;
	int middle = (l+r)/2;
	
	build(noL,l,middle);
	build(noR,middle+1,r);
	
	st[root] = min(st[noL],st[noR]);	
}
 
 
int query(int no, int l , int r , int i, int j){
	
	if(l > j || r < i) return INF;
	
	if(l>=i && r <= j) return st[no];
	
	int noL = 2*no,noR = 2*no+1;
	int middle = (l+r)/2;
	
	return min(query(noL,l,middle,i,j),query(noR,middle+1,r,i,j));
	
}
 
 
 
 
 
 
int main(){
	
	//~ freopen("in","r",stdin);
	
	int t,n,m;
	
	cin>>t;
	int x = 1;
	while(t--){
		cin>>n>>m;
		for(int i = 0 ; i < n ; ++i) cin>>vet[i];
		build(1,0,n-1);
		cout << "Scenario #"<<x++ << ":\n";
		
		for(int ct = 1 ; ct <= m ; ++ct){
			int i,j;
			cin>>i>>j;
			i--,j--;
			cout << query(1,0,n-1,min(i,j),max(i,j))<<'\n';
		}
	}
	return 0;
}
 
