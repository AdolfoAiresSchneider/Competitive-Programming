#include <bits/stdc++.h>
using namespace std;

vector<int> grafo[110];
int num[110],low[110],parent[110]; 
map<string,int> indice;
map<int,string> nome;
set<string> resp;
string a,b;
int cont,child;

void point_Art(int u, int root)
{
	register int i,v,N = grafo[u].size();
    num[u] = low[u] = cont++;
    for( i = 0 ; i < N ; ++i)
    {
        v = grafo[u][i];
        if(num[v] == -1)
        {
            parent[v] = u;
            if(u == root) child ++;
            point_Art(v,root);
            if( low[v] >= num[u] && u!=root ) resp.insert(nome[u]);
            low[u] = min(low[u],low[v]);
        }
        else if(v != parent[u]) low[u] = min(low[u],num[v]);
    }
}

void clr(int N)
{	
	for(int i = 0;i <= N;++i) grafo[i].clear();
	memset(low,0,sizeof(low));
	memset(parent,0,sizeof(parent));
	memset(num,-1,sizeof(num));
	indice.clear();
	nome.clear();
	resp.clear();
}
int main()
{
	//freopen("in","r",stdin);
	//freopen("out","w",stdout);
    int vertices,flag = 0,i,arestas,casos = 1;
    while(scanf("%d",&vertices),vertices)
    {
		clr(vertices);
        if(flag) cout<<endl;
        flag = 1;
        cont = 0;
        for(i = vertices;i--;)
        {
            cin>>a;
            indice[a] = cont;
            nome[cont]= a;
            cont++;
        }
        scanf("%d",&arestas);
        while(arestas--)
        {
            cin>>a>>b;
            grafo[indice[a]].push_back(indice[b]);
            grafo[indice[b]].push_back(indice[a]);
        }
        cont = 0;
        for(i = 0 ; i < vertices ; i++)
        {
            if(num[i] == -1)
            {
                child = 0;
                point_Art(i,i);
                if(child > 1) resp.insert(nome[i]);
            }
        }
        printf("City map #%d: %d camera(s) found\n",casos++,(int)resp.size());
        for(set<string>::iterator it = resp.begin() ; it != resp.end();it++)
            cout<<*it<<endl;
    }
}
