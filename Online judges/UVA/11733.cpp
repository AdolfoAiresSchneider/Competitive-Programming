#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;


int pais[10009];
vector <iii> edges;
int s;

int find(int a)
{
	if(a == pais[a]) return a;
	return pais[a] = find(pais[a]);
}

int isUnion(int a, int b)
{
	return find(a) == find(b);
}

void unionSet(int a, int b)
{
	pais[find(a)] = find(b);
}

int kruskal(int np,int cport)
{
	for(int i = 0; i <= np ;i++) pais[i] = i;
	sort(edges.begin(),edges.end());
	int cost ;
	s = np;
	cost = np*cport;
	for(int i = 0; i < (int)edges.size(); i++)
	{
		iii front = edges[i];	
		if(!isUnion(front.second.first,front.second.second))
		{
			unionSet(front.second.first,front.second.second);
			cost += front.first - cport;
			s--;
		}
	}
	return cost;
}
int main()
{
	freopen("in","r",stdin);
	int a,n,m,ca,x,y,c,caso=1;
	scanf("%d",&a);
	while(a--)
	{
		scanf("%d %d %d",&n,&m,&ca);
		while(m--)
		{
			scanf("%d %d %d",&x,&y,&c);	
			if(c < ca)
				edges.push_back(iii(c,ii(x,y)));
		}
		cout<<"Case #"<<caso++<<": ";
		int o = kruskal(n,ca);
		cout<<o<<" "<<s<<endl;
		edges.clear();
	}
}
