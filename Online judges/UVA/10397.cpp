#include <bits/stdc++.h>
using namespace std;
typedef pair<double,double> ii;

vector<ii> grafo[10004];
vector<int> taken;
priority_queue<ii> pq;

double getDist(double a, double b, double c, double d)
{
	return sqrt(pow(a-c,2)+pow(b-d,2));
}

void process(int vtx)
{
	taken[vtx] = 1;
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
	vector<ii> pont;
	int n;
	int a,b;
	while(cin>>n)	
	{
		for(int i = 0;i<n;i++)
		{
			cin>>a>>b;	
			pont.push_back(ii(a,b));
		}
		
		for(int i = 0;i<n;i++)
		{
			for(int j = i+1;j<n;j++)	
			{
					grafo[i].push_back(ii(j,getDist(pont[i].first,pont[i].second,pont[j].first,pont[j].second)));
					grafo[j].push_back(ii(i,getDist(pont[i].first,pont[i].second,pont[j].first,pont[j].second)));
			}
		}
				
		int cabos;
		cin>>cabos;
		double wstcost = 0;
		taken.assign(n+1,0);
		while(cabos--)
		{   
			cin>>a>>b;
		    grafo[a-1].push_back(ii(b-1,0));
		    grafo[b-1].push_back(ii(a-1,0));
		}
		process(1);
		while(!pq.empty())
		{
			ii front = pq.top(); pq.pop();
			double w = -front.first;
			double u = -front.second;
			if(!taken[u])
			{
				wstcost+=w;
				process(u);
			}	
		}
		printf("%.2f\n",wstcost);
		for(int i = 0;i<=n;i++) grafo[i].clear();
		pont.clear();
	}
}
