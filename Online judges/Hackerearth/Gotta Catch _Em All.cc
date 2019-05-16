#include <bits/stdc++.h>
using namespace std;

#define maxn 1000009
#define nd second
#define st first
typedef long long ll;
typedef pair<int, int> ii;

int p[maxn], spf[maxn], qtd[maxn];

// Calculate the smallest prime factor --> O(n log log n) 
void sieve(int n){
  for(int i = 1; i <= n; i++){
    spf[i] = i%2 ? i : 2 ;
  }
  for(int i = 3; i*i <= n; i++){
    if(spf[i] == i){
      for(int j = i*i; j <= n; j += i){
        if(spf[j] == j) spf[j] = i;
      }
    }
  }
}

// number of factors using prime factorization = (1+freq[pf1])*(1+freq[pf2]) ... (1+freq[pfn]) --> O(log n)
int nFactors(int x){
  int last = -1, cnt = 0, ans = 1;
  while(x != 1){
    if(last == -1) last = spf[x], cnt = 1;
    else if(last == spf[x]) cnt++;
    else{
      ans *= cnt+1, last = spf[x];
      cnt = 1;
    }
    x /= spf[x];
  }
  return ans * (cnt+1);
}
  
int main(){
  
  cin.sync_with_stdio(0), cin.tie(0);
  //~ freopen("in", "r", stdin);
  
  int n, t;
  cin>>t>>n;
  sieve(n);
  
  for(int i = 1; i <= n; i++){
    int x = nFactors(i);
    qtd[i] = x, p[x]++;
  }
  
  for(int i = 1; i <= n; i++){
    p[i] += p[i-1];
  }
  
  while(t--){
    int x;
    cin>>x;
    cout<<p[qtd[x]-1]<<'\n';
  }
}
