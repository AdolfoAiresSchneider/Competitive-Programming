#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
ll freq[2], dp[1000];
 
ll f(ll i){
  if(i == 1) return 1ll;
  if(dp[i] != -1) return dp[i];
  return dp[i] = f(i-1) + ((1ll<<(i-1ll))-1)*(i-1)+i;
}

int main(){
  memset(dp, -1, sizeof dp);
  
  ll n, t;
  cin>>t;
  
  while(t--){
    cin>>n;
    
    ll x = 0;
    while(f(x) <= n) x++;
    x--;
    
    int ans = 0;
    if(f(x)+(x-1) <= n) ans = 2*x-1;
    else ans = max(x, x+x-1-2);
    
    cout<<ans<<endl;
  }
}
