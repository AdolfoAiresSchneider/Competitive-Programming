#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define maxn 1000010
#define mod 1000000007


ll fastPow(int x, int y){
  if(y == 0) return 1;
  if(y%2) return x*fastPow(x, y-1)%mod;
  ll aux = fastPow(x, y/2);
  return aux*aux%mod;
}

int main(){
  ll n, f = 1, g;
  cin>>n;
  for(int i = 0; i < n; i++){
    ll x;
    cin>>x;
    if(i) g = __gcd(g, x);
    else g = x;
    f = x*f%mod;
  }
  
  cout<<fastPow(f, g)<<endl;
}
