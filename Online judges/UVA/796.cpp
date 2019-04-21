#include <bits/stdc++.h>
using namespace std;

//// uva 796 - Critical Links
//// OBJ : Indentificar e imprimir as pontes de articulação em ordem crescente

vector<vector<int> >grafo;
vector<int> dfs_num,dfs_low,parent;
vector< pair<int,int> > pontes;
int cont;

void DFS_AP(int u)
{
	register int i,v,N = grafo[u].size();
    dfs_low[u] = dfs_num[u] = cont++;
    for(i = 0 ; i< N ;i++)
    {
        v = grafo[u][i];
        if(dfs_num[v] == -1)
        {
            parent[v] = u;
            DFS_AP(v);
            if(dfs_low[v] > dfs_num[u]) pontes.push_back(make_pair(min(u, v), max(u, v))); // It is a bridge
            dfs_low[u] = min(dfs_low[u],dfs_low[v]);
        }
        else if(parent[u] != v) dfs_low[u] = min(dfs_low[u],dfs_num[v]);
    }
}

void clr(int N)
{
        grafo.clear();
        grafo.resize(N);
        dfs_low.clear();
        dfs_low.resize(N,-1);
        dfs_num.clear();
        dfs_num.resize(N,-1);
        parent.clear();
        parent.resize(N,-1);
        pontes.clear();
}

int main()
{
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	
    register int N,i,vertice,a,b;
    char c;
    while(cin>>N)
    {
		clr(N);
        for(i = N;i--;)
        {
            scanf(" %d %c %d %c",&vertice,&c,&a,&c);
            while(a--)
            {
                scanf("%d",&b);
                grafo[vertice].push_back(b);
                grafo[b].push_back(vertice);
            }
        }

        cont=0;
        for(i =0;i<N;i++) if(dfs_num[i] == -1) DFS_AP(i);
        
        sort(pontes.begin(),pontes.end());
        printf("%d critical links\n",(int)pontes.size());
        for(vector<pair<int,int> >::iterator it = pontes.begin();it!=pontes.end();it++)
            printf("%d - %d\n",it->first,it->second);
        puts("");
    }
}
