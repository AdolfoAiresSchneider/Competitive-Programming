#include <bits/stdc++.h>
using namespace std;

//// uva 610 - Street Directions
/// OBJ : turn many two-ways streets into one-way street as possible
/// the graph must keep connected

vector<int> grafo[1010];
int num[1010], low[1010], parent[1010], road[1010][1010];
int point;

void findBridge(int u)
{
	register int i,v,N = grafo[u].size();
	low[u] = num[u] = ++point;
	for( i=0 ; i<N ; ++i )
	{
		v = grafo[u][i];
		if( !num[v] ) // se nao foi visitado
		{
			parent[v] = u; //// de onde v veio
			findBridge(v);
			if( low[v] > num[u] ) road[u][v] = road[v][u]=1; // it is a A.bridge, so it can't change
			else if( !road[v][u] ) road[u][v]=1; //// posso transformar em uma via, se ela já nao for
			low[u] = min( low[u] , low[v] );
		}
		else if( parent[u] != v)///nao é um ciclo
			 {
				low[u]=min( low[u] , num[v] );
				if(!road[v][u]) road[u][v]=1; //// posso transformar em uma via, se ela já não for
			 }
	}
}

void clr(int n){
	memset(road,0,sizeof road);
	memset(num,0,sizeof num);
	memset(parent,0,sizeof parent);
	for(int i=1;i<=n;i++) grafo[i].clear();    
}

int main()
{
	int n, m, u, v, caso=1,i,j;
	while(scanf("%d%d",&n,&m) && n)
	{
		for( i=0 ; i < m ; ++i)
		{
			scanf("%d%d",&u,&v);
			grafo[u].push_back(v);
			grafo[v].push_back(u);
		}
		
		point=0;
		findBridge(1);
		
		printf("%d\n\n",caso++);
		for(i=1;i<=n;++i)
			for(j=1;j<=n;++j)
				if(road[i][j]) printf("%d %d\n",i,j);
				
		puts("#");
		clr(n); // limpar arrays
	}
}
