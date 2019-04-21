#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
typedef pair<int,ii> edge;

vector<edge> edges;
vector<edge> edges2;
int p[30];


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

void kruskal(int np)
{
	for(int i = 0; i <= np;i++) p[i] = i;
	sort(edges.begin(),edges.end());
	
	for(int i = 0;i<(int)edges.size();i++)
	{
		edge front = edges[i];
		if(!isUnion(front.second.first,front.second.second))	
		{
			unionSet(front.second.first,front.second.second);	
			edges2.push_back(front);
		}
	}
}

int main()
{
	int n,nc,peso,caso=1;
	char aux;
	cin>>n;
	while(n--)
	{
		cin>>nc;
		for(int i = 0; i <nc;i++)
		{
			for(int j = 0; j < nc;j++)
			{
				scanf("%d%c",&peso,&aux);
				if(j != i && peso > 0 ) edges.push_back(edge(peso,ii(i,j)));	
			}	
		}
		
		kruskal(nc);
		cout<<"Case "<<caso++<<":"<<endl;
		for(int i= 0; i<(int)edges2.size();i++)
		{
			edge front = edges2[i];
			char a = front.second.first+65;
			char b = front.second.second+65;
			cout<<a<<"-"<<b<<" "<<front.first<<endl;
		}
		edges.clear();
		edges2.clear();
	}
}
