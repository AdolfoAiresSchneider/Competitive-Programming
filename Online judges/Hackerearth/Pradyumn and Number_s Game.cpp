#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define inf 1e9
#define maxn 1000009
#define endl '\n'
#define mod 1000000007

ll n, p[maxn], l[maxn], q[maxn], bit[maxn], r[maxn];

void reMap(){
  sort(q, q+n);
  for(ll i = 0; i < n; i++){
    p[i] = lower_bound(q, q+n, p[i]) - q + 1;
  }
}

void update(ll idx, ll x){
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

int main(){
  
  cin.sync_with_stdio(0), cin.tie(0);
  //~ freopen("in", "r", stdin);
  
  cin>>n;
  
  for(ll i = 0; i < n; i++){
    cin>>p[i];
    q[i] = p[i];
  }
  
  reMap();
  
  for(ll i = 0; i < n; i++){
    l[i] = query(p[i]-1);
    update(p[i], 1 );
  }
  
  memset(bit, 0, sizeof bit);
  for(ll i = n-1; i >= 0; i--){
    r[i] = query(p[i]-1);
    update(p[i], 1);
  }
  
  ll ans = 0;
  for(ll  i = 0; i < n; i++){
    ans = (ans + l[i]*r[i]%mod)%mod;
  }
  cout<<ans<<endl;
}

