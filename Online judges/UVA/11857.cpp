#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;

vector<ii> grafo[1000010];
vector<int> taken;
priority_queue<ii> pq;

int vt;
void proces(int vtx)
{
	taken[vtx] = 1;
	vt++;
	for(int i = 0;i<(int)grafo[vtx].size();i++)
	{
		ii v = grafo[vtx][i];
		if(!taken[v.first]) pq.push(ii(-v.second,-v.first));	
	}
}

int main()
{
	//freopen("in","r",stdin);
	//freopen("out","w",stdout);
	
	int n,m;
	
	while(cin>>n>>m&&n)
	{
		int a,b,c;	
		while(m--)
		{
			cin>>a>>b>>c;
			grafo[a].push_back(ii(b,c));
			grafo[b].push_back(ii(a,c));
		}
		
		vt = 0;
		int mstcost = 0;
		taken.assign(n,0);
		proces(0);
		
		int w,u;
		int aux= -21;
		while(!pq.empty())
		{
			ii front = pq.top(); pq.pop();
			u = -front.second;
			w = -front.first;
			if(!taken[u])
			{
				
				aux = max(w,aux);
				mstcost+=w;
				proces(u);
			}
		}
		if(vt != n ) cout<<"IMPOSSIBLE"<<endl;
		else cout<<aux<<endl;
		for(int i = 0;i<n;i++) grafo[i].clear();
	}
}

