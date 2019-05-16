#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

// Turán graph
int main(){
  
  freopen("in", "r", stdin);
  ll t, n;
  ll q;
  cin>>t;
  
  while(t--){
    cin>>n>>q;
    q--;
    ll a = ceil(n/(double)q);
    ll b = floor(n/(double)q);
    ll ans = n*n - (n%q)*a*a;
    ans -= ((q - n%q)*b*b);
    ans /= 2;
    ans = n*(n-1ll)/2ll - ans;
    cout<<ans<<endl;
  }
}
