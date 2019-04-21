#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
typedef pair<ii,int> iii;
#define INF (static_cast<int>(1e9))

int dist[50000][30];
vector<iii> grafo[50000];
map<string,int> id;

inline int dikjstra(int inc,int fim,int qtd)
{
	iii f,v;
	int u,lt1,lt2,t;
	register int j,i;
	for(i = qtd+10; --i>=0;) for(j =30; --j>=0;) dist[i][j] = INF;
	dist[inc][29] = 0;
	priority_queue< iii, vector<iii>, greater<iii> > S;
	S.push(iii(ii(0,inc),29));
	while(!S.empty())
	{
		f = S.top(); S.pop();	
		u = f.first.second;
		lt1 = f.second;
		
	    t = grafo[u].size();
		for( i = t; --i>=0;)
		{
			v = grafo[u][i];
			lt2 = v.second;
			if(lt1!=lt2)
			{
				if(dist[u][lt1] + v.first.second < dist[v.first.first][lt2])
				{
					 dist[v.first.first][lt2]= dist[u][lt1] + v.first.second;
					 S.push(iii(ii(dist[v.first.first][lt2],v.first.first),lt2));	 
				}
			}
		}
	}
	
	register int cost = INF;
	for(i = 27; --i>=0  ;)
		cost = min(cost,dist[fim][i]);
	if(cost != INF) return cost;
	return -20;
}				

int main()
{
	//freopen("in","r",stdin);
	//freopen("out","w",stdout);
	int citys;
	string  a,b,c,inc,fim;
	register int i,j;
	while(cin>>citys&&citys)
	{
		cin>>inc>>fim;
		id[inc] = 1;
		id[fim] = 2;
		i = 2;
		while(citys--)
		{
			cin>>a>>b>>c;
			if(!id[a]) id[a] = ++i;
			if(!id[b]) id[b] = ++i;
			grafo[id[a]].push_back(iii(ii(id[b],c.size()),c[0]-97));
			grafo[id[b]].push_back(iii(ii(id[a],c.size()),c[0]-97));
			
		}
		++i;
		int cmp = dikjstra(1,2,i+1);
		if(cmp>0) cout << cmp << endl;
		else cout<<"impossivel"<<endl;	
		i+=10;
		for(j = 0; j <i;j++) grafo[j].resize(0);	
		id.clear();
	}
	return 0;
}
