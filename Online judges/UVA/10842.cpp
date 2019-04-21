#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;

vector<ii> grafo[10000];
vector<int> taken;
priority_queue<ii> pq;
int t;
ii v;


void process(int vtx)
{
	taken[vtx] =1;
	t = grafo[vtx].size();
	for(int i = 0; i <t;i++)
	{
		v = grafo[vtx][i];
		if(!taken[v.first]) pq.push(ii(v.second,v.first));
	}
}

int main()
{
	//freopen("in","r",stdin);
	//freopen("out","w",stdout);
	int n,a,b,c,i;
	cin>>n;
	int nv,arestas;
	int caso = 1;
	int mstcost,maximominimo,w,u;
	ii front;
	
	while(n--)
	{
		cin>>nv>>arestas;
		while(arestas--)
		{
			cin>>a>>b>>c;
			grafo[a].push_back(ii(b,c));
			grafo[b].push_back(ii(a,c));
		}
		
		taken.assign(nv,0);
		process(0);
		mstcost = 0;
		maximominimo = 1e9;
		
		while(!pq.empty())
		{
			 front  = pq.top(); pq.pop();
			 w = front.first;
			 u = front.second;
			
			if(!taken[u])
			{
				maximominimo = min(maximominimo,w);
				mstcost += w;
				process(u);
			}
		}
		printf("Case #%d: %d\n",caso++,maximominimo);
		for(i  = 0 ;i<=nv ; i++) grafo[i].resize(0);
	}
}
