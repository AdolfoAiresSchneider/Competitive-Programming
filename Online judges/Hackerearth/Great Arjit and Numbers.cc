#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define maxn 10000009
#define mod 1000000007

ll fPow(ll x, ll y){
  if(y == 0) return 1;
  if(y%2) return x*fPow(x, y-1)%mod;
  ll res = fPow(x, y/2);
  return res*res%mod;
}

ll arr[maxn], A[maxn];

ll gauss(ll n){
  n %= mod;
  return ((n*(n+1))/2ll)%mod;
}


int main(){
  //~ freopen("in", "r", stdin);  
  cin.sync_with_stdio(0), cin.tie(0);
  
  int t;
  cin>>t;
  
  while(t--){
    ll n, mul = 1, k = 0;
    
    cin>>n;
    for(int i = 0; i < n; i++){
      cin>>arr[i];
      if(i == 0) mul = arr[0];
      else{
         A[k] = arr[i]*fPow(mul, mod-2)%mod ;
         mul *= A[k];
         mul %= mod;
         k++;
       }
    }
    
    ll f = 0;
    for(int i = 0; i < k; i++){
      f += gauss(A[i])%mod;
      f %= mod;
    }
    
    ll ans = gauss(f);
    cout<<ans<<endl;
    
  }
  
}
  
