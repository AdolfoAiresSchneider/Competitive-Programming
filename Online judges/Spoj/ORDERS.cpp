#include<bits/stdc++.h>
using namespace std;
 
typedef pair<int,int> ii;
 
#define endl '\n'
#define maxn 200009
#define A(x) (2*x)
#define B(x) (2*x+1)
 
int p[maxn], n, seg[maxn], st[4*maxn], ans[maxn];
 
void build(int no, int l, int r){
  if(l == r){ st[no] = seg[l] == 0; return; }
  int mid = (l+r)/2;
  build(A(no), l, mid), build(B(no), mid+1, r);
  st[no] = st[A(no)] + st[B(no)]; 
}
 
void update(int no , int l, int r , int idx, int val){
  if(l == r){ st[no] = (val == 0); return;}
  int mid = (l+r)/2;
  if(idx <= mid) update(A(no), l, mid, idx, val);
  else update(B(no), mid+1, r, idx, val);
  st[no] = st[A(no)] + st[B(no)];
}
 
int query_k(int no , int l, int r, int i, int j, int k){
  if(l == r ) return l;
  int mid = (l+r)/2;
  if(st[A(no)] >= k) return query_k(A(no), l, mid, i, j, k);
  return query_k(B(no), mid+1, r, i, j, k-st[A(no)]);
}
 
void init(){
  memset(seg, 0, sizeof seg);
}
 
int main(){
  
  cin.sync_with_stdio(0), cin.tie(0);
  //~ freopen("in","r",stdin);
  int t;
  cin>>t;
  
  while(t--){
    cin>>n;
    
    for(int i = 0; i < n; i++)
      cin>>p[i];
    init();
    build(1, 0, n-1); 
    
    for(int i = n-1; i >= 0; i--){
      int k = (i+1) - p[i];
      ans[i] = query_k(1, 0, n-1, 0, n-1, k);
      update(1, 0, n-1, ans[i], 1);      
    }
    
    for(int i = 0; i < n; i++){
      cout<<ans[i]+1<<' ';
    }
    cout<<endl;
  }
}

