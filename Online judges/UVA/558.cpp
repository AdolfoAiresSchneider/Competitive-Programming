#include <bits/stdc++.h>
using namespace std;



int main()
{
    int c;
    scanf("%d",&c);
    while(c--)
    {

        vector<pair<int,int> > grafo[1002];
        int dist[1002] = {99999999};
        int flag;

        int a,b;
        scanf("%d %d",&a,&b);

        for(int i = 0;i <= a;i++)
            grafo[a].clear();

        int aux = b;
        while(aux--)
        {
            int q,w,e;
            scanf("%d %d %d",&q,&w,&e);
            grafo[q].push_back(make_pair(w,e));
        }

        dist[0] = 0;

        for(int i = 0;i<a-1;i++)
            for(int u = 0;u<a;u++)
                for(int j = 0;j<(int)grafo[u].size();j++){
                    pair<int,int> aux = grafo[u][j];
                    dist[aux.first] = min(dist[aux.first],dist[u]+aux.second);
                }
        flag = 0;
        for(int u = 0;u<a;u++)
            for(int j =0; j<(int)grafo[u].size();j++){
                    pair<int,int> aux = grafo[u][j];
                    if(dist[aux.first] > dist[u]+aux.second){
                        flag = 1;
                        break;
                    }
            }
        if(flag)
            cout<<"possible"<<endl;
        else
            cout<<"not possible"<<endl;
    }
}
