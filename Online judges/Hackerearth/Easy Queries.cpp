#include <bits/stdc++.h>
using namespace std;
 
typedef pair<int,int> ii;
 
#define maxn 100009
#define A(no) 2*no
#define B(no) (2*no+1)
#define st first
#define nd second
#define inf 1e9
 
int n, q, p[maxn];
ii st[2][4*maxn];
 
void build(int no = 1, int l = 0, int r = n-1){
  if(l == r){
    st[0][no] = ii(-p[l], l);
    st[1][no] = ii(-p[l],-l);
    return;
  }
  int mid = (l+r)/2;
  build(A(no), l, mid), build(B(no), mid+1, r);
  st[0][no] = min(st[0][A(no)], st[0][B(no)]);
  st[1][no] = min(st[1][A(no)], st[1][B(no)]);
}
 
void update(int i, int no = 1, int l = 0, int r = n-1){
  if(l == r){
    st[0][no] = ii(-1, l);
    st[1][no] = ii(-1,-l);
    return;
  }
  
  int mid = (l+r)/2;
  if(i <= mid) update(i, A(no), l, mid);
  else  update(i, B(no), mid+1, r);
  st[0][no] = min(st[0][A(no)], st[0][B(no)]);
  st[1][no] = min(st[1][A(no)], st[1][B(no)]);
}
 
ii query(int idx, int i, int j, int no = 1, int l = 0, int r = n-1){
  if(r < i || l > j){
    return ii(0,0);
  }
  if(l >= i && r <= j) return st[idx][no];
  int mid = (l+r)/2;
  return min(query(idx, i, j, A(no),l, mid), query(idx, i, j, B(no), mid+1, r));
}
 
int main(){
  //~ freopen("in","r", stdin);
  
  cin.sync_with_stdio(0), cin.tie(0);
  
  cin>>n>>q;
  for(int i = 0; i < n; i++){
    cin>>p[i];
  }
  
  build();
  
  while(q--){
    int t, id;
    cin>>t>>id;
    if(t){
      update(id);
    }else{
      
      ii l = query(1, 0, id-1);
      ii r = query(0, id+1, n-1);
      
      if(l.st == 0 ) cout<<-1;
      else cout<<abs(l.nd);
      
      cout<<' ';
      
      if(r.st == 0) cout<<-1<<endl;
      else cout<<abs(r.nd)<<endl;
    }
  }
}
Language: C++14
