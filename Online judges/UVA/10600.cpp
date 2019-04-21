#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> ii;
typedef pair<ii,int> iii;

vector<ii> grafo[100];
vector<int> taken;
priority_queue<iii> pq;
iii f;

void process(int vtx)
{
	taken[vtx] = 1;
	for(int i = 0; i < (int)grafo[vtx].size();i++)
	{
		ii v = grafo[vtx][i];
		iii aux = iii(ii(vtx,v.first),v.second);
		iii aux2 = iii(ii(v.first,vtx),v.second);
		
		if(!taken[v.first]&&aux!=f&&aux2!=f)
		{  
			pq.push(iii(ii(-v.second,-v.first),-vtx));
		}
	}
}


int main()
{
	int n,nv,na,a,b,c;
	scanf("%d",&n);
	vector<iii> proibidos;
	iii front;
	int u,w,from;
	while(n--)
	{	
		scanf("%d %d",&nv,&na);
		while(na--)
		{
			scanf("%d %d %d",&a,&b,&c);
			grafo[a].push_back(ii(b,c));
			grafo[b].push_back(ii(a,c));
		}
				
		f = iii(ii(-1,-1),-1);
		int cost1 = 0;
		taken.assign(nv+50,0);
		process(1);
		while(!pq.empty())
		{
			front = pq.top(); pq.pop();
			u = -front.first.second;
			w = -front.first.first;
			from = - front.second;
			if(!taken[u])
			{
				proibidos.push_back(iii(ii(from,u),w));
				cost1+=w;
				process(u);	
			}
		}
		int cost2 = 1e9,aux3=0;
		for(int i = 0; i <(int)proibidos.size();i++)
		{
		    f = proibidos[i];
			taken.assign(nv+50,0);
	    	aux3 = 0;
			process(1);			
			while(!pq.empty())
			{
				front = pq.top(); pq.pop();
				u = -front.first.second;
				w = -front.first.first;
				if(!taken[u])
				{
					aux3 += w;
					process(u);
				}
			}
			if(aux3>=cost1)
				cost2 = min(cost2,aux3);
		}
		cout<<cost1<<" "<<cost2<<endl;
		for(int i=0; i <= nv;i++) grafo[i].clear();
		proibidos.clear();
	}	
}
