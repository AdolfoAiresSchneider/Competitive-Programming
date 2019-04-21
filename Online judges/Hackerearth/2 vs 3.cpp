#include <bits/stdc++.h>
using namespace std; 

typedef long long ll;
#define all(x) x.begin(), x.end()
#define maxn 100009
#define A(x) 2*x
#define B(x) (2*x+1)
#define pb push_back
#define endl '\n'
#define mod 3

int st[4*maxn], n, q, pot[maxn];
vector<int> p;

int merge(int x, int y, int l2){
  return (x*pot[l2]%mod + y)%mod;
}

void build(int no = 1, int l = 0, int r = n-1){
if(l == r){
   st[no] = p[l];
   return;
 }
 int mid = (l+r)/2;
 build(A(no), l, mid), build(B(no), mid+1, r);
 st[no] = merge(st[A(no)], st[B(no)], r-mid);
}


void update(int idx, int x, int no =1, int l = 0, int r = n-1){
 if(l == r){
   st[no] = x;
   return ;
 }
 int mid = (l+r)/2;
 if(idx <= mid) update(idx, x, A(no), l, mid);
 else update(idx, x, B(no), mid+1, r);
 st[no] = merge(st[A(no)], st[B(no)], r-mid);
}

int query(int i, int j, int no =1, int l = 0, int r = n-1){
  if(r < i || l > j) return 0;
  if(l >= i && r <= j) return st[no];
  int mid = (l+r)/2;
  int x = query(i, j, A(no), l, mid);
  int y = query(i, j, B(no), mid+1, r);
  return merge(max(x,0), max(y,0), max(0, min(r, j)-mid));
}

int main(){
 
 cin.sync_with_stdio(0), cin.tie(0);
 //~ freopen("in", "r", stdin);
 
 string s;
 cin>>n>>s>>q;
 
 pot[0] = 1;
 for(int i = 1; i <= n; i++)
  pot[i] = (2*pot[i-1])%mod;
 
 for(int c : s) p.pb(c-'0');
 
 build();
 
 while(q--){
   int op;
   cin>>op;
   if(op == 0){
     int l, r;
     cin>>l>>r;
     cout<<query(l, r)<<endl;
   }else{
     int id;
     cin>>id;
     update(id, 1);
   }
 }
}

