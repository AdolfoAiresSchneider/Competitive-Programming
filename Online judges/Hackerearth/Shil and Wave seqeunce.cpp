#include<bits/stdc++.h>
using namespace std;

#define maxn 100009
#define mod 1000000007

int n, bit[3][maxn], p[maxn], mx;

void upd(int idx, int x, int t){
  x %= mod;
  for(; idx <= mx; idx += idx&-idx ){
    bit[t][idx] += x;
    bit[t][idx] %= mod;
  }
}

int query(int idx, int t){
  int sum = 0;
  for(; idx > 0; idx -= idx&-idx){
    sum += bit[t][idx];
    sum %= mod;
  }
  return sum;
}

int f(){
  int ans = 0;
  for(int i = 0; i < n; i++){
    int x = query(p[i]-1, 0);
    int y = query(p[i]-1, 2);
    x += y;
    x %= mod;
    
    upd(p[i], x, 1);
    ans += x;
    ans %= mod;
    
    x = (query(mx, 1) -  query(p[i], 1) + mod)%mod;
    y = (query(mx, 2) -  query(p[i], 2) + mod)%mod;
    x += y;
    x %= mod;
    
    upd(p[i], x, 0);
    ans += x;
    ans %= mod;
    
    upd(p[i], 1, 2);  
  }
  
  return ans;
}

int main(){
  
  //~ freopen("in", "r", stdin);
  cin.sync_with_stdio(0), cin.tie(0);
  cin>>n;
  for(int i = 0 ; i < n ; i++){
    cin>>p[i];
    mx = max(mx, p[i]);
  }
  mx++;
  
  cout<<f()<<endl;
}

