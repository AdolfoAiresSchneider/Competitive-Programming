#include <bits/stdc++.h>
using namespace std;

#define maxn 1500000

int trie[maxn][30], cnt ;

void add(string x){
  int node = 0;
  for(int c : x){
    c -= 'a';
    if(!trie[node][c])
      trie[node][c] = ++cnt;
    node = trie[node][c];
  }
}

int main(){
  //~ freopen("in", "r", stdin);
  string s;
  cin>>s;
  for(int i = 0; i < (int)s.size(); i++){
    add(s.substr(i));
  }
  cout<<cnt<<endl;
}
