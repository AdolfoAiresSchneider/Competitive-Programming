#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define maxn 1000009
#define mod 1000000007

ll fPow(ll x, ll y){
  if(y == 0) return 1;
  if(y%2) return x*fPow(x, y-1)%mod;
  ll res = fPow(x, y/2);
  return res*res%mod;
}


int main(){
  ll a, b;
  cin>>a>>b;
  cout<<fPow(a, b)<<endl;
}
