#include <bits/stdc++.h>
using namespace std;

int hasaip[3000];
int dist [3000];
vector<pair<int,int> > grafo[3000];

int dkjstra(int inicio, int fim,int qtd)
{
	if(inicio == fim) return hasaip[fim];
	for(int i = 0 ; i <=qtd;i++) dist[i] = 1e9;
	priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > S;
	dist[inicio] = !hasaip[inicio];
	S.push(make_pair(0,inicio));
	while(!S.empty())
	{
		pair<int,int> aux = S.top(); S.pop();
		int d = aux.first;
		int u = aux.second;
		if(d> dist[u]) continue;
		for(int i =0;i  <(int)grafo[u].size();i++)
		{
			pair<int,int> v = grafo[u][i];
			if(dist[u]+v.second < dist[v.first])
			{
				dist[v.first] = dist[u]+v.second ;
				S.push(make_pair(dist[v.first],v.first));				
			}
		}
	}
	if(dist[fim] == 1e9) return -1;
	return dist[fim];
}


int main()
{
	//freopen("in","r",stdin);
	//freopen("out","w",stdout);
	int caso = 1;
	int a;
	cin>>a;
	while(a--)
	{
		memset(hasaip,0,sizeof(hasaip));
		int n,m,k;
		cin>>n>>m>>k;	
		while(k--)
		{	
			int aux;
			cin>>aux;
			hasaip[aux] = 1;
		}	
		while(m--)
		{
			int a,b;
			cin>>a>>b;
			if(hasaip[b] == 0) grafo[a].push_back(make_pair(b,1));
			else grafo[a].push_back(make_pair(b,0));	
			if(hasaip[a] == 0)  grafo[b].push_back(make_pair(a,1));	
			else grafo[b].push_back(make_pair(a,0));		
		}
		int cst;
		cin>>cst;
		cout<<"Case "<<caso++<<":"<<endl;
		while(cst--)
		{
			int y,u;
			cin>>y>>u;
			cout<<dkjstra(y,u,n)<<endl;
		}
		for(int i = 0;i<=n;i++) grafo[i].clear();	
		cout<<endl;
	}	
}

