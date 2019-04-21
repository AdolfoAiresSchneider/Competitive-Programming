#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
typedef pair<int,ii> edge;

vector<edge> edges;
map<string,int > id;
set<int> fathers;
int p[500];

int find(int a)
{
	if(p[a]==a) return a;
	return p[a] = find(p[a]);
}

bool isUnion(int a, int b)
{
	return find(a) == find(b);
}

void unionSet(int a,int b)
{
	p[find(a)] = find(b);
}

int kruskal(int np)
{
	for(int i = 0;i<=np;i++) p[i]=i;
	sort(edges.begin(),edges.end());
	int cost = 0;
	
	for(int i = 0; i<(int)edges.size();i++)
	{
		edge front = edges[i];	
		if(!isUnion(front.second.first,front.second.second))
		{
			cost+= front.first;
			unionSet(front.second.first,front.second.second);
		}
	}
	return cost;
}


int main()
{
	//freopen("in","r",stdin);
	int n,m,c,startVertice,flag;
	string name,a,b;
	while(cin>>n>>m&&n)
	{
		for(int i = 0; i <n;i++)
		{
			cin>>name;
			id[name] = i;
		}
		while(m--)
		{
			cin>>a>>b>>c;
			edges.push_back(edge(c,ii(id[a],id[b])));
		}	
		cin>>a;
		startVertice = id[a];
		flag = 0;
		int cost = kruskal(n);
		for(int i = 0;i < n;i++)
		{
			fathers.insert(find(i));
			if(fathers.size()>=2) 
			{
				flag = 1;	
				break;	
			}
		}
		if(flag) printf("Impossible\n");
		else printf("%d\n",cost);
		edges.clear();
		id.clear();
		fathers.clear();
	}
}
