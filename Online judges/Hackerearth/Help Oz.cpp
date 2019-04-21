#include<bits/stdc++.h>
using namespace std;

#define pb push_back

vector<int> ans;
int p[500], n;

int f(int mod){
  int x = p[1]%mod;
  for(int i = 2; i < n; i++){
    if(p[i]%mod != x) return 0;
  }
  return 1;
}

int main(){
  
  //~ freopen("in","r", stdin);
  
  cin>>n;
  
  for(int i = 0; i < n; i++){
    cin>>p[i];  
  }
  
  int dif = abs(p[1]-p[0]);
  for(int j = 1; j*j <= dif; j++){
    if(dif%j) continue;
    if(dif / j == j){ if(j != 1)ans.pb(j);}
    else {
      if(f(dif/j)) ans.pb(dif/j);
      if(f(j) && j != 1) ans.pb(j);
    }
  }
  
  sort(ans.begin(), ans.end());
  for(int x : ans) cout<<x<<' ';
  cout<<endl;
}

