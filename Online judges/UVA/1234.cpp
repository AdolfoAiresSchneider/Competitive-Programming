#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
typedef pair<int,ii> edge;

vector<edge> edges;
int p[11000];


int find(int a)
{
	if(p[a]==a) return a;
	else return p[a] = find(p[a]);
}

void unionSet(int a,int b)
{
	p[find(a)] = find(b);
}

bool isUnion(int a, int b)
{
	return find(a) == find(b);
}


void kruskal(int np,int soma)
{
	for(int i = 0; i <= np;i++) p[i] = i;
	int cost = soma;
	sort(edges.rbegin(),edges.rend());
	
	for(int i = 0; i <(int)edges.size();i++)
	{
		edge front = edges[i];
		if(!isUnion(front.second.first,front.second.second))
		{
			cost-=front.first;
			unionSet(front.second.first,front.second.second);	
		}
	}
	cout<<cost<<endl;
}


int main()
{
	//freopen("in","r",stdin);
	//freopen("out","w",stdout);
	int casos;
	int n,m,a,b,c;
	scanf("%d",&casos);
	while(casos--)
	{
		scanf("%d %d",&n,&m);
		int soma=0;
		while(m--)
		{
			scanf("%d %d %d",&a,&b,&c);
			edges.push_back(edge(c,ii(a,b)));
			soma+=c;
		}
		kruskal(n,soma);
		edges.clear();
	}
	cin>>m;
}
