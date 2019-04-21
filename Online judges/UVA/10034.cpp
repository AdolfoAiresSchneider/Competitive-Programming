#include <bits/stdc++.h>
#include <iomanip>
using namespace std;
typedef pair<double,double> ii;

vector<ii> grafo[110];
vector<ii> edges;
vector<int> taken;
priority_queue<ii> pq;
ii v;

inline void process(int vtx)
{
	taken[vtx]=1;	
	for(int i = 0; i < (int)grafo[vtx].size();i++)
	{
	    v = grafo[vtx][i];
		if(!taken[v.first]) pq.push(ii(-v.second,-v.first));
	}
}


float getDist(float x0,float y0,float x1, float y1)
{
	return sqrt((x0-x1)*(x0-x1)+(y0-y1)*(y0-y1));
}




int main()
{
	//freopen("in","r",stdin);
	//freopen("out","w",stdout);
	ii front;
	double u,w;
	int n,nv,i,j;
	double a,b;
	cin>>n;
	
	while(n--)
	{		
		cin>>nv;
		for( i = 0;i <nv;i++)
		{
			scanf("%lf %lf",&a,&b);
			edges.push_back(ii(a,b));
		}
		
		for( i = 0; i <nv;i++)
		{
			for(j = i+1;j<nv;j++)
			{
				grafo[i].push_back(ii(j,getDist(edges[i].first,edges[i].second,edges[j].first,edges[j].second)));
				grafo[j].push_back(ii(i,getDist(edges[i].first,edges[i].second,edges[j].first,edges[j].second)));
			}
		}
		
		taken.assign(nv,0);
		process(0);
		float mstcost = 0;
		while(!pq.empty())
		{
			front = pq.top(); pq.pop();	
			u = -front.second;
			w = -front.first;
			if(!taken[u]) 
			{
				mstcost+= w;
				process(u);
			}
		}
		
		printf("%.2f\n",mstcost);
		if(n) cout<<endl;
		edges.resize(0);
		for(int i = 0; i <=nv;i++) grafo[i].clear();
	}
}
