#include <bits/stdc++.h>
using namespace std;
typedef pair<double,double> dd;

int grafo[500][500];
int match[500];
int visited[500];

vector<dd> gopher;
vector<dd> holes;

int n,m,s,v;
double x,y;

int canMatch(int u) // dfs
{
	for(int j = 0; j < (int)holes.size();j++ )
	{
		if(!visited[j] && grafo[u][j])
		{
			visited[j] = true;
			if(match[j] < 0 || canMatch(match[j])) // se eu posso combnar o que estava conbinado em j com outro, assim recursivamente
			{	// vou testar todos que ja tiveram um mach
				match[j] = u;
				return 1;
			}
		}
	}
	return 0;
}

int MCBM(int nVertices)
{
	int matchs = 0;
	memset(match,-1,sizeof match);
	for(int i = 0; i < nVertices ;i++)
	{
		memset(visited,0,sizeof visited);
		matchs += canMatch(i);
	}
	return matchs;
}

int main()
{
	//~ freopen("in","r",stdin);
	//~ freopen("out","w",stdout);
	
	while(scanf("%d%d%d%d",&n,&m,&s,&v)!=EOF)
	{
		gopher.clear();
		holes.clear();
		memset(grafo,0,sizeof grafo);
		
		while(n--)
		{
			scanf("%lf%lf",&x,&y);
			gopher.push_back(dd(x,y));
		}
		while(m--)
		{
			scanf("%lf%lf",&x,&y);
			holes.push_back(dd(x,y));
		}
		for(int i = 0; i < (int)gopher.size();i++) // verificar a montagem desse grafo
		{
			for(int j = 0; j <(int)holes.size();j++)
			{
				double dist = hypot(gopher[i].first - holes[j].first , gopher[i].second - holes[j].second);
				if((double)dist/v + 1e-9 <= (double)s) grafo[i][j] = 1;
			}
		}
		printf("%d\n",(int)gopher.size() - MCBM(gopher.size()));
	}
}
