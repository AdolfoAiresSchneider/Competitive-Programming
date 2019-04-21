#include <bits/stdc++.h>
using namespace std;
 
typedef pair<int,int> ii;
 
#define maxn 1000009
#define A(no) 2*no
#define B(no) (2*no+1)
#define st first
#define nd second
#define inf 1e9
 
int n, q, st[4*maxn];
 
void build(int no = 1, int l = 0, int r = n-1){
  if(l == r){
    st[no] = 1;
    return;
  }
  int mid = (l+r)/2;
  build(A(no), l, mid), build(B(no), mid+1, r);
  st[no] = st[A(no)] + st[B(no)];
}
 
void update(int idx, int no = 1, int l = 0 , int r = n-1){
  if(l == r){
    st[no] = 0  ; 
    return;
  }
  int mid = (l+r)/2;
  if(idx <= mid) update(idx, A(no), l, mid);
  else update(idx, B(no), mid+1, r);
  st[no] = st[A(no)] + st[B(no)];
}
 
int query(int k, int no = 1, int l = 0, int r = n-1){
  if(st[no] < k) return -2;
  if(l == r) return l;
  int mid = (l+r)/2;
  if(st[A(no)] >= k) return query(k, A(no), l, mid);
  return query(k-st[A(no)], B(no), mid+1, r);
}
 
int main(){
  
  //~ freopen("in","r", stdin);
  cin.sync_with_stdio(0), cin.tie(0);
  
  cin>>n>>q;
  build();
  while(q--){
    int t, k;
    cin>>t>>k;
    if(t){
        int x = query(k);
        cout<<x+1<<endl;
    }else update(k-1);
  }
}
Language: C++14
