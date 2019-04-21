#include <bits/stdc++.h>
using namespace std;
int N;


// Apenas verificar se o grafo é bicolor( bipartido )
vector<int> grafo[400];

const int  corA = 1 ;
const int  corB = 2 ;
int color[400];
int ca,cb;

bool bfs()
{
	memset(color,0,sizeof color);
	queue<int> S;	
	S.push(0);
	color[0] = corA;
	while(!S.empty())
	{
		int atual  = S.front(); S.pop();
		for(int i = 0; i < (int)grafo[atual].size();i++)
		{
			int v = grafo[atual][i];
			if(color[atual] == color[v]) return false;
			if(!color[v])
			{
				if(color[atual] == corA)color[v] = corB;			
				else  color[v] = corA;		
				S.push(v);
			}	
		}
	}
	return true;
}

int main()
{
	//~ freopen("in","r",stdin);
	while(scanf("%d",&N) != EOF && N)
	{
		for(int i = 0; i <= N; i++) grafo[i].clear();
		int a,b;
		while(scanf("%d%d",&a,&b) && (a||b))
		{
			grafo[a-1].push_back(b-1);
			grafo[b-1].push_back(a-1);
		}
		if(bfs()) printf("YES\n");
		else printf("NO\n");
	}
}
