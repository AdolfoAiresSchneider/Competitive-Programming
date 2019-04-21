#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;

vector<int> grafo[101];
int visited[101];
int dpe;
// apenas rodar o dfs e contar
void dfs(int u)
{
	visited[u] = 1;
	dpe++;
	for(int i = 0 ; i < (int)grafo[u].size();i++ )
	{
		int v = grafo[u][i];
		if(!visited[v]) dfs(v);
	}
}


int main()
{
	//~ freopen("in","r",stdin);
	int N,aux,b;
	while( scanf("%d",&N) && N )
	{
		for(int i = 0; i < N; i++) grafo[i].clear();
		ii resp = ii(0,1);
		for(int i = 0; i < N; i++)
		{
			scanf("%d",&aux);
			while(aux--)
			{
				scanf("%d",&b);
				b--;
				grafo[i].push_back(b);
			}
		}
		for(int i = 0 ; i < N;i++)
		{
			memset(visited,0,sizeof visited);
			dpe = 0;
			if(!visited[i]) dfs(i);
			resp = max(resp,ii(dpe,(i+1)*-1));
		}
		cout<<-resp.second<<endl;
	}
}
