#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define maxn 1000000
#define mod 1000000007

ll freq[maxn], fat[maxn];

ll fastExp(int x, int y){
  if(y == 0) return 1;
  if(y%2) return x*fastExp(x, y-1)%mod;
  ll res = fastExp(x, y/2);
  return res*res%mod;
}

int main(){
  
  //~ freopen("in", "r", stdin);
  
  cin.sync_with_stdio(0), cin.tie(0);
  fat[0] = 1;
  for(int i = 1; i < maxn-1; i++){
    fat[i] = i*fat[i-1]%mod;
  }
  
  int t;
  cin>>t;
  cin.ignore();
  
  while(t--){
    string x;
    getline(cin, x);
    
    memset(freq, 0, sizeof freq);
    for(int c : x){
      freq[c - '0']++;
    }
    
    ll ans = fat[x.size()];
    for(int i = 0; i <= 9; i++){
      int x = freq[i];
      ans *= fastExp(fat[x], mod-2);
      ans %= mod;
    }
    
    cout<<ans<<endl;
  }
}
