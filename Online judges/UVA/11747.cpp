#include <bits/stdc++.h>
using namespace std;
typedef pair<long int,long int> ii;
typedef pair<long long int,ii> edge;

vector<edge> edges;
int p[1009];
set<long long int> pesos;

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
	for(int i = 0; i<= np;i++) p[i] = i;
	sort(edges.begin(),edges.end());
	
	for(int i = 0;i<(int)edges.size();i++)
	{
		edge front = edges[i];
		if(!isUnion(front.second.first,front.second.second))
		{
			unionSet(front.second.first,front.second.second);
		}
		else
		{
			pesos.insert(front.first);	
		}
	}
}

int main()
{
	freopen("in","r",stdin);
	int n,m,a,b,c;
	while(cin>>n>>m&&n)
	{
		while(m--)
		{
			cin>>a>>b>>c;
			edges.push_back(edge(c,ii(a,b)));
		}
		kruskal(n);
		if(!pesos.empty())
		{
			while(pesos.size()!=1)
			{
				cout<<*pesos.begin()<<" ";
				pesos.erase(pesos.begin());
			}
			cout<<*pesos.begin()<<endl;
		}
		else
		{
			cout<<"forest"<<endl;	
		}
		edges.clear();
		pesos.clear();
	}	
}
