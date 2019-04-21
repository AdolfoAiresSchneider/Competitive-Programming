#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> ii;
typedef pair<char,ii> iii;

// Converter um grafo em dag , Caminho + numero de caminhos minimos em um unico BFS

int N;
vector<iii> letras;

char grafo[12][12];
int dist[12][12];
int dp[12][12];

int mx[] = {0,0,1,-1}; 
int my[] = {1,-1,0,0};


ii bfs(int x, int y, char letra, int x2,int y2)
{
	queue<ii> S;
	S.push(ii(x,y));
	
	memset(dp,0,sizeof dp);
	memset(dist,0,sizeof dist);
	
	dp[x][y] = 1;
    dist[x][y] = 0;
	
	while(!S.empty())
	{
		ii front = S.front(); S.pop();
		
		x = front.first;
		y = front.second;
		
		for(int i = 0; i < 4;i++)
		{
			int xx = x+mx[i]; 
			int yy = y+my[i];
			
			if(xx < 0 || xx >= N || yy < 0 || yy >= N) continue;
			if(grafo[xx][yy] != '.' && grafo[xx][yy] != letra) continue;
			
			if( dist[xx][yy] == 0)
			{
				dist[xx][yy] = dist[x][y] + 1;
				S.push(ii(xx,yy));
			}	
			
			if(dist[xx][yy] == dist[x][y] + 1)
			{
				dp[xx][yy] += dp[x][y];
				dp[xx][yy] %= 20437;
			}
		}
	}
	if(dist[x2][y2] == 0) return ii(-1,-1);
	return ii(dist[x2][y2],(dp[x2][y2]));
}


int main()
{
	int caso=1;
	
	//~ freopen("in","r",stdin);
	//~ freopen("out","w",stdout);
	
	while(cin>>N&&N)
	{
		letras.clear();
		
		for(int i = 0;i < N;i++){
			for(int j = 0;j < N;j++){
				cin>>grafo[i][j];
				if(grafo[i][j] != '#' && grafo[i][j]!='.')
					letras.push_back(iii(grafo[i][j],ii(i,j)));	
			}
		}
		
		
		ll ways = 1;
		int passos = 0;
		
		sort(letras.begin(),letras.end());
		grafo[letras[0].second.first][letras[0].second.second] = '.';
		
		for(int i = 0; i <(int)letras.size()-1;i++)
		{
			char l = letras[i+1].first;
			
			int x = letras[i].second.first;
			int y = letras[i].second.second;
			
			
			ii aux = bfs(x,y,l,letras[i+1].second.first,letras[i+1].second.second);
			grafo[letras[i+1].second.first][letras[i+1].second.second] = '.';
			
			if(aux.first == -1)
			{
				passos = -1;
				break;	
			}
						
			passos += aux.first;
			passos %= 20437;
			ways *= aux.second;
			ways %= 20437;
		}		
		if(passos == -1) printf("Case %d: Impossible\n",caso++);
		else printf("Case %d: %d %lld\n",caso++,passos,ways);
	}
}
