#include<bits/stdc++.h>
using namespace std;

#define inf 1e9
#define maxn 1000009

//~ typedef long long int;

int n, k, p[maxn], q[maxn];

void update(int idx, int x, int * bit){
  for(; idx <= n; idx += idx&-idx){
    bit[idx] = min(bit[idx], x);
  }
}
int query(int idx, int * bit){
  int ans = inf;
  for(; idx > 0; idx -= idx&-idx){
    ans = min(ans, bit[idx]);
  }
  return ans;
}

void reMap(){
  sort(q, q+n);
  for(int i = 0; i < n; i++){
    p[i] = lower_bound(q, q+n, p[i]) - q + 1;
  }
}

int main(){
  
  cin.sync_with_stdio(0), cin.tie(0);
  //~ freopen("in", "r", stdin);
  
  cin>>n>>k;
  
  int bit[k+2][n+2];
  memset(bit, 0x3f, sizeof bit);
  
  for(int i = 0; i < n; i++){
    cin>>p[i];
    q[i] = p[i];
  }
  
  reMap();
  
  int ans = 0;
  for(int i = 0; i < n; i++){
    update(p[i], q[p[i]-1], bit[1]);
    for(int j = 2; j <= k; j++){
      int x = query(p[i]-1, bit[j-1]);
      if(x >= inf) break;
      update(p[i], x, bit[j]);
    }
    ans = max(ans, q[p[i]-1] - query(p[i]-1, bit[k-1]));
  }
  
  if(ans == 0) cout<<-1<<endl;
  else cout<<ans<<endl;
}

