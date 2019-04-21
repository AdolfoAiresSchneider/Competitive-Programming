#include<bits/stdc++.h>
using namespace std;
 
#define maxn 100009
#define A(x) (2*x)
#define B(x) (2*x+1)
 
int n, p1[maxn], p2[maxn];
bitset<5002> st1[4*maxn], st2[4*maxn];  
 
void build(int no = 1, int l = 0, int r = n-1){
  if(l == r){
    st1[no].set(p1[l]), st2[no].set(p2[l]);
    return ;
  }
  int mid = (l+r)/2;
  build(A(no), l, mid), build(B(no), mid+1, r);
  st1[no] = st1[A(no)] | st1[B(no)];
  st2[no] = st2[A(no)] | st2[B(no)];
}
 
bitset<5002> query(bitset<5002> * st, int i, int j, int no = 1, int l = 0, int r = n-1){
  if(r < i || l > j) return 0;
  if(l >= i && r <= j) return st[no];
  int mid = (l+r)/2;
  return query(st, i, j, A(no), l, mid) | query(st, i, j, B(no), mid+1, r);
}
 
 
int main(){
  
  //freopen("in", "r", stdin);  
  cin.sync_with_stdio(0), cin.tie(0);
  cin>>n;
  
  for(int i = 0; i < n; i++)
    cin>>p1[i];
    
  for(int i = 0; i < n; i++)
    cin>>p2[i];
  
  build();
  
  int q;
  cin>>q;
  bitset<5002> ans;
  while(q--){
    int l1, r1, l2, r2;
    cin>>l1>>r1>>l2>>r2;
    ans = query(st1, l1-1, r1-1) | query(st2, l2-1, r2-1);
    cout<<ans.count()<<endl;
  }  
}
Language: C++14
