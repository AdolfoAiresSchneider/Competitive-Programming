#include <bits/stdc++.h>
using namespace std;
#define maxn 1000009
#define lt 27


// ---------- Some Trie aplications --------------------------//

// --> contiguous sub-sequence of the array, so that the bitwise XOR of all chosen numbers is maximum.

      // Make trie of the binary form of the xor-prefix.
      // Make a query before each ADD, trying to maximaze the binarie form and update the answer.

// --> Numbers of sub-arrays with xor at least k

      // Make trie of the binary form of the xor-prefix.
      // Make a query before each ADD

int trie[maxn][lt] = {};
int fim[maxn] = {};
int link[maxn] ;

int cnt ;

void add(string & a)
{
	int no = 0;
	for(int c : a)
	{
		c -= 'a';
		if(!trie[no][c])
			trie[no][c] = cnt++;
		no = trie[no][c];		
	}
	fim[no] = true;
}

// kmp na trie
void aho()
{
	queue<int> q;
	q.push(0);
	int v, l;
	while(!q.empty())
	{
		v = q.front(); q.pop();
		l = link[v];
		fim[v] |= fim[l];
		for(int i = 0; i < 26; ++i){
			if(trie[v][i]){
				link[trie[v][i]] = v ? trie[l][i] : 0;
				q.push(trie[v][i]);
			}
			else trie[v][i] = trie[l][i];
		}
	}
}

void init()
{
  memset(trie, 0, sizeof trie);
  memset(link, 0,sizeof link);
  memset(fim, 0,sizeof fim);
  cnt = 1;
}



int main()
{
	//~ freopen("in","r",stdin);

	int n;
	string a;
	
	cin>>n;
  init();
	
	while(n--)
  {
		cin>>a;
		add(a);
	}
  
	aho();	
  
}
