#include<bits/stdc++.h>
using namespace std;

#define maxn 2000010
#define pb push_back
#define mod 1000000007
#define inv(x) fpow(x, mod-2)

typedef long long ll;

int vis[maxn], freq[maxn];
vector<ll> primes;
ll fat[maxn], n, k;

void sieve(ll lim){
  memset(vis, 1, sizeof(vis));
  vis[0] = vis[1] = 0;
  for(ll i = 2; i <= lim; i++){
    if(!vis[i] || i*i > lim) continue;
    for(ll j = i*i; j <= lim; j+= j) vis[j] = 0;
    primes.pb(i);
  }
}

void fact(ll x){
  for(ll f : primes){
    if(f*f > x) break;
    while(x % f == 0){
      x /= f;
      freq[f]++;
    }
  }
  if(x != 1) freq[x]++;
}

ll fpow(ll x, ll y){
  if(!y) return 1;
  if(y%2) return (x*fpow(x, y-1))%mod;
  ll aux = fpow(x, y/2ll);
  return (aux*aux)%mod;
}

ll C(ll n, ll k){
  return ((((fat[n] * inv(fat[k]))% mod) * inv(fat[n-k]))%mod)%mod;
}

void init(){
  sieve(1000000);
  fat[0] = 1;
  for(int i = 1; i < maxn; i++){
    fat[i] = (fat[i-1]*i)%mod;
  }
}

int main(){
  
  cin.sync_with_stdio(0), cin.tie(0);
  //~ freopen("in", "r", stdin);
  
  cin>>n>>k;
  init();
  while(n--){
    int x;
    cin>>x;
    fact(x); 
  }
  
  ll ans = 1;
  for(int i = 0; i < maxn; i++){
    if(!freq[i]) continue;
    ans *= C(freq[i]+k-1, k-1);
    ans %= mod;
  }
  
  cout<<ans<<endl;
}
