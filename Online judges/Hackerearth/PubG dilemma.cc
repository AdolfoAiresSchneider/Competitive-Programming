#include<bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define maxn 1000089
#define pb push_back
#define aint(x) x.begin(), x.end()
#define endl '\n'

typedef pair<int, int> ii;

int n, input[maxn], deg[maxn], pref[maxn];

vector<int> ans;

int erdosGal(int block){
  
  int cnt = 0;
  int sum = 0;
  for(int i = 0; i <= n; i++){
    if(block == i) continue;
     deg[cnt++] = input[i];
     sum += input[i];
  }
  if(sum%2) return false;
  sort(deg, deg+n); reverse(deg, deg+n);
  memset(pref, 0, sizeof pref);
  
  pref[n-1] = deg[n-1]; 
  for(int i = n-2; i >= 0; i--)
    pref[i] = deg[i] + pref[i+1]; 
  
  int p = 0;
  for(int i = 1; i <= n; i++){
    p += deg[i-1];
    int idx = lower_bound(deg+i, deg+n, i, greater<int>()) - deg;
    if(p > (idx-i)*i + pref[idx] + i*(i-1)){
      return 0;
    }
  }
  return 1;
}

int main(){
  
  cin.sync_with_stdio(0), cin.tie();
  //~ freopen("in", "r", stdin);
  while(cin>>n){
    
    for(int i = 0; i <= n; i++){
      cin>>input[i];
    }
    
    for(int i = 0; i <= n; i++){
      if(erdosGal(i)) ans.pb(i);
    }
    
    cout<<ans.size()<<endl;
    for(int x : ans){
      cout<<x+1<<endl;
    }

  }
}

