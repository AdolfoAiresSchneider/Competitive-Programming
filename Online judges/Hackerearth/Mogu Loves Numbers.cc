#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define pb push_back
#define maxn 1000010
#define mod 1000000007

int nDiv(int x){
  int cnt = 0;
  for(int i = 1; i*i <= x; i++){
    if(x%i) continue;
    cnt++;
    if(x/i != i) cnt++;
    if(cnt > 2) return cnt;
  }
  return cnt;
}

int p[maxn];

int main(){
  
    cin.sync_with_stdio(0), cin.tie(0);
    //~ freopen("in","r", stdin);
    int t;
    cin>>t;
    
    for(int i = 1; i <= 1000000; i++){
      int cnt = nDiv(i);
      if(cnt == 2) p[i] = 1;
      else p[i] = 0;
      p[i] += p[i-1];
    }
    
    while(t--){
      int l, r;
      cin>>l>>r;
      if(l > r) swap(l, r);
      cout<<p[r] - p[l-1]<<'\n';
    }
}
