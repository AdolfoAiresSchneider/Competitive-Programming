#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define maxn 1000049
#define mod 1000000007
#define mod2 (mod-1)
#define inv(x) fpow(x, mod2-2, mod2)
#define C(n, k) choose[n][k]
#define endl '\n'

bool isPrime[maxn];
ll fat[maxn], choose[1001][1001];

void init(ll lim){
  memset(isPrime, 1, sizeof isPrime);
  isPrime[1] = isPrime[0] = 0;
  for(ll i = 2; i <= lim; i++){
    if(isPrime[i] == 0 || i*i > lim) continue;
    for(ll j = i*i; j <= lim ; j += i){
      isPrime[j] = 0;
    }
  }
  choose[0][0] = 1;
  for(int i = 1; i <= 1000; i++){
    choose[i][0] = 1, choose[i][1] = i;
  }
  for(int i = 2; i <= 1000; i++){
    for(int j = 2; j <= 1000; j++){
      if(j > i) break;
      choose[i][j] = (choose[i - 1][j] + choose[i - 1][j-1])%mod2; 
    }
  }
}

ll fpow(ll x, ll y, ll MOD){
  if(0ll == y) return 1ll;
  if(y%2ll) return (x*fpow(x, y-1, MOD))%MOD;
  ll aux = fpow(x, y/2ll, MOD);
  return (aux*aux)%MOD;
}

int main(){
  //~ freopen("in", "r", stdin);
  //~ freopen("out", "w", stdout);
  cin.sync_with_stdio(0), cin.tie(0);
  
  ll n, t, p, r;
  cin>>t;
  
  init(maxn-3);
  
  while(t--){
    cin>>n;
    p = r = 0;
    while(n--){
      ll x;
      cin>>x;
      if(isPrime[x]) p++;
      else r++;
    }
    
    ll nC = fpow(2, r, mod2);
    ll ans = 1;
    for(ll i = 0; i <= p; i++){
      ll ways = (C(p, i) * nC) % mod2;
      ans *= fpow(i+2, ways, mod)%mod;
      ans %= mod;
    }
    cout<<ans<<endl;
  }
}
