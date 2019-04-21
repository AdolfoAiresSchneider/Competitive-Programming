#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
#define st first
#define nd second
#define pb push_back
#define maxn 500009
#define inf 0x3f3f3f3f

int  z[maxn];

void  z_function(string s){
    int n = s.length();
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r) z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
          ++z[i];
        if (i + z[i] - 1 > r){
          l = i, r = i + z[i] - 1;
        }
    }
}

int main(){
  
  cin.sync_with_stdio(0), cin.tie(0);
  //~ freopen("in","r", stdin);
  
  int q;
  string s;
  cin>>s>>q;
  s = s + "@"+s;
  reverse(s.begin(), s.end());
  z_function(s);
      
  while(q--){
    int id;
    cin>>id;
    int ans = z[s.size()-id];
    cout<<ans<<endl;
  }
}
