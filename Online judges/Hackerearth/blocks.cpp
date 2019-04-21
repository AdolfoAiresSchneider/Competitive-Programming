#include<bits/stdc++.h>
using namespace std;
 
#define maxn 2000001
#define A(x) (2*x)
#define B(x) (2*x+1)
#define inf 1e9
 
int p[maxn], st[4*maxn], act[maxn];
int np = 200001;
void build(int no = 1, int l = 0, int r = np-1){
  if(l == r){ st[no] = p[l]; return;}
  int mid = (l+r)/2;
  build(A(no), l, mid), build(B(no), mid+1, r);
  st[no] = max(st[A(no)], st[B(no)]);
}
 
void push(int no){
  if(act[no] == 0) return;
  st[A(no)] = st[B(no)] = st[no];
  act[no] = !(act[A(no)] = act[B(no)] = 1);
  
}
 
void update(int i, int j, int val, int no = 1, int l = 0, int r = np-1){
  if(i > r || l > j) return;
  if(l >= i && r <= j){
    act[no] = 1, st[no] = val;
    return ;
  }
  push(no);
  int mid = (l+r)/2;
  update(i, j, val, A(no), l, mid), update(i, j, val, B(no), mid+1, r);
  st[no] = max(st[A(no)], st[B(no)]);
}
 
int query(int i, int j, int no = 1, int l = 0, int r = np-1){
  if(i > r || l > j) return -inf;
  if(l >= i && r <= j){
    return st[no];
  }
  push(no);
  int mid = (l+r)/2;
  return max(query(i, j, A(no), l, mid), query(i, j, B(no), mid+1, r));
}
 
int main(){
  
  cin.sync_with_stdio(0), cin.tie(0);
  //~ freopen("in", "r", stdin);  
  
  int n;
  cin>>n;
  
  build();
  
  while(n--){
    
    int l, h, p, c, x;
    cin>>l>>h>>p>>c>>x;
    
    int q = query(x, x+l-1);
    if(c){
      update(x, x+l-1, q+1), update(x+p-1, x+p-1, q+h+1);
    }
    else{
      int qc = query(x+p-1, x+p-1);
      if(q - h >= qc) update(x, x+l-1, q+1);
      else update(x, x+l-1, qc+h+1);
    }
  }
  
  cout<<query(0, np-1)<<endl;
}
Language: C++14
