#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int> > grafo[150];
int dist[150];

int dkjstra(int timer,int s,int m){
	for( int i = 1; i <= m; i++ ) dist[i] = 999999;
	priority_queue<pair<int,int> > S;
	dist[s] = 0 ;
	S.push(make_pair( 0 , s ));
	while(!S.empty()){
		int u = S.top().second; S.pop();
		if(dist[u] <= timer )
		for(int i = 0;i < (int)grafo[u].size() ; i++ ){
			pair<int,int> aux = grafo[u][i];
			if(dist[u] + aux.second < dist[aux.first] ){
				dist[aux.first]  = 	dist[u] + aux.second;
				S.push(make_pair(dist[aux.first],aux.first));
			}
		}
	}
	int c=0;
	for(int i = 1;i<=m;i++)
		if(dist[i] <= timer)
			c++;
	return c;
}

int main(){
	int n;
	cin>>n;
	while(n--){
		int a,b,c,d;			
		cin>>a>>b>>c>>d;
		while(d--)
		{
			int x,y,z;
			cin>>x>>y>>z;
			grafo[y].push_back(make_pair(x,z));
		}
		cout<<dkjstra(c,b,a)<<endl;
		if(n) cout<<endl;
		for(int i = 0;i<150;i++)
		{ 
			dist[i] = 999999;
			grafo[i].clear();
		}
	}
}
