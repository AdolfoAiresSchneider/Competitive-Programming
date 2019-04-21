#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> ii;

#define maxn 100009
#define pb push_back
#define inf 1e18
#define st first
#define nd second
#define cur_sz(x) (int)x.size()

ll n, A[maxn], B[maxn], bit[2][maxn], mx, pref, sum[maxn];
ii q[maxn];
vector<ii> ar[maxn];

void reMap(){
  sort(q, q+n);
  for(int i = 0; i < n; i++){
    B[i] = lower_bound(q, q+n, ii(B[i], i)) - q + 1;
  }
  
  for(int i = 0; i <= n; i++){
    ar[A[i]].pb({B[i], q[B[i]-1].st});
  }
}

void upd(int idx, ll x, int t){
  for(; idx <= n; idx += idx&-idx){
    bit[t][idx] += x;
  }
}

ll query(ll idx, ll t){
  ll ans = 0;
  for(; idx > 0; idx -= idx & - idx){
    ans += bit[t][idx];
  }
  return ans;
}

int kth(int k){
  if(k < 0) return 0;
  int l = 1, r = n;
  while(l < r){
    int mid = (l+r)/2;
    if(query(mid,0) >= k) r = mid;
    else l = mid+1;
  }
  return l;
}

ll solve(){
  ll ans = inf, cur_sz = 0, cur = pref;
  for(int x = 1; x <= mx; x++){
    if(ar[x].empty()) continue;
    cur -= sum[x];
    cur_sz += ar[x].size();
    int idx = kth(cur_sz - 2*ar[x].size()+1);
    ans = min(cur + query(idx, 1), ans);
    for(auto y : ar[x]){
      upd(y.st, y.nd, 1);
      upd(y.st, 1, 0);
    }
  }
  return ans;
}

int main(){
 
  cin.sync_with_stdio(0), cin.tie(0);
  //~ freopen("in", "r", stdin);
  
  cin>>n;
  for(int i = 0 ; i < n ; i++){
    cin>>A[i];
    mx = max(mx, A[i]);
  }
  
  for(int i = 0 ; i < n ; i++){
    cin>>B[i];
    q[i] = {B[i], i};
    sum[A[i]] += B[i];
    pref += B[i];
  }
  
  reMap();
  cout<<solve()<<endl;
}

