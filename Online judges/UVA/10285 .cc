#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
typedef pair<int,ii> iii;

// Apenas o maior caminho em um dag, bfs foi utilizado

int grafo[101][101];
int resp;

int r,c;

bool valido(int x, int y)
{
	return !(x < 0 || x >= r || y < 0 || y >= c); 	
}


int mx[] = {-1,0,0,1};
int my[] = {0,-1,1,0};

void  bfs(int i, int j)
{	
	priority_queue <iii> S;
	S.push(iii(1,ii(i,j)));
	
	while(!S.empty())
	{
		iii front = S.top();S.pop();
		resp = max(resp,front.first);
	    
		for(int k = 0; k <4 ; k++)
		{
			int x = front.second.first + mx[k];
			int y = front.second.second + my[k];
			
			if(valido(x,y) && grafo[x][y] < grafo[front.second.first][front.second.second])
				S.push(iii(front.first+1,ii(x,y)));
		}
	}
}

int main()
{
	 //~ freopen("in","r",stdin);
	 //~ freopen("out","w",stdout);
	
	string a;
	int casos;
	scanf("%d",&casos);
	while(casos--)
	{
		cin>>a>>r>>c;
		for(int i = 0 ; i < r; i++)
			for(int j = 0; j <c;j++)
				cin>>grafo[i][j];
		
		resp = 0;
		for(int i = 0 ; i < r; i++)
			for(int j = 0; j < c;j++)
				bfs(i,j);
		cout<<a<<": "<<resp<<endl;
	}
}
