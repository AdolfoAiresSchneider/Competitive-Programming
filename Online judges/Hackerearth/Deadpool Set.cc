#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<ll,ll> ii;
 
#define pb push_back
#define maxn 1000002
#define mod 1000000007
#define nd second
#define st first
#define all(x) x.begin(), x.end()

vector<int> g[maxn];
int arr[maxn], spf[maxn];
ll dp[maxn];
 
void sieve(int n){
  for(int i = 1; i <= n; i++){
    spf[i] = i%2 ? i : 2 ;
  }
  for(int i = 3; i*i <= n; i++){
    if(spf[i] == i){
      for(int j = i*i; j <= n; j += i){
        if(spf[j] == j) spf[j] = i;
      }
    }
  }
}
 
void gen(int n){
  for(int i = 2; i <= n; i++){
    int prime = spf[i];
    int div = i/prime;
    g[i].pb(i), g[i].pb(prime);
    for(int x : g[div]){
      g[i].pb(x), g[i].pb(x*prime); 
    }
    sort(all(g[i]));
    g[i].erase(unique(all(g[i])), g[i].end());
  }
}
 
int main(){
  
  cin.sync_with_stdio(0), cin.tie(0);
  //~ freopen("in", "r", stdin);  
  
  int n, mx = -1;
  cin>>n;
  for(ll i = 0; i < n; i++){
    cin>>arr[i];
    mx = max(mx, arr[i]);
  }
  
  sieve(mx);
  gen(mx);
  
  ll ans = 0;
  sort(arr, arr + n);
  for(int i = 0; i < n; i++){
    int x = arr[i];
    if(x == 1) continue;
    dp[x] = 1;
    
    for(int f : g[x]){
      if(f == x) continue;
      int l = f, r = x/f;
      dp[x] += dp[l] * dp[r] % mod;
      dp[x] %= mod;
    }
    
    ans += dp[x];
    ans %= mod;
  }
   
  cout<<ans<<endl;
}
