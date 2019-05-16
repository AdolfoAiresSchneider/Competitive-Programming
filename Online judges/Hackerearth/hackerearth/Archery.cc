#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll lcm(ll x, ll y){
  return x*y/(__gcd(x,y));
}

int main(){
  //~ freopen("in", "r", stdin);
  int t;
  cin>>t;
  
  while(t--){
    ll n = 0, ans = 1;
    cin>>n;
    while(n--){
      ll x;
      cin>>x;
      ans = lcm(x,ans);
    }
    cout<<ans<<endl;
  } 
}
