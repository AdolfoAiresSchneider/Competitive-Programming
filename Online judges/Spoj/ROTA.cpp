#include <bits/stdc++.h>
using namespace std;
 
#define maxn 300
 
typedef pair<string,string> ss;
typedef pair<int,ss> iss;
 
typedef pair<int, int> ii;
typedef pair<int,ii> iii;
 
map<string,int> id;
map<int,string> r_id;
map<ii,int> od;
 
vector<iii> ans;
vector<int> g[maxn];
int vis[maxn];
 
int n,m;
queue<int> q;
 
bool bfs (int u, int v)
{
	queue<int> q; q.push (0);
	memset(vis,0,sizeof vis);
	vis[0] = 1;
 
	while (!q.empty())
	{
		int t = q.front(); q.pop();
 
		for (int i=0; i<(int)g[t].size(); i++)
		{
			int V = g[t][i];
 
			if(vis[V]) continue;
			if ( !(t == u && i == v) )
			{
				vis[V] = 1;
				q.push (V);
			}
		}
	}
 
	for (int i=0; i<n; i++)
		if (!vis[i]) return 0;
	return 1;
}
 
 
void f()
{
	
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < (int)g[i].size(); j++)
		{
			memset(vis, 0, sizeof vis);
			if(!bfs(i,j)) 
				ans.push_back(iii(od[ii(g[i][j],i)],ii(g[i][j],i)));
		}
	}
}
	
 
 
int main()
{
	//~ freopen("in","r",stdin);
	
	while(cin>>n>>m && (n || m))
	{
		ans.clear();
		id.clear();
		r_id.clear();
		od.clear();
		
		for(int i = 0; i <= n;i++)
			g[i].clear();
			
		for(int i = 0; i < n; i++)
		{
			string a;
			cin>>a;
			
			id[a] = i;
			r_id[i] = a;
		}
		
		for(int i = 0; i < m; i++)
		{
			string a,b;
			cin>>a>>b;	
			od[ii(id[a],id[b])] = i;	
			g[id[b]].push_back(id[a]);
		}
		
		f();
		
		sort(ans.begin(),ans.end());
		for(int i = 0; i < (int)ans.size(); i++)
		{
			ii w = ans[i].second;
			cout<<r_id[w.first]<<' '<<r_id[w.second]<<endl;
		}
	
		if(ans.size() == 0) cout<<"Nenhuma"<<endl;
		else cout<<endl;
	}
}
 
