#include <bits/stdc++.h>
using namespace std;
//////////////////////  Network - 315 uva

bool visit[110];
vector<long int >grafo[110];	
int n;

int AP() 
{
    for(int i=1 ; i<=n ; ++i)
       if(!visit[i]) return 1;	
    return 0;
}

void dfs(int node) // dfs default
{
    visit[node]=true;
    for(int j=0;j<(int)grafo[node].size();j++)
        if(!visit[grafo[node][j]]) dfs(grafo[node][j]);
}

int main()
{
    register int i, f, t , ans;
    string aux;

    while(scanf("%d",&n) != EOF)
    {
        for(i=1;i<=n;i++) grafo[i].clear(); // cleaning the graph
        if(n==0) break;
        if(n==1)
        {
            cin>>f;
            printf("0\n");
            continue;
        }
        getchar();
        while(getline(cin,aux))
        {
            istringstream stream(aux);
            stream>>f;
            if(f==0) break;
            while(stream>>t)
            {
                grafo[f].push_back(t);
                grafo[t].push_back(f);
            }
        }
        
        ans=0;
        for(i=2; i<=n ; ++i){
            memset(visit,0,sizeof(visit));
            visit[i]=true; // to check if this is a articulation point
            dfs(1);
            ans+=AP();
        }
        
        memset(visit,0,sizeof(visit));
        visit[1]=true;
        dfs(2);
        ans+=AP();
        
        printf("%d\n",ans);
    }
}
