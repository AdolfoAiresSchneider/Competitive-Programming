#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define maxn 200009
#define sz(x) (ll)x.size()

ll bit[maxn], n, p[maxn];

void update(ll idx, ll x){
  for(; idx <= n; idx += idx & -idx){
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


ll solve(){
  memset(bit, 0, sizeof bit);
  ll ans = 0, inv = 0, m = n;
  n = 2*n-1;
  for(ll i = n-1, j = n; i >= 0; i--){
    while(j > 0 && i-j+1 < m){
      ll c = p[--j];
      update(c, 1);
      inv += query(c-1);
    }
    ll c = p[i];
    ans ^= inv;
    update(c, -1);
    inv -= (query(n) - query(c));
    if(j == 0) break;
  }
  
  return ans;
}

int main(){
  
  cin.sync_with_stdio(0), cin.tie(0);
  //~ freopen("in", "r", stdin);
  
  ll t;
  cin>>t;
  
  while(t--){
    cin>>n;
    for(ll i = 0; i < n; i++){
      cin>>p[i];
      p[i+n] = p[i];
    }
    
    cout<<solve()<<endl;
  }
}

