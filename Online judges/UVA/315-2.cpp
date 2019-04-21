#include <bits/stdc++.h>
using namespace std;
//////////////////////  Network - 315 uva
/// Obj : encontrar pontos de articulação - puro

vector<long int >grafo[110];	
int n,point,Root,subtree;
int parent[110],num[110],low[110];
bool AP[110];

void tarjanAP(int u)
{
	register int i,v,N = grafo[u].size();
	num[u] = low[u] = ++point;
	for( i = 0 ; i < N ; ++i )
	{
	    v = grafo[u][i];
		if(!num[v])// se não foi visitado
		{
			if( u == Root ) ++subtree; // se tiver mais de um ramo no vertice inicial
			tarjanAP(v);
			if(num[u] <= low[v]) AP[u] = true; // apenas menor para ponte
			low[u] = min(low[v] , low[u]); // atualiza o menor que o u pode chegar na dfs-tree
		}
		else if( parent[u] != num[v] ) low[u] = min( low[u] , num[v] );
		// se ja visitou, verifica senão é uma aresta de volta e se é um ciclo
	}
}

int main()
{
    register int i, f, t , ans;
    string aux;
    while(scanf("%d",&n) != EOF)
    {
        for(i=1;i<=n;i++) grafo[i].clear(); // cleaning the graph
        if(n==0) break;
        if(n==1){
            cin>>f;
            printf("0\n");
            continue;
        }
        getchar();
        while(getline(cin,aux))
        {
            istringstream stream(aux);
            stream>>f;
            if(f==0) break;
            while(stream>>t)
            {
                grafo[f].push_back(t);
                grafo[t].push_back(f);
            }
        }       
        for(int i = 1; i <= n ;++i)
        {
			memset(num,0,sizeof num);memset(low,0,sizeof low); // zerar vetores
			memset(parent,0,sizeof parent); memset(AP,0,sizeof AP); // zerar vetores
			subtree = ans = point = 0;
			Root = i;
			tarjanAP(i);
			AP[Root] = (subtree > 1); // caso especial, se o dfsnum i for uma raiz com mais de um filho não conectados
		}
        ans = 0;
        for(int i = 1; i <= n;i++) if(AP[i]) ans++;
        printf("%d\n",ans);
    }
}
