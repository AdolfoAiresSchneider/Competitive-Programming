#include <bits/stdc++.h>
using namespace std;
 
#define ll long long int
#define mod 1000000007
#define maxn 100009
 
ll n, q, a[maxn], pref[4*maxn][50] ,bin[maxn];
 
void build(){
  
    for(int i = 0; i < maxn; i++){
      if(!i){ bin[i] = 1; continue;}
      bin[i] = 2*bin[i-1];
      bin[i] %= mod;
    }
    
    for(int i = 0;i <= 42; i++)
      for(int j = 1; j <= n; j++){
        pref[j][i]= pref[j-1][i] + (bool)(a[j]&(1LL<<i));
      }
}
 
ll solve(int l, int r){
  ll sum=0;
  for(int i = 0; i <= 42; i++)
  {
      ll c1 = pref[r][i]-pref[l-1][i];
      ll c0 = (r-l+1)-c1;
      ll ans = c1*(c0*(c0-1))/2ll;
      ans = (ans + (c1*(c1-1)*(c1-2))/6ll)%mod;
      ans = ans*bin[i] % mod;
      sum =(sum + ans)%mod;
  }
    return sum;
}
 
int main(){
    cin.sync_with_stdio(0), cin.tie(0);
    //~ freopen("in", "r", stdin);
    
    cin>>n;
    for(int i = 1; i <= n; i++)
      cin>>a[i];
        
    build();
    
    int q, x;
    cin>>q>>x;
    
    while(q--){
      int l, r;
        cin>>l>>r;
        cout<<solve(l, r)<<endl;
    }
}
Language: C++14
