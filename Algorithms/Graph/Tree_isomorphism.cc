#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
#define maxn 10001
#define pb push_back

int l[maxn], deg1[maxn], deg2[maxn], cnt, N;

vi g1[maxn], g2[maxn], c1, c2;

map<vi, int > dp;

// Calcula os subconjuntos de cada vertice
int f(int u , vi * g, int pai)
{
	vi sub;
  for(auto v : g[u])
	{
		if(v == pai) 
      continue;
         
		sub.pb(f(v,g,u));
	}
  
	sort(sub.begin(), sub.end());
  
	if(dp[sub]) 
    return dp[sub];
    
	return  dp[sub] = cnt++;
}

// Econtra os centros de um grafo
vi findCenter( vi* g, int * deg )
{
  vi c;
  int maxlevel = 1;
  queue<int> q; 
  
	for(int i = 0 ; i <= N; i++)
  {
    if(deg[i] == 1) 
      q.push(i);
      
    l[i] = 0;  
  }
  
	while(!q.empty())
	{
		int u = q.front(); q.pop();
		for(auto v : g[u])
		{
			if(--deg[v] == 1)
			{
				q.push(v);
				l[v] = l[u] + 1;	
				maxlevel = max(maxlevel , l[v]);
			}
		}
	}
	
	for(int i = 0; i < N;i++)
		if(l[i] == maxlevel)
			c.pb(i);
			
	return c;
}

bool isIsomorfo(vi & c1, vi & c2) 
{	
	vi h1, h2;
  
  for(int v : c1)
		h1.pb(f(v, g1, v));
    
  for(int v : c2)
		h2.pb(f(v, g2, v));
  
  for(int v : h1)
    for(int u : h2)
      if(u == v)
        return true;
				
	return false;
}

void init(int n)
{
  while(n--)
    g1[n].clear(), g2[n].clear();
    
  memset(deg1, 0, sizeof deg1);
  memset(deg2, 0, sizeof deg2);
  
}


int main()
{
	//~ freopen("in","r",stdin);
	//~ freopen("ot2","w",stdout);
	
  cnt = 1;
	while(cin>>N)
	{
		init(N);
		
		for(int i = N -1 ; i--;)
		{
      int a, b;
			cin>>a>>b;
			a--;b--;
			g1[a].pb(b), g1[b].pb(a);
			deg1[a]++, deg1[b]++;
		}
		
		for(int i = 0; i < N-1;i++)
		{
      int a, b;
			cin>>a>>b;
			a--;b--;
			g2[a].pb(b), g2[b].pb(a);
			deg2[a]++, deg2[b]++;
		}	
		
		c1 = findCenter(g1 , deg1);
		c2 = findCenter(g2 , deg2);		
		
		if(isIsomorfo(c1,c2)) 
      printf("S\n");
		else printf("N\n");
	}
}
