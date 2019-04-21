#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;

#define maxn 100003
#define endl '\n'

//------------------------------ Interesting facts about graphs -------------------------------------

//~ --> The SUM of all vertice's degrees of a graph is allways twice the number of Edges .
//~ --> In any graph the are a even number of odd degree vertices.

/*  --> The Erdős-Gallai theorem : Check if the graph or path is graphical or not.
          
          * the integer d1 + ⋯ + dn is even;
          * for any 1 ≤ k ≤ n, d1 + ⋯ + dk ≤ k(k−1) + min(k,dk+1) + ⋯ + min(k,dn);
          
    --> A graph is bipartite if and only if there is no odd cycle. That holds true for the oposite. 
    --> A graph is a Tree if there is no cycle and the graph is conected.
    
    * 
    --> The eccentricity of a vertex is the is : E(v)  = max(dist(v, u)), for all u in G.
    --> Radius of a graph is :Rad(G) =  min(E(u)) of the graph for all u in G.
    --> If E(v) == Diam(G), then v it's is called peripheral.
    --> If E(v) == Rad(G), then v it's is called Center
    --> Rad(G) <= Diam(G) <= 2(Rad(G))
    
    * 
*/



ll g[maxn], P[maxn];

int main()
{
	int n;
	while(scanf("%d", &n) == 1)
	{	
		ll SUM = 0, FLAG = 0;
		
    for(int i = 0; i < n; i++)
    {
			scanf("%lld",&g[i]);
			SUM += g[i];
		}
		
		if(SUM % 2)
		{
			printf("impossivel\n");
			continue;
		}
			
		sort(g, g+n); reverse(g, g+n);
    memset(P, 0, sizeof P);
    
		P[n-1] = g[n-1]; 
		for(int i = n-2; i >= 0; i--)
			P[i] = g[i] + P[i+1]; 
		
    
		SUM = FLAG = 0;
		for(int i = 1; i <= n; i++)
		{
			SUM += g[i-1];
      
			ll idx = lower_bound(g+i, g+n, i, greater<ll>()) - g;
      ll SUM2 = (idx-i)*i + P[idx] + i*(i-1ull);
      
			if(SUM > SUM2)
			{
				printf("impossivel\n"), FLAG = 1;
				break;
			}
		}
    
		if(FLAG)
			continue;
      
		printf("possivel\n");
	}
}	
  
