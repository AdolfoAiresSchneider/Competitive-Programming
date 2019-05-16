#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define endl '\n'

typedef unsigned long long ll;


ll fpow(ll x, ll y){
  if(y == 0) return 1ll;
  if(y%2ll) return (x*fpow(x, y-1))%mod;
  ll half = fpow(x, y/2)%mod;
  return (half*half)%mod;
}

int main(){
  
  //~ freopen("in", "r", stdin);
  
  
  ll a, r = 0;
  string b;
  cin>>a>>b;
  
  for(int c : b){
    c -= '0';
    r = r*10ll%(mod-1) + c;
    r %= (mod-1);
  }
  
  cout<<fpow(a, r)<<endl;
}
