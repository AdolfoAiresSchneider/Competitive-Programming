#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int> > grafo[105];
int tempo[5];
vector<int> dist;
void dkjstra(int s){
    priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > fila;
    fila.push(make_pair(0,s));
    while(!fila.empty()){
        pair<int,int> front = fila.top(); fila.pop();
        int d = front.first, u = front.second;
        if(d>dist[u]) continue;
        for(int j = 0;j<(int)grafo[u].size();j++){
            pair<int,int> v = grafo[u][j];
            if(dist[u]+v.second + 60 < dist[v.first] ){
                dist[v.first] = dist[u]+v.second+60;
                fila.push(make_pair(dist[v.first],v.first));
            }
        }
    }
}
int main(){
    int n,k;
    string el;
    freopen("test.txt","r",stdin);
    while(cin>>n>>k){
        for(int i = 0; i <=30;i++)
            grafo[i].clear();
        memset(tempo,-1,sizeof(tempo));
        for(int i =1;i<=n;i++)
            scanf(" %d ",&tempo[i]);
        for(int i =1;i<=n;i++){
            getline(cin,el);
            int nodes[el.size()];
            stringstream fluxo(el);
            int l = 0;
            while(fluxo>>nodes[l++]);
            for(int x = 0; x<l-1;x++)
                for(int y = x+1;y<l-1;y++){
                    grafo[nodes[x]].push_back(make_pair(nodes[y],(nodes[y]-nodes[x])*tempo[i]));
                    grafo[nodes[y]].push_back(make_pair(nodes[x],(nodes[y]-nodes[x])*tempo[i])); ///cout<<i<<'-'<<nodes[x]<<' '<<nodes[y]<<" "<<(nodes[y]-nodes[x])*tempo[i]<<endl;
                }
        }
        dist.assign(200,999999);
        dist[0] = 0;
        dkjstra(0);
        if(dist[k] != 999999){
            if(k!=0) cout<<dist[k]-60<<endl;
            else cout<<dist[k]<<endl;
        }
        else
            cout<<"IMPOSSIBLE"<<endl;
    }
}
