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
  cin.sync_with_stdio(0), cin.tie(0);
  //~ freopen("in", "r", stdin);  
  
  ll n, t;
  cin>>t;
  
  while(t--){
    cin>>n;
    cout<<fPow(2, n)-1<<endl;
  }
}

