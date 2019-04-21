#include <bits/stdc++.h>
using namespace std;
#define inf 9999999
using namespace std;

vector<pair<int,int> > grafo[105];
int dist[105][100];
map<string, int> id;

void dikstra(int n, int k) 
{
    queue<pair<int,int> > s;
    for(int i = 0; i < n; i++) for(int j = 0; j <= k; j++) dist[i][j] = inf;
    dist[0][0] = 0;
    s.push(make_pair(0,0));
    while(!s.empty()) {
		pair<int , int > v =  s.front(); s.pop();
        if(v.second >= k)    continue;
        for(int i = 0;i<(int)grafo[v.first].size();i++){
			pair<int,int> c = grafo[v.first][i];
			if(dist[c.first][v.second+1] > dist[v.first][v.second] + c.second){
				dist[c.first][v.second+1] = dist[v.first][v.second] + c.second;
				s.push(make_pair(c.first,v.second+1));
			}
		}
    }
    int ans = inf;
    for(int i = 0; i <= k; i++)  ans = min(ans,dist[n-1][i]);
    if(ans == inf) puts("No satisfactory flights");
    else printf("Total cost of flight(s) is $%d\n", ans);
}
int main() 
{
	freopen("in","r",stdin);
	freopen("saida","w",stdout);
    int cases = 0, n, m;
    int  i, j, v;
    int e;
    string cidade;
    cin>>e;
    while(e--) {
		cin>>n;
        for(i = 0; i < n; i++) {
            cin>>cidade;
            id[cidade] = i;
            grafo[i].clear();
        }
        cin>>m;
        while(m--) {
            cin>>cidade;
            i = id[cidade];
            cin>>cidade;
            j = id[cidade];
            cin>>v;
            grafo[i].push_back(make_pair(j, v));
        }
        if(cases)   cout<<endl;
        printf("Scenario #%d\n", ++cases);
        int q, l;
        cin>>q;
        while(q--) {
            cin>>l;
            dikstra(n, l+1);
        }
        id.clear();
    }
}
