#include <bits/stdc++.h>
using namespace std;
typedef pair<long long int,long long int> ii;

vector<ii> grafo[200010];
vector<int> taken;
priority_queue<ii> pq;


void process(int vtx)
{
	ii v;
	taken[vtx] = 1;
	for(int i = 0;i <(int)grafo[vtx].size();i++)
	{
		v = grafo[vtx][i]; 
		if(!taken[v.first]) pq.push(ii(-v.second,-v.first));
	}
}

int main()
{
	//freopen("in","r",stdin);
	long int m,n;
	long long a,b,c,sum = 0;;
	while(cin>>m>>n&&n)
	{
		sum = 0;
		while(n--)
		{  
			cin>>a>>b>>c;
			grafo[a].push_back(ii(b,c));   
			grafo[b].push_back(ii(a,c));   
			sum+=c;
		}		
		taken.assign(m+1,0);
		long long mstcost = 0,w,u;
		process(0);
		while(!pq.empty())
		{
			ii front  = pq.top(); pq.pop();
			u = -front.second;
			w = -front.first;
			if(!taken[u]) 
			{
				mstcost+=w;
				process(u)	;
			}
		}
		cout<<sum - mstcost<<endl;
		for(int i = 0; i <m+9;i++) grafo[i].clear();
	}
}
