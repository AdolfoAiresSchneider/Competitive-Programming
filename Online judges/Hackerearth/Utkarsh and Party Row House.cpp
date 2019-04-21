#include<bits/stdc++.h>
using namespace std;

#define inf 1e9
#define maxn 1000009
#define endl '\n'

typedef long long ll;

ll n, q, bit[3][maxn], p[maxn];

void upd(ll idx, ll x, ll t){
  for(; idx <= n; idx += idx&-idx){
    bit[t][idx] += x;
  }
}

ll query(ll idx, ll t){
  ll ans = 0;
  for(; idx > 0; idx -= idx&-idx){
    ans += bit[t][idx];
  }
  return ans;
}

ll range(ll l, ll r, ll t){
  return query(r, t) - query(l-1, t);
}


ll query2(ll l, ll r, ll k){
  ll sum = range(l, r, 2);
  if(k >= l && k <= r){
    ll x1 = range(k+1, r, 0), x2 = range(l, k-1, 1);
    return (x1 - range(k+1, r, 2)*k) + (x2 - range(l, k-1, 2)*(n-k+1));
  }
  if(k < l) return range(l, r, 0) - sum*k;
  return range(l, r, 1) - sum*(n-k+1);
}

int main(){
  
  cin.sync_with_stdio(0), cin.tie(0);
  //~ freopen("in", "r", stdin);
  //~ freopen("out", "w", stdout);
  
  cin>>n>>q;
  for(ll i = 1; i <= n; i++){
    cin>>p[i];
    upd(i, i*p[i], 0);
    upd(i, (n-i+1)*p[i], 1);
    upd(i, p[i], 2);
  }
  
  while(q--){
    ll op, k, l, r, s;
    cin>>op>>k;
    if(op == 1){
      cin>>l>>r;
      cout<< query2(l, r, k)<<endl;
    }else{
      cin>>s;
      upd(k, s, 2);
      ll x = range(k, k, 2);
      upd(k, k*x - range(k, k, 0), 0);  
      upd(k, (n-k+1)*x - range(k, k, 1), 1);  
    }
  }
}

