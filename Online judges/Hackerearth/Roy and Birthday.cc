#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define maxn 1000009
#define mod 1000000007

ll fat[maxn];
ll C,V, freq[50];
string vowel("aeiou");

ll fPow(ll x, ll y){
  if(y == 0) return 1;
  if(y%2) return x*fPow(x, y-1)%mod;
  ll res = fPow(x, y/2);
  return res*res%mod;
}

void calc_fat(){
  fat[0] = 1;
  for(ll i = 1; i < maxn; i++){
    fat[i] = i*fat[i-1]%mod;
  }
}

ll ways(ll n, ll r){
  //~ if(n <= 0 || r < 0 || n < r) return 0ll;
  ll aux = (fat[n] * fPow(fat[r], mod-2))%mod;
  return ( aux * fPow(fat[n-r], mod-2))%mod;
}

ll solve(){
  
  if(C+1 < V) return -1;
  
  ll f1 = fat[C], f2 = fat[V];  
  for(ll i = 'a'; i <= 'z'; i++){
    if(!freq[i-'a']) continue;
    if(vowel.find(i) == string::npos) {
      f1 *= fPow(fat[freq[i-'a']], mod-2);
      f1 %= mod;
    }else {
      f2 *= fPow(fat[freq[i-'a']], mod-2);
      f2 %= mod;
    }
  }
  
  ll perm = (f1 * f2 % mod);
  return (perm * ways(C+1, V)%mod) % mod;
}

int main(){
  
  //~ freopen("in", "r", stdin);  
  cin.sync_with_stdio(0), cin.tie(0);
  
  calc_fat();
  ll t;
  cin>>t;
  
  while(t--){
    
    string str;
    cin>>str;
    
    C = 0, V = 0;
    memset(freq, 0, sizeof freq);
    for(char c : str){
      freq[c-'a']++;
      if(vowel.find(c) == string::npos) C++;
      else V++;
    }
    
    cout<<solve()<<endl;
  }
}
