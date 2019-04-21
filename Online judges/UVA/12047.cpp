#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
typedef pair<int,ii> edge;

vector<ii> grafo[2][12000];
int dist[2][12000];

void djks(int saida ,int sentido,int qtd)
{
	for(int i = 0; i <=qtd+10;i++) dist[sentido][i] = 1e9; 
	    priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > S;
	dist[sentido][saida] = 0;
	S.push(ii(0,saida));	
	while(!S.empty())
	{
		ii aux = S.top();	 S.pop();
		int d = aux.first;
		int u = aux.second;
		if(d>dist[sentido][u]) continue;
		for(int i = 0; i <(int)grafo[sentido][u].size();i++){
			ii v = grafo[sentido][u][i];
			if(dist[sentido][u]+v.second < dist[sentido][v.first]){
				dist[sentido][v.first] = dist[sentido][u]+v.second;
				S.push(ii(dist[sentido][v.first],v.first));
			}
		}	
	}
}

int main()
{
	//freopen("in","r",stdin);
	//freopen("out","w",stdout);
	int n;
	cin>>n;
	while(n--)
	{
		priority_queue<edge> edges;
		int nv,arestas,saida,chegada,total;
		cin>>nv>>arestas>>saida>>chegada>>total;
		while(arestas--)
		{
			int a,b,c;
			cin>>a>>b>>c;
			grafo[1][a].push_back(ii(b,c));
			grafo[0][b].push_back(ii(a,c));
			edges.push(edge(c,ii(a,b)));
		}
		djks(saida,1,nv);
		djks(chegada,0,nv);
		int resposta = -1 ;
		while(!edges.empty())
		{
			edge aux = edges.top();
			edges.pop();	
			if(aux.first + dist[1][aux.second.first] + dist[0][aux.second.second] <= total)
			{
				resposta = aux.first;
				break;
			}
		}
		cout<<resposta<<endl;
		for(int i = 0; i <=nv;i++) 
		{
			grafo[0][i].clear();
			grafo[1][i].clear();
		}
	}
}
