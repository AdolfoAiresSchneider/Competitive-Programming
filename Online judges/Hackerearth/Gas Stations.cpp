#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back


int main(){
  
  //~ freopen("in","r", stdin);
  ll n, x, ans = 0;
  cin>>n>>x;
  while(n--){
    ll l;
    cin>>l;
    x -= l;
    ans++;
    if(x <= 0) break;
  }
  cout<<ans<<endl;
}

