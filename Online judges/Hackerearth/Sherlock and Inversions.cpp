#include <bits/stdc++.h>
using namespace std;

#define maxn 100009
#define pb push_back
#define all(x) x.begin(), x.end()
#define endl '\n'

typedef long long ll;
ll n, q, p[maxn], id[maxn], x, bit[maxn], ans[maxn];

void reMap(){
  sort(id, id+n);
  for(ll i = 0; i < n; i++){
    p[i] = lower_bound(id, id+n, p[i]) - id + 1;
  }
}

void upd(ll idx, ll x){
  for(; idx <= n; idx += idx&-idx){
    bit[idx] += x;
  }
}

ll query(ll idx){
  ll sum = 0;
  for(; idx > 0; idx -= idx&-idx){
    sum += bit[idx];
  }
  return sum;
}

struct node{
  ll l, r, block, idx;
  node(ll l, ll r, ll block, ll idx) : l(l), r(r), block(block), idx(idx){}
  bool operator < (node other) const{
    if(block == other.block)
      return r < other.r;
    return block < other.block;
  }
};

ll inv = 0;
void addR(ll v){
  inv += query(n)-query(v);
  upd(v, 1);
}

void addL(int v){
  inv += query(v-1);
  upd(v, 1);
}

void remL(ll v){
  inv -= query(v-1);
  upd(v, -1);
}

void remR(int v){
  inv -= query(n) - query(v);
  upd(v, -1);
}

vector<node> qs;
void process(){
  ll l = 0, r = -1;
  for(node cur : qs){
    ll i = cur.l, j = cur.r;
    while(r < j) addR(p[++r]);
    while(r > j) remR(p[r--]);
    while(l < i) remL(p[l++]);
    while(l > i) addL(p[--l]);
    ans[cur.idx] = inv;
  }
}

int main(){
  
  cin.sync_with_stdio(0), cin.tie(0);
  //~ freopen("in", "r", stdin);
  //~ freopen("out", "w", stdout);
  
  cin>>n>>q;
  for(ll i = 0; i < n; i++){
   cin>>x; 
   id[i] = p[i] = x;
  }
  
  reMap();
  int block_size = sqrt(n);
  for(ll i = 0; i < q; i++){
    ll l, r;
    cin>>l>>r;
    l--;r--;
    qs.pb(node(l, r, l/block_size, i));
  }
  sort(all(qs));
  process();
  for(ll i = 0; i < q; i++){
    cout<<ans[i]<<endl;
  }
}

