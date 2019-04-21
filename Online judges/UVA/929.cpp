#include <bits/stdc++.h>
using namespace std;

int matriz[1002][1002];
int dist [1002][1002];

int mx[] = {1,-1,0,0};
int my[] = {0,0,1,-1};

void dikjstra(int xx,int yy)
{
	dist[1][1] = matriz[1][1];
	priority_queue<pair<int,pair<int,int> >, vector<pair<int,pair<int,int> > >, greater<pair<int,pair<int,int> > > > S;
	S.push(make_pair(0,make_pair(1,1)));
	while(!S.empty())
	{
	    pair<int,pair<int,int> > front = S.top(); S.pop();
	    pair<int,int> u = front.second; //vertice
	    int d = front.first; // peso que esta carregando
	    if(d>dist[u.first][u.second]) continue;
	    for(int i = 0; i <4;i++)
		{
			int x = u.first+mx[i];
			int y = u.second+my[i];
			int p = matriz[x][y];
			if( x>0 && y>0 && x<=xx&&y<=yy )
			{
				if(dist[u.first][u.second]+p < dist[x][y])
				{
					dist[x][y] = dist[u.first][u.second]+p;
					S.push(make_pair(dist[x][y],make_pair(x,y)));
				}
			}
		}
	}
}
int main()
{
	int n;
	cin>>n;
	while(n--)
	{		
		int x,y;
		cin>>x>>y;
		for(int i = 1;i<=x;i++)
			for(int j = 1;j<=y;j++)
			{
				dist[i][j] = 99999999;
				cin>>matriz[i][j];
			}
		dikjstra(x,y);
		cout<<dist[x][y]<<endl;
	}
}
