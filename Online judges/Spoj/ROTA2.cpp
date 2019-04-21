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
vector<ii> g[maxn];
int vis[maxn];
 
int n,m;
queue<int> q;
 
void bfs1()
{
	q.push(0);
	vis[0] = 1;
	memset(vis, 0 , sizeof vis); 
	
	while(!q.empty())
	{
		int u = q.front(); q.pop();
		vis[u] = 1;
 
		for (int i = 0; i < (int)g[u].size(); i++)
		{
			int v = g[u][i].first;	
			if (!vis[v])
			{
				g[u][i] = ii(v, 1);
				q.push (v);
			}
		}
	}
}
 
 
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
			int V = g[t][i].first;
 
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
	bfs1();
	
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < (int)g[i].size(); j++)
		{
			if(!g[i][j].second ) continue;
			memset(vis, 0, sizeof vis);
			if(!bfs(i,j))  ans.push_back(iii(od[ii(g[i][j].first,i)],ii(g[i][j].first,i)));
		}
	}
	
	sort(ans.begin(),ans.end());
	for(int i = 0; i < (int)ans.size(); i++)
	{
		ii w = ans[i].second;
		cout<<r_id[w.first]<<' '<<r_id[w.second]<<endl;
	}
	
	
	if(ans.size() == 0) cout<<"Nenhuma"<<endl;
	else cout<<endl;
	
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
			g[id[b]].push_back(ii(id[a],0));
		}
		
		f();
	}
}
