#include <bits/stdc++.h>
using namespace std;

#define maxn 100000

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

vector<int> g[maxn];
int deg[maxn];

vector<int> toposort(int n)
{
  vector<int> order;
	queue<int> q;
	
	for(int i = 1; i <= n; i++)
		if(deg[i] == 0)
			q.push(i);
	
	while(!q.empty())
	{
		int u = q.front(); 
    q.pop();
		order.push_back(u);
		
		for(int v : g[u])
			if(--deg[v] == 0)
				q.push(v);
	}
	
	if((int)order.size() != n){
		// tem um ciclo
	}
	
	return order;
}

int main()
{
  
}
