#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;

// Dag --> bfs com dp -->  calcula o numero de caminhos minimos

int city[100][100];
int dp[100][100];
int dist[100][100];
int a,b,x,y;

int mx[] = {0,0,1,-1}; 
int my[] = {1,-1,0,0};

int bfs()
{
	memset(dist,0,sizeof dist);
	memset(dp,0,sizeof dp);
	
	dp[0][0] = 1;
	queue<ii> S; S.push(ii(0,0));
	
	while(!S.empty())
	{
		ii atual = S.front(); S.pop();
		
		for(int i = 0; i < 4;i++)
		{
			int x = atual.first + mx[i];
			int y = atual.second + my[i];
			
			if(x < 0 || y < 0 || x >= a || y >= b || city[x][y] == 0) continue;
			
			if(dist[x][y] == 0)
			{
				dist[x][y] = dist[atual.first][atual.second] + 1;
				S.push(ii(x,y));
			}
			
			if(dist[x][y] == dist[atual.first][atual.second] + 1) // só atualiza se for o tamanho minimo
				dp[x][y] += dp[atual.first][atual.second];
		}
	}
	return dp[a-1][b-1];
}

int main()
{
	
	int casos;
	string line;
	scanf("%d",&casos);	

	while(casos--)
	{	
		scanf(" %d%d",&a,&b);
		
		for(int i =0 ; i <= a;i++) for(int j = 0 ; j <= b ; j++) city[i][j] = 1; // limpar o grafo
				
		for(int i = 0; i < a ;i++)
		{
			scanf(" ");
			getline(cin,line);
			stringstream fluxo(line);
			fluxo>>x;
		
			while(fluxo>>y)
				city[x-1][y-1] = 0;	 // coloca as restrições
		}
		
		cout << bfs() << endl;
		if(casos) cout<<endl;
	}
}
