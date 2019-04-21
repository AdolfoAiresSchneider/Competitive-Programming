#include <bits/stdc++.h>
using namespace std;
typedef pair<double,double> ii;
typedef pair<double,double> iF;
typedef ii point;

double getDist(int a, int b, int c, int d)
{
	return sqrt(pow(a-c,2)+pow(b-d,2));
}

vector<ii> grafo[1000009];
vector<int> taken;
priority_queue<ii> pq;

void process(int  vtx)
{
	taken[vtx] = 1;
	for(int i = 0; i <(int)grafo[vtx].size();i++)
	{
		ii v = grafo[vtx][i];
		if(!taken[v.first])  pq.push(ii(-v.second,-v.first));
	}
}


int main()
{
//	freopen("in","r",stdin);
	//freopen("out","w",stdout);
	
	int a,b,f,n,casos =1;
	int np;
	double cstate;
	ii front;
	double w,u;
	double dt;
	
	scanf("%d",&n);
	vector<point> pontos; 
	while(n--)
	{
		cin>>np>>cstate;
		for(int i = 0; i <np;i++)
		{
			scanf("%d %d",&a,&b);
			pontos.push_back(point(a,b));
		}
		for(int i = 0;i<np;i++)
		{
			for(int j = i+1;j<np;j++)
			{
				dt = getDist(pontos[i].first,pontos[i].second,pontos[j].first,pontos[j].second);
				grafo[i].push_back(ii(j,dt));
				grafo[j].push_back(ii(i,dt));
			}
		}
		
		taken.assign(np+2,0);
		process(0);
		double ruas= 0,estados = 0;
		f = 1;
		while(!pq.empty())
		{
			front = pq.top();
		    pq.pop();
		    
			w = -front.first;
			u = -front.second;
			if(!taken[u])
			{
				if(w<=cstate) ruas+=w;
				else
				{ 
					f++;
					estados+=w;
				}
				process(u);
			}
		}
		printf("Case #%d: %d %.0f %.0f\n",casos++,f,ruas,estados);
		for(int i = 0;i <=np;i++) grafo[i].clear();
		pontos.clear();
	}
}
