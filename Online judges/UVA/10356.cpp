#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int> > grafo[600];
int dist[2][600];

void dkjstra(int nv)
{
	for(int i = 0;i<2;i++) for(int j = 0;j<=nv;j++) dist[i][j] = 9999999;
	priority_queue<pair<int,pair<int,int> >, vector<pair<int,pair<int,int> > >, greater<pair<int,pair<int,int> > > > S;
	dist[1][0] = 0;
	S.push(make_pair(0,make_pair(0,1)));
	
	while(!S.empty()){
		pair<int,pair<int,int> > aux = S.top(); S.pop();
		int d = aux.first;
		int u = aux.second.first;
		int bike = aux.second.second;
		if(d>dist[bike][u]) continue;
		for(int i = 0; i <(int)grafo[u].size();i++){
			pair<int,int> v = grafo[u][i];
			if(bike == 1){
				if(dist[1][u]+v.second<dist[0][v.first]){
					dist[0][v.first] = dist[1][u]+v.second;
					S.push(make_pair(dist[0][v.first],make_pair(v.first,0)));
				}
			}
			else{
				if(dist[0][u]+v.second<dist[1][v.first]){
					dist[1][v.first] = dist[0][u]+v.second;
					S.push(make_pair(dist[1][v.first],make_pair(v.first,1)));
				}
				
			}
		}
	}
}

int main()
{
	int nv,na;
	int r = 1;
	while(cin>>nv>>na)
	{
		while(na--){
			int a,b,c;
			cin>>a>>b>>c;
			grafo[a].push_back(make_pair(b,c));
			grafo[b].push_back(make_pair(a,c));		
		}	
		dkjstra(nv);
		cout<<"Set #"<<r++<<endl;
		if(dist[1][nv-1] !=9999999) cout<<dist[1][nv-1]<<endl;
		else cout<<"?"<<endl;
		for(int i = 0; i <nv;i++) grafo[i].clear();
	}
}
