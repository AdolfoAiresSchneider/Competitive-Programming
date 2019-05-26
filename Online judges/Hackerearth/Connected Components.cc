#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define maxn 200009
typedef long long ll;

ll inv[maxn], fat[maxn];

ll fpow(ll x, ll y){
  if(!y) return 1;
  if(y%2ll) return x*fpow(x, y-1)%mod;
  ll x2 = fpow(x, y/2);
  return x2*x2%mod;
}

void init(int lim){
  fat[0] = 1, inv[0] = 1;
  for(ll i = 1; i <= lim; i++){
    fat[i] = i*fat[i-1]%mod;
    inv[i] = fpow(fat[i], mod-2);
  }
}

ll C(ll n, ll k){
  //~ cout<<" ## "<<n<<' '<<k<<' '<<n-k<<endl;
  if (n<k)return 0;
  if (k<0)return 0;
  return fat[n]*inv[k]%mod*inv[n-k]%mod;
}

ll n, m, c; 
int main(){
  
  freopen("in", "r", stdin);
  int t;
  cin>>t;
  
  init(maxn-2);
  while(t--){
    cin>>n>>m>>c;
    
    if(c == 0){
      if(m == n) cout<<1<<endl;
      else cout<<0<<endl;
      continue;
    }
    
    ll ans = C(m+1,m-(c-1))*C(n-m-1,c-1)%mod;
    cout<<ans<<endl;
  } 
}
