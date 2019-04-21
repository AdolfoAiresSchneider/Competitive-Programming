#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;

map<string,int> id;
vector<ii> grafo[2003];
priority_queue<ii> pq;
vector<int> taken;

void process (int vtx)/// func to prim algorithm use
{
	taken[vtx] = 1;
	for(int j = 0;j<(int)grafo[vtx].size();j++)
	{	
		ii v = grafo[vtx][j];
		if(!taken[v.first]) pq.push(ii(-v.second,-v.first));	
	}	
}

int main()
{
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	int n,arestas,i,cost,nv;
	string a,b;
	cin>>n;
	while(n--)
	{
		cin>>nv>>arestas;
		i = 1;
		while(arestas--)
		{
			cin>>a>>b>>cost;
			if(!id[a]) id[a] = i++;
			if(!id[b]) id[b] = i++;
			grafo[id[a]].push_back(ii(id[b],cost));
			grafo[id[b]].push_back(ii(id[a],cost));
		}
		taken.assign(nv+10,0);
		process(1);
		int mst_cost = 0;
		while(!pq.empty()) /// part of prim algorithm
		{
			ii front = pq.top();
			pq.pop();
			int u = -front.second;
			int w = -front.first;
			if(!taken[u])
			{
					mst_cost+=w;
					process(u);
			}	
		}
		cout<<mst_cost<<endl;
		id.clear();
		for(int i = 0; i <=nv;i++) grafo[i].clear();
		if(n) cout<<endl;
	}
}

