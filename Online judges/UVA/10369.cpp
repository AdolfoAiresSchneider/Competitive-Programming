	#include <bits/stdc++.h>
	using namespace std;
	typedef pair<int,int> ii;
	
	int p[130000];
	struct Edge
	{
		int from;
		int to;
		double dist;
		Edge(int from,int to, double dist) : from(from),to(to),dist(dist){}
	};
	bool operator < ( Edge a ,Edge b){  return a.dist < b.dist ; }
	
	vector<ii> pontos;
	vector<Edge> edges;
	int find(int a)
	{
		if(a==p[a]) return a;
		return p[a] = find(p[a]);
	}
	int isUnion(int a,int b)
	{
		return find(a) == find(b);
	}
	void unionSet(int a, int b)
	{
		p[find(a)] = find(b);
	}
	double kruskal(int np,int satelite)
	{
		int y = 0;
		for(int i = 0; i < (int)pontos.size() ;i++) p[i] = i;
		sort(edges.begin(),edges.end());
		double cost = 0;
		for(int i = 0; i < (int)edges.size() && y < np-satelite ;i++)
		{
				Edge front = edges[i];
				if(!isUnion(front.from,front.to))
				{
					unionSet(front.from,front.to);
					cost = front.dist;
					y++;
				}
		}
		return cost;
	}

	int main()
	{
		//freopen("in2","r",stdin);
		//freopen("out","w",stdout);
		int a;
		cin>>a;
		while(a--)
		{
			int satelites,np;
			cin>>satelites>>np;
			int na = np;
			while(na--)
			{
				int x,y;
				cin>>x>>y;
				pontos.push_back(ii(x,y));
			}
			for(int i = 0; i <(int)pontos.size();i++)
			{
				for(int j = i+1; j < (int)pontos.size();j++)
				{	
					edges.push_back(Edge(i,j,hypot(pontos[i].first-pontos[j].first,pontos[i].second-pontos[j].second)));		
				}
			}
			double ans = kruskal(np,satelites);
			printf("%.2f\n",ans);						
			edges.clear();
			pontos.clear();
		}
}
