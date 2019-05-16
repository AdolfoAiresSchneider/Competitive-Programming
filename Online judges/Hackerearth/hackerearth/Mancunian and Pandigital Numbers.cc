#include<bits/stdc++.h>
using namespace std;

#define maxn 1000009

int p[maxn];

int is(int x){
  int freq[10] = {0}, sz = to_string(x).size();
  while(x){
    int d = x%10;
    if(freq[d] || !d || d > sz) return 0;
    freq[d]++;
    x /= 10;
  }
  
  for(int i = 1; i <= sz; i++){
    if(!freq[i]) return 0;
  }
  return 1;
}
  

void init(){
  for(int i = 0; i < maxn; i++){
    p[i] = is(i);
    if(i) p[i] += p[i-1];
  }
}

int main(){

  cin.sync_with_stdio(0), cin.tie(0);
  
  init();
  int q;
  cin>>q;
  
  while(q--){
    int l, r;
    if(l  > r) swap(l, r);
    cin>>l>>r;
    cout<<p[r] - p[l-1]<<'\n';
  }
}
