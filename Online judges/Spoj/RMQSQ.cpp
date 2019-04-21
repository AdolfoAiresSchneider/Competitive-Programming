#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<ll,ll> ii;
 
#define st first
#define nd second
#define maxn 100009
#define max_log 30
#define inf 1e9
 
ll p[maxn][max_log], n, q;
 
 
void process()
{
  for(ll j = 1; j <= log2(n)+1; j++){
    for(ll i = 0; i + (1<<j)-1 < n; i++){
      p[i][j] = min(p[i][j-1], p[i+(1<<(j-1))][j-1]);
    }
  }
}
 
ll query(ll l, ll r)
{
  ll ans = inf;
  for(ll j = log2(n); j >= 0; j--){
    if(l+(1<<j)-1 <= r){
      ans = min(ans, p[l][j]);
      l += (1<<j);
    }
  }
  return ans;
}
 
 
int main()
{
  //~ freopen("in", "r", stdin);
  cin>>n;
  
  for(ll i = 0; i < n; i++){
    cin>>p[i][0];
  }
  
  process();
  cin>>q;
  
  while(q--)
  {
    ll l, r;
    cin>>l>>r;
    cout<<query(l, r)<<endl;
  }
}
