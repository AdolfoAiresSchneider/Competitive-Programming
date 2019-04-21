#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define maxn 200009
#define sz(x) (ll)x.size()
#define endl '\n'

ll bit[maxn], n, p[maxn], q[maxn], l1[maxn], r1[maxn], l2[maxn], r2[maxn];

void update(ll idx, ll x){
  for(; idx <= n; idx += idx & -idx){
    bit[idx] += x;
  }
}

ll query(ll idx){
  ll sum = 0;
  for(; idx > 0; idx -= idx&-idx){
    sum += bit[idx];
  }
  return sum;
}

void init(){
  memset(bit, 0, sizeof bit);
}

void reMap(){
  sort(q, q+n);
  for(ll i = 0 ; i < n; i++){
    p[i] = lower_bound(q, q+n, p[i]) - q + 1;
  }
}

void getR(){
   for(ll i = n-1; i >= 0; i--){
    ll x = p[i];
    r1[i] = query(x- 1);
    r2[i] = query(n) - query(x);
    update(x, 1);
  }
}

void getL(){
  for(ll i = 0; i < n; i++){
    ll x = p[i];
    l1[i] = query(x-1);
    l2[i] = query(n) - query(x);
    update(x, 1);
  }
}
  
int main(){
  
  cin.sync_with_stdio(0), cin.tie(0);
  //~ freopen("in", "r", stdin);
  
  ll t;
  cin>>t;
  
  while(t--){
    string op[2]  = {"Ananya", "Sarika"};
    cin>>n;
    for(ll i = 0; i < n; i++){
      cin>>p[i]; 
      q[i] = p[i];
    }
    
    ll st ;
    cin>>st;
    
    reMap();
    init();
    getR();
    init();
    getL();
    
    ll s1 = 0, s2 = 0;
    for(ll i = 0; i < n; i++){
      s1 += (l1[i]*r1[i]);
      s2 += (l2[i]*r2[i]);
    }
    
    
    if(st) swap(op[0], op[1]);
    
    
    if(s1 == 0){
      cout<<op[1]<<endl;
      cout<<0<<endl;
      continue;
    }
    
    if(s1 > s2){
      cout<<op[0]<<endl;
      cout<<2ll*s2+1<<endl;
    }else if(s1 < s2){
      cout<<op[1]<<endl;
      cout<<2ll*s1 <<endl;
    }else{
      cout<<op[!(s1%2)]<<endl;
      cout<<2ll*s1<<endl;
    }
  }
}

