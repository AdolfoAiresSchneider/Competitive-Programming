#include <bits/stdc++.h>
using namespace std; 

typedef long long ll;
typedef pair<ll,ll> ii;
#define all(x) x.begin(), x.end()
#define maxn 100009
#define A(x) 2*x
#define B(x) (2*x+1)
#define pb push_back
#define endl '\n'

struct node{
  ll i, j, beg, end, ans;
  node(ll i, ll j, ll beg, ll end, ll ans) :
   i(i), j(j), beg(beg), end(end),ans(ans){}
  node(){};
};

ll n, q, p[maxn];
node st[4*maxn];
vector<ii> aux;

node merge(node x, node y){
  node z;
  z.beg = x.beg, z.end = y.end;
  z.ans = max(x.ans, y.ans);
  if(p[x.end] < p[y.beg]){
    ll ni = x.j, nj = y.i;
    z.i = x.i, z.j = y.j;
    if(y.j <= nj) z.j = ni;
    if(x.i >= ni) z.i = nj;
    z.ans = max(z.ans, nj-ni+1);
  }else z.i = x.i, z.j = y.j;
  return z;
}

void build(ll no = 1, ll l = 0, ll r = n-1){
  if(l == r){
    st[no] = node(l,l,l,l,1);
    return;
  }
  ll mid = (l+r)/2;
  build(A(no), l, mid), build(B(no), mid+1, r);
  st[no] = merge(st[A(no)], st[B(no)]);
}

void update(ll idx, ll x, ll no = 1, ll l = 0, ll r = n-1){
  if(l == r){
    p[r] += x;
    return;
  }
  ll mid = (l+r)/2;
  if(idx <= mid) update(idx, x, A(no), l, mid);
  else update(idx, x, B(no), mid+1, r);
  st[no] = merge(st[A(no)], st[B(no)]);
}


node query(ll i, ll j, ll no = 1, ll l = 0, ll r = n-1){
  if(r < i || l > j) return node(-1,-1,-1,-1,-1);
  if(l >= i && r <= j) return st[no];
  ll mid = (l+r)/2;
  node x = query(i, j, A(no), l, mid);
  node y = query(i, j, B(no), mid+1, r);
  if(x.i != -1 && y.i != -1) return merge(x, y); 
  if(x.ans == -1) return y;
  return x;
}

int main(){
  
  cin.sync_with_stdio(0), cin.tie(0);
  //~ freopen("in", "r", stdin);
  //~ freopen("out", "w", stdout);
  ll t;
  cin>>t;
  
  while(t--){
    
    cin>>n>>q;
    for(ll i = 0; i < n; i++){
      cin>>p[i];
    }
    build();
    
    while(q--){
      ll op, x, y;
      cin>>op>>x>>y;
      if(op){
        update(x-1, y);
      }else cout<<query(x-1, y-1).ans<<endl;
    }
  }
}

