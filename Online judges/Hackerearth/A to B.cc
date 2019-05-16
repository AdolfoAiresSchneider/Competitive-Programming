#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define maxn 100008
#define mod 1000000007
#define endl '\n'

ll tot = 1, A[maxn], n, q, NZ = 0;

ll fpow(ll x, ll y){
  if(!y) return 1ll;
  if(y%2ll) return (x*fpow(x, y-1))%mod;
  ll aux = fpow(x, y/2ll);
  return (aux*aux)%mod;
}

void upd(ll id, ll v){
  
  if(A[id] != 0){
    tot *= fpow(A[id], mod-2);
    tot %= mod;  
  }else NZ--;
  
  A[id] = v;
  if(!v){
    NZ++;
    return;
  }
  
  tot *= v;
  tot %= mod;
}

ll query(ll id){
  if(NZ) {if(NZ >= 2 || A[id] != 0) return 0;}
  ll aux = tot;
  if(A[id] == 0){
    return tot;
  }
  aux *= fpow(A[id], mod-2);
  aux %= mod;
  return aux;
}

int main(){
  
  //~ freopen("in", "r", stdin);
  cin.sync_with_stdio(0), cin.tie(0);
  cin>>n;
  for(ll i = 1; i <= n; i++){
    cin>>A[i];
    if(A[i] == 0){
       NZ++;
       continue;
    }
    tot = tot*A[i]%mod;
    tot %= mod;
  }
  
  
  cin>>q;
  while(q--){
    ll type, id, v;
    cin>>type>>id;
    if(type == 0){
      cin>> v;
      upd(id, v);
    }else cout<<query(id)<<endl;
  }
}
