#include<bits/stdc++.h>
using namespace std;
 
#define maxn 2000010
#define pb push_back
#define endl '\n'
vector<int> idx[maxn];
int ans[maxn], trie[maxn][258], cnt = 0, link[maxn];
bool fim[maxn], vis[maxn];
 
void add(char * s, int id){
  int no = 0;
  for(int i = 0; i < (int)strlen(s); i++){  
    int c = s[i];
    if(!trie[no][c])
      trie[no][c] = ++cnt;
    no = trie[no][c];
  }
  idx[no].pb(id); // strings repetidas
  fim[no] = 1;
}
 
void aho(int no){
	queue<int> q;
	q.push(no);
	int v, l;
	while(!q.empty())
	{
		v = q.front(); q.pop();
		l = link[v];
		fim[v] |= fim[l];
		for(int i = 0; i <= 257; ++i){
			if(trie[v][i]){
				link[trie[v][i]] = v ? trie[l][i] : 0;
				q.push(trie[v][i]);
			}
			else trie[v][i] = trie[l][i];
		}
	}
}
 
void check(char * s){
  int no = 0;
  for(int i = 0; i < (int)strlen(s); i++){  
    int c = s[i];
    while(trie[no][c] == 0 && no)
      no = link[no];
    no = trie[no][c];
    if(vis[no]) continue;
    int aux = no;
    while(aux){
      vis[aux] = 1;
      for(int x : idx[aux])
        ans[x] = 1;
      aux = link[aux];
    }
  }
}
 
void init(int n)
{
  cnt = 0;
  for(int i = 0; i <= n; i++)
    idx[i].clear();
  memset(trie, 0, sizeof trie);
  memset(link, 0, sizeof link);
  memset(ans, 0, sizeof ans);
  memset(fim, 0, sizeof fim);
  memset(vis, 0, sizeof vis);
  
}
char word[maxn], txt[maxn];
 
int main(){
  //~ freopen("in", "r", stdin);
  int n;  
  scanf("%s %d", txt, &n);
  
  for(int i = 1; i <= n; i++){
    scanf("%s", word);
    add(word, i);
  }
  aho(0);
  check(txt);
  
  for(int i = 1; i <= n; i++){
    printf((ans[i] ? "Y\n" : "N\n"));
  } 
}
