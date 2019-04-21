#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back
#define mod 1000003

ll p[1000009];

int main(){
  
  //~ freopen("in","r", stdin);
  
  p[0] = 1;
  for(ll i = 1; i <= mod; i++) p[i] = p[i-1]*i%mod;
  
  ll x, n, t;
  cin>>t;
  
  while(t--){
    cin>>n>>x;
    if(n >= mod) cout<<0<<endl;
    else cout<<x*(p[n])%mod<<endl;
  }
}

