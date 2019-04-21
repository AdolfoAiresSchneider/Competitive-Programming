#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define mod2 1000000006
typedef long long ll;

string a, b;

ll fastPow(ll x, ll y){
  if(y == 0) return 1;
  if(y%2ll) return x*fastPow(x, y-1)%mod;
  ll aux = fastPow(x, y/2ll);
  return aux*aux%mod;
}
// Fermat's little theorem
int main(){
  cin>>a>>b;
  ll x = 0, y = 0;
  
  for(auto c : a){
    c -= '0';
    x = (x*10ll%mod+c)%mod;
  }
  
  for(auto c : b){
    c -= '0';
    y = (y*10ll%mod2+c)%mod2;
  }
  
  cout<<fastPow(x, y)<<endl;
}
